#include "Apple.h"
#include "Game.h"

void InitApple(Apple& apple, const Game& game)
{
	apple.position = GetRandomPositionInScreen(SCREEN_WIDTH, SCREEN_HEIGHT, OFFSET);

	// init apple sprite
	apple.sprite.setTexture(game.appleTexture);
	SetSpriteSize(apple.sprite, APPLE_SIZE, APPLE_SIZE);
	SetSpriteRelationOrigin(apple.sprite, 0.5f, 0.5f);
}

void DrawApple(Apple& apple, sf::RenderWindow& window)
{
	apple.sprite.setPosition(apple.position.x, apple.position.y);
	window.draw(apple.sprite);
}
