// A very simple videogame project to get my daughter started with coding
// for bare-metal platforms. I shall try and keep all machine-dependent source
// together and separate so we can port the project 'easily'
// Authors: Iraia Agirre, Saioa Urresti & Jon Agirre, 2019
// Licence: GPL v3.0 (https://www.gnu.org/licenses/gpl.html)
//

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdio.h>
#include "gp32.h"
#include "assets_background_a_bin.h"
#include "assets_background_b_bin.h"
#include "assets_ball_bin.h"
#include "assets_font_bin.h"

int swapper;
int framerate;
int refreshrate;

char buffer[64];
u16 *framebuffer[2];

// We have a Korean GP32 (original) and a BLU model (UK), both with Samsung LCD
// so don't want to be using a hotkey to turn off Taiwanese LCD code every time
extern short gp_initFramebufferN(void *add,u16 bitmode,u16 refreshrate);

void init_graphics   ();
void draw_background ( int mode );
void draw_framerate  ();

#endif
