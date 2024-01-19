#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"

struct Game;

struct TableRow
{
	std::string name;
	int score;
};

struct ScoreTable
{
	sf::RectangleShape highlighter;

	std::vector<TableRow> data;
	float xcor = 280.f;
	float ycor = 250.f;

	void InitScoreTable(const int playerScore);

	void UpdateScoreTable(const int playerScore);
};

void DrawScoreTable(Game& game, sf::RenderWindow& window, float xcor, float ycor);
