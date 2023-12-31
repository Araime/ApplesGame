#include<algorithm>
#include "ScoreTable.h"
#include "Game.h"

namespace ApplesGame
{
	void ScoreTable::InitScoreTable(const int playerScore)
	{
		// init highlighter
		highlighter.setSize(sf::Vector2f(HIGHLIGHTER_WIDTH, HIGHLIGHTER_HEIGHT));
		highlighter.setFillColor(sf::Color::Magenta);

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

	void DrawScoreTable(Game& game, sf::RenderWindow& window, float xcor, float ycor)
	{
		for (auto& row : game.scoreTable.data)
		{
			if (row.name == PLAYER_NAME)
			{
				// update highlighter position
				game.scoreTable.highlighter.setPosition(xcor - TABLE_STEP, ycor + HIGHLIGHTER_STEP);
				window.draw(game.scoreTable.highlighter);
			}
			

			game.scoresText.setString(row.name);
			game.scoresText.setPosition(xcor, ycor);
			window.draw(game.scoresText);

			game.scoresText.setString(std::to_string(row.score));
			game.scoresText.setPosition(xcor + TABLE_INDENT, ycor);
			window.draw(game.scoresText);

			ycor += TABLE_STEP;
		}
	}
}
