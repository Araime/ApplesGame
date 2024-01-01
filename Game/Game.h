#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "Player.h"
#include "Constants.h"
#include "Apple.h"
#include "Background.h"
#include "Sound.h"
#include "GameMode.h"
#include "ScoreTable.h"

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

		// init game over timer handlers
		sf::Clock gameTimer;
		float newTime = 0.f;
		float pastTime = 0.f;

		// init scores
		int playerScore = 0;

		// init apples variable
		int applesCount = 1;

		// create BG's
		BG menuBG;
		BG fieldBG;
		BG blackBG;

		// create sounds and music
		Sound pickUpSnd;
		Sound deathSnd;
		Sound selectSND;
		Sound unselectSND;
		Music gameMusic;

		// create player
		Player player;

		// create apple and apples array
		Apple apple;
		std::vector<Apple> apples;

		// create score table
		std::string score = "SCORE: ";
		sf::Font font;
		sf::Text scores;

		// create game mode
		GameMode gameMode;

		// create textures
		sf::Texture playerTexture;
		sf::Texture appleTexture;
		sf::Texture menuTexture;
		sf::Texture grassTexture;
		sf::Texture blackTexture;

		ScoreTable scoreTable;
	};

	void InitGame(Game& game);

	void DrawTitleScreen(Game& game, sf::RenderWindow& window);

	void ResetApplesArray(Game& game);

	void RestartGame(Game& game);

	void HandlePlayerInput(Game& game);

	void CheckCollisionWithBorders(Game& game);

	void CheckCollisionWithApples(Game& game, const float deltaTime);

	void CheckRemainingApples(Game& game);

	void UpdateGame(Game& game, const float deltaTime, sf::RenderWindow& window);

	void DrawGame(Game& game, sf::RenderWindow& window);

	void DrawGameOver(Game& game, sf::RenderWindow& window);

	void DeinitializeGame(Game& gameState);
}
