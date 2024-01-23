#include "GameMode.h"
#include "Constants.h"

void GameMode::InitGameMode(sf::Font& font)
{
	// switch all modes on
	mode = mode | 1 << 0;
	mode = mode | 1 << 1;

	// init game font
	modeFont.loadFromFile(FONTS_PATH + "Roboto-Bold.ttf");

	// init mode texts
	modePopup.setFont(modeFont);
	modePopup.setCharacterSize(BIG_TEXT);
	modePopup.setFillColor(sf::Color::Yellow);
	modePopup.setString(OPTIONS_POPUP);
	modePopup.setPosition(POPUP_X_COORD, POPUP_Y_COORD);

	modeOne.setFont(modeFont);
	modeOne.setCharacterSize(OPTION_TEXT);
	modeOne.setFillColor(sf::Color::Green);
	modeOne.setString(FIRST_OPTION_ON);
	modeOne.setPosition(FIRST_X_COORD, FIRST_Y_COORD);

	modeTwo.setFont(modeFont);
	modeTwo.setCharacterSize(OPTION_TEXT);
	modeTwo.setFillColor(sf::Color::Green);
	modeTwo.setString(SECOND_OPTION_ON);
	modeTwo.setPosition(SECOND_X_COORD, SECOND_Y_COORD);
}

void GameMode::ChangeMode(int bit)
{
	mode = mode ^ 1 << bit;

	UpdateGameMode();
}

void GameMode::UpdateGameMode()
{
	if (mode & (1 << 0))
	{
		modeOne.setString(FIRST_OPTION_ON);
		modeOne.setFillColor(sf::Color::Green);
	}
	else
	{
		modeOne.setString(FIRST_OPTION_OFF);
		modeOne.setFillColor(sf::Color::Red);
	}

	if (mode & (1 << 1))
	{
		modeTwo.setString(SECOND_OPTION_ON);
		modeTwo.setFillColor(sf::Color::Green);
	}
	else
	{
		modeTwo.setString(SECOND_OPTION_OFF);
		modeTwo.setFillColor(sf::Color::Red);
	}
}

void GameMode::DrawGameMode(sf::RenderWindow& window)
{
	window.draw(modePopup);
	window.draw(modeOne);
	window.draw(modeTwo);
}
