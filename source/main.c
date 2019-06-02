// A very simple videogame project to get my daughter started with coding
// for bare-metal platforms. I shall try and keep all machine-dependent source
// together and separate so we can port the project 'easily'
// Authors: Iraia Agirre, Saioa Urresti & Jon Agirre, 2019
// Licence: GPL v3.0 (https://www.gnu.org/licenses/gpl.html)
//
#include "characters.h"
#include "ball.h"
#include "game.h"
#include "machine/controllers.h"
#include "machine/cpu.h"
#include "machine/graphics.h"
#include "machine/sound.h"
#include <stdlib.h>

int game_mode;

int main() {
  game_mode = 0;        // single player, background 'A'
  set_min_clockspeed(); // lower clockspeed = longer battery life on portables
  init_clock();
  init_graphics();
  init_gamepad(&gamepad_1);
  init_gamepad(&gamepad_2);
  init_player(&player_1, 0);
  init_player(&player_2, 1);
  init_ball(true); // by default, place it on the left
  init_scores();

  while (true) {
    if ( joy_1_select() ) {
      game_mode = (game_mode ? 0 : 1);
      init_player(&player_1, 0);
      init_player(&player_2, 1);
      init_ball(true);
      init_scores();
    }
    update_gamepad(&gamepad_1, 0); // 0 is gamepad 1
    draw_background(game_mode);
    move_player_1(&gamepad_1);
    move_player_2();
    move_ball();
    update_scores(0); // no movement for now
    draw_framerate();
  }
}
