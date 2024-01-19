#include "Player.h"
#include "Game.h"

void InitPlayer(Player& player, const Game& game)
{
	// init player state
	player.position = { SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f };
	player.speed = INITIAL_SPEED;
	player.direction = PlayerDirection::Right;

	// init player sprite
	player.sprite.setTexture(game.playerTexture);
	SetSpriteSize(player.sprite, PLAYER_SIZE, PLAYER_SIZE);
	SetSpriteRelationOrigin(player.sprite, 0.5f, 0.5f);
}

void UpdatePlayer(Game& game, const float deltaTime)
{
	switch (game.player.direction)
	{
	case PlayerDirection::Right:
	{
		game.player.position.x += game.player.speed * deltaTime;
		break;
	}
	case PlayerDirection::Up:
	{
		game.player.position.y -= game.player.speed * deltaTime;
		break;
	}
	case PlayerDirection::Left:
	{
		game.player.position.x -= game.player.speed * deltaTime;
		break;
	}
	case PlayerDirection::Down:
	{
		game.player.position.y += game.player.speed * deltaTime;
		break;
	}
	default:
		break;
	}
}

void DrawPlayer(Player& player, sf::RenderWindow& window)
{
	player.sprite.setPosition(player.position.x, player.position.y);

	// get sprite size and scale
	const sf::Vector2u textureSize = player.sprite.getTexture()->getSize();
	const sf::Vector2f spriteScale = { PLAYER_SIZE / textureSize.x, PLAYER_SIZE / textureSize.y };

	// rotate player sprite
	switch (player.direction)
	{
	case PlayerDirection::Right:
	{
		player.sprite.setRotation(0.f);
		player.sprite.setScale(spriteScale.x, spriteScale.y);
		break;
	}
	case PlayerDirection::Up:
	{
		player.sprite.setRotation(-90.f);
		player.sprite.setScale(spriteScale.x, spriteScale.y);
		break;
	}
	case PlayerDirection::Left:
	{
		player.sprite.setRotation(0.f);
		player.sprite.setScale(-spriteScale.x, spriteScale.y);
		break;
	}
	case PlayerDirection::Down:
	{
		player.sprite.setRotation(90.f);
		player.sprite.setScale(spriteScale.x, spriteScale.y);
		break;
	}
	default:
		break;
	}

	window.draw(player.sprite);
}
