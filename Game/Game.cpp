#include "Game.h"
#include <cassert>

namespace ApplesGame
{
	void InitGame(Game& game)
	{
		assert(game.playerTexture.loadFromFile(IMG_PATH + "Player.png"));
		assert(game.appleTexture.loadFromFile(IMG_PATH + "Apple.png"));
		assert(game.menuTexture.loadFromFile(IMG_PATH + "Wall.png"));
		assert(game.grassTexture.loadFromFile(IMG_PATH + "Grass.png"));
		assert(game.blackTexture.loadFromFile(IMG_PATH + "Black.png"));
		assert(game.nextTexture.loadFromFile(IMG_PATH + "steps.png"));

		// init BG's
		InitBG(game.menuBG, game.menuTexture);
		InitBG(game.fieldBG, game.grassTexture);
		InitBG(game.blackBG, game.blackTexture);
		InitBG(game.nextLevelBG, game.nextTexture);

		// init sounds
		assert(game.deathSnd.buffer.loadFromFile(SND_PATH + "Death.wav"));
		game.deathSnd.sound.setBuffer(game.deathSnd.buffer);
		game.deathSnd.sound.setVolume(30.f);

		assert(game.pickUpSnd.buffer.loadFromFile(SND_PATH + "AppleEat.wav"));
		game.pickUpSnd.sound.setBuffer(game.pickUpSnd.buffer);
		game.pickUpSnd.sound.setVolume(50.f);

		assert(game.selectSND.buffer.loadFromFile(SND_PATH + "Select.wav"));
		game.selectSND.sound.setBuffer(game.selectSND.buffer);
		game.selectSND.sound.setVolume(70.f);

		// init and play menu music
		game.gameMusic.music.openFromFile(SND_PATH + "credits.ogg");
		game.gameMusic.music.play();

		// init game font
		assert(game.font.loadFromFile(FONTS_PATH + "Roboto-Bold.ttf"));

		// init score table text
		game.scoresText.setFont(game.font);
		game.scoresText.setCharacterSize(30);
		game.scoresText.setFillColor(sf::Color::Yellow);
		game.scoresText.setString(MAIN_MENU_TEXT);
		game.scoresText.setPosition(TEXT_COORD_X, TEXT_COORD_Y);

		InitGameMode(game.gameMode);

		// init score table
		game.scoreTable.InitScoreTable(game.playerScore);

		// update last time
		game.pastTime = game.gameTimer.getElapsedTime().asSeconds();
	}

	void DrawTitleScreen(Game& game, sf::RenderWindow& window)
	{
		window.clear();

		window.draw(game.menuBG.sprite);
		window.draw(game.scoresText);

		DrawGameMode(game.gameMode, window);

		window.display();

		HandlePlayerInput(game);
	}

	void ResetApplesArray(Game& game)
	{
		// clear array
		game.apples.clear();

		// reset array size
		game.apples.resize(0);

		// create apples array
		for (int i = 0; i < game.applesCount; i++)
		{
			game.apples.push_back(game.apple);
		}

		// init apples shapes and positions
		for (int i = 0; i < game.applesCount; i++)
		{
			InitApple(game.apples[i], game);
		}
	}

	void RestartGame(Game& game)
	{
		InitPlayer(game.player, game);

		// init random total apples number
		game.applesCount = NUM_APPLES + rand() % NUM_APPLES;

		ResetApplesArray(game);

		// update game score table
		game.playerScore = 0;
		game.scoresText.setPosition(SCORE_XCOR, SCORE_YCOR);
		game.scoresText.setString(game.score + std::to_string(game.playerScore));

		// update game variables
		game.gameState = GameState::Game;
		game.pastTime = game.gameTimer.getElapsedTime().asSeconds();

		// init and play game music
		game.gameMusic.music.openFromFile(SND_PATH + "level5.ogg");
		game.gameMusic.music.play();
	}

	void ChangeLevel(Game& game)
	{
		InitPlayer(game.player, game);

		// init random total apples number
		game.applesCount = NUM_APPLES + rand() % NUM_APPLES;

		ResetApplesArray(game);

		// update game scores
		game.scoresText.setPosition(SCORE_XCOR, SCORE_YCOR);
		game.scoresText.setString(game.score + std::to_string(game.playerScore));

		// update game variables
		game.gameState = GameState::Game;
		game.pastTime = game.gameTimer.getElapsedTime().asSeconds();

		// init and play game music
		game.gameMusic.music.openFromFile(SND_PATH + "level5.ogg");
		game.gameMusic.music.play();
	}

	void HandlePlayerInput(Game& game)
	{
		switch (game.gameState)
		{
		case GameState::Menu:
		{
			game.newTime = game.gameTimer.getElapsedTime().asSeconds();

			if (game.newTime - game.pastTime > MENU_BUTTON_COOLDOWN)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					RestartGame(game);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
				{
					ChangeMode(game.gameMode, 0);

					// play select sound
					game.selectSND.sound.play();

					// note the time
					game.pastTime = game.newTime;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
				{
					ChangeMode(game.gameMode, 1);

					// play select sound
					game.selectSND.sound.play();

					// note the time
					game.pastTime = game.newTime;
				}
			}
			break;
		}
		case GameState::Game:
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				game.player.direction = PlayerDirection::Right;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				game.player.direction = PlayerDirection::Up;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				game.player.direction = PlayerDirection::Left;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				game.player.direction = PlayerDirection::Down;
			}
			break;
		}
		case GameState::GameOver:
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				// update score text
				game.scoresText.setString(MAIN_MENU_TEXT);
				game.scoresText.setPosition(TEXT_COORD_X, TEXT_COORD_Y);

				// init and play menu music
				game.gameMusic.music.openFromFile(SND_PATH + "credits.ogg");
				game.gameMusic.music.play();

				// change game state
				game.gameState = GameState::Menu;

				game.pastTime = game.gameTimer.getElapsedTime().asSeconds();
			}
			break;
		}
		default:
			break;
		}
	}

	void CheckCollisionWithBorders(Game& game)
	{
		if (isCollideWithBorders(game.player.position))
		{
			// update score table
			game.scoreTable.UpdateScoreTable(game.playerScore);

			// note the time
			game.pastTime = game.gameTimer.getElapsedTime().asSeconds();

			// change game state
			game.gameState = GameState::GameOver;

			// stop music
			game.gameMusic.music.stop();

			// play death snd
			game.deathSnd.sound.play();
		}
	}

	void CheckCollisionWithApples(Game& game, const float deltaTime)
	{
		// check player collision with apples
		for (auto i = game.apples.begin(); i != game.apples.end();)
		{
			Apple& apple = *i;
			if (IsCollideWithApple(game.player.position, PLAYER_SIZE / 2.f, apple.position, APPLE_SIZE / 2.f))
			{
				// check apples option
				if (game.gameMode.mode & (1 << 0))
				{
					// respawn aplle in new coordinates
					apple.position = GetRandomPositionInScreen(SCREEN_WIDTH, SCREEN_HEIGHT, OFFSET);
					apple.sprite.setPosition(apple.position.x, apple.position.y);
				}
				else
				{
					i = game.apples.erase(i);
				}

				// count player scores
				++game.playerScore;
				game.scoresText.setString(game.score + std::to_string(game.playerScore));

				// increase the player's speed if option is enable
				if (game.gameMode.mode & (1 << 1))
				{
					game.player.speed += ACCELERATION * deltaTime;
				}

				// play pickup snd
				game.pickUpSnd.sound.play();
			}
			else
			{
				i++;
			}
		}
	}

	void CheckRemainingApples(Game& game)
	{
		if (game.apples.size() == 0)
		{
			// update score table
			game.scoreTable.UpdateScoreTable(game.playerScore);

			// update score text
			game.scoresText.setPosition(TEXT_COORD_X, TEXT_COORD_Y);
			game.scoresText.setString(NEXT_LEVEL);

			// note the time
			game.pastTime = game.gameTimer.getElapsedTime().asSeconds();

			// change game state
			game.gameState = GameState::NextLevel;

			// stop music
			game.gameMusic.music.stop();
		}
	}

	void UpdateGame(Game& game, const float deltaTime, sf::RenderWindow& window)
	{
		HandlePlayerInput(game);

		UpdatePlayer(game, deltaTime);

		CheckCollisionWithBorders(game);

		CheckCollisionWithApples(game, deltaTime);

		CheckRemainingApples(game);
	}

	void DrawGame(Game& game, sf::RenderWindow& window)
	{
		window.clear();

		window.draw(game.fieldBG.sprite);
		DrawPlayer(game.player, window);

		for (auto& apple : game.apples)
		{
			DrawApple(apple, window);
		}

		window.draw(game.scoresText);

		window.display();
	}

	void TransitionToNextLevel(Game& game, sf::RenderWindow& window)
	{
		// update newTime timer
		game.newTime = game.gameTimer.getElapsedTime().asSeconds();

		window.clear();

		window.draw(game.nextLevelBG.sprite);
		window.draw(game.scoresText);

		window.display();

		// check that enough time has passed
		if (game.newTime - game.pastTime > NEXT_LEVEL_COOLDOWN)
		{
			ChangeLevel(game);
		}
	}

	void DrawGameOver(Game& game, sf::RenderWindow& window)
	{
		// update newTime timer
		game.newTime = game.gameTimer.getElapsedTime().asSeconds();

		window.clear();

		window.draw(game.blackBG.sprite);

		DrawScoreTable(game, window, game.scoreTable.xcor, game.scoreTable.ycor);

		window.display();
		
		HandlePlayerInput(game);
	}

	void DeinitializeGame(Game& gameState) {}
}
