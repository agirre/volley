// A very simple videogame project to get my daughter started with coding
// for bare-metal platforms. I shall try and keep all machine-dependent source
// together and separate so we can port the project 'easily'
// Authors: Jon Agirre & Iraia Agirre, 2019
// Licence: GPL v3.0 (https://www.gnu.org/licenses/gpl.html)
//

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdio.h>
#include "gp32.h"
#include "background_a_bin.h"

void init_graphics   ();
void draw_background ();
void draw_framerate  ();

#endif
