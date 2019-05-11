// A very simple videogame project to get my daughter started with coding
// for bare-metal platforms. I shall try and keep all machine-dependent source
// together and separate so we can port the project 'easily'
// Authors: Iraia Agirre, Saioa Urresti & Jon Agirre, 2019
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
  init_gamepad ( gamepad_1 );
  init_gamepad ( gamepad_2 );

  while ( true )
  {
    bool select_pressed = joy_1_select();
    if ( select_pressed && !gamepad_1.select_button )
      gamepad_1.select_button = true;
    else if ( !select_pressed && gamepad_1.select_button )
    {
      game_mode = ( game_mode ? 0 : 1 );
      gamepad_1.select_button = false;
    }
    draw_background ( game_mode );
    draw_player_1 ( );
    draw_player_2 ( );
    draw_framerate ( );
  }

}
