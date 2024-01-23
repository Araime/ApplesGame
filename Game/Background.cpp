#include "Background.h"
#include "Constants.h"

void BG::InitBG(const sf::Texture& texture)
{
	sprite.setTexture(texture);
	SetSpriteSize(sprite, static_cast<float>(SCREEN_WIDTH), static_cast<float>(SCREEN_HEIGHT));
	sprite.setPosition(0.f, 0.f);
}
