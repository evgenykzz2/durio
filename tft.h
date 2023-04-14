#pragma once
#include <stdint.h>

#define MODE_ROW_ORDER 0x80
#define MODE_COLUMN_ORDER 0x40
#define MODE_ROW_COLUMN_EXCHANGE 0x20
#define MODE_VERTICAL_REFRESH_ORDER 0x10
#define MODE_RGB_BGR_ORDER 0x08
#define MODE_HREFRESH_ORDER 0x04

class Tft
{
  inline static void SetDataPin( uint8_t v );

  uint16_t m_screen_scroll_prev;
  uint16_t m_screen_scroll;

public:
  Tft();
  void Init();
  void HWReset();
  void SendCmd( uint8_t cmd );
  void SendData( uint8_t data );
  void FillBlack();
  void FillPalette( uint8_t pal );
  void SetWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);
  void VerticalScrollingDefinition( uint16_t top_fixed, uint16_t v_scroll, uint16_t bot_fixed );
  void VerticalScrollingStartAddress( uint16_t address );
  void PartialArea( uint16_t area_start, uint16_t area_end );
  void PartialMode();
  void NormalMode();
  void TearingEffectLineOn();
  void TearingEffectLineOff();

  void Durio_FullDrawScreen();
  void Durio_ScrollScreenDraw();
};
