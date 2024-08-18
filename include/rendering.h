#pragma once
#include "textures.h"
#include "input.h"
#include <raylib.h>

void Update(){
	running = !WindowShouldClose();

	playerSrc.x = 0;

	if(playerMoving)
	{
		if(playerUp) {playerDest.y-=playerSpeed;}
		if(playerDown) {playerDest.y+=playerSpeed;}
		if(playerLeft) {playerDest.x-=playerSpeed;}
		if(playerRight) {playerDest.x+=playerSpeed;}
		if(frameCount % 8 == 1)
			playerFrame++;
		playerSrc.x = playerSrc.width * float(playerFrame);
	}

	frameCount++;
	if(playerFrame > 3)
		playerFrame = 0;
	playerSrc.y = playerSrc.height * float(playerDir);

	camera.target = Vector2{float(playerDest.x-(playerDest.width/2)), float(playerDest.y-(playerDest.height/2))};
	
	playerMoving = false;
	playerUp = false;
	playerDown = false;
	playerLeft = false;
	playerRight = false;
}

void Render()
{
	BeginDrawing();
	ClearBackground(bgColor);
	BeginMode2D(camera);

	DrawScene();

  EndMode2D();
	EndDrawing();
}

void Run()
{
	Init();
	// HideCursor();

	while (running)
	{
		Input();
		Update();
		Render();
	}
}

void Quit()
{
	unloadTextures();
  CloseWindow();
}