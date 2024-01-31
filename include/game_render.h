#ifndef GAME_RENDER_H
#define GAME_RENDER_H

#include "game.h"

void game_render_walls(const game_t *game);
void game_render_moved_snake(game_t *game);
void game_render_apple(game_t *game);
void game_render_score(game_t *game);
void game_render_best_score(game_t *game);
void game_render_scene(game_t *game);

#endif  /* GAME_RENDER_H */
