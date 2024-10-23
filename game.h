#ifndef GAME_H_
#define GAME_H_
#define N 3

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef enum {
  PLAYER_X_TURN,
  PLAYER_O_TURN,
  PLAYER_X_WINS,
  PLAYER_O_WINS,
  TIE,
  EXIT
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
Cell getCell(const Game *game, int x, int y);

// Make turn
void makeTurn(Game *game, int x, int y);

// Print game state
void debugGame(const Game *game);


#endif // GAME_H
