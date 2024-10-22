#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#define GAME_IMPLEMENTATION
#include "game.h"


int main(void)
{
  Game game = {
    .board = { 
      E, E, E,
      E, E, E,
      E, E, E,
    },
    .state = PLAYER_X_TURN
  };

  debugGame(&game);
  makeTurn(&game, 1, 1);
  debugGame(&game);
  makeTurn(&game, 2, 0);
  debugGame(&game);
  makeTurn(&game, 1, 0);
  debugGame(&game);
  makeTurn(&game, 2, 1);
  debugGame(&game);
  makeTurn(&game, 1, 2);
  debugGame(&game);
  assert(game.state == PLAYER_X_WINS);

  //  SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_TOPMOST | FLAG_WINDOW_ALWAYS_RUN);
  //  SetTargetFPS(60);
  //  InitWindow(INIT_SCREEN_WIDTH, INIT_SCREEN_HEIGHT, WINDOW_TITLE);
  //
  //  while(!WindowShouldClose()) {
  //    RenderGame();
  //    ReadEvents();
  //  }
  //
  //  CloseWindow();

  return EXIT_SUCCESS;
}
