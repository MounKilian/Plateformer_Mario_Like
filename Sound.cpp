#include "Sound.h"

Sound::Sound(sf::SoundBuffer* buffer) : sound(*buffer)
{
}

void Sound::Play(sf::SoundBuffer* buffer) {
	sf::Sound newSound(*buffer);
	this->sound = newSound;
	sound.play();
}

void Sound::Play() {
	sound.play();
}