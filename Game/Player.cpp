#include "Player.h"
#include "Game.h"

void Player::InitPlayer(const sf::Texture& texture)
{
	// init player state
	position = { SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f };
	speed = INITIAL_SPEED;
	direction = PlayerDirection::Right;

	// init player sprite
	sprite.setTexture(texture);
	SetSpriteSize(sprite, PLAYER_SIZE, PLAYER_SIZE);
	SetSpriteRelationOrigin(sprite, 0.5f, 0.5f);
}

void Player::UpdatePlayer(const float deltaTime)
{
	switch (direction)
	{
	case PlayerDirection::Right:
	{
		position.x += speed * deltaTime;
		break;
	}
	case PlayerDirection::Up:
	{
		position.y -= speed * deltaTime;
		break;
	}
	case PlayerDirection::Left:
	{
		position.x -= speed * deltaTime;
		break;
	}
	case PlayerDirection::Down:
	{
		position.y += speed * deltaTime;
		break;
	}
	default:
		break;
	}
}

void Player::HandlePlayerInput(Game& game)
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
				game.gameMode.ChangeMode(0);

				// play select sound
				game.selectSND.sound.play();

				// note the time
				game.pastTime = game.newTime;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
			{
				game.gameMode.ChangeMode(1);

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
			game.gameMusic.PlayMusic(SND_PATH + "credits.ogg");

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

void Player::DrawPlayer(sf::RenderWindow& window)
{
	sprite.setPosition(position.x, position.y);

	// get sprite size and scale
	const sf::Vector2u textureSize = sprite.getTexture()->getSize();
	const sf::Vector2f spriteScale = { PLAYER_SIZE / textureSize.x, PLAYER_SIZE / textureSize.y };

	// rotate player sprite
	switch (direction)
	{
	case PlayerDirection::Right:
	{
		sprite.setRotation(0.f);
		sprite.setScale(spriteScale.x, spriteScale.y);
		break;
	}
	case PlayerDirection::Up:
	{
		sprite.setRotation(-90.f);
		sprite.setScale(spriteScale.x, spriteScale.y);
		break;
	}
	case PlayerDirection::Left:
	{
		sprite.setRotation(0.f);
		sprite.setScale(-spriteScale.x, spriteScale.y);
		break;
	}
	case PlayerDirection::Down:
	{
		sprite.setRotation(90.f);
		sprite.setScale(spriteScale.x, spriteScale.y);
		break;
	}
	default:
		break;
	}

	window.draw(sprite);
}
