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
	const float NEXT_LEVEL_COOLDOWN = 3.f;
	const float MENU_BUTTON_COOLDOWN = 0.3f;
	const int MAX_RAND_SCORE = 100;
	const int TABLE_ROWS = 9;

	// init text coordinates
	const int OFFSET = 20;
	const float SCORE_XCOR = SCREEN_WIDTH / 2.f - 70.f; // score table x coordinate
	const float SCORE_YCOR = 5.f; // score table y coordinate
	const float TABLE_INDENT = 200.f;
	const float TABLE_STEP = 30.f;
	const float TEXT_COORD_X = 255.f; // menu text x coordinate for score table
	const float TEXT_COORD_Y = 250.f; // menu text y coordinate for score table
	const float GAMEOVER_X_COORD = 330; // game over score display x coord
	const float POPUP_X_COORD = 160.f;
	const float POPUP_Y_COORD = 430.f;
	const float FIRST_X_COORD = 50.f;
	const float FIRST_Y_COORD = 500.f;
	const float SECOND_X_COORD = 450.f;
	const float SECOND_Y_COORD = 500.f;

	//  init all game texts
	const std::string MAIN_MENU_TEXT = ("Press Arrows \nfor changing direction\n\nPress SPACE to start");
	const std::string OPTIONS_POPUP = ("\tKeys 1 and 2 for switch MODE:");
	const std::string FIRST_OPTION_ON = ("Infinite apples - ON");
	const std::string FIRST_OPTION_OFF = ("Infinite apples - OFF");
	const std::string SECOND_OPTION_ON = ("Player acceleration - ON");
	const std::string SECOND_OPTION_OFF = ("Player acceleration - OFF");
	const std::string PLAYER_NAME = ("Player");
	const std::string NAMES[] = { "Omega", "Rico", "Micro", "Alpha", "CyBot", "Pilot", "Cassandra", "Blossom", "Otto", //
		"Duster", "Kronos", "Ultron", "Blade", "Eyebot", "Agnes", "Zen", "Automata", "Olympus", "Titan", "Cerberus" };
}
