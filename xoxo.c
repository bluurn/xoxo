#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "raylib.h"
#include "render.h"

#define WINDOW_TITLE "Tic Tac Toe"
#define INIT_SCREEN_WIDTH 1024
#define INIT_SCREEN_HEIGHT 1024


void ReadEvents(Game * game) 
{
  if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    int cellWidth = GetScreenWidth() / N;
    int cellHeight = GetScreenHeight() / N;
    makeTurn(game, GetMouseX() / cellWidth, GetMouseY() / cellHeight);
  }
}

int main(void)
{
  Game game = {0};

  SetConfigFlags(FLAG_WINDOW_TOPMOST | FLAG_WINDOW_ALWAYS_RUN);
  SetTargetFPS(60);
  InitWindow(INIT_SCREEN_WIDTH, INIT_SCREEN_HEIGHT, WINDOW_TITLE);

  while(!WindowShouldClose()) {
    RenderGame(&game);
    ReadEvents(&game);
  }

  CloseWindow();

  return EXIT_SUCCESS;
}
