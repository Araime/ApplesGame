#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "Player.h"
#include "Constants.h"
#include "Apple.h"
#include "Background.h"
#include "Sound.h"

namespace ApplesGame
{
	enum class GameState
	{
		Menu = 0,
		Game,
		GameOver
	};

	struct Game
	{
		// init game state
		GameState gameState = GameState::Menu;

		// game over timer
		sf::Clock gameoverTimer;
		float current_time = 0.f;
		float last_time = 0.f;

		// create BG's
		BG menuBG;
		BG fieldBG;
		BG blackBG;

		// create sounds and music
		Sound pickUpSnd;
		Sound deathSnd;
		Music gameMusic;

		// create player and apples array
		Player player;
		Apple apples[NUM_APPLES];

		// init scores
		int playerScore = 0;

		// create score table
		std::string score = "SCORE: ";
		sf::Font font;
		sf::Text scoreTable;

		// create textures
		sf::Texture playerTexture;
		sf::Texture appleTexture;
		sf::Texture menuTexture;
		sf::Texture grassTexture;
		sf::Texture blackTexture;
	};

	void InitGame(Game& game);

	void DrawTitleScreen(Game& game, sf::RenderWindow& window);

	void RestartGame(Game& game);

	void HandlePlayerInput(Game& game);

	void UpdateGame(Game& game, const float deltaTime, sf::RenderWindow& window);

	void DrawGame(Game& game, sf::RenderWindow& window);

	void DrawGameOver(Game& game, sf::RenderWindow& window);

	void DeinitializeGame(Game& gameState);
}
