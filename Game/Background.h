#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Math.h"

namespace ApplesGame
{
	struct Game;

	struct BG
	{
		Position2D position;
		sf::Sprite sprite;
	};

	void InitBG(BG& bg, const sf::Texture& texture);
}
