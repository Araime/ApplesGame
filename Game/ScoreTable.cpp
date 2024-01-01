#include<algorithm>
#include "ScoreTable.h"
#include "Game.h"

namespace ApplesGame
{
	void ScoreTable::InitScoreTable(const int playerScore)
	{
		// add player in score table
		TableRow player = { PLAYER_NAME, playerScore };
		data.push_back(player);

		// generate random scores and names and add it to score table
		for (int i = 0; i < TABLE_ROWS; i++)
		{
			TableRow new_row = { NAMES[rand() % int(sizeof(NAMES) / sizeof(NAMES[0]))] , rand() % MAX_RAND_SCORE };
			data.push_back(new_row);
		}
	}

	void ScoreTable::UpdateScoreTable(const int playerScore)
	{
		// find player in score table and update score
		for (auto& row : data)
		{
			if (row.name == PLAYER_NAME)
			{
				row.score = playerScore;
				break;
			}
		}

		//// sorting score table by score
		std::sort(std::begin(data), std::end(data), [](const TableRow& a, const TableRow& b) { return b.score < a.score; });
	}

	void DrawScoreTable(Game& game, sf::RenderWindow& window)
	{

		game.scoresText.setString(game.scoreTable.data[0].name);

		window.draw(game.scoresText);
	}
}
