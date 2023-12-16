#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "Constants.h"

namespace ApplesGame
{
	struct Game;

	enum class PlayerDirection
	{
		Right = 0,
		Up,
		Left,
		Down
	};

	struct Player
	{
		Position2D position;
		float speed = INITIAL_SPEED;
		PlayerDirection direction = PlayerDirection::Right;
		sf::Sprite sprite;
	};

	void InitPlayer(Player& player, const Game& game);

	void UpdatePlayer(Game& game, const float deltaTime);

	void DrawPlayer(Player& player, sf::RenderWindow& window);
}
