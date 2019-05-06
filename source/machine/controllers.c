// A very simple videogame project to get my daughter started with coding
// for bare-metal platforms. I shall try and keep all machine-dependent source
// together and separate so we can port the project 'easily'
// Authors: Jon Agirre & Iraia Agirre, 2019
// Licence: GPL v3.0 (https://www.gnu.org/licenses/gpl.html)
//

#include "controllers.h"
#include "gp32.h"


bool joy_1_L ( )
{
  return (gp_getButton() & BUTTON_L);
}

bool joy_1_R ( )
{
  return (gp_getButton() & BUTTON_R);
}

bool joy_1_A ( )
{
  return (gp_getButton() & BUTTON_A);
}

bool joy_1_B ( )
{
  return (gp_getButton() & BUTTON_B);
}

bool joy_1_up     ( )
{
  return (gp_getButton() & BUTTON_UP);
}

bool joy_1_down   ( )
{
  return (gp_getButton() & BUTTON_DOWN);
}

bool joy_1_left   ( )
{
  return (gp_getButton() & BUTTON_LEFT);
}

bool joy_1_right  ( )
{
  return (gp_getButton() & BUTTON_RIGHT);
}

bool joy_1_start  ( )
{
  return (gp_getButton() & BUTTON_START);
}

bool joy_1_select ( )
{
  return (gp_getButton() & BUTTON_SELECT);
}

bool joy_2_L      ( )
{
  return false;
}

bool joy_2_R      ( )
{
  return false;
}

bool joy_2_A      ( )
{
  return false;
}

bool joy_2_B      ( )
{
  return false;
}

bool joy_2_up     ( )
{
  return false;
}

bool joy_2_down   ( )
{
  return false;
}

bool joy_2_left   ( )
{
  return false;
}

bool joy_2_right  ( )
{
  return false;
}

bool joy_2_start  ( )
{
  return false;
}

bool joy_2_select ( )
{
  return false;
}
