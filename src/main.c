#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <limits.h>
#include "scene.h"
#include "resources.h"
#include "utils.h"
#include "game.h"

int level_menu() {
  int timer = 0;
  char ch;
  static char *items[] = {
    "1 - EMPTY SPACE",
    "2 - EASY",
    "3 - MEDIUM",
    "4 - 404"
  };

  clear_screen();
  putsprite(spr_or, 77, 11, SNAKE_TITLE);
  textbackground(0);
  settextcolor(7);

  gotoxy(25, 14);
  cputs("SELECT LEVEL:");

  for(int i = 0; i < 4; ++i) {
    gotoxy(24, 15 + i);
    cputs(items[i]);
  }

  while(1) {
    if(kbhit()) {
      ch = getk();

      if(ch >= '1' && ch <= '4') {
        srand(timer);

        return ch - '0';
      }
    }

    timer = timer == INT_MAX ? 0 : timer + 1;
  }
}

int speed_menu() {
  char ch = 0;

  clear_screen();
  putsprite(spr_or, 77, 11, SNAKE_TITLE);
  textbackground(0);
  settextcolor(7);

  gotoxy(20, 14);
  cputs("SELECT SPEED FROM 1 TO 9");
  
  while(1) {
    ch = getk();

    if(ch >= '1' && ch <= '9') {
      return ch - '0';
    }
  }
}

void exit_program(const int exit_code) {
  exit(EXIT_SUCCESS);
}

int gameover_menu() {
  char ch;
  static char *items[] = {
    "1 - RETRY",
    "2 - RETURN TO MAIN MENU",
    "3 - BACK TO BASIC"
  };

  clear_screen();
  putsprite(spr_or, 58, 12, SNAKE_GAMEOVER);
  textbackground(0);
  settextcolor(7);

  for(int i = 0; i < 3; ++i) {
    gotoxy(20, 14 + i);
    cputs(items[i]);
  }

  while(1) {
    if(kbhit()) {
      ch = getk();

      if(ch >= '1' && ch <= '3') {
        return ch - '0';
      }
    }
  }
}

int main(void) {
  game_t game;
  char *map = MAPS[level_menu() - 1];
  int speed = abs(speed_menu() - 9) + 1;

  game.score = game.best_score = 0;

  while(1) {
    game_play(&game, map, speed);

    switch(gameover_menu()) {
    case 1:
      if(game.score > game.best_score) {
        game.best_score = game.score;
      }

      break;
    case 2:
      map = MAPS[level_menu() - 1];
      speed = abs(speed_menu() - 9) + 1;
      game.score = game.best_score = 0;

      break;
    case 3:
      clear_screen();
      return 0;
    }
  }

  return 0;
}
