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
	}
}

int main()
{
	// init randomizer with random seed
	srand(static_cast<int>(time(NULL)));

	// init window
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Apples game!");

	// game initialization
	Game game;
	game.InitGame(game);

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
			game.DrawTitleScreen(game, window);
			break;
		}
		case GameState::Game:
		{
			game.UpdateGame(game, deltaTime, window);
			game.DrawGame(game, window);
			break;
		}
		case GameState::GameOver:
		{
			game.DrawGameOver(game, window);
			break;
		}
		case GameState::NextLevel:
		{
			game.TransitionToNextLevel(game, window);
			break;
		}
		case GameState::ExitDialog:
		{
			game.DrawExitDialog(game, window);
			break;
		}
		default:
			break;
		}
	}

	// deinitialization
	game.DeinitializeGame(game);

	return 0;
}
