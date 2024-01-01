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
		std::vector<TableRow>::iterator it = std::find(data.begin(), data.end(), PLAYER_NAME);
		data[std::distance(data.begin(), it)].score = playerScore;

		// sorting score table by score
		std::sort(std::begin(data), std::end(data), [](const TableRow& a, const TableRow& b) { return b.score < a.score; });
	}

	void DrawScoreTable(Game& game, sf::RenderWindow& window)
	{

	}
	
}
