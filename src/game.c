#include "game.h"
#include "game_render.h"
#include "utils.h"
#include <conio.h>

direction_t OPPOSITE_DIRECTIONS_TABLE[] = {
/* left  */ Right,
/* right */ Left,
/*  up   */ Down,
/* down  */ Up
};

direction_t read_direction(direction_t prev) {
  if(!kbhit()) 
    return;

  switch(getk()) {
    case '7': 
      return Up;
    case '5':
      return Left;
    case '8':
      return Right;
    case '6':
      return Down;
  }

  return prev;
}

void game_initialize(game_t *game) {
  clear_screen();
  textbackground(0);
  settextcolor(7);
  game_render_walls(game);
  game_render_apple(game);
  game_render_score(game);
  game_render_best_score(game);
}

void game_sleep(game_t *game) {
  for(int i = 0; i < (MIN_STEP_TICKS * game->speed); ++i);
}

void game_play(game_t *game, const char *map, int speed) {
  int gameover = 0;
  direction_t new_dir;

  scene_initialize(game->scene, map);
  game->score = 0;
  game->speed = speed;

  game_initialize(game);

  while(!gameover) {
    new_dir = read_direction(game->scene.snake.direction);

    if(OPPOSITE_DIRECTIONS_TABLE[game->scene.snake.direction] != new_dir) {
      game->scene.snake.direction = new_dir;
    }

    gameover = scene_update(&game->scene);
    game_render_scene(game);
    game_sleep(game);
  }
}
