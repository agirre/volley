// A very simple videogame project to get my daughter started with coding
// for bare-metal platforms. I shall try and keep all machine-dependent source
// together and separate so we can port the project 'easily'
// Authors: Iraia Agirre, Saioa Urresti & Jon Agirre, 2019
// Licence: GPL v3.0 (https://www.gnu.org/licenses/gpl.html)
//

#include "controllers.h"
#include "gp32.h"

bool joy_1_L() {
  gamepad_1.l_button = gp_getButton() & BUTTON_L;
  return (gamepad_1.l_button);
}

bool joy_1_R() {
  gamepad_1.r_button = gp_getButton() & BUTTON_R;
  return (gamepad_1.r_button);
}

bool joy_1_A() {
  gamepad_1.a_button = gp_getButton() & BUTTON_A;
  return (gamepad_1.a_button);
}

bool joy_1_B() {
  gamepad_1.b_button = gp_getButton() & BUTTON_B;
  return (gamepad_1.b_button);
}

bool joy_1_up() {
  gamepad_1.joy_up = gp_getButton() & BUTTON_UP;
  return (gamepad_1.joy_up);
}

bool joy_1_down() {
  gamepad_1.joy_down = gp_getButton() & BUTTON_DOWN;
  return (gamepad_1.joy_down);
}

bool joy_1_left() {
  gamepad_1.joy_left = gp_getButton() & BUTTON_LEFT;
  return (gamepad_1.joy_left);
}

bool joy_1_right() {
  gamepad_1.joy_right = gp_getButton() & BUTTON_RIGHT;
  return (gamepad_1.joy_right);
}

bool joy_1_start() {
  bool tmp = gp_getButton() & BUTTON_START;
  if (gamepad_1.start_button && !tmp) {
    gamepad_1.start_button = tmp; // set to false, as button is now released
    return true;
  } else if (tmp == true) {
    gamepad_1.start_button = true;
    return false;
  } else
    return false;
}

bool joy_1_select() {
  bool tmp = gp_getButton() & BUTTON_SELECT;
  if (gamepad_1.select_button && !tmp) {
    gamepad_1.select_button = tmp; // set to false, as button is now released
    return true;
  } else if (tmp == true) {
    gamepad_1.select_button = true;
    return false;
  } else
    return false;
}

bool joy_2_L() { return false; }

bool joy_2_R() { return false; }

bool joy_2_A() { return false; }

bool joy_2_B() { return false; }

bool joy_2_up() { return false; }

bool joy_2_down() { return false; }

bool joy_2_left() { return false; }

bool joy_2_right() { return false; }

bool joy_2_start() { return false; }

bool joy_2_select() { return false; }

void init_gamepad(struct controls_set *gamepad) {
  gamepad->l_button = false;
  gamepad->r_button = false;
  gamepad->a_button = false;
  gamepad->b_button = false;
  gamepad->start_button = false;
  gamepad->select_button = false;
  gamepad->joy_up = false;
  gamepad->joy_down = false;
  gamepad->joy_left = false;
  gamepad->joy_right = false;
}

void update_gamepad(struct controls_set *gamepad, int n_gamepad) {
  gamepad->l_button =  n_gamepad ? joy_2_L()     : joy_1_L();
  gamepad->r_button =  n_gamepad ? joy_2_R()     : joy_1_R();
  gamepad->a_button =  n_gamepad ? joy_2_A()     : joy_1_A();
  gamepad->b_button =  n_gamepad ? joy_2_B()     : joy_1_B();
  gamepad->joy_up =    n_gamepad ? joy_2_up()    : joy_1_up();
  gamepad->joy_down =  n_gamepad ? joy_2_down()  : joy_1_down();
  gamepad->joy_left =  n_gamepad ? joy_2_left()  : joy_1_left();
  gamepad->joy_right = n_gamepad ? joy_2_right() : joy_1_right();
}
