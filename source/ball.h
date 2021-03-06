// A very simple videogame project to get my daughter started with coding
// for bare-metal platforms. I shall try and keep all machine-dependent source
// together and separate so we can port the project 'easily'
// Authors: Iraia Agirre, Saioa Urresti & Jon Agirre, 2019
// Licence: GPL v3.0 (https://www.gnu.org/licenses/gpl.html)
//

#include "machine/controllers.h"
#include "machine/graphics.h"

struct one_ball {
  int x_pos;
  int y_pos;
  int animation_index;
  int animation_counter;
};

struct one_ball ball;

void init_ball (bool on_the_left);
void move_ball ();
