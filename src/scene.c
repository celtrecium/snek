#include "scene.h"
#include <stdlib.h>

int scene_check_snake_walls_collision(scene_t *scene, point_t head_point) {
  for(int i = 0; i < scene->size; ++i) {
    if(scene->walls[i].x == head_point.x && scene->walls[i].y == head_point.y) {
      return 1;
    }
  }

  return 0;
}

scene_event_t scene_check_snake_move(scene_t *scene) {
  point_t tmp;
  tmp.x = scene->snake.body[0].point.x;
  tmp.y = scene->snake.body[0].point.y;

  point_move_by_direction(&tmp, scene->snake.direction);

  if(scene_check_snake_walls_collision(scene, tmp)) {
    return WallCollision;
  } else if(tmp.x == scene->apple.x && tmp.y == scene->apple.y) {
    return AppleWasEaten;
  } else if(snake_check_collision(&scene->snake, tmp)) {
    return YourselfCollision;
  }

  return Nothing;
}

int scene_check_apple_position(scene_t *scene, point_t point) {
  for(int i = 0; i < scene->size; ++i) {
    if(scene->walls[i].x == point.x && scene->walls[i].y == point.y) {
      return 0;
    }
  }

  for(int i = 0; i < scene->snake.size; ++i) {
    if(scene->snake.body[i].point.x == point.x && 
       scene->snake.body[i].point.y == point.y) {
      return 0;
    }
  }

  return 1;
}

void scene_apple_new(scene_t *scene) {
  do {
    scene->apple.x = rand() % FIELD_WIDTH;
    scene->apple.y = rand() % FIELD_HEIGHT;
  } while(!scene_check_apple_position(scene, scene->apple));
}

void scene_snake_eat_apple(scene_t *scene) {
  snake_growth(&scene->snake);
  scene_apple_new(scene);
}

int scene_update(scene_t *scene) {
  switch(scene->current_event = scene_check_snake_move(scene)) {
  case Nothing:
    snake_move(&scene->snake);
    return 0;
  case WallCollision:
  case YourselfCollision:
    return 1;
  case AppleWasEaten:
    scene_snake_eat_apple(scene);
    snake_move(&scene->snake);
    return 0;
  }
}

void scene_initialize(scene_t *scene, const char *map) {
  int width = map[0];
  int width_bytes = width / 8 + !!(width % 8);
  int height = map[1];

  snake_initialize(&scene->snake);
  scene->size = 0;
  scene->current_event = Nothing;

  for(int y = 0; y < height; ++y) {
    for(int x = 0; x < width_bytes; ++x) {
      for(int i = 0; i < 8; ++i) {
        if((map[y * width_bytes + x + 2] << i) & 128) {
          scene->walls[scene->size].x = x * 8 + i;
          scene->walls[scene->size].y = y;
          ++scene->size;
        }
      }
    }
  }

  scene_apple_new(scene);
}
