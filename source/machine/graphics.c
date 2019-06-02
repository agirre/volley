// A very simple videogame project to get my daughter started with coding
// for bare-metal platforms. I shall try and keep all machine-dependent source
// together and separate so we can port the project 'easily'
// Authors: Iraia Agirre, Saioa Urresti & Jon Agirre, 2019
// Licence: GPL v3.0 (https://www.gnu.org/licenses/gpl.html)
//

#include "graphics.h"

inline void swap_screen() {
  gp_setFramebuffer(framebuffer[swapper], 1);
  swapper++;
  if (swapper == 2)
    swapper = 0;
}

void init_graphics() {
  swapper = 0;
  framerate = 0;
  refreshrate = 0;

  framebuffer[0] = (u16 *)FRAMEBUFFER1;
  framebuffer[1] = (u16 *)FRAMEBUFFER2;

  sprintf(buffer, "Framerate:         ");

  refreshrate = gp_initFramebufferN(framebuffer[0], 16, 85);
}

void draw_framerate() {
  if (gp_getRTC() > 63) {
    sprintf(buffer, "Framerate: %d,%d    ", framerate, refreshrate);
    framerate = 0;
    gp_clearRTC();
  }

  gp_drawString(15, 230, 20, buffer, 0x0000, framebuffer[swapper]);
}

// this function has to be called before the other drawing operations
// as it swaps the screen and clears the framebuffer
void draw_background(int mode) {
  swap_screen();
  gp_clearFramebuffer16(framebuffer[swapper],
                        0xFFFF); // very very fast asm, faster than memset

  if (mode == 0)
    gp_drawSpriteH((u16 *)assets_background_a_bin, 0, 0, framebuffer[swapper]);
  else
    gp_drawSpriteH((u16 *)assets_background_b_bin, 0, 0, framebuffer[swapper]);

  framerate++;
}

void draw_player(int player, int animation_index, int x, int y) {
  if (player == 1)
    gp_drawTiled16((u16 *)assets_player_1_bin, TRANSPARENT, 43,
                   animation_index, x, y, framebuffer[swapper]);
  else
    gp_drawTiled16((u16 *)assets_player_2_bin, TRANSPARENT, 43,
                 animation_index, x, y, framebuffer[swapper]);
}

void draw_ball (int animation_index, int x, int y) {
  gp_drawTiled16((u16 *)assets_ball_bin, TRANSPARENT, 25,
               animation_index, x, y, framebuffer[swapper]);
}

void draw_score (int score_player_1, int score_player_2) {
  gp_drawTiled16((u16 *)assets_font_bin, TRANSPARENT, FONT_SIZE,
               score_player_1, SCORE_X1_HOME, SCORE_Y_HOME, framebuffer[swapper]);

  gp_drawTiled16((u16 *)assets_font_bin, TRANSPARENT, FONT_SIZE,
               score_player_2, SCORE_X2_HOME, SCORE_Y_HOME, framebuffer[swapper]);
}
