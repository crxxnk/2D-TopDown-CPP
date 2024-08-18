#pragma once
#include "textures.h"
#include <raylib.h>

float playerSpeed = 3;

void Input()
{
  if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
  {
    playerMoving = true;
    playerDir = 1;
    playerUp = true;
  }
  if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
  {
    playerMoving = true;
    playerDir = 0;
    playerDown = true;
  }
  if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
  {
    playerMoving = true;
    playerDir = 2;
    playerLeft = true;
  }
  if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
  {
    playerMoving = true;
    playerDir = 3;
    playerRight = true;
  }
   
}