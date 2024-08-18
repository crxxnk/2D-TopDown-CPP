#pragma once
#include <vector>

bool running = true;
Color bgColor = Color{147, 211, 196, 255};

//Textures variables
Texture2D grassSprite;
Texture2D playerSprite;

Rectangle playerSrc;
Rectangle playerDest;

void DrawScene()
{
	DrawTexture(grassSprite, 100, 50, WHITE);
	DrawTexturePro(playerSprite, playerSrc, playerDest, Vector2(), 0, WHITE);
}

void Init(const int screenWidth, const int screenHeight)
{
	InitWindow(screenWidth, screenHeight, "Top Down 2D");
	SetExitKey(0);
	SetTargetFPS(60);

	grassSprite = LoadTexture("assets/SproutLands/Tilesets/Grass.png");
	playerSprite = LoadTexture("assets/Fantasy/Player/Player.png");

	playerSrc = Rectangle{0, 0, 24, 24};
	playerDest = Rectangle{200, 200, 100, 100};
}

void unloadTextures()
{
	UnloadTexture(grassSprite);
	UnloadTexture(playerSprite);
}