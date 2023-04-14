#pragma once
#include <stdint.h>
#include <avr/pgmspace.h>

typedef uint8_t (*GetLevelBlock)(uint16_t x, uint8_t y);

extern GetLevelBlock s_get_level_block;
extern uint8_t GetLevelBlock_1_1(uint16_t x, uint8_t y);

extern const uint8_t* s_game_palette;
extern const uint8_t s_game_palette_hills[64];

extern const uint8_t s_block_chr[128*4] PROGMEM;
extern const uint8_t s_block_pal[128] PROGMEM;


enum EBlock
{
  Block_Empty = 0x00,
  Block_Black = 0x01,
  
  Block_Bush_Left = 0x02,
  Block_Bush_Mid = 0x03,
  Block_Bush_Right = 0x04,
  
  Block_Mount_Left = 0x05,
  Block_Mount_DotLeft = 0x06,
  Block_Mount_Top = 0x07,
  Block_Mount_Right = 0x08,
  Block_Mount_DotRight = 0x09,
  Block_Mount_Mid = 0x0A,
  
  Block_c0 = 0x0B,
  Block_dd = 0x0C,
  
  Block_Tree_Top = 0x0D,
  Block_Tree_Circle = 0x0E,
  Block_Tree_Bottom = 0x0F,
  
  Block_Pipe_TopLeft = 0x10,
  Block_Pipe_TopRight = 0x11,
  Block_Pipe_TopLeft_Enter = 0x12,
  Block_Pipe_TopRight_Enter = 0x13,
  Block_Pipe_Left = 0x14,
  Block_Pipe_Right = 0x15,
  
  Block_Island_Left = 0x16,
  Block_Island_Mid  = 0x17,
  Block_Island_Right = 0x18,
  
  Block_Mushroom_Left = 0x19,
  Block_Mushroom_Mid = 0x1A,
  Block_Mushroom_Right = 0x1B,
  
  Block_Pipe_28 = 0x1C,
  Block_Pipe_29 = 0x1D,
  Block_Pipe_30 = 0x1E,
  Block_Pipe_31 = 0x1F,
  Block_Pipe_32 = 0x20,
  Block_Pipe_33 = 0x21,
  
  Block_WaterPlant = 0x22,
  
  Block_HiddenLive = 0x23,
  
  Block_PoleTop = 0x24,
  Block_PoleTube = 0x25,
  Block_HiddenBeat = 0x26,
  
  Block_Rope_Vertical = 0x27,
  Block_Rope_Horizontal = 0x28,
  Block_Rope_Center = 0x29,
  
  Block_CastleTopA = 0x2C,
  Block_CastleWindowA = 0x2D,
  Block_CastleBrick = 0x2E,
  Block_CastleWindowB = 0x2F,
  Block_CastleTopB = 0x30,
  
  Block_CastleArc = 0x31,
  
  Block_Soil = 0x33,
  Block_Fence = 0x34,
  Block_Trunk = 0x35,
  
  Block_Brick_A = 0x38,   //Common brick
  Block_Brick_B = 0x39,   //Solid brick
  Block_Brick_C = 0x3A,
  Block_Ground  = 0x3B,
  
  Block_Brick_Coin10 = 0x3C,
  Block_Brick_Star = 0x3D,
  Block_BrickT_3E = 0x3E,
  Block_BrickT_3F = 0x3F,
  
  Block_BrickT_40 = 0x40,
  Block_Brick_41 = 0x41,
  Block_Brick_42 = 0x42,
  Block_Brick_43 = 0x43,
  Block_Brick_44 = 0x44,
  Block_Brick_45 = 0x45,
  
  Block_Hidden_46 = 0x46,
  Block_Hidden_47 = 0x47,
  
  Block_Cell  = 0x48,
  Block_BossBrick = 0x49,
  Block_Bridge = 0x4A,
  Block_CannonTop = 0x4B,
  Block_CannonBot = 0x4C,
  Block_CastleWindow = 0x4D,
  
  Block_Hidden_4E = 0x4E,
  Block_Brick_Half = 0x4F,
  Block_WaterBlock = 0x50,
  Block_Brick_Half_51 = 0x51,
  Block_PipeWaterTop = 0x52,
  Block_PipeWaterBottom = 0x53,
  
  Block_Cloud_TopLeft  = 0x55,
  Block_Cloud_TopMid   = 0x56,
  Block_Cloud_TopRight = 0x57,
  Block_Cloud_BotLeft  = 0x58,
  Block_Cloud_BotMid   = 0x59,
  Block_Cloud_BotRight = 0x5A,
  
  Block_Water_Top = 0x5B,
  Block_Water_Fill = 0x5C,
  
  Block_CloudBrick = 0x5D,
  Block_BossBridge = 0x5E,
  
  Block_Question_Coint = 0x5F,
  Block_Question_Mushroom = 0x60,
  
  Block_Coin_1 = 0x61,
  Block_Coin_2 = 0x62,
  
  Block_BeatEmpty = 0x63,
  Block_Hummer = 0x64,
};
