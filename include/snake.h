#ifndef SNAKE_H
#define SNAKE_H

#include "point.h"
#include "direction.h"

typedef struct snake_cell {
  point_t point;
  direction_t direction;
} snake_cell_t;

typedef struct snake {
  snake_cell_t body[30*20];
  snake_cell_t deleted_tail;
  int size;
  direction_t direction;  
} snake_t;

void snake_initialize(snake_t *s);
void snake_move(snake_t *s);
void snake_growth(snake_t *s);
int snake_check_collision(snake_t *s, const point_t head_point);

#define get_head(snake) (snake)->body[0]
#define get_tail(snake) (snake)->body[(snake)->size-1]

#endif  /* SNAKE_H */
