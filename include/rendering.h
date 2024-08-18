#pragma once
#include "textures.h"
#include <raylib.h>

void Update(){
	running = !WindowShouldClose();
}

void Render()
{
	BeginDrawing();
	ClearBackground(bgColor);

	DrawScene();

	EndDrawing();
}

void Quit()
{
	unloadTextures();
  CloseWindow();
}