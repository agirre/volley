// A very simple videogame project to get my daughter started with coding
// for bare-metal platforms. I shall try and keep all machine-dependent source
// together and separate so we can port the project 'easily'
// Authors: Iraia Agirre, Saioa Urresti & Jon Agirre, 2019
// Licence: GPL v3.0 (https://www.gnu.org/licenses/gpl.html)
//

#include "game.h"

void update_scores ( int scored_player ) {
  if ( scored_player != 0 ) {

    ( scored_player == 1 ) ? game.score_player_1++ : game.score_player_2++;

    if ( game.score_player_1 == GAME_OVER || game.score_player_1 == GAME_OVER )
      game.finished = true;
  }


}

void init_scores ( ) {
  game.score_player_1=0;
  game.score_player_2=0;
  game.finished = false;
}
