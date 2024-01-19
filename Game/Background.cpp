#include "Background.h"
#include "Constants.h"

void BG::InitBG(const sf::Texture& texture)
{
	sprite.setTexture(texture);
	SetSpriteSize(sprite, float(SCREEN_WIDTH), float(SCREEN_HEIGHT));
	sprite.setPosition(0.f, 0.f);
}
