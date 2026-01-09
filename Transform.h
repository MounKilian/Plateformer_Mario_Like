#pragma once

#include <SFML/Graphics.hpp>
#include "AComponent.h"

class Transform : public sf::Transformable, public AComponent
{
};

