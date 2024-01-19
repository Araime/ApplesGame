#pragma once
#include <SFML\Graphics.hpp>
#include "Constants.h"

struct GameMode
{
	int mode = 0;

	sf::Font modeFont;

	sf::Text modePopup;
	sf::Text modeOne;
	sf::Text modeTwo;
};

void InitGameMode(GameMode& gameMode);

void ChangeMode(GameMode& gameMode, int bit);

void UpdateGameMode(GameMode& gameMode);

void DrawGameMode(GameMode& gameMode, sf::RenderWindow& window);
