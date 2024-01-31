#ifndef UTILS_H
#define UTILS_H

#include "point.h"
#include "constants.h"

typedef enum attribute {
  BGColorBlack = 0x00,
  BGColorBlue = 0x08,
  BGColorRed = 0x10,
  BGColorMagenta = 0x18,
  BGColorGreen = 0x20,
  BGColorCyan = 0x28,
  BGColorYellow = 0x30,
  BGColorWhite = 0x38,
  FGColorBlack = 0x00,
  FGColorBlue = 0x01,
  FGColorRed = 0x02,
  FGColorMagenta = 0x03,
  FGColorGreen = 0x04,
  FGColorCyan = 0x05,
  FGColorYellow = 0x06,
  FGColorWhite = 0x07,
  Dim = 0x40,
  Flash = 0x80
} attribute_t;

void set_char_cell_attribute(const point_t p, const attribute_t attr);
void put_sprite(point_t p, const char attr, void *sprite);
void put_clear_sprite(const point_t p, const attribute_t attr);
void clear_screen();
  
#endif  /* UTILS_H */
