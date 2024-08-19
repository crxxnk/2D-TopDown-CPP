#pragma once
#include <raylib.h>
#include "textures.h"
#include "input.h"

int frameCount{};

void Update(){
	running = !WindowShouldClose();

	playerSrc.x = playerSrc.width * float(playerFrame);
	if(playerMoving)
	{
		if(playerUp) {playerDest.y-=playerSpeed;}
		if(playerDown) {playerDest.y+=playerSpeed;}
		if(playerLeft) {playerDest.x-=playerSpeed;}
		if(playerRight) {playerDest.x+=playerSpeed;}
		if(frameCount % 8 == 1)
			playerFrame++;
	} else if (frameCount % 45 == 1)
		playerFrame++;

	frameCount++;
	if(playerFrame > 3)
		playerFrame = 0;
	if(!playerMoving && playerFrame > 1)
		playerFrame = 0;

	playerSrc.x = playerSrc.width * float(playerFrame);
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