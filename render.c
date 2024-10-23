#include "game.h"
#include "raylib.h"

void RenderGrid() {
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

