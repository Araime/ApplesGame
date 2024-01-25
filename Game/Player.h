#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "Constants.h"

class Game;

enum class PlayerDirection
{
	Right = 0,
	Up,
	Left,
	Down
};

class Player
{
public:
	Position2D position;
	float speed = INITIAL_SPEED;
	PlayerDirection direction = PlayerDirection::Right;
	sf::Sprite sprite;

	void InitPlayer(const sf::Texture& texture);

	void UpdatePlayer(const float deltaTime);

	void HandlePlayerInput(Game& game, sf::RenderWindow& window);

	void DrawPlayer(sf::RenderWindow& window);
};
