#ifndef GAME_H
#define GAME_H
#define WINDOW_TITLE "Tic Tac Toe"
#define INIT_SCREEN_WIDTH 1024
#define INIT_SCREEN_HEIGHT 768
#define N 3

typedef enum {
  PLAYER_X_TURN,
  PLAYER_Y_TURN,
  PLAYER_X_WINS,
  PLAYER_Y_WINS,
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

// Print game state
void debugGame(const Game *game);

#endif
