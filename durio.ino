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
  
  g_time_millis = millis();
}

void loop()
{
  tft.Durio_ScrollScreenDraw();
  delay(33);
}
