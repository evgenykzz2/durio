#pragma once

#define SPRITE_MODE_NONE   0x00
#define SPRITE_MODE_2x2    0x01
#define SPRITE_MODE_2x3    0x02

struct Sprite
{
  uint8_t mode;

	int16_t x;
	int16_t y;

  uint8_t index[6];
  uint8_t flag[6];
};

struct UpdateArea
{
  int16_t x;
  int16_t y;
  uint8_t width;
  uint8_t height;
};
