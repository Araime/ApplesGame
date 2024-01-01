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
	};

	void InitScoreTable(Game& game);

	void UpdateScoreTable();

	void DrawScoreTable();
}

//std::sort(std::begin(data), std::end(data), [](const Data& a, const Data& b) { return a.x_ < b.x_; });