#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "render.h"

#define WINDOW_TITLE "Tic Tac Toe"
#define INIT_SCREEN_WIDTH 1024
#define INIT_SCREEN_HEIGHT 768

void ReadEvents() 
{
  if (IsKeyDown(KEY_F)) !IsWindowMaximized() ? MaximizeWindow() : RestoreWindow();
}


void RenderGame(const Game * game) 
{
}

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

  SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_TOPMOST | FLAG_WINDOW_ALWAYS_RUN);
  SetTargetFPS(60);
  InitWindow(INIT_SCREEN_WIDTH, INIT_SCREEN_HEIGHT, WINDOW_TITLE);

  while(!WindowShouldClose()) {
    ReadEvents();
    BeginDrawing();
    ClearBackground(DARKGRAY);
    RenderGrid();
    RenderGame(&game);
    EndDrawing();
  }

  CloseWindow();

  return EXIT_SUCCESS;
}
