#include "Background.h"
#include "Game.h"

namespace ApplesGame
{
	void InitBG(BG& bg, const sf::Texture& texture)
	{
		bg.sprite.setTexture(texture);
		SetSpriteSize(bg.sprite, float(SCREEN_WIDTH), float(SCREEN_HEIGHT));
		bg.sprite.setPosition(0.f, 0.f);
	}
}
