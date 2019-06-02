// A very simple videogame project to get my daughter started with coding
// for bare-metal platforms. I shall try and keep all machine-dependent source
// together and separate so we can port the project 'easily'
// Authors: Iraia Agirre, Saioa Urresti & Jon Agirre, 2019
// Licence: GPL v3.0 (https://www.gnu.org/licenses/gpl.html)
//

#ifndef GRAPHICS_H
#define GRAPHICS_H

#define TRANSPARENT    0xF83E

#define BALL_SIZE      25
#define PLAYER_SIZE    43
#define FONT_SIZE      18

#define P1_LEFT_LIMIT  0
#define P1_RIGHT_LIMIT 110
#define P2_RIGHT_LIMIT 300
#define P2_LEFT_LIMIT  190
#define GROUND_LEVEL   170

#define PLAYER_1_HOME  30
#define PLAYER_2_HOME  250
#define BALL_Y_HOME    130
#define BALL_X1_HOME   PLAYER_1_HOME + BALL_SIZE
#define BALL_X2_HOME   PLAYER_1_HOME - BALL_SIZE
#define SCORE_Y_HOME   FONT_SIZE
#define SCORE_X1_HOME  FONT_SIZE
#define SCORE_X2_HOME  270

#include <stdio.h>
#include "gp32.h"
#include "controllers.h"
#include "assets_background_a_bin.h"
#include "assets_background_b_bin.h"
#include "assets_player_1_bin.h"
#include "assets_player_2_bin.h"
#include "assets_ball_bin.h"
#include "assets_font_bin.h"

int swapper;
int framerate;
int refreshrate;

char buffer[64];
u16 *framebuffer[2];

// We have a Korean GP32 (original) and a BLU model (UK), both with Samsung LCD
// so don't want to be using a hotkey to turn off Taiwanese LCD code every time
extern short gp_initFramebufferN(void *add, u16 bitmode, u16 refreshrate);

void init_graphics();
void draw_background(int mode);
void draw_framerate();
void draw_player(int player, int animation_index, int x, int y);
void draw_ball (int animation_index, int x, int y);
void draw_score (int score_player_1, int score_player_2);

#endif
