#pragma once
#include <SFML/Graphics/Transformable.hpp>

#include "SFML/Graphics.hpp"
#include "box2d/box2d.h"

#include "SFML-Utilities.h"
#include "textureManager.h"
#include "userData.h"


class Entity : public sf::Drawable, public sf::Transformable
{

public:
	Entity(b2World& world_);
	~Entity();

	void update();

protected:
	b2Body* m_body = nullptr;
	UserData* m_userData;

	b2World& m_world;

	TextureManager* texManager = TextureManager::Instance();

	virtual void createFixture(const float sizeX, const float sizeY) = 0;

};