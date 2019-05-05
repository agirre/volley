// A very simple videogame project to get my daughter started with coding
// for bare-metal platforms. I shall try and keep all machine-dependent source
// together and separate so we can port the project 'easily'
// Authors: Jon Agirre & Iraia Agirre, 2019
// Licence: GPL v3.0 (https://www.gnu.org/licenses/gpl.html)
//

#include "cpu.h"

void set_min_clockspeed ()
{
  gp_setCpuspeed(133);
}

void init_clock ()
{
  gp_initRTC();
  gp_clearRTC();
}
