// #include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include "game_render.h"
#include "utils.h"
#include "resources.h"

char *SNAKE_DIRECTION_TABLE[4][4] = { 
/*             left                  right                  up                   down                 */
/* left  */  { SNAKE_BODY_HOR,       SNAKE_BODY_HOR,        SNAKE_BODY_UP_RIGHT, SNAKE_BODY_DOWN_RIGHT },
/* right */  { SNAKE_BODY_HOR,       SNAKE_BODY_HOR,        SNAKE_BODY_UP_LEFT,  SNAKE_BODY_DOWN_LEFT  },
/*  up   */  { SNAKE_BODY_DOWN_LEFT, SNAKE_BODY_DOWN_RIGHT, SNAKE_BODY_VERT,     SNAKE_BODY_VERT       },
/* down  */  { SNAKE_BODY_UP_LEFT,   SNAKE_BODY_UP_RIGHT,   SNAKE_BODY_VERT,     SNAKE_BODY_VERT       } 
};

char *SNAKE_TAIL_DIRECTION_TABLE[4] = {
/* left  */  SNAKE_TAIL_LEFT,
/* right */  SNAKE_TAIL_RIGHT,
/*  up   */  SNAKE_TAIL_UP,
/* down  */  SNAKE_TAIL_DOWN
};

char *SNAKE_HEAD_DIRECTION_TABLE[4] = {
/* left  */  SNAKE_HEAD_LEFT,
/* right */  SNAKE_HEAD_RIGHT,
/*  up   */  SNAKE_HEAD_UP,
/* down  */  SNAKE_HEAD_DOWN
};

void game_render_walls(const game_t *game) {
  static const char wall_colors[] = { FGColorGreen, (FGColorGreen | Dim) };

  for(int i = 0; i < game->scene.size; ++i) {
    put_sprite(game->scene.walls[i],
               wall_colors[rand() % sizeof(wall_colors)],
               WALLS[rand() % 3]);
  }
}

void game_render_moved_snake(game_t *game) {
  put_clear_sprite(game->scene.snake.deleted_tail, FGColorWhite);

  put_clear_sprite(game->scene.snake.body[1].point, FGColorWhite);
  put_sprite(game->scene.snake.body[1].point, FGColorYellow | Dim, 
             SNAKE_DIRECTION_TABLE[game->scene.snake.body[1].direction][get_head(&game->scene.snake).direction]);

  put_clear_sprite(get_head(&game->scene.snake).point, FGColorWhite);
  put_sprite(get_head(&game->scene.snake).point, FGColorYellow, 
             SNAKE_HEAD_DIRECTION_TABLE[game->scene.snake.direction]);

  put_clear_sprite(get_tail(&game->scene.snake).point, FGColorWhite);
  put_sprite(get_tail(&game->scene.snake).point, FGColorYellow, 
             SNAKE_TAIL_DIRECTION_TABLE[game->scene.snake.body[game->scene.snake.size-2].direction]);
}

void game_render_apple(game_t *game) {
    put_sprite(game->scene.apple, FGColorRed | Dim, APPLE);
}

void game_render_score(game_t *game) {
  gotoxy(2, 0);
  cprintf("SCORE: %d", game->score);
}

void game_render_best_score(game_t *game) {
  gotoxy(2, 1);
  cprintf("BEST SCORE: %d", game->best_score);
}

void game_render_scene(game_t *game) {
  switch(game->scene.current_event) {
  case Nothing:
    game_render_moved_snake(game);
    break;
  case AppleWasEaten:
    ++game->score;
    game_render_moved_snake(game);
    game_render_apple(game);
    game_render_score(game);
    break;
  case WallCollision:
    break;
  }
}
