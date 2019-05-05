// A very simple videogame project to get my daughter started with coding
// for bare-metal platforms. I shall try and keep all machine-dependent source
// together and separate so we can port the project 'easily'
// Authors: Jon Agirre & Iraia Agirre, 2019
// Licence: GPL v3.0 (https://www.gnu.org/licenses/gpl.html)
//

#include "graphics.h"

int x;
int swapper=0;
int spritex=-150;
int framerate=0;
int refreshrate=0;

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

  refreshrate = gp_initFramebuffer(framebuffer[0],16,85);
}

void draw_framerate ( )
{
  if (gp_getRTC() > 63)
  {
    sprintf(buffer,"Framerate: %d,%d    ", framerate, refreshrate);
    framerate=0;
    gp_clearRTC();
  }

  gp_drawString ( 10, 230, 20, buffer, 0x0000, framebuffer[swapper] );
}

void draw_background ( )
{
  swap_screen();
  gp_clearFramebuffer16 ( framebuffer[swapper], 0xffff ); // very very fast asm, faster than memset

  gp_drawSpriteH  ( (u16*)background_a_bin, 0, 0, framebuffer[swapper] );

  framerate++;
}
