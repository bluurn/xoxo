#ifndef GAME_H
#define GAME_H
#include "raylib.h"
#define WINDOW_TITLE "Tic Tac Toe"
#define INIT_SCREEN_WIDTH 1024
#define INIT_SCREEN_HEIGHT 768
#define N 3

typedef enum {
  PLAYER_X_WINS,
  PLAYER_Y_WINS,
  TIE,
} GameState ;

typedef enum {
  X,
  O,
  EMPTY,
} Cell;


typedef struct {
  Cell field[N*N];
  GameState state;
} Game;

void RenderGame();
void ReadEvents();
#endif
