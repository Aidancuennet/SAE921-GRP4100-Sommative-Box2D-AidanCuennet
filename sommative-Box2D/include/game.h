#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Window//Event.hpp"
#include "box2d/b2_world.h"

#include "placedBouncer.h"
#include "bouncer.h"
#include "ball.h"

class Game{
public:
	
	Game();
	void init();
	void loop();
	
	b2World& getWorld() { return world_; };

	static b2Vec2 pixelsToMeters(sf::Vector2f pixels);
	static b2Vec2 pixelsToMeters(sf::Vector2u pixels);
	static float pixelsToMeters(float pixels);

	static sf::Vector2f metersToPixels(b2Vec2 meters);

	static const float pixelsMetersRatio;

private:

	
	
	// The window ---------------------------------------------
	sf::RenderWindow window_;

	// The physical world -------------------------------------
	b2World world_{ b2Vec2(0.0f, -9.81f) };


	sf::Vector2f mousePressedPos_bouncer, mouseReleasedPos_bouncer;
	sf::Vector2f mousePressedPos_ball, mouseReleasedPos_ball;
	sf::Sprite m_sprite;
	void addBouncer(sf::Vector2f centre, float angle, float size);
	Ball theBall;
	std::vector<Bouncer> bouncers;
	void clearBouncers();
};
