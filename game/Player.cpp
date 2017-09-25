#pragma GCC optimize ("-O3")

#ifndef EMULATED
#include "libgame.h"
#include "font.h"
#include "graphics.h"
#include "controls.h"
#include "music.h"
#include "menu.h"

#define PREV BITMASK(BUTTON_NE) | BITMASK(BUTTON_LEFT)
#define NEXT BITMASK(BUTTON_SE) | BITMASK(BUTTON_RIGHT)

struct PlayerData
{
};
static PlayerData* data;

static const uint8_t red_dawn[] PROGMEM = {
0x46, 0x58, 0x53, 0x4d, 0x0f, 0xcd, 0x15, 0xcd, 0x66, 0xd0, 0xca, 0xd0, 0x82, 0x02, 0x86, 0x5b, 
0xce, 0x87, 0x61, 0xce, 0x50, 0x80, 0x50, 0x80, 0x81, 0xf4, 0xcf, 0x81, 0xf4, 0xcf, 0x81, 0xa8, 
0xcf, 0x81, 0xa8, 0xcf, 0x81, 0x3b, 0xcf, 0x81, 0x3b, 0xcf, 0x81, 0xe6, 0xce, 0x81, 0xe6, 0xce, 
0x81, 0x65, 0xce, 0x81, 0x65, 0xce, 0x83, 0x86, 0x5b, 0xce, 0x87, 0x61, 0xce, 0x50, 0x80, 0x50, 
0x70, 0x81, 0x60, 0xcd, 0x86, 0x58, 0xcd, 0x81, 0x66, 0xcd, 0x00, 0x10, 0x80, 0x15, 0xcd, 0x82, 
0x0c, 0x00, 0xf4, 0x00, 0x80, 0x58, 0xcd, 0x86, 0x55, 0xd0, 0x87, 0x5e, 0xd0, 0x2f, 0x10, 0x34, 
0x18, 0x33, 0x08, 0x36, 0x08, 0x34, 0x08, 0x2f, 0x08, 0x2c, 0x08, 0x31, 0x20, 0x2d, 0x18, 0x31, 
0x08, 0x36, 0x18, 0x34, 0x08, 0x33, 0x08, 0x31, 0x08, 0x2f, 0x08, 0x2d, 0x08, 0x2c, 0x30, 0x2f, 
0x10, 0x34, 0x18, 0x33, 0x08, 0x36, 0x08, 0x34, 0x08, 0x2f, 0x08, 0x2c, 0x08, 0x31, 0x20, 0x2d, 
0x08, 0x31, 0x08, 0x36, 0x08, 0x34, 0x08, 0x33, 0x10, 0x36, 0x10, 0x39, 0x10, 0x33, 0x10, 0x34, 
0x30, 0x38, 0x08, 0x36, 0x08, 0x33, 0x18, 0x33, 0x08, 0x31, 0x08, 0x33, 0x08, 0x34, 0x08, 0x31, 
0x08, 0x33, 0x20, 0x2f, 0x08, 0x2f, 0x08, 0x2e, 0x08, 0x2f, 0x08, 0x31, 0x18, 0x31, 0x08, 0x36, 
0x10, 0x34, 0x10, 0x33, 0x30, 0x36, 0x10, 0x36, 0x18, 0x33, 0x08, 0x2f, 0x08, 0x2f, 0x08, 0x2e, 
0x08, 0x2f, 0x08, 0x38, 0x20, 0x34, 0x08, 0x31, 0x08, 0x33, 0x08, 0x34, 0x08, 0x33, 0x10, 0x36, 
0x10, 0x34, 0x10, 0x31, 0x10, 0x2f, 0x30, 0x38, 0x08, 0x36, 0x08, 0x34, 0x20, 0x2f, 0x18, 0x2c, 
0x08, 0x31, 0x20, 0x2d, 0x10, 0x36, 0x08, 0x34, 0x08, 0x33, 0x20, 0x31, 0x10, 0x2f, 0x10, 0x2f, 
0x30, 0x2f, 0x10, 0x38, 0x20, 0x36, 0x10, 0x2f, 0x08, 0x2f, 0x08, 0x34, 0x20, 0x33, 0x18, 0x33, 
0x08, 0x31, 0x18, 0x30, 0x08, 0x31, 0x10, 0x36, 0x10, 0x36, 0x30, 0x38, 0x08, 0x36, 0x08, 0x34, 
0x20, 0x2f, 0x18, 0x2c, 0x08, 0x31, 0x20, 0x2d, 0x10, 0x36, 0x08, 0x34, 0x08, 0x33, 0x20, 0x31, 
0x10, 0x2f, 0x10, 0x38, 0x30, 0x38, 0x10, 0x3b, 0x20, 0x39, 0x10, 0x38, 0x08, 0x38, 0x08, 0x36, 
0x18, 0x38, 0x08, 0x39, 0x18, 0x39, 0x08, 0x38, 0x18, 0x38, 0x08, 0x36, 0x18, 0x36, 0x08, 0x34, 
0x30, 0x89, 0x82, 0x03, 0xfc, 0x80, 0x5b, 0xce, 0x0d, 0xde, 0x0d, 0xde, 0x86, 0xee, 0xcf, 0x87, 
0xe7, 0xcf, 0x3d, 0x08, 0x3e, 0x08, 0x3f, 0x08, 0x40, 0x08, 0x42, 0x08, 0x40, 0x08, 0x3e, 0x08, 
0x3d, 0x08, 0x3b, 0x08, 0x3d, 0x08, 0x3e, 0x08, 0x3d, 0x08, 0x40, 0x08, 0x3e, 0x08, 0x3d, 0x08, 
0x3b, 0x08, 0x3d, 0x08, 0x3e, 0x08, 0x3f, 0x08, 0x40, 0x08, 0x42, 0x08, 0x40, 0x08, 0x3e, 0x08, 
0x3d, 0x08, 0x3b, 0x08, 0x3d, 0x08, 0x3e, 0x08, 0x3d, 0x08, 0x40, 0x08, 0x3e, 0x08, 0x3d, 0x08, 
0x3b, 0x08, 0x36, 0x08, 0x38, 0x08, 0x39, 0x08, 0x38, 0x08, 0x3b, 0x08, 0x39, 0x08, 0x38, 0x08, 
0x36, 0x08, 0x38, 0x08, 0x39, 0x08, 0x3a, 0x08, 0x3b, 0x08, 0x3d, 0x08, 0x3b, 0x08, 0x39, 0x08, 
0x38, 0x08, 0x36, 0x08, 0x38, 0x08, 0x39, 0x08, 0x38, 0x08, 0x3b, 0x08, 0x39, 0x08, 0x38, 0x08, 
0x36, 0x08, 0x38, 0x08, 0x39, 0x08, 0x3b, 0x08, 0x38, 0x08, 0x34, 0x20, 0x89, 0x39, 0x17, 0x3b, 
0x08, 0x3d, 0x08, 0x3d, 0x08, 0x3b, 0x08, 0x39, 0x08, 0x38, 0x10, 0x39, 0x10, 0x3b, 0x10, 0x34, 
0x18, 0x39, 0x10, 0x3b, 0x08, 0x3d, 0x08, 0x3d, 0x08, 0x3b, 0x08, 0x39, 0x08, 0x38, 0x10, 0x39, 
0x10, 0x3b, 0x10, 0x34, 0x18, 0x36, 0x10, 0x38, 0x08, 0x39, 0x08, 0x39, 0x08, 0x38, 0x08, 0x36, 
0x08, 0x34, 0x10, 0x38, 0x10, 0x3b, 0x10, 0x39, 0x08, 0x38, 0x10, 0x36, 0x10, 0x38, 0x08, 0x39, 
0x08, 0x39, 0x08, 0x38, 0x08, 0x36, 0x08, 0x34, 0x10, 0x38, 0x10, 0x3b, 0x10, 0x39, 0x08, 0x38, 
0x09, 0x89, 0x86, 0x55, 0xd0, 0x87, 0x5e, 0xd0, 0x00, 0x07, 0x38, 0x10, 0x36, 0x08, 0x34, 0x10, 
0x34, 0x10, 0x34, 0x04, 0x36, 0x04, 0x34, 0x04, 0x33, 0x04, 0x34, 0x08, 0x36, 0x08, 0x38, 0x10, 
0x38, 0x10, 0x00, 0x08, 0x3b, 0x10, 0x39, 0x08, 0x38, 0x10, 0x38, 0x10, 0x38, 0x04, 0x39, 0x04, 
0x38, 0x04, 0x36, 0x04, 0x38, 0x08, 0x39, 0x08, 0x3b, 0x10, 0x3b, 0x10, 0x00, 0x08, 0x39, 0x10, 
0x39, 0x08, 0x39, 0x10, 0x3d, 0x08, 0x3b, 0x04, 0x39, 0x04, 0x38, 0x10, 0x38, 0x10, 0x38, 0x10, 
0x34, 0x10, 0x00, 0x08, 0x33, 0x10, 0x33, 0x08, 0x33, 0x10, 0x36, 0x08, 0x34, 0x04, 0x33, 0x04, 
0x34, 0x08, 0x31, 0x08, 0x31, 0x04, 0x33, 0x04, 0x31, 0x04, 0x30, 0x04, 0x31, 0x21, 0x89, 0x86, 
0xee, 0xcf, 0x87, 0xe7, 0xcf, 0x36, 0x10, 0x33, 0x08, 0x34, 0x08, 0x36, 0x10, 0x33, 0x08, 0x34, 
0x08, 0x36, 0x04, 0x38, 0x04, 0x36, 0x04, 0x34, 0x04, 0x33, 0x08, 0x34, 0x08, 0x31, 0x10, 0x39, 
0x08, 0x38, 0x08, 0x36, 0x10, 0x33, 0x08, 0x34, 0x08, 0x36, 0x10, 0x33, 0x08, 0x34, 0x08, 0x38, 
0x04, 0x39, 0x04, 0x38, 0x04, 0x36, 0x04, 0x38, 0x08, 0x3c, 0x08, 0x3d, 0x20, 0x89, 0x0e, 0x01, 
0x3f, 0x3e, 0x3d, 0x0a, 0x00, 0x82, 0x0c, 0xf4, 0x80, 0xee, 0xcf, 0x86, 0x55, 0xd0, 0x87, 0x5e, 
0xd0, 0x31, 0x17, 0x33, 0x08, 0x34, 0x18, 0x31, 0x04, 0x33, 0x04, 0x34, 0x08, 0x34, 0x08, 0x33, 
0x08, 0x31, 0x08, 0x33, 0x10, 0x2c, 0x10, 0x00, 0x08, 0x33, 0x10, 0x34, 0x08, 0x36, 0x18, 0x33, 
0x04, 0x34, 0x04, 0x36, 0x08, 0x36, 0x08, 0x34, 0x08, 0x33, 0x08, 0x31, 0x20, 0x38, 0x10, 0x3d, 
0x10, 0x3b, 0x08, 0x3d, 0x10, 0x3b, 0x08, 0x39, 0x08, 0x39, 0x08, 0x38, 0x08, 0x36, 0x08, 0x38, 
0x10, 0x31, 0x10, 0x00, 0x08, 0x39, 0x10, 0x36, 0x08, 0x38, 0x18, 0x33, 0x04, 0x34, 0x04, 0x36, 
0x08, 0x36, 0x08, 0x34, 0x08, 0x33, 0x08, 0x31, 0x10, 0x00, 0x11, 0x89, 0xfe, 0xfe, 0x02, 0x02, 
0x03, 0xfd, 0x80, 0x55, 0xd0, 0x00, 0x01, 0x0f, 0x01, 0x40, 0x3f, 0x0c, 0x00, 0x87, 0x7d, 0xd0, 
0x86, 0x8c, 0xd0, 0x28, 0x10, 0x84, 0x0d, 0x81, 0xa8, 0xd0, 0x25, 0x10, 0x84, 0x07, 0x81, 0xa8, 
0xd0, 0x80, 0x66, 0xd0, 0x0f, 0x03, 0x0e, 0x02, 0x0d, 0x02, 0x0c, 0x02, 0x3d, 0x3c, 0x3b, 0x3a, 
0x39, 0x00, 0x00, 0x1d, 0x80, 0x8c, 0xd0, 0x85, 0x01, 0x8a, 0x87, 0xbc, 0xd0, 0x82, 0x04, 0x84, 
0x1a, 0x07, 0x01, 0x84, 0x00, 0x07, 0x01, 0x83, 0x8b, 0x85, 0x08, 0x87, 0x5e, 0xd0, 0x89, 0x85, 
0x01, 0x8a, 0x87, 0xbc, 0xd0, 0x82, 0x10, 0x39, 0x01, 0x8d, 0x10, 0x83, 0x8b, 0x85, 0x08, 0x87, 
0x7d, 0xd0, 0x89, 0x0f, 0x01, 0x40, 0x3f, 0x3e, 0x3d, 0x3c, 0x3b, 0x3a, 0x39, 0x38, 0x37, 0x00, 
0x00, 0x82, 0x02, 0x86, 0x7a, 0xd1, 0x87, 0x6f, 0xd1, 0x0d, 0x00, 0x81, 0x5c, 0xd1, 0x81, 0x5c, 
0xd1, 0x82, 0x04, 0x14, 0x60, 0x0d, 0x20, 0x83, 0x81, 0x4f, 0xd1, 0x81, 0x4f, 0xd1, 0x82, 0x04, 
0x81, 0x3e, 0xd1, 0x83, 0x83, 0x10, 0x00, 0x81, 0xf9, 0xd0, 0x81, 0xf9, 0xd0, 0x80, 0xca, 0xd0, 
0x10, 0x40, 0x15, 0x40, 0x17, 0x40, 0x10, 0x80, 0x15, 0x40, 0x17, 0x40, 0x10, 0x40, 0x17, 0x20, 
0x12, 0x20, 0x17, 0x40, 0x12, 0x40, 0x0f, 0x40, 0x17, 0x40, 0x10, 0x40, 0x17, 0x20, 0x12, 0x20, 
0x17, 0x40, 0x10, 0x40, 0x15, 0x40, 0x17, 0x40, 0x10, 0x60, 0x17, 0x20, 0x0d, 0x20, 0x14, 0x20, 
0x15, 0x40, 0x17, 0x40, 0x10, 0x40, 0x15, 0x40, 0x17, 0x40, 0x10, 0x80, 0x12, 0x40, 0x10, 0x20, 
0x17, 0x20, 0x10, 0x40, 0x89, 0x15, 0x40, 0x10, 0x40, 0x15, 0x40, 0x10, 0x40, 0x17, 0x40, 0x10, 
0x40, 0x17, 0x40, 0x10, 0x40, 0x89, 0x0d, 0x80, 0x10, 0x80, 0x12, 0x40, 0x0d, 0x40, 0x14, 0x40, 
0x0d, 0x40, 0x89, 0x0d, 0x60, 0x14, 0x80, 0x0d, 0x60, 0x12, 0x20, 0x0d, 0x20, 0x12, 0x20, 0x0d, 
0x20, 0x14, 0x20, 0x0d, 0x20, 0x89, 0x0f, 0x02, 0x0e, 0x02, 0x3f, 0x3e, 0x0b, 0x02, 0x80, 0x6f, 
0xd1, 0x09, 0x04, 0xfc, 0xf7, 0xf7, 0xfc, 0x04, 0x82, 0x0c, 0x83, 0x04, 0x02, 0xfe, 0xfc, 0xfc, 
0xfe, 0x02, 0x82, 0xfb, 0x83, 0x06, 0x03, 0xfd, 0xfa, 0xfa, 0xfd, 0x03, 0x82, 0x05, 0x83, 0x04, 
0x02, 0xfe, 0xfc, 0xfc, 0xfe, 0x02, 0x82, 0xf4, 0x83, 0x80, 0x7a, 0xd1, };

static const MenuItem tunes[] = {
  {"Red dawn", red_dawn},
  {NULL, NULL}
};

void Player_prepare()
{
  game_set_ups(50);
  menu_setup(tunes);
}

static void Player_render()
{
  menu_render();
}

static void Player_update(unsigned long delta)
{
  void *p = menu_update(delta);
  if (p)
  {
    fxm_init(p);
  }
  fxm_loop();
}

game_instance Player = {
    "Player",
    Player_prepare,
    Player_render,
    Player_update,
    sizeof(PlayerData),
    (void**)(&data)
};
#endif

