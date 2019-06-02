// A very simple videogame project to get my daughter started with coding
// for bare-metal platforms. I shall try and keep all machine-dependent source
// together and separate so we can port the project 'easily'
// Authors: Iraia Agirre, Saioa Urresti & Jon Agirre, 2019
// Licence: GPL v3.0 (https://www.gnu.org/licenses/gpl.html)
//

#include "machine/controllers.h"
#include "machine/graphics.h"
#define GAME_OVER 15

struct the_game {
  int score_player_1;
  int score_player_2;
  bool finished;
};

struct the_game game;

void update_scores ( int scored_player );
void init_scores ( );
