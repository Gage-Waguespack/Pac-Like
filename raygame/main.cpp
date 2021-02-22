/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "Game.h"
#include "Maze.h"
#include <Vector2.h>

int main()
{
	Game game = Game();

	// Create a maze, add it to the scene, and set it as the current scene
	game.setCurrentScene(game.addScene(new Maze()));

	game.run();

	return 0;
}