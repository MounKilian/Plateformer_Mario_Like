#include "Sound.h"

Sound::Sound(sf::SoundBuffer* buffer) : sound(*buffer)
{
}

void Sound::Play() {
	sound.play();
}