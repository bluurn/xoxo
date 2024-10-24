#include "game.h"

Cell getCell(const Game *game, int x, int y) 
{ 
  return game->board[x + y * N]; 
}

void setCell(Game *game, int x, int y, Cell cell)
{
  game->board[x + y * N] = cell;
}

bool isTie(const Game *game)
{
  for(int i = 0; i < N*N; ++i) {
    if(game->board[i] == E) return false;
  }

  return true;
}


bool isPlayerWon(const Game *game, Cell player) {
  assert(player != E);

  for(int i = 0; i < N; ++i) {
    bool rowWin = true, colWin = true;
    for(int j = 0; j < N; ++j) {
      if(getCell(game, i, j) != player) rowWin = false;
      if(getCell(game, j, i) != player) colWin = false;
    }
    if(rowWin || colWin) return true; 
  }

  bool mainDiagonalWin = true, antiDiagonalWin = true;
  for(int i = 0; i < N; ++i) {
    if(getCell(game, i, i) != player) mainDiagonalWin = 0;
    if(getCell(game, i, N - i - 1) != player) antiDiagonalWin = 0;
  }

  if(mainDiagonalWin || antiDiagonalWin) return true;

  return false;
}

void checkGameOver(Game *game)
{
  if(isPlayerWon(game, X)) {
    game->state = PLAYER_X_WINS;
  } else if(isPlayerWon(game, O)) {
    game->state = PLAYER_O_WINS;
  } else if(isTie(game)) {
    game->state = TIE;
  }
}

void switchPlayer(Game *game)
{
  if(game->state == PLAYER_X_TURN) {
    game->state = PLAYER_O_TURN;
  } else {
    game->state = PLAYER_X_TURN;
  }
}

void resetGame(Game *game)
{
  for(int i = 0; i < N*N; ++i) game->board[i] = E;
  game->state = PLAYER_X_TURN;
}

void makeTurn(Game *game, int x, int y)
{
  switch (game->state) {
    case PLAYER_X_TURN:
      if(getCell(game, x, y) != E) return;
      setCell(game, x, y, X);
      switchPlayer(game);
      checkGameOver(game);
      break;
    case PLAYER_O_TURN:
      if(getCell(game, x, y) != E) return;
      setCell(game, x, y, O);
      switchPlayer(game);
      checkGameOver(game);
      break;
    case PLAYER_X_WINS:
    case PLAYER_O_WINS:
    case TIE:
      resetGame(game);
      break;
  }
}
