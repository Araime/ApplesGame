#include "Math.h"
#include <stdlib.h>
#include <SFML/Graphics.hpp>

namespace ApplesGame
{
	Position2D GetRandomPositionInScreen(int screenWidth, int screenHeight, const int offset)
	{
		Position2D result;
		result.x = offset + rand() / float(RAND_MAX) * (screenWidth - offset * 2);
		result.y = offset + rand() / float(RAND_MAX) * (screenHeight - offset * 2);
		return result;
	}

	bool IsCollideWithApple(Position2D circle1Pos, float circle1Rad, Position2D circle2Pos, float circle2Rad)
	{
		const float squareDistance = (circle1Pos.x - circle2Pos.x) *
			(circle1Pos.x - circle2Pos.x) +
			(circle1Pos.y - circle2Pos.y) *
			(circle1Pos.y - circle2Pos.y);
		const float squareRadiusSum = (circle1Rad + circle2Rad) * (circle1Rad + circle2Rad);
		return squareDistance <= squareRadiusSum;
	}

	bool isCollideWithBorders(Position2D Pos)
	{
		return (Pos.x - PLAYER_SIZE / 2.f < 0.f ||
				Pos.x - PLAYER_SIZE / 2.f > SCREEN_WIDTH - OFFSET ||
				Pos.y - PLAYER_SIZE / 2.f < 0.f ||
				Pos.y - PLAYER_SIZE / 2.f > SCREEN_HEIGHT - OFFSET);
	}

	void SetSpriteSize(sf::Sprite& sprite, float desiredWidth, float desiredHeight)
	{
		sf::FloatRect spriteRect = sprite.getLocalBounds();
		sf::Vector2f scale = { desiredWidth / spriteRect.width, desiredHeight / spriteRect.height };
		sprite.setScale(scale);
	}

	void SetSpriteRelationOrigin(sf::Sprite& sprite, float originX, float originY)
	{
		sf::FloatRect spriteRect = sprite.getLocalBounds();
		sprite.setOrigin(originX * spriteRect.width, originY * spriteRect.height);
	}
}
