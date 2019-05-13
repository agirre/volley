// A very simple videogame project to get my daughter started with coding
// for bare-metal platforms. I shall try and keep all machine-dependent source
// together and separate so we can port the project 'easily'
// Authors: Iraia Agirre, Saioa Urresti & Jon Agirre, 2019
// Licence: GPL v3.0 (https://www.gnu.org/licenses/gpl.html)
//

#include "characters.h"

void draw_player_1 ( )
{
  gp_drawTiled16 ( (u16*)assets_player_1_bin, 0xF83E, 45, 0, 30, 170, framebuffer[swapper]);
}

void draw_player_2 ( )
{
  gp_drawTiled16 ( (u16*)assets_player_2_bin, 0xF83E, 45, 0, 250, 170, framebuffer[swapper]);
}
