#include "game.h"
#include <assert.h>


void ReadEvents() {
  if (IsKeyDown(KEY_F)) !IsWindowMaximized() ? MaximizeWindow() : RestoreWindow();
}

void RenderGame() {
  BeginDrawing();
  ClearBackground(DARKGRAY);
  EndDrawing();
}


Cell getCell(const Game *game, int x, int y) 
{ 
  return game->board[x + y * N]; 
}

void setCell(Game *game, int x, int y, Cell cell)
{
  game->board[x + y * N] = cell;
}

bool isPlayerWon(const Game *game, Cell player) {
  assert(player != E);
  //TODO not implemented

  // check if any column is filled with same cell value
  // check if any row is filled with same cell value
  // check if any diagonal is filled with same cell value

  return false;
}

void updateState(Game *game)
{
  if(game->state == PLAYER_X_TURN) {
    game->state = PLAYER_O_TURN;
  } else {
    game->state = PLAYER_X_TURN;
  }
}

void makeTurn(Game *game, int x, int y)
{
  switch (game->state) {
    case PLAYER_X_TURN:
      if(getCell(game, x, y) != E) return;
      setCell(game, x, y, X);
      updateState(game);

      break;
    case PLAYER_O_TURN:
      if(getCell(game, x, y) != E) return;
      setCell(game, x, y, O);
      updateState(game);
      break;
    case PLAYER_X_WINS:
    case PLAYER_O_WINS:
    case TIE:
    case EXIT:
      break;
  }
}

char cellToText(Cell it) {
  char c;
  switch (it) {
    case X:
      c = 'X';
      break;
    case O:
      c = 'O';
      break;
    case E:
      c = ' ';
      break;
    default:
      fprintf(stderr, "Unexpected cell value %d", it);
      exit(EXIT_FAILURE);
  }

  return c;
}


void printBoard(const Game *game) {
  printf("Board:\n");
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      Cell cell = getCell(game, j, i);
      if(j > 0) printf(" "); 
      printf("%c", cellToText(cell));
    }
    printf("\n");
  }
}

void printState(const Game *game)
{
  printf("State: ");
  switch(game->state)
  {
    case PLAYER_X_TURN: printf("Player X's turn.\n"); break;
    case PLAYER_O_TURN: printf("Player O's turn.\n"); break;
    case PLAYER_X_WINS: printf("Player X wins.\n"); break;
    case PLAYER_O_WINS: printf("Player O wind.\n"); break;
    case TIE: printf("Tie.\n"); break;
    case EXIT: printf("Exit.\n");break;
    default: 
               fprintf(stderr, "Unexpected cell value %d", game->state);
               exit(EXIT_FAILURE);
  }
}

void debugGame(const Game *game)
{
  printBoard(game);
  printState(game);
}

