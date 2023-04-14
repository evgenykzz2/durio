#include "tft.h"
#include "game_data.h"
Tft tft;

long long g_time_millis = 0;
uint8_t game_map[15*20];

void setup()
{
  Serial.begin(9600);
  tft.Init();

  //pinMode(A13, INPUT);
  //pinMode(A14, INPUT);
  //pinMode(A15, INPUT);

  {
    unsigned long time0 = micros();
    tft.FillBlack();
    unsigned long time1 = micros();
    Serial.print(F("Fill black: "));
    Serial.println(time1-time0);
  }

  {
    unsigned long time0 = micros();
    tft.FillPalette(0);
    unsigned long time1 = micros();
    Serial.print(F("Fill palette RAM: "));
    Serial.println(time1-time0);
  }
  //tft.TearingEffectLineOn();

  //Setup Level
  s_get_level_block = GetLevelBlock_1_1;
  s_game_palette = s_game_palette_hills;

  {
    unsigned long time0 = micros();
    tft.Durio_FullDrawScreen();
    unsigned long time1 = micros();
    Serial.print(F("FullScreen: "));
    Serial.println(time1-time0);
  }

  s_sprite[0].mode = SPRITE_MODE_2x2;
  s_sprite[0].x = 32;
  s_sprite[0].y = 16*12;
  s_sprite[0].index[0] = 0x36;
  s_sprite[0].index[1] = 0x37;
  s_sprite[0].index[2] = 0x38;
  s_sprite[0].index[3] = 0x39;

  s_sprite[0].flag[0] = 0;
  s_sprite[0].flag[1] = 0;
  s_sprite[0].flag[2] = 0;
  s_sprite[0].flag[3] = 0;
  
  g_time_millis = millis();
}

void loop()
{
  tft.Durio_ScrollScreenDraw();
  ++s_sprite[0].x;
  tft.Durio_DrawSprites();
  delay(33);
}
