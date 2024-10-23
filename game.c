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

bool isTie(const Game *game)
{
  for(int i = 0; i < N*N; ++i) {
    if(game->board[i] == E) return false;
  }

  return true;
}


bool isPlayerWon(const Game *game, Cell player) {
  assert(player != E);

  int rowCount = 0;
  int colCount = 0;
  int diag1Count = 0;
  int diag2Count = 0;

  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      if(game->board[i * N + j]== player) rowCount++;
      if(game->board[j * N + i] == player) colCount++;
    }

    if(rowCount >= N || colCount >= N) return true;

    rowCount = 0;
    colCount = 0;

    if(game->board[i * N + 1] == player) diag1Count++;
    if(game->board[i * N + N - i - 1]) diag2Count++;
  }

  return diag1Count >= N || diag2Count >= N;
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

