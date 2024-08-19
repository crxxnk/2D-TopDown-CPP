#pragma once
#include <vector>
#include <fstream>

Camera2D camera;

const int screenWidth = 1280;
const int screenHeight = 800;

bool running = true;
Color bgColor = Color{147, 211, 196, 255};

//Textures variables
Texture2D grassSprite;
Texture2D playerSprite;

Rectangle tileDest;
Rectangle tileSrc;
std::vector<int> tileMap{};
std::string srcMap[]{};
int mapW{}, mapH{};

Rectangle playerSrc;
Rectangle playerDest;

bool playerMoving;
int playerDir{};
bool playerUp, playerDown, playerLeft, playerRight;
int playerFrame{};

void DrawScene()
{
	// DrawTexture(grassSprite, 100, 50, WHITE);

	for (size_t i = 0; i < tileMap.size(); i++) {
		if(tileMap.at(i)!=0) {
			tileDest.x = tileDest.width * float(i % mapW);
			tileDest.y = tileDest.height * float(i / mapW);
			tileSrc.x = tileSrc.width * float((tileMap.at(i)-1) % int(grassSprite.width/int(tileSrc.width)));
			tileSrc.y = tileSrc.height * float((tileMap[i]-1) / int(grassSprite.width/int(tileSrc.width)));
			DrawTexturePro(grassSprite, tileSrc, tileDest, Vector2{tileDest.width, tileDest.height}, 0, WHITE);
		}
	}

	DrawTexturePro(playerSprite, playerSrc, playerDest, Vector2{playerDest.width, playerDest.height}, 0, WHITE);
}

void loadMap(std::string mapFile)
{
	std::ifstream map_file(mapFile);
	mapW = 5;
	mapH = 5;
	for(int i = 0; i < (mapW*mapH); i++) {
		tileMap.push_back(128);
	}
}

void Init()
{
	InitWindow(screenWidth, screenHeight, "Top Down 2D");
	SetExitKey(0);
	SetTargetFPS(60);

	grassSprite = LoadTexture("assets/SproutLands/Tilesets/Grass.png");

	tileDest = Rectangle{0, 0, 16, 16};
	tileSrc = Rectangle{0, 0, 16, 16};

	playerSprite = LoadTexture("assets/Sproutlands/Characters/Basic Charakter Spritesheet.png");

	playerSrc = Rectangle{0, 0, 48, 48};
	playerDest = Rectangle{200, 200, 100, 100};

	camera = Camera2D{Vector2{float(screenWidth/2), float(screenHeight/2)}, Vector2{float(playerDest.x-(playerDest.width/2)), float(playerDest.y-(playerDest.height/2))}, 0.0, 1.5};
	
	loadMap("grass.map");
}

void unloadTextures()
{
	UnloadTexture(grassSprite);
	UnloadTexture(playerSprite);
}