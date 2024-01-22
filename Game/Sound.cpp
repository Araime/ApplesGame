#include "Sound.h"

void Music::PlayMusic(const std::string& path)
{
	music.openFromFile(path);
	music.play();
}
