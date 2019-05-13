// A very simple videogame project to get my daughter started with coding
// for bare-metal platforms. I shall try and keep all machine-dependent source
// together and separate so we can port the project 'easily'
// Authors: Iraia Agirre, Saioa Urresti & Jon Agirre, 2019
// Licence: GPL v3.0 (https://www.gnu.org/licenses/gpl.html)
//

#include "machine/controllers.h"
#include "machine/graphics.h"

#include "assets_player_1_bin.h"
#include "assets_player_2_bin.h"

void draw_player_1   ();
void draw_player_2   ();
