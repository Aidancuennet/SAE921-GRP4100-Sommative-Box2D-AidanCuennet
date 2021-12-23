
#include <iostream>

#include "ball.h"
#include "game.h"
#include "textureManager.h"

#include "SFML-Utilities.h"

Ball::Ball(Game& game_, sf::RenderWindow& window_) : game(game_), window(window_)
{
}

void Ball::init() {

    // Defining the shape
	shape.setRadius(24.0f);
    TextureManager* texManager = TextureManager::Instance();
    m_sprite.setTexture(texManager->getEarthTexture());
    m_earth.setOrigin(texManager->getEarthTexture().getSize().x * 0.0f, texManager->getEarthTexture().getSize().y * 0.0f);

    // Defing the box 2D elements
    b2BodyDef bodyDef;
    bodyDef.fixedRotation = true;
    bodyDef.type = b2_dynamicBody;
    b2Vec2 windowSize = Game::pixelsToMeters(window.getSize());
    bodyDef.position.Set(windowSize.x / 2.0f, windowSize.y / 2.0f);
    body = this->game.getWorld().CreateBody(&bodyDef);

    // Shape of the physical (A box)
    b2CircleShape ballBox;
	
    ballBox.m_radius =
       (
         Game::pixelsToMeters(texManager->getEarthTexture().getSize().x),
         Game::pixelsToMeters(texManager->getEarthTexture().getSize().y),
		 Game::pixelsToMeters(shape.getRadius())
       );
    

    // The fixture is what it defines the physic react
    b2FixtureDef playerFixtureDef;
    playerFixtureDef.shape = &ballBox;
    playerFixtureDef.density = 1.0f;
    playerFixtureDef.friction = 0.4f;
    playerFixtureDef.restitution = 1.1f;
    //playerFixtureDef.userData.pointer = reinterpret_cast <std::uintptr_t>(&playerBoxData);
    body->CreateFixture(&playerFixtureDef);

}

void Ball::update() {
    
    std::cout << "body position [" << body->GetPosition().x << ":" << body->GetPosition().y 
        << "]|shape position [" << shape.getPosition().x << ":" << shape.getPosition().y << "]" << std::endl;
    
    // Get the position of the body
    b2Vec2 bodyPos = body->GetPosition();
    // Translate meters to pixels
    sf::Vector2f graphicPosition = Game::metersToPixels(bodyPos);
    // Set the position of the Graphic object
    m_sprite.setPosition(graphicPosition);
	shape.setPosition(graphicPosition);
}

void Ball::render() {
    window.draw(m_sprite);
}

void Ball::setPixelsPosition(sf::Vector2f _pixelsPosition) {
    // Put in mouse position
    body->SetTransform(Game::pixelsToMeters(_pixelsPosition), body->GetAngle());
    // Reset the velocity (Speed)
    body->SetLinearVelocity(b2Vec2_zero);
}