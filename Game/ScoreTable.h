#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"

namespace ApplesGame
{
	struct Game;

	struct TableRow
	{
		std::string name;
		int score;
	};

	struct ScoreTable
	{
		std::vector<TableRow> data;
		int SCORE_TABLE_XCOR = 100.f;
		int SCORE_TABLE_YCOR = 200.f;

		void InitScoreTable(const int playerScore);

		void UpdateScoreTable(const int playerScore);
	};

	void DrawScoreTable(Game& game, sf::RenderWindow& window);
}