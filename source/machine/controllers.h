// A very simple videogame project to get my daughter started with coding
// for bare-metal platforms. I shall try and keep all machine-dependent source
// together and separate so we can port the project 'easily'
// Authors: Iraia Agirre, Saioa Urresti & Jon Agirre, 2019
// Licence: GPL v3.0 (https://www.gnu.org/licenses/gpl.html)
//

#ifndef CONTROLLER_H
#define CONTROLLER_H

// stdbool requires C99
#include <stdbool.h>

struct controls_set {
  bool l_button;
  bool r_button;
  bool a_button;
  bool b_button;
  bool start_button;
  bool select_button;
  bool joy_up;
  bool joy_down;
  bool joy_left;
  bool joy_right;
};

struct controls_set gamepad_1;
struct controls_set gamepad_2;

bool joy_1_L();
bool joy_1_R();
bool joy_1_A();
bool joy_1_B();
bool joy_1_up();
bool joy_1_down();
bool joy_1_left();
bool joy_1_right();
bool joy_1_start();
bool joy_1_select();

bool joy_2_L();
bool joy_2_R();
bool joy_2_A();
bool joy_2_B();
bool joy_2_up();
bool joy_2_down();
bool joy_2_left();
bool joy_2_right();
bool joy_2_start();
bool joy_2_select();

void init_gamepad(struct controls_set *gamepad);
void update_gamepad(struct controls_set *gamepad, int n_gamepad);
#endif
