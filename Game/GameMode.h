#pragma once
#include <SFML\Graphics.hpp>

class GameMode
{
public:
	int mode = 0;

	sf::Font modeFont;

	sf::Text modePopup;
	sf::Text modeOne;
	sf::Text modeTwo;

	void InitGameMode(sf::Font& font);

	void ChangeMode(int bit);

	void UpdateGameMode();

	void DrawGameMode(sf::RenderWindow& window);
};
