#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "game.h"

int main(void)
{
  Game game = {
    .board = { 
      E, X, E,
      O, E, O,
      O, X, O,
    },
    .state = PLAYER_X_TURN
  };

  debugGame(&game);

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
