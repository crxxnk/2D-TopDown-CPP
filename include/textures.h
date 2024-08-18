#pragma once
#include <vector>

Camera2D camera;

const int screenWidth = 1280;
const int screenHeight = 800;

bool running = true;
Color bgColor = Color{147, 211, 196, 255};

//Textures variables
Texture2D grassSprite;
Texture2D playerSprite;

Rectangle playerSrc;
Rectangle playerDest;

bool playerMoving;
int playerDir{};
bool playerUp, playerDown, playerLeft, playerRight;
int playerFrame{};

int frameCount{};

void DrawScene()
{
	DrawTexture(grassSprite, 100, 50, WHITE);
	DrawTexturePro(playerSprite, playerSrc, playerDest, Vector2{playerDest.width, playerDest.height}, 0, WHITE);
}

void Init()
{
	InitWindow(screenWidth, screenHeight, "Top Down 2D");
	SetExitKey(0);
	SetTargetFPS(60);

	grassSprite = LoadTexture("assets/SproutLands/Tilesets/Grass.png");
	playerSprite = LoadTexture("assets/Sproutlands/Characters/Basic Charakter Spritesheet.png");

	playerSrc = Rectangle{0, 0, 48, 48};
	playerDest = Rectangle{200, 200, 100, 100};

	camera = Camera2D{Vector2{float(screenWidth/2), float(screenHeight/2)}, Vector2{float(playerDest.x-(playerDest.width/2)), float(playerDest.y-(playerDest.height/2))}, 0.0, 1.5};
}

void unloadTextures()
{
	UnloadTexture(grassSprite);
	UnloadTexture(playerSprite);
}