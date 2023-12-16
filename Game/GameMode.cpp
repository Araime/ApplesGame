#include "GameMode.h"

namespace ApplesGame
{
	void InitGameMode(GameMode& gameMode)
	{
		// switch all modes on
		gameMode.mode = gameMode.mode | 1 << 1;
		gameMode.mode = gameMode.mode | 1 << 2;

		// init game font
		gameMode.modeFont.loadFromFile(FONTS_PATH + "Roboto-Bold.ttf");

		// init mode texts
		gameMode.modePopup.setFont(gameMode.modeFont);
		gameMode.modePopup.setCharacterSize(30);
		gameMode.modePopup.setFillColor(sf::Color::Yellow);
		gameMode.modePopup.setString(OPTIONS_POPUP);
		gameMode.modePopup.setPosition(TEXT_COORD_X, TEXT_COORD_Y);

		gameMode.modePopup.setFont(gameMode.modeFont);
		gameMode.modePopup.setCharacterSize(25);
		gameMode.modePopup.setFillColor(sf::Color::Red);
		gameMode.modePopup.setString(FIRST_OPTION_ON);
		gameMode.modePopup.setPosition(TEXT_COORD_X, TEXT_COORD_Y);

		gameMode.modePopup.setFont(gameMode.modeFont);
		gameMode.modePopup.setCharacterSize(25);
		gameMode.modePopup.setFillColor(sf::Color::Red);
		gameMode.modePopup.setString(SECOND_OPTION_ON);
		gameMode.modePopup.setPosition(TEXT_COORD_X, TEXT_COORD_Y);
	}
}