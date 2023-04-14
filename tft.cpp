#include "tft.h"
#include "Arduino.h" 
#include "nes_palette.h"
#include "game_data.h"
#include "charset.h"
    
#define TFT_WIDTH 320
#define TFT_HEIGHT 240

//#define TFT_WIDTH 480
//#define TFT_HEIGHT 320

#if defined(__AVR_ATmega328P__) // Arduino Uno

static const int LCDpin[8] = {8, 9, 2, 3, 4, 5, 6, 7};

#define RESET A4
#define CS A3
#define RS A2
#define WR A1
#define RD A0

#define TFT_SWAP_DATA_WR    PORTC = 1+4+16; PORTC = 1+2+4+16;
#define TFT_SWAP        PORTC &= ~2;PORTC |= 2;
#define TFT_SWAP_RD     PORTC &= ~1;PORTC |= 1;
#define TFT_CMD_MODE    PORTC &= ~4;
#define TFT_DATA_MODE    PORTC |= 4;
#define TFT_DATAPIN_SET(v) PORTD=v&0xFC;PORTB=v&3;

#elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__) // Mega 1280 & 2560

static const int LCDpin[8] = {22, 23, 24, 25, 26, 27, 28, 29};

#define RESET 33
#define CS 34
#define RS 35
#define WR 36
#define RD 37

#define TFT_SWAP_DATA_WR    PORTC = 1+4+16; PORTC = 1+2+4+16;
#define TFT_SWAP        PORTC &= ~2; PORTC |= 2;
#define TFT_CMD_MODE    PORTC &= ~4;
#define TFT_DATA_MODE    PORTC |= 4;
#define TFT_DATAPIN_SET(v) PORTA=v;

// RD WR RS CS RST
// 1  0  1  0  1

#elif defined(__SAM3X8E__)  //due

static const int LCDpin[8] = {25, 26, 27, 28, 14, 15, 29, 11};

#define RESET 33
#define CS 34
#define RS 35
#define WR 36
#define RD 37

// RESET CS RS WR   RD
//  2    4   8  16  32

#define TFT_SWAP_DATA_WR    REG_PIOC_ODSR = 32+8+2; REG_PIOC_ODSR = 32+8+2+16;
//#define TFT_SWAP_DATA_WR        REG_PIOC_ODSR &= ~16; REG_PIOC_ODSR |= 16;
#define TFT_SWAP        REG_PIOC_ODSR &= ~16; REG_PIOC_ODSR |= 16;
#define TFT_CMD_MODE    REG_PIOC_ODSR &= ~8;
#define TFT_DATA_MODE    REG_PIOC_ODSR |= 8;
#define TFT_DATAPIN_SET(v) REG_PIOD_ODSR = v;

#endif

Tft::Tft()
{}

void Tft::Init()
{
  //PinSetup
  pinMode(RESET, OUTPUT);
  pinMode(CS, OUTPUT);
  pinMode(RS, OUTPUT);
  pinMode(WR, OUTPUT);
  pinMode(RD, OUTPUT);
  for ( int i = 0; i < 8; ++i )
    pinMode(LCDpin[i], OUTPUT);
  digitalWrite( RD, HIGH );
  digitalWrite( WR, HIGH );
  digitalWrite( CS, LOW );

  HWReset();

  SendCmd(0x1);   //Software reset
  delay(120);

  SendCmd(0xB6);    // Display Function Control 
  SendData(0x08); 
  SendData(0x82);
  SendData(0x27);

  //SendCmd(0xB1);  //Frame rate
  //SendData(0);
  //SendData(0x10);

  //SendCmd(0x34);  //Tearing Effect Line OFF

  SendCmd(0x3A);  //Pixel Format 16bpp only
  SendData(0x55); //RGB
 
  SendCmd(0xC0);    //Power control 
  SendData(0x23);   // 4.6v 
  //SendData(0x03);   // 3.0v
  //SendData(0x2B);   // 5.0v
 
  SendCmd(0xC1);    //Power control 
  SendData(0x10);
 
  SendCmd(0xC5);    //VCM control 
  SendData(0x3e);   //4.2 v
  SendData(0x28); 
  SendCmd(0xC7);    //VCM control2 
  SendData(0x86);
  
  //Write CTRL Display
  /*SendCmd(0x53);
  SendData(0xff);    //4 - Backlight Control   //8 - Display Dimming, only for manual brightness setting //32 Brightness Control Block On/Off
  //Backlight Control
  SendCmd(0xB8);
  SendData(0);
  SendCmd(0xB9);
  SendData(0);
  SendCmd(0xBA);
  SendData(0);
  SendCmd(0xBB);
  SendData(0);
  SendCmd(0xBC);
  SendData(0);
  SendCmd(0xBE);
  SendData(0);
  SendCmd(0xBF);
  SendData(0);
  SendCmd(0x51); // Write Display Brightness
  SendData(0x0); // 00h value means the lowest brightness*/
  

  SendCmd(0x11);  //Sleep off
  delay(5);
  SendCmd(0x29);
  SendCmd(0x13);
  SendCmd(0x38);

  SendCmd(0x36);  //Memory Access Control
  SendData( 0
    //| 0x04  //Horizontal Refresh ORDER
    | 0x08  //RGB-BGR Order
    //| 0x10  //Vertical Refresh Order
    | 0x20  //Row / Column Exchange
    //| 0x40 //Column Address Order
    //| 0x80  //Row Address Order
    );  //32 -x/y flip 64 - y flip 128-xflip
}

void Tft::VerticalScrollingDefinition( uint16_t top_fixed, uint16_t v_scroll, uint16_t bot_fixed )
{
  SendCmd(0x33);
  SendData(top_fixed >> 8);
  SendData(top_fixed&0xFF);
  SendData(v_scroll >> 8);
  SendData(v_scroll&0xFF);
  SendData(bot_fixed >> 8);
  SendData(bot_fixed&0xFF);
}

void Tft::VerticalScrollingStartAddress( uint16_t address )
{
  SendCmd(0x37);
  SendData(address >> 8);
  SendData(address & 0xFF);
}

void Tft::PartialArea( uint16_t area_start, uint16_t area_end )
{
  SendCmd(0x30);
  SendData(area_start >> 8);
  SendData(area_start & 0xFF);
  SendData(area_end >> 8);
  SendData(area_end & 0xFF);
}

void Tft::PartialMode()
{
  SendCmd(0x12);
}

void Tft::NormalMode()
{
  SendCmd(0x13);
}

void Tft::TearingEffectLineOn()
{
  SendCmd(0x35);
}

void Tft::TearingEffectLineOff()
{
  SendCmd(0x34);
}

void Tft::HWReset()
{
  digitalWrite(RESET, LOW);
  delay(12);
  digitalWrite(RESET, HIGH);
  delay(12);
}

void Tft::SendCmd( uint8_t cmd )
{
  TFT_CMD_MODE
  TFT_DATAPIN_SET(cmd);
  TFT_SWAP
}

void Tft::SendData( uint8_t data )
{
  TFT_DATA_MODE
  TFT_DATAPIN_SET(data);
  TFT_SWAP
}

void Tft::SetWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
  SendCmd(0x2A);
  SendData(x0>>8);
  SendData(x0&0xFF);
  SendData(x1>>8);
  SendData(x1&0xFF);

  SendCmd(0x2B);
  SendData(y0>>8);
  SendData(y0);
  SendData(y1>>8);
  SendData(y1);
}

void Tft::FillBlack()
{
  SetWindow(0, 0, TFT_WIDTH-1, TFT_HEIGHT-1);
  SendCmd(0x2c);
  TFT_DATA_MODE
  TFT_DATAPIN_SET(0);
  for ( uint16_t n = 0; n < (TFT_WIDTH/4)*TFT_HEIGHT; ++n )
  {
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
      TFT_SWAP_DATA_WR
  }
}

void Tft::FillPalette( uint8_t pal )
{
  SetWindow(0, 0, TFT_WIDTH-1, TFT_HEIGHT-1);
  SendCmd(0x2c);
  TFT_DATA_MODE
  uint8_t hi = s_palette[pal] >> 8;
  uint8_t lo = s_palette[pal];
  for ( uint16_t w = 0; w < TFT_WIDTH; ++w )
  {
    for ( uint16_t h = 0; h < TFT_HEIGHT; ++h )
    {
      TFT_DATAPIN_SET(hi);
      TFT_SWAP_DATA_WR
      TFT_DATAPIN_SET(lo);
      TFT_SWAP_DATA_WR
    }
  }
}

void Tft::Durio_FullDrawScreen()
{
  for ( uint16_t block_y = 0; block_y < TFT_HEIGHT/16; ++block_y )
  {
    for ( uint16_t block_x = 0; block_x < TFT_WIDTH/16; ++block_x )
    {
      SetWindow(block_x*16, block_y*16, block_x*16+15, block_y*16+15);
      SendCmd(0x2c);
      TFT_DATA_MODE
      uint8_t block = s_get_level_block(block_x, block_y);
      if (block == Block_Empty)
      {
        uint8_t hi = s_palette[s_game_palette[0]] >> 8;
        uint8_t lo = s_palette[s_game_palette[0]];
        for (uint16_t n = 0; n < 16*16; ++n)
        {
          TFT_DATAPIN_SET(hi);
          TFT_SWAP_DATA_WR
          TFT_DATAPIN_SET(lo);
          TFT_SWAP_DATA_WR
        }
      } else
      {
        uint8_t block_palette = pgm_read_byte_near(s_block_pal + block);
        uint8_t chr0 = pgm_read_byte_near(s_block_chr + ((uint16_t)block) * 4 + 0);
        uint8_t chr1 = pgm_read_byte_near(s_block_chr + ((uint16_t)block) * 4 + 2);
        uint8_t chr2 = pgm_read_byte_near(s_block_chr + ((uint16_t)block) * 4 + 1);
        uint8_t chr3 = pgm_read_byte_near(s_block_chr + ((uint16_t)block) * 4 + 3);
        uint8_t color_offset = block_palette*4;
        for (uint8_t y = 0; y < 8; ++y)
        {
          uint8_t b0 = pgm_read_byte_near(s_progmem_charset + 4096 + ((uint16_t)chr0 * 16) + y);
          uint8_t b1 = pgm_read_byte_near(s_progmem_charset + 4096 + ((uint16_t)chr0 * 16) + y + 8);
          for (uint8_t x = 0; x < 8; ++x)
          {
            //uint8_t color = (b0 & 1) | ((b1 & 1) << 1);
            uint8_t color = (b0 >> 7) | ((b1 >> 6) & 2);
            TFT_DATAPIN_SET(s_palette[s_game_palette[color | color_offset]] >> 8);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET(s_palette[s_game_palette[color | color_offset]]);
            TFT_SWAP_DATA_WR
            b0 <<= 1;
            b1 <<= 1;
          }

          b0 = pgm_read_byte_near(s_progmem_charset + 4096 + ((uint16_t)chr1 * 16) + y);
          b1 = pgm_read_byte_near(s_progmem_charset + 4096 + ((uint16_t)chr1 * 16) + y + 8);
          for (uint8_t x = 0; x < 8; ++x)
          {
            uint8_t color = (b0 >> 7) | ((b1 >> 6) & 2);
            TFT_DATAPIN_SET(s_palette[s_game_palette[color | color_offset]] >> 8);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET(s_palette[s_game_palette[color | color_offset]]);
            TFT_SWAP_DATA_WR
            b0 <<= 1;
            b1 <<= 1;
          }
        }  

        for (uint8_t y = 0; y < 8; ++y)
        {
          uint8_t b0 = pgm_read_byte_near(s_progmem_charset + 4096 + ((uint16_t)chr2 * 16) + y);
          uint8_t b1 = pgm_read_byte_near(s_progmem_charset + 4096 + ((uint16_t)chr2 * 16) + y + 8);
          for (uint8_t x = 0; x < 8; ++x)
          {
            uint8_t color = (b0 >> 7) | ((b1 >> 6) & 2);
            TFT_DATAPIN_SET(s_palette[s_game_palette[color | color_offset]] >> 8);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET(s_palette[s_game_palette[color | color_offset]]);
            TFT_SWAP_DATA_WR
            b0 <<= 1;
            b1 <<= 1;
          }

          b0 = pgm_read_byte_near(s_progmem_charset + 4096 + ((uint16_t)chr3 * 16) + y);
          b1 = pgm_read_byte_near(s_progmem_charset + 4096 + ((uint16_t)chr3 * 16) + y + 8);
          for (uint8_t x = 0; x < 8; ++x)
          {
            uint8_t color = (b0 >> 7) | ((b1 >> 6) & 2);
            TFT_DATAPIN_SET(s_palette[s_game_palette[color | color_offset]] >> 8);
            TFT_SWAP_DATA_WR
            TFT_DATAPIN_SET(s_palette[s_game_palette[color | color_offset]]);
            TFT_SWAP_DATA_WR
            b0 <<= 1;
            b1 <<= 1;
          }
        }
              
      }
    }
  }
}
