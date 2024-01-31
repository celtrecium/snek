#ifndef GAME_H
#define GAME_H

#include "scene.h"
#include "constants.h"

typedef struct game {
  scene_t scene;
  int score;
  int best_score;
  int speed;
} game_t;

void game_initialize(game_t *game);
void game_sleep(game_t *game);
void game_play(game_t *game, const char *map, int speed);

#endif  /* GAME_H */
