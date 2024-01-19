#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"

struct Game;

class Apple
{
public:
	Position2D position;
	sf::Sprite sprite;

	void InitApple(const sf::Texture& texture);

	void DrawApple(Apple& apple, sf::RenderWindow& window);
};
