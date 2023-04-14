#include "game_data.h"
GetLevelBlock s_get_level_block = 0;

const uint8_t g_level_lines_1x1[16*33] PROGMEM =
{
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59, 59, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 95, 0, 0, 0, 59, 59, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 56, 0, 0, 0, 59, 59, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 96, 0, 0, 0, 59, 59, 0, 
  0, 0, 0, 0, 0, 95, 0, 0, 0, 56, 0, 0, 0, 59, 59, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 20, 59, 59, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17, 21, 59, 59, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 20, 20, 59, 59, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17, 21, 21, 59, 59, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 20, 20, 20, 59, 59, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 17, 21, 21, 21, 59, 59, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 20, 20, 20, 59, 59, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 19, 21, 21, 21, 59, 59, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 35, 0, 0, 0, 0, 59, 59, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 56, 0, 0, 0, 0, 0, 0, 0, 59, 59, 0, 
  0, 0, 0, 0, 0, 56, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 95, 0, 0, 0, 60, 0, 0, 0, 59, 59, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 61, 0, 0, 0, 59, 59, 0, 
  0, 0, 0, 0, 0, 96, 0, 0, 0, 95, 0, 0, 0, 59, 59, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 72, 59, 59, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 72, 72, 59, 59, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 72, 72, 72, 59, 59, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 72, 72, 72, 72, 59, 59, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 72, 72, 72, 72, 72, 59, 59, 0, 
  0, 0, 0, 0, 0, 0, 0, 72, 72, 72, 72, 72, 72, 59, 59, 0, 
  0, 0, 0, 0, 0, 0, 72, 72, 72, 72, 72, 72, 72, 59, 59, 0, 
  0, 0, 0, 0, 0, 72, 72, 72, 72, 72, 72, 72, 72, 59, 59, 0, 
  0, 0, 36, 37, 37, 37, 37, 37, 37, 37, 37, 37, 72, 59, 59, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44, 46, 46, 59, 59, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 44, 45, 48, 46, 46, 59, 59, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 44, 46, 48, 49, 1, 59, 59, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 44, 47, 48, 46, 46, 59, 59, 0
};

const uint8_t g_level_1x1[16*13] PROGMEM =
{
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 3, 4, 1, 2, 0, 0, 0, 5, 6, 0, 0, 0, 0, 0, 0, 0, 0, 7, 8, 0, 0, 0, 0, 0, 0, 9, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 12, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 14, 14, 0, 0, 0, 0, 0, 0, 2, 3, 2, 15, 15, 15, 15, 15, 15, 16, 16, 14, 0, 0, 15, 15, 15, 17, 0, 0, 0, 0, 0, 2, 18, 0, 0, 0, 0, 1, 0, 0, 19, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, 15, 15, 15, 0, 0, 0, 0, 15, 4, 4, 15, 0, 0, 20, 21, 22, 23, 0, 0, 23, 22, 21, 20, 0, 0, 0, 0, 20, 21, 22, 23, 23, 14, 14, 23, 22, 21, 20, 0, 0, 0, 0, 5, 6, 0, 0, 0, 2, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 5, 6, 20, 21, 22, 23, 24, 25, 26, 27, 27, 0, 0, 0, 0, 0, 0, 0, 0, 28, 0, 0, 0, 29, 30, 31, 32, 29, 0
};

uint8_t GetBackGroundBlock(uint16_t x, uint8_t y)
{
  if ( y < 3 || y >= 13 )
    return 0;
  uint8_t xi = x%48;
  if ( y == 3 )
  {
    switch( xi )
    {
      case 19:
      case 36:
        return 0x55;
      case 20:
      case 37:
      case 38:
        return 0x56;
      case 21:
      case 39:
        return 0x57;
    }
    return 0;
  } else if ( y == 4 )
  {
    switch( xi )
    {
      case 8:
      case 27:
        return 0x55;
      case 9:
      case 28:
      case 29:
      case 30:
        return 0x56;
      case 10:
      case 31:
        return 0x57;
      case 19:
      case 36:
        return 0x58;
      case 20:
      case 37:
      case 38:
        return 0x59;
      case 21:
      case 39:
        return 0x5A;
    }
    return 0;
  } else if ( y == 5 )
  {
    switch( xi )
    {
      case 8:
      case 27:
        return 0x58;
      case 9:
      case 28:
      case 29:
      case 30:
        return 0x59;
      case 10:
      case 31:
        return 0x5A;
    }
    return 0;
  } else if ( y == 10 )
  {
    if (xi == 2)
      return 7;
    else
      return 0;
  } else if ( y == 11 )
  {
    switch(xi)
    {
      case 1:
        return 0x05;
      case 2:
        return 0x09;
      case 3:
        return 0x08;
      case 17:
        return 0x07;
    }
    return 0;
  } else if ( y == 12 )
  {
    static const uint8_t data[24] = {0x59,0xA9,0x80,0x00,0x00,0x02,0x33,0x34,   0x59,0x80,0x00,0x02,0x34,0x00,0x00,0x00,  0x00,0x00,0x00,0x00,0x02,0x34,0x00,0x00};
    if ( (xi&1) == 0 )
      return (data[xi>>1] >> 4);
    else
      return (data[xi>>1] & 0xF);
  } else
    return 0;
}

uint8_t GetLevelBlock_1_1(uint16_t x, uint8_t y)
{
  uint8_t line = x >= 16*13 ? 0 : pgm_read_byte_near(g_level_1x1+x);
  uint8_t block = pgm_read_byte_near( g_level_lines_1x1 + (((uint16_t)line << 4) | y) );
  if (block == 0)
    return GetBackGroundBlock(x, y);
  else
    return block;
}

const uint8_t* s_game_palette;
const uint8_t s_game_palette_hills[64] =
{
  0x22, 0x29, 0x1A, 0x0F,   0x22, 0x36, 0x17, 0x0F,   0x22, 0x30, 0x21, 0x0F,   0x22, 0x27, 0x17, 0x0F,
  0x22, 0x16, 0x27, 0x18,   0x0F, 0x1A, 0x30, 0x27,   0x0F, 0x16, 0x30, 0x27,   0x0F, 0x0F, 0x36, 0x17,
  0x22, 0x30, 0x27, 0x19,   0x22, 0x30, 0x27, 0x12,   0x22, 0x30, 0x27, 0x0D,   0x22, 0x37, 0x26, 0x16,
  0x22, 0x37, 0x26, 0x19,   0x22, 0x37, 0x26, 0x12,   0x22, 0x37, 0x26, 0x0D,   0x22, 0x37, 0x26, 0x0D
};

const uint8_t s_block_chr[128*4] PROGMEM =
{
    0x24, 0x24, 0x24, 0x24,   0x27, 0x27, 0x27, 0x27,   0x24, 0x24, 0x24, 0x35,   0x36, 0x25, 0x37, 0x25,   //00
    0x24, 0x38, 0x24, 0x24,   0x24, 0x30, 0x30, 0x26,   0x26, 0x26, 0x34, 0x26,   0x24, 0x31, 0x24, 0x32,   //04
    0x33, 0x26, 0x24, 0x33,   0x34, 0x26, 0x26, 0x26,   0x26, 0x26, 0x26, 0x26,   0x24, 0xC0, 0x24, 0xC0,   //08
    0x24, 0x7F, 0x7F, 0x24,   0xB8, 0xBA, 0xB9, 0xBB,   0xB8, 0xBC, 0xB9, 0xBD,   0xBA, 0xBC, 0xBB, 0xBD,   //0C
    0x60, 0x64, 0x61, 0x65,   0x62, 0x66, 0x63, 0x67,   0x60, 0x64, 0x61, 0x65,   0x62, 0x66, 0x63, 0x67,   //10
    0x68, 0x68, 0x69, 0x69,   0x26, 0x26, 0x6A, 0x6A,   0x4B, 0x4C, 0x4D, 0x4E,   0x4D, 0x4F, 0x4D, 0x4F,   //14
    0x4D, 0x4E, 0x50, 0x51,   0x6B, 0x70, 0x2C, 0x2D,   0x6C, 0x71, 0x6D, 0x72,   0x6E, 0x73, 0x6F, 0x74,   //18
    0x86, 0x8A, 0x87, 0x8B,   0x88, 0x8C, 0x88, 0x8C,   0x89, 0x8D, 0x69, 0x69,   0x8E, 0x91, 0x8F, 0x92,   //1C
    0x26, 0x93, 0x26, 0x93,   0x90, 0x94, 0x69, 0x69,   0xA4, 0xE9, 0xEA, 0xEB,   0x24, 0x24, 0x24, 0x24,   //20
    0x24, 0x2F, 0x24, 0x3D,   0xA2, 0xA2, 0xA3, 0xA3,   0x24, 0x24, 0x24, 0x24,   0xA2, 0xA2, 0xA3, 0xA3,   //24
    0x99, 0x24, 0x99, 0x24,   0x24, 0xA2, 0x3E, 0x3F,   0x5B, 0x5C, 0x24, 0xA3,   0x24, 0x24, 0x24, 0x24,   //28
    0x9D, 0x47, 0x9E, 0x47,   0x47, 0x47, 0x27, 0x27,   0x47, 0x47, 0x47, 0x47,   0x27, 0x27, 0x47, 0x47,   //2C
    0xA9, 0x47, 0xAA, 0x47,   0x9B, 0x27, 0x9C, 0x27,   0x27, 0x27, 0x27, 0x27,   0x52, 0x52, 0x52, 0x52,   //30
    0x80, 0xA0, 0x81, 0xA1,   0xBE, 0xBE, 0xBF, 0xBF,   0x75, 0xBA, 0x76, 0xBB,   0xBA, 0xBA, 0xBB, 0xBB,   //34
    0x45, 0x47, 0x45, 0x47,   0x47, 0x47, 0x47, 0x47,   0x45, 0x47, 0x45, 0x47,   0xB4, 0xB6, 0xB5, 0xB7,   //38
    0x45, 0x47, 0x45, 0x47,   0x45, 0x47, 0x45, 0x47,   0x45, 0x47, 0x45, 0x47,   0x45, 0x47, 0x45, 0x47,   //3C
    0x45, 0x47, 0x45, 0x47,   0x47, 0x47, 0x47, 0x47,   0x47, 0x47, 0x47, 0x47,   0x47, 0x47, 0x47, 0x47,   //40
    0x47, 0x47, 0x47, 0x47,   0x47, 0x47, 0x47, 0x47,   0x24, 0x24, 0x24, 0x24,   0x24, 0x24, 0x24, 0x24,   //44
    0xAB, 0xAC, 0xAD, 0xAE,   0x5D, 0x5E, 0x5D, 0x5E,   0xC1, 0x24, 0xC1, 0x24,   0xC6, 0xC8, 0xC7, 0xC9,   //48
    0xCA, 0xCC, 0xCB, 0xCD,   0x2A, 0x2A, 0x40, 0x40,   0x24, 0x24, 0x24, 0x24,   0x24, 0x47, 0x24, 0x47,   //4C
    0x82, 0x83, 0x84, 0x85,   0x24, 0x47, 0x24, 0x47,   0x86, 0x8A, 0x87, 0x8B,   0x8E, 0x91, 0x8F, 0x92,   //50
    0x24, 0x2F, 0x24, 0x3D,   0x24, 0x24, 0x24, 0x35,   0x36, 0x25, 0x37, 0x25,   0x24, 0x38, 0x24, 0x24,   //54
    0x24, 0x24, 0x39, 0x24,   0x3A, 0x24, 0x3B, 0x24,   0x3C, 0x24, 0x24, 0x24,   0x41, 0x26, 0x41, 0x26,   //58
    0x26, 0x26, 0x26, 0x26,   0xB0, 0xB1, 0xB2, 0xB3,   0x77, 0x79, 0x77, 0x79,   0x53, 0x55, 0x54, 0x56,   //5C
    0x53, 0x55, 0x54, 0x56,   0xA5, 0xA7, 0xA6, 0xA8,   0xC2, 0xC4, 0xC3, 0xC5,   0x57, 0x59, 0x58, 0x5A,   //60
    0x7B, 0x7D, 0x7C, 0x7E,   0x3F, 0x00, 0x20, 0x0F,   0x15, 0x12, 0x25, 0x0F,   0x3A, 0x1A, 0x0F, 0x0F,   //64
    0x30, 0x12, 0x0F, 0x0F,   0x27, 0x12, 0x0F, 0x22,   0x16, 0x27, 0x18, 0x0F,   0x10, 0x30, 0x27, 0x0F,   //68
    0x16, 0x30, 0x27, 0x0F,   0x0F, 0x30, 0x10, 0x00,   0x3F, 0x00, 0x20, 0x0F,   0x29, 0x1A, 0x0F, 0x0F,   //6C
    0x36, 0x17, 0x0F, 0x0F,   0x30, 0x21, 0x0F, 0x0F,   0x27, 0x17, 0x0F, 0x0F,   0x16, 0x27, 0x18, 0x0F,   //70
    0x1A, 0x30, 0x27, 0x0F,   0x16, 0x30, 0x27, 0x0F,   0x0F, 0x36, 0x17, 0x00,   0x3F, 0x00, 0x20, 0x0F,   //74
    0x29, 0x1A, 0x09, 0x0F,   0x3C, 0x1C, 0x0F, 0x0F,   0x30, 0x21, 0x1C, 0x0F,   0x27, 0x17, 0x1C, 0x0F,   //78
    0x16, 0x27, 0x18, 0x0F,   0x1C, 0x36, 0x17, 0x0F,   0x16, 0x30, 0x27, 0x0F,   0x0C, 0x3C, 0x1C, 0x00    //7C
};

const uint8_t s_block_pal[128] PROGMEM =
{
    0, 0, 0, 0, //00
    0, 0, 0, 0, //04
    0, 0, 0, 0, //08
    0, 0, 0, 0, //0C
    0, 0, 0, 0, //10
    0, 0, 0, 0, //14
    0, 0, 0, 0, //18
    0, 0, 0, 0, //1C
    0, 0, 0, 0, //20
    0, 0, 0, 0, //24
    0, 0, 0, 0, //28
    1, 1, 1, 1, //2C
    1, 1, 0, 1, //30
    0, 0, 0, 0, //34
    1, 1, 1, 1, //38
    1, 1, 1, 1, //3C
    1, 1, 1, 1, //40
    1, 1, 0, 0, //44
    1, 0, 1, 1, //48
    1, 1, 0, 1, //4C
    2, 1, 0, 0, //50
    0, 2, 2, 2, //54
    2, 2, 2, 0, //58
    0, 0, 0, 3, //5C
    3, 3, 3, 1, //60
    0, 0, 0, 0, //64
    0, 0, 0, 0, //68
    0, 0, 0, 0, //6C
    0, 0, 0, 0, //70
    0, 0, 0, 0, //74
    0, 0, 0, 0, //78
    0, 0, 0, 0, //7C
};
