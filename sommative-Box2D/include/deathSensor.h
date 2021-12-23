#pragma once

#include "bouncer.h"
#include "SFML/Graphics.hpp"
#include "box2d/box2d.h"

#include "userData.h"

class Game;

class deathSensor : public Bouncer
{
public:
	explicit deathSensor(b2World& world_, sf::Vector2f pos_, sf::Vector2f size_);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

protected:
	void createFixture(const float sizeX, const float sizeY) override;

};
