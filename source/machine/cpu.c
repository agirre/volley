// A very simple videogame project to get my daughter started with coding
// for bare-metal platforms. I shall try and keep all machine-dependent source
// together and separate so we can port the project 'easily'
// Authors: Iraia Agirre, Saioa Urresti & Jon Agirre, 2019
// Licence: GPL v3.0 (https://www.gnu.org/licenses/gpl.html)
//

#include "cpu.h"

// Lower clockspeed, longer battery life on GP32, GP2x, etc
// Ignored on Dreamcast, i686 or RPi versions
void set_min_clockspeed ()
{
  gp_setCpuspeed ( 133 );
}

void init_clock ()
{
  gp_initRTC();
  gp_clearRTC();
}
