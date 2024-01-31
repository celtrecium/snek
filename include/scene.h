#ifndef SCENE_H
#define SCENE_H

#include "snake.h"
#include "point.h"
#include "constants.h"

typedef enum scene_event {
  Nothing,
  AppleWasEaten,
  WallCollision,
  YourselfCollision
} scene_event_t;

typedef struct scene {
  snake_t snake;
  point_t walls[30*20];
  int size;
  point_t apple;
  scene_event_t current_event;
} scene_t;

void scene_draw_walls(const scene_t *scene);
int scene_check_snake_walls_collision(scene_t *scene, point_t head_point);
scene_event_t scene_check_snake_move(scene_t *scene);
void scene_move_snake(scene_t *sc);
int scene_check_apple_position(scene_t *scene, point_t point);
void scene_apple_new(scene_t *scene);
void scene_snake_eat_apple(scene_t *scene);
int scene_update(scene_t *scene);
void scene_initialize(scene_t *scene, const char *map);

#endif  /* SCENE_H */
