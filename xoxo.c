#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#define GAME_IMPLEMENTATION
#include "game.h"


int main(void)
{
  Game game = {
    .board = { 
      E, E, E,
      E, E, E,
      E, E, E,
    },
    .state = PLAYER_X_TURN
  };

  debugGame(&game);
  makeTurn(&game, 1, 1);
  debugGame(&game);
  makeTurn(&game, 2, 0);
  debugGame(&game);
  makeTurn(&game, 1, 0);
  debugGame(&game);
  makeTurn(&game, 2, 1);
  debugGame(&game);
  makeTurn(&game, 1, 2);
  debugGame(&game);
  assert(game.state == PLAYER_X_WINS);

  return EXIT_SUCCESS;
}
