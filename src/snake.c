#include "snake.h"

void snake_initialize(snake_t *s) {
  s->size = 3;

  for(int i = 0; i < s->size; ++i) {
    s->body[i].point.x = 15 - i;
    s->body[i].point.y = 10;
    s->body[i].direction = Right;
  }

  s->direction = Right;
}

void snake_move(snake_t *s) {
  s->deleted_tail = get_tail(s);
  
  for(int i = s->size - 1; i > 0; --i) {
    s->body[i] = s->body[i - 1];
  }
  
  point_move_by_direction(&s->body[0].point, s->direction);
  s->body[0].direction = s->direction;
}

int snake_check_collision(snake_t *s, const point_t head_point) {
  for(int i = 1; i < s->size; ++i) {
    if(head_point.x == s->body[i].point.x && head_point.y == s->body[i].point.y) {
      return 1;
    }
  }

  return 0;
}

void snake_growth(snake_t *s) {
  ++s->size;

  for(int i = s->size - 1; i > 0; --i) {
    s->body[i] = s->body[i - 1];
  }
}
