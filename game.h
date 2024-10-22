#ifndef GAME_H_
#define GAME_H_
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#define WINDOW_TITLE "Tic Tac Toe"
#define INIT_SCREEN_WIDTH 1024
#define INIT_SCREEN_HEIGHT 768
#define N 3

typedef enum {
  PLAYER_X_TURN,
  PLAYER_O_TURN,
  PLAYER_X_WINS,
  PLAYER_O_WINS,
  TIE,
  EXIT
} GameState ;

typedef enum {
  X,
  O,
  E,
} Cell;


typedef struct {
  Cell board[N*N];
  GameState state;
} Game;


// Get cell by coordinates
Cell getCell(const Game *game, int x, int y);

// Make turn
void makeTurn(Game *game, int x, int y);

// Print game state
void debugGame(const Game *game);


#endif // GAME_H
