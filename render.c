#include "game.h"
#include "raylib.h"
#include "raymath.h"

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

void RenderGrid(void) {
  float lineThickness = 5.0;
  float screenWidth = GetScreenWidth();
  float screenHeight = GetScreenHeight();
  float cellWidth = screenWidth / N;
  float cellHeight = screenHeight / N;
  for (int i = 1; i < N; ++i) {
    Vector2 verticalLineStart = {cellWidth * i, 0};
    Vector2 verticalLineEnd = {cellWidth * i, screenHeight};
    DrawLineEx(verticalLineStart, verticalLineEnd, lineThickness, LIGHTGRAY);

    Vector2 horizontalLineStart = {0, cellHeight * i};
    Vector2 horizontalLineEnd = {screenWidth, cellHeight * i};
    DrawLineEx(horizontalLineStart, horizontalLineEnd, lineThickness,
        LIGHTGRAY);
  }
}

