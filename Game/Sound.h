#pragma once
#include <SFML/Audio.hpp>

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
