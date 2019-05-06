// A very simple videogame project to get my daughter started with coding
// for bare-metal platforms. I shall try and keep all machine-dependent source
// together and separate so we can port the project 'easily'
// Authors: Jon Agirre & Iraia Agirre, 2019
// Licence: GPL v3.0 (https://www.gnu.org/licenses/gpl.html)
//
#include <stdlib.h>
#include "machine/controllers.h"
#include "machine/graphics.h"
#include "machine/sound.h"
#include "machine/cpu.h"

int game_mode;

int main ()
{
  game_mode = 0; // single player, background 'A'
  set_min_clockspeed ( ); // lower clockspeed = longer battery life on portables
  init_clock ( );
  init_graphics ( );

  while (1)
  {
    if ( joy_1_select() )
      game_mode = ( game_mode ? 0 : 1 );
    draw_background ( game_mode );
    draw_framerate ( );
  }

}
