#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "render.h"
#include "raymath.h"

#define WINDOW_TITLE "Tic Tac Toe"
#define INIT_SCREEN_WIDTH 1024
#define INIT_SCREEN_HEIGHT 1024

void ReadEvents() 
{
  if (IsKeyDown(KEY_F)) !IsWindowMaximized() ? MaximizeWindow() : RestoreWindow();
}


void RenderX(int x, int y) {
  float w = (float)GetScreenWidth() / N;
  float h = (float)GetScreenHeight() / N;

  Vector2 tl = { w / 3, h / 3 };
  Vector2 br = { w - w / 3, h - h / 3 };
  Vector2 bl = { w / 3, h - h / 3 };
  Vector2 tr = { w - w / 3, h / 3};
  Vector2 delta = { w * x, h * y};

  DrawLineEx(Vector2Add(tl, delta), Vector2Add(br, delta), 10, RAYWHITE);
  DrawLineEx(Vector2Add(bl, delta), Vector2Add(tr, delta), 10, RAYWHITE);
}

void RenderO(int x, int y)
{
  float w = (float)GetScreenWidth() / N;
  float h = (float)GetScreenHeight() / N;
  float radius = fmin(w, h) / 4; 
  Vector2 center = { w / 2, h / 2 };
  Vector2 delta = { w * x, h * y};

  DrawRing(Vector2Add(center, delta), radius - 10, radius, 0.0f, 360.0f, 0, MAROON);
}

void RenderCellValue(Cell value, int x, int y)
{
  switch(value) {

  case E:
    break;
  case X:
    RenderX(x, y);
    break;
  case O:
    RenderO(x, y);
    break;
  }
}


void RenderGame(const Game * game) 
{
  for(int y = 0; y < N; ++y) {
    for(int x = 0; x < N; ++x) {
      Cell value = getCell(game, x, y);
      RenderCellValue(value, x, y);
    }
  }
}

int main(void)
{
  Game game = {
    .board = { 
      X, X, E,
      O, X, O,
      E, O, E,
    },
    .state = PLAYER_X_TURN
  };

  SetConfigFlags(FLAG_WINDOW_TOPMOST | FLAG_WINDOW_ALWAYS_RUN);
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
