#pragma once
#include <SFML/Audio.hpp>
#include "Constants.h"

namespace ApplesGame
{
	struct Sound
	{
		sf::SoundBuffer buffer;
		sf::Sound sound;
	};

	struct Music
	{
		sf::Music music;
	};
}
