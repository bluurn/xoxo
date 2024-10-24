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

  DrawLineEx(Vector2Add(tl, delta), Vector2Add(br, delta), 10, PINK);
  DrawLineEx(Vector2Add(bl, delta), Vector2Add(tr, delta), 10, PINK);
}

void RenderO(int x, int y)
{
  float w = (float)GetScreenWidth() / N;
  float h = (float)GetScreenHeight() / N;
  float radius = fmin(w, h) / 4; 
  Vector2 center = { w / 2, h / 2 };
  Vector2 delta = { w * x, h * y};

  DrawRing(Vector2Add(center, delta), radius - 10, radius, 0.0f, 360.0f, 0, YELLOW);
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



void RenderGrid(const Game * game) {
  float lineThickness = 5.0;
  float screenWidth = GetScreenWidth();
  float screenHeight = GetScreenHeight();
  float cellWidth = screenWidth / N;
  float cellHeight = screenHeight / N;


  Color lineColor;
  if(game->state == PLAYER_X_WINS) {
    lineColor = PINK;
  } else if (game->state == PLAYER_O_WINS) {
    lineColor = YELLOW;
  } else {
    lineColor = GRAY;
  }

  for (int i = 1; i < N; ++i) {
    Vector2 verticalLineStart = {cellWidth * i, 0};
    Vector2 verticalLineEnd = {cellWidth * i, screenHeight};
    DrawLineEx(verticalLineStart, verticalLineEnd, lineThickness, lineColor);

    Vector2 horizontalLineStart = {0, cellHeight * i};
    Vector2 horizontalLineEnd = {screenWidth, cellHeight * i};
    DrawLineEx(horizontalLineStart, horizontalLineEnd, lineThickness, lineColor);
  }
}
Vector2 GetTextUpperLeftCorner(const char * text, int fontSize)
{
  const float screenWidth = GetScreenWidth();
  const float screenHeight = GetScreenHeight();
  const float textOffsetWidth = MeasureText(text, fontSize);

  Vector2 result = {
    .x = (screenWidth / 2) - (textOffsetWidth / 2),
    .y = screenHeight / 2 - fontSize
  };

  return result;
}

void DrawHint(void)
{
  const char * text  = "Click to continue";
  const int fontSize = BASE_FONT_SIZE / 2;
  Vector2 ltCorner = GetTextUpperLeftCorner(text, fontSize);
  DrawText(text, ltCorner.x, ltCorner.y + fontSize, fontSize, LIGHTGRAY);
}

void RenderPlayerXWins(void) 
{
  const int fontSize = BASE_FONT_SIZE;
  const char * text  = "Player X Wins!";
  Vector2 ltCorner = GetTextUpperLeftCorner(text, fontSize);
  DrawText(text, ltCorner.x, ltCorner.y, fontSize, RAYWHITE);
}

void RenderPlayerOWins(void)
{
  const int fontSize = BASE_FONT_SIZE;
  const char * text  = "Player O Wins!";
  Vector2 ltCorner = GetTextUpperLeftCorner(text, fontSize);
  DrawText(text, ltCorner.x, ltCorner.y, fontSize, RAYWHITE);
}

void RenderTie(void)
{
  const int fontSize = BASE_FONT_SIZE;
  const char * text  = "Tie!";
  Vector2 ltCorner = GetTextUpperLeftCorner(text, fontSize);
  DrawText(text, ltCorner.x, ltCorner.y, fontSize, LIGHTGRAY);
}

void RenderGame(const Game * game) 
{
  BeginDrawing();
  ClearBackground(DARKGRAY);
  RenderGrid(game);
  for(int y = 0; y < N; ++y) {
    for(int x = 0; x < N; ++x) {
      Cell value = getCell(game, x, y);
      RenderCellValue(value, x, y);
    }
  }

  if(game->state == PLAYER_X_WINS) {
    RenderPlayerXWins();
    DrawHint();
  } else if(game->state == PLAYER_O_WINS) {
    RenderPlayerOWins();
    DrawHint();
  } else if(game->state == TIE) {
    RenderTie();
    DrawHint();
  }
  EndDrawing();
}

