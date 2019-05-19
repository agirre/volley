// A very simple videogame project to get my daughter started with coding
// for bare-metal platforms. I shall try and keep all machine-dependent source
// together and separate so we can port the project 'easily'
// Authors: Iraia Agirre, Saioa Urresti & Jon Agirre, 2019
// Licence: GPL v3.0 (https://www.gnu.org/licenses/gpl.html)
//

#include "characters.h"

void draw_player_1(struct controls_set *gamepad) {

  if (gamepad->joy_left)
    player_1.x_pos = (player_1.x_pos - 3 <= P1_LEFT_LIMIT)
                         ? P1_LEFT_LIMIT
                         : player_1.x_pos - 3;
  if (gamepad->joy_right)
    player_1.x_pos = (player_1.x_pos + 3 >= P1_RIGHT_LIMIT)
                         ? P1_RIGHT_LIMIT
                         : player_1.x_pos + 3;

  if (!gamepad->joy_left && !gamepad->joy_right) {
    player_1.animation_index = 0;
    gp_drawTiled16((u16 *)assets_player_1_bin, 0xF83E, 43,
                   player_1.animation_index, player_1.x_pos, 170,
                   framebuffer[swapper]);
  } else {
    if (--player_1.animation_counter < 1) {
      player_1.animation_counter = 6;
      if (player_1.animation_index == 3)
        player_1.animation_index = 1;
      else
        player_1.animation_index++;
    }
    gp_drawTiled16((u16 *)assets_player_1_bin, 0xF83E, 43,
                   player_1.animation_index, player_1.x_pos, 170,
                   framebuffer[swapper]);
  }
}

void draw_player_2() {
  gp_drawTiled16((u16 *)assets_player_2_bin, 0xF83E, 43, 0, 250, 170,
                 framebuffer[swapper]);
}
