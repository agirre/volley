// A very simple videogame project to get my daughter started with coding
// for bare-metal platforms. I shall try and keep all machine-dependent source
// together and separate so we can port the project 'easily'
// Authors: Iraia Agirre, Saioa Urresti & Jon Agirre, 2019
// Licence: GPL v3.0 (https://www.gnu.org/licenses/gpl.html)
//

#include "graphics.h"

int swapper;
int framerate;
int refreshrate;

char buffer[64];
u16 *framebuffer[2];

inline void swap_screen ( )
{
   gp_setFramebuffer ( framebuffer[swapper], 1 );
   swapper++;
   if ( swapper == 2 )
    swapper=0;
}

void init_graphics ( )
{
  swapper = 0;
  framerate = 0;
  refreshrate = 0;

  framebuffer[0] = (u16*) FRAMEBUFFER1;
  framebuffer[1] = (u16*) FRAMEBUFFER2;

  sprintf(buffer, "Framerate:         ");

  refreshrate = gp_initFramebufferN(framebuffer[0],16,85);
}

void draw_framerate ( )
{
  if (gp_getRTC() > 63)
  {
    sprintf(buffer,"Framerate: %d,%d    ", framerate, refreshrate);
    framerate=0;
    gp_clearRTC();
  }

  gp_drawString ( 10, 220, 20, buffer, 0x0000, framebuffer[swapper] );
}

// this function has to be called before the other drawing operations
// as it swaps the screen and clears the framebuffer
void draw_background ( int mode )
{
  swap_screen();
  gp_clearFramebuffer16 ( framebuffer[swapper], 0xFFFF ); // very very fast asm, faster than memset

  if ( mode == 0 )
    gp_drawSpriteH  ( (u16*)background_a_bin, 0, 0, framebuffer[swapper] );
  else
    gp_drawSpriteH  ( (u16*)background_b_bin, 0, 0, framebuffer[swapper] );

  framerate++;
}

void draw_player_1 ( )
{
  gp_drawTiled16 ( (u16*)player_1_bin, 0xF83E, 45, 0, 30, 170, framebuffer[swapper]);
}

void draw_player_2 ( )
{
  gp_drawTiled16 ( (u16*)player_2_bin, 0xF83E, 45, 0, 250, 170, framebuffer[swapper]);
}
