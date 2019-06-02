// A very simple videogame project to get my daughter started with coding
// for bare-metal platforms. I shall try and keep all machine-dependent source
// together and separate so we can port the project 'easily'
// Authors: Iraia Agirre, Saioa Urresti & Jon Agirre, 2019
// Licence: GPL v3.0 (https://www.gnu.org/licenses/gpl.html)
//

#include "characters.h"

void move_player_1(struct controls_set *gamepad) {
  if (gamepad->joy_left)
    player_1.x_pos = (player_1.x_pos - 4 <= P1_LEFT_LIMIT) ? P1_LEFT_LIMIT
                                                           : player_1.x_pos - 4;
  if (gamepad->joy_right)
    player_1.x_pos = (player_1.x_pos + 4 >= P1_RIGHT_LIMIT)
                         ? P1_RIGHT_LIMIT
                         : player_1.x_pos + 4;

  if (!gamepad->joy_left && !gamepad->joy_right) {
    player_1.animation_index = 0;

  } else {
    if (--player_1.animation_counter < 1) {
      player_1.animation_counter = ANIMATION_DELAY;
      if (player_1.animation_index == 6)
        player_1.animation_index = 1;
      else
        player_1.animation_index++;
    }
  }
  draw_player(1, player_1.animation_index, player_1.x_pos, player_1.y_pos);
}

void move_player_2() {
  player_2.animation_index = 0;
  player_2.x_pos = 250;
  player_2.y_pos = GROUND_LEVEL;
  draw_player(2, player_2.animation_index, player_2.x_pos, player_2.y_pos);
}
