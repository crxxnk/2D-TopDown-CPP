#include <iostream>
#include <raylib.h>
#include "include/textures.h"
#include "include/rendering.h"
#include "include/input.h"

int main()
{
	Init(1280, 800);

	while (running)
	{
		Input();
		Update();
		Render();
	}

	Quit();
	return 0;
}