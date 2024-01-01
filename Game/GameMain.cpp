#include <SFML/Graphics.hpp>
#include <time.h>
#include "Game.h"

void HandleWindowEvents(sf::RenderWindow& window)
{
	// read events
	sf::Event event;

	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		{
			window.close();
		}
	}
}

int main()
{
	using namespace ApplesGame;

	// init randomizer with random seed
	srand((int)time(NULL));

	// init window
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Apples game!");

	// game initialization
	Game game;
	InitGame(game);

	// init game timer
	sf::Clock gameClock;
	float lastTime = gameClock.getElapsedTime().asSeconds();

	// main loop
	while (window.isOpen())
	{
		// calculate the delta
		const float currentrTime = gameClock.getElapsedTime().asSeconds();
		const float deltaTime = currentrTime - lastTime;
		lastTime = currentrTime;

		HandleWindowEvents(window);

		// check game state
		switch (game.gameState)
		{
		case GameState::Menu:
		{
			DrawTitleScreen(game, window);
			break;
		}
		case GameState::Game:
		{
			UpdateGame(game, deltaTime, window);
			DrawGame(game, window);
			break;
		}
		case GameState::GameOver:
		{
			DrawGameOver(game, window);
			break;
		}
		case GameState::NextLevel:
		{
			TransitionToNextLevel(game, window);
			break;
		}
		default:
			break;
		}
	}

	// deinitialization
	DeinitializeGame(game);

	return 0;
}
