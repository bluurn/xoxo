#include "game.h"
#include "raylib.h"

void ReadEvents() {
  if (IsKeyDown(KEY_F)) !IsWindowMaximized() ? MaximizeWindow() : RestoreWindow();
}

void RenderGame() {
  BeginDrawing();
  ClearBackground(DARKGRAY);
  EndDrawing();
}

