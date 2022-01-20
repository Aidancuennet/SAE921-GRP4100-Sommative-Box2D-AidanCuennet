#include <iostream>
#include <math.h>

#include "platform.h"
#include "game.h"
#include "SFML-Utilities.h"

Bouncer::Platform(Game& game_, sf::RenderWindow& window_, sf::Vector2f center_, float angle_, float size_) : game(game_), window(window_)
{
    init(center_, angle_, size_);
}

void Platform::init(sf::Vector2f center_, float angle_, float size_) {

    
    b2Vec2 physicalSize(game.pixelsToMeters(size_), 0.1f);
    shape.setSize(Game::metersToPixels(physicalSize));
    shape.setFillColor(sf::Color::Cyan);
    shape.setFillColor(sf::Color::Cyan);
    shape.setOrigin(0.5F * shape.getSize().x, 0.5F * shape.getSize().y);
    shape.setPosition(center_);
    

    
    b2BodyDef bodyDef;
    bodyDef.fixedRotation = true;
    bodyDef.type = b2BodyType::b2_staticBody; 
    bodyDef.position.Set(Game::pixelsToMeters(shape.getPosition()).x, Game::pixelsToMeters(shape.getPosition()).y);


    bodyDef.angle = SFML_Utilities::degToRad(-1.0f * angle_);

    body = this->game.getWorld().CreateBody(&bodyDef);

    
    b2PolygonShape platformBox;
    
    platformBox.SetAsBox(
        0.5f * Game::pixelsToMeters(shape.getSize()).x,
        0.5f * Game::pixelsToMeters(shape.getSize()).y,
        b2Vec2_zero,
        SFML_Utilities::degToRad(.0f));

    
    b2FixtureDef playerFixtureDef;
    playerFixtureDef.shape = &platformBox;
    playerFixtureDef.density = 1.0f;
    playerFixtureDef.friction = 0.5f;
    playerFixtureDef.restitution = 0.6f; 
    body->CreateFixture(&playerFixtureDef);

}

void Bouncer::update() {

    std::cout << "platform position [" << body->GetPosition().x << ":" << body->GetPosition().y
        << "]|shape position [" << shape.getPosition().x << ":" << shape.getPosition().y << "]" << std::endl;


    const auto& b2Position = body->GetPosition();
    shape.setPosition(Game::metersToPixels(b2Position));
    const auto b2rotation = body->GetAngle();
    shape.setRotation(-1.0f * SFML_Utilities::radToDeg(b2rotation));

}

void Platform::render() {
    window.draw(shape);
}