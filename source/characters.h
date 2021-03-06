// A very simple videogame project to get my daughter started with coding
// for bare-metal platforms. I shall try and keep all machine-dependent source
// together and separate so we can port the project 'easily'
// Authors: Iraia Agirre, Saioa Urresti & Jon Agirre, 2019
// Licence: GPL v3.0 (https://www.gnu.org/licenses/gpl.html)
//

#include "machine/graphics.h"

#define ANIMATION_DELAY 3

struct character {
  int x_pos;
  int y_pos;
  int animation_index;
  int animation_counter;
};

struct character player_1;
struct character player_2;

inline void init_player( struct character * player, int n_player ) {
  player->x_pos = n_player ? PLAYER_2_HOME : PLAYER_1_HOME;
  player->y_pos = GROUND_LEVEL;
  player->animation_index = 0;
  player->animation_counter = ANIMATION_DELAY;
}

void move_player_1( struct controls_set *gamepad );
void move_player_2();
