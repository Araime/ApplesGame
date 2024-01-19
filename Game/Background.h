#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"

class BG
{
public:
	Position2D position;
	sf::Sprite sprite;

	void InitBG(const sf::Texture& texture);
};
