#ifndef POINT_H
#define POINT_H

#include "direction.h"

typedef struct point {
  char x;
  char y;
} point_t;

void point_move_by_direction(point_t *p, direction_t dir);

#endif  /* POINT_H */
