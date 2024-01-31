#include "point.h"

void point_move_by_direction(point_t *p, direction_t dir) {
  switch(dir) {
    case Left:
      --p->x; 
      break;
    case Right: 
      ++p->x; 
      break;
    case Up:
      --p->y; 
      break;
    case Down:
      ++p->y; 
      break;
  }
}
