#pragma once
#include "Constants.h"

namespace sf
{
	class Sprite;
}

namespace ApplesGame
{
	struct Vector2D
	{
		float x = 0;
		float y = 0;
	};

	typedef Vector2D Position2D;

	Position2D GetRandomPositionInScreen(int screenWidth, int screenHeight, const int offset);

	bool IsCollideWithApple(Position2D circle1Pos, float circle1Rad, Position2D circle2Pos, float circle2Rad);

	bool isCollideWithBorders(Position2D Pos);

	void SetSpriteSize(sf::Sprite& sprite, float desiredWidth, float desiredHeight);

	void SetSpriteRelationOrigin(sf::Sprite& sprite, float originX, float originY);
}
