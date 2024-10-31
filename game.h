#ifndef GAME_H_
#define GAME_H_
#define N 3
#define BASE_FONT_SIZE 60

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef enum {
  PLAYER_X_TURN,
  PLAYER_O_TURN,
  PLAYER_X_WINS,
  PLAYER_O_WINS,
  TIE
} GameState ;

typedef enum {
  E,
  X,
  O,
} Cell;


typedef struct {
  Cell board[N*N];
  GameState state;
} Game;


// Get cell by coordinates
Cell Game_getCell(const Game *game, int x, int y);

// Make turn
void Game_makeTurn(Game *game, int x, int y);

#endif // GAME_H
