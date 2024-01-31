#include "utils.h"
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>

void set_char_cell_attribute(const point_t p, const attribute_t attr) {
  *(char*)(SCR_ATTR_AREA + (p.x + SCENE_POS_X) + (p.y + SCENE_POS_Y) * SCR_CC_WIDTH) = attr;
}

void put_sprite(point_t p, const char attr, void *sprite) {
  set_char_cell_attribute(p, attr);
  putsprite(spr_or, (p.x + SCENE_POS_X) * CC_WIDTH, (p.y + SCENE_POS_Y) * CC_HEIGHT, sprite);
}

void put_clear_sprite(const point_t p, const attribute_t attr) {
  set_char_cell_attribute(p, attr);
  clga((p.x + SCENE_POS_X) * CC_WIDTH, (p.y + SCENE_POS_Y) * CC_HEIGHT, 8, 8);
}

void clear_screen() {
  clg();
  memset(SCR_ATTR_AREA, FGColorWhite, SCR_CC_WIDTH * SCR_CC_HEIGHT);
  __asm
    ld a, 0
    out (254), a
  __endasm
}
