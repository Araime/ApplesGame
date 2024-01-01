#include "ScoreTable.h"
#include "Game.h"

namespace ApplesGame
{
	void InitScoreTable(Game& game)
	{
		TableRow player = { PLAYER_NAME, game.playerScore };
		game.scoreTable.data.push_back(player);

		for (int i = 0; i < 5; i++)
		{
			TableRow d = { NAMES[rand() % int(sizeof(NAMES) / sizeof(NAMES[0]))] , rand() % TABLE_ROWS };
			game.scoreTable.data.push_back(d);
		}
	}

	void UpdateScoreTable()
	{

	}

	void DrawScoreTable()
	{

	}
}
