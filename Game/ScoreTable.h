#pragma once
#include <SFML/Graphics.hpp>

class Game;

struct TableRow
{
	std::string name;
	int score;
};

class ScoreTable
{
public:
	sf::RectangleShape highlighter;

	std::vector<TableRow> data;

	float xcor = 280.f;
	float ycor = 250.f;

	void InitScoreTable(const int playerScore);

	void UpdateScoreTable(const int playerScore);

	void DrawScoreTable(sf::Text& scoresText, sf::RenderWindow& window, float xcor, float ycor);
};
