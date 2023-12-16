#include "Game.h"
#include <cassert>
#include <iostream>

namespace ApplesGame
{
	void InitGame(Game& game)
	{
		assert(game.playerTexture.loadFromFile(IMG_PATH + "Player.png"));
		assert(game.appleTexture.loadFromFile(IMG_PATH + "Apple.png"));
		assert(game.menuTexture.loadFromFile(IMG_PATH + "Wall.png"));
		assert(game.grassTexture.loadFromFile(IMG_PATH + "Grass.png"));
		assert(game.blackTexture.loadFromFile(IMG_PATH + "Black.png"));

		// init BG's
		InitBG(game.menuBG, game.menuTexture);
		InitBG(game.fieldBG, game.grassTexture);
		InitBG(game.blackBG, game.blackTexture);

		// init sounds
		game.deathSnd.buffer.loadFromFile(SND_PATH + "Death.wav");
		game.deathSnd.sound.setBuffer(game.deathSnd.buffer);
		game.deathSnd.sound.setVolume(30.f);
		game.pickUpSnd.buffer.loadFromFile(SND_PATH + "AppleEat.wav");
		game.pickUpSnd.sound.setBuffer(game.pickUpSnd.buffer);
		game.pickUpSnd.sound.setVolume(50.f);

		// init and play menu music
		game.gameMusic.music.openFromFile(SND_PATH + "credits.ogg");
		game.gameMusic.music.play();

		// init game font
		game.font.loadFromFile(FONTS_PATH + "Roboto-Bold.ttf");

		game.scoreTable.setFont(game.font);
		game.scoreTable.setCharacterSize(30);
		game.scoreTable.setFillColor(sf::Color::Yellow);
		game.scoreTable.setString(MAIN_MENU_TEXT);
		game.scoreTable.setPosition(TEXT_COORD_X, TEXT_COORD_Y);
	}

	void DrawTitleScreen(Game& game, sf::RenderWindow& window)
	{
		window.clear();

		window.draw(game.menuBG.sprite);
		window.draw(game.scoreTable);

		window.display();

		HandlePlayerInput(game);
	}

	void RestartGame(Game& game)
	{
		InitPlayer(game.player, game);

		// init apples shapes and positions
		for (int i = 0; i < NUM_APPLES; i++)
		{
			InitApple(game.apples[i], game);
		}

		// update game score table
		game.playerScore = 0;
		game.scoreTable.setPosition(TABLE_X, TABLE_Y);
		game.scoreTable.setString(game.score + std::to_string(game.playerScore));

		// init game over varianles
		game.gameState = GameState::Game;
		game.last_time = game.gameoverTimer.getElapsedTime().asSeconds();

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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				RestartGame(game);
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
		default:
			break;
		}
	}

	void UpdateGame(Game& game, const float deltaTime, sf::RenderWindow& window)
	{
		HandlePlayerInput(game);

		UpdatePlayer(game, deltaTime);

		// check collision with screen borders
		if (isCollideWithBorders(game.player.position))
		{
			// stop game and update score table with game over text
			game.scoreTable.setPosition(GAMEOVER_X_COORD, TEXT_COORD_Y);
			game.last_time = game.gameoverTimer.getElapsedTime().asSeconds();
			game.gameState = GameState::GameOver;

			// stop music
			game.gameMusic.music.stop();

			// play death snd
			game.deathSnd.sound.play();
		}

		// check player collision with apples
		for (auto& apple : game.apples)
		{
			if (IsCollideWithApple(game.player.position, PLAYER_SIZE / 2.f, apple.position, APPLE_SIZE / 2.f))
			{
				// respawn aplle in new coordinates
				apple.position = GetRandomPositionInScreen(SCREEN_WIDTH, SCREEN_HEIGHT, OFFSET);
				apple.sprite.setPosition(apple.position.x, apple.position.y);

				// count player scores
				++game.playerScore;
				game.scoreTable.setString(game.score + std::to_string(game.playerScore));

				// increase the player's speed
				game.player.speed += ACCELERATION * deltaTime;

				// play pickup snd
				game.pickUpSnd.sound.play();
			}
		}
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

		window.draw(game.scoreTable);

		window.display();
	}

	void DrawGameOver(Game& game, sf::RenderWindow& window)
	{
		// update gameover timer
		game.current_time = game.gameoverTimer.getElapsedTime().asSeconds();

		window.clear();

		window.draw(game.blackBG.sprite);
		window.draw(game.scoreTable);

		window.display();

		if (game.current_time - game.last_time > GAMEOVER_COOLDOWN_TIME)
		{
			// update score text
			game.scoreTable.setString(MAIN_MENU_TEXT);
			game.scoreTable.setPosition(TEXT_COORD_X, TEXT_COORD_Y);

			// init and play menu music
			game.gameMusic.music.openFromFile(SND_PATH + "credits.ogg");
			game.gameMusic.music.play();

			// change game state
			game.gameState = GameState::Menu;
		}
	}

	void DeinitializeGame(Game& gameState) {}
}
