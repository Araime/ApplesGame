#include "Apple.h"
#include "Constants.h"

void Apple::InitApple(const sf::Texture& texture)
{
	position = GetRandomPositionInScreen(SCREEN_WIDTH, SCREEN_HEIGHT, OFFSET);

	// init apple sprite
	sprite.setTexture(texture);
	SetSpriteSize(sprite, APPLE_SIZE, APPLE_SIZE);
	SetSpriteRelationOrigin(sprite, 0.5f, 0.5f);
}

void Apple::DrawApple(Apple& apple, sf::RenderWindow& window)
{
	apple.sprite.setPosition(apple.position.x, apple.position.y);
	window.draw(apple.sprite);
}
