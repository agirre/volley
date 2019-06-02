// A very simple videogame project to get my daughter started with coding
// for bare-metal platforms. I shall try and keep all machine-dependent source
// together and separate so we can port the project 'easily'
// Authors: Iraia Agirre, Saioa Urresti & Jon Agirre, 2019
// Licence: GPL v3.0 (https://www.gnu.org/licenses/gpl.html)
//

#include "ball.h"

void init_ball (bool on_the_left) {
  if (on_the_left == true)
    ball.x_pos = PLAYER_1_HOME;
  else
    ball.x_pos = PLAYER_2_HOME;

  ball.y_pos = BALL_Y_HOME;
  ball.animation_index = 0;

  draw_ball (ball.animation_index, ball.x_pos, ball.y_pos);
}

void move_ball () {
  (ball.animation_index >= 25) ? ball.animation_index = 0 : ball.animation_index++;
  draw_ball (ball.animation_index, ball.x_pos, ball.y_pos);
}
