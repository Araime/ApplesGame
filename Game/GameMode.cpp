#include "GameMode.h"

namespace ApplesGame
{
	void InitGameMode(GameMode& gameMode)
	{
		// switch all modes on
		gameMode.mode = gameMode.mode | 1 << 0;
		gameMode.mode = gameMode.mode | 1 << 1;

		// init game font
		gameMode.modeFont.loadFromFile(FONTS_PATH + "Roboto-Bold.ttf");

		// init mode texts
		gameMode.modePopup.setFont(gameMode.modeFont);
		gameMode.modePopup.setCharacterSize(30);
		gameMode.modePopup.setFillColor(sf::Color::Yellow);
		gameMode.modePopup.setString(OPTIONS_POPUP);
		gameMode.modePopup.setPosition(POPUP_X_COORD, POPUP_Y_COORD);

		gameMode.modeOne.setFont(gameMode.modeFont);
		gameMode.modeOne.setCharacterSize(25);
		gameMode.modeOne.setFillColor(sf::Color::Red);
		gameMode.modeOne.setString(FIRST_OPTION_ON);
		gameMode.modeOne.setPosition(FIRST_X_COORD, FIRST_Y_COORD);

		gameMode.modeTwo.setFont(gameMode.modeFont);
		gameMode.modeTwo.setCharacterSize(25);
		gameMode.modeTwo.setFillColor(sf::Color::Red);
		gameMode.modeTwo.setString(SECOND_OPTION_ON);
		gameMode.modeTwo.setPosition(SECOND_X_COORD, SECOND_Y_COORD);
	}

	void ChangeMode(GameMode& gameMode, int bit)
	{
		gameMode.mode = gameMode.mode ^ 1 << bit;

		UpdateGameMode(gameMode);
	}

	void UpdateGameMode(GameMode& gameMode)
	{
		if (gameMode.mode & (1 << 0))
		{
			gameMode.modeOne.setString(FIRST_OPTION_ON);
			gameMode.modeOne.setFillColor(sf::Color::Red);
		}
		else
		{
			gameMode.modeOne.setString(FIRST_OPTION_OFF);
			gameMode.modeOne.setFillColor(sf::Color::Magenta);
		}

		if (gameMode.mode & (1 << 1))
		{
			gameMode.modeTwo.setString(SECOND_OPTION_ON);
			gameMode.modeTwo.setFillColor(sf::Color::Red);
		}
		else
		{
			gameMode.modeTwo.setString(SECOND_OPTION_OFF);
			gameMode.modeTwo.setFillColor(sf::Color::Magenta);
		}
	}

	void DrawGameMode(GameMode& gameMode, sf::RenderWindow& window)
	{
		window.draw(gameMode.modePopup);
		window.draw(gameMode.modeOne);
		window.draw(gameMode.modeTwo);
	}
}