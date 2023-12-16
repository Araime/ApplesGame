#pragma once
#include <string>

namespace ApplesGame
{
	// init resorce path variables
	const std::string IMG_PATH = "Game/Resources/Images/";
	const std::string SND_PATH = "Game/Resources/Sounds/";
	const std::string FONTS_PATH = "Game/Resources/Fonts/";

	// init game variables
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
	const int BGS_NUM = 2;
	const float INITIAL_SPEED = 100.f; // pixels per seconds
	const float PLAYER_SIZE = 25.f;
	const float ACCELERATION = 10000.f; // pixels  per seconds
	const int NUM_APPLES = 30;
	const float APPLE_SIZE = 25.f;
	const int OFFSET = 20;
	const float TABLE_X = SCREEN_WIDTH / 2.f - 70.f; // score table x coordinate
	const float TABLE_Y = 5.f; // score table y coordinate
	const float TEXT_COORD_X = 255; // menu text x coordinate for score table
	const float TEXT_COORD_Y = 300; // menu text y coordinate for score table
	const float GAMEOVER_X_COORD = 330; // game over score display x coord
	const float GAMEOVER_COOLDOWN_TIME = 3.f;
	const std::string MAIN_MENU_TEXT = ("Press Arrows \nfor changing direction\n\nPress SPACE to start game");
	const std::string GAME_OVER_TEXT = ("Press SPACE to restart"); // game over text
}
