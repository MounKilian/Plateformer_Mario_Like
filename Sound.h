#pragma once

#include "AComponent.h"

class Sound : public AComponent
{
	sf::Sound sound;

	public:
	    Sound(sf::SoundBuffer* buffer);
		void Play();
};

