
#include <iostream>
#include <math.h>

#include "bouncer.h"
#include "game.h"
#include "SFML-Utilities.h"

Bouncer::Bouncer(Game& game_, sf::RenderWindow& window_, sf::Vector2f center_ , float angle_, float size_) : game(game_), window(window_)
{
    init(center_, angle_, size_);
}

void Bouncer::init(sf::Vector2f center_, float angle_, float size_) {

    // Defining the shape
    // 2 meters long, 0,5 meters high
    b2Vec2 physicalSize(game.pixelsToMeters(size_), 0.1f);
    shape.setSize(Game::metersToPixels(physicalSize));
	shape.setFillColor(sf::Color::Cyan);
	shape.setFillColor(sf::Color::Cyan);
    shape.setOrigin(0.5F * shape.getSize().x, 0.5F * shape.getSize().y);
    shape.setPosition(center_);
    //shape.setRotation(45.0f);

    // Defing the box 2D elements
    b2BodyDef bodyDef;
    bodyDef.fixedRotation = true;
    bodyDef.type = b2BodyType::b2_staticBody; // Static !!! it does not move when something collides
    bodyDef.position.Set(Game::pixelsToMeters(shape.getPosition()).x, Game::pixelsToMeters(shape.getPosition()).y);


    bodyDef.angle = SFML_Utilities::degToRad(-1.0f * angle_);

    body = this->game.getWorld().CreateBody(&bodyDef);

    // Shape of the physical (A box)
    b2PolygonShape bouncerBox;
    //bouncerBox.SetAsBox(physicalSize.x, physicalSize.y);
    bouncerBox.SetAsBox(
        0.5f * Game::pixelsToMeters(shape.getSize()).x,
        0.5f * Game::pixelsToMeters(shape.getSize()).y,
        b2Vec2_zero,
        SFML_Utilities::degToRad(.0f));

    // The fixture is what it defines the physic react
    b2FixtureDef playerFixtureDef;
    playerFixtureDef.shape = &bouncerBox;
    playerFixtureDef.density = 1.0f;
    playerFixtureDef.friction = 0.5f;
    playerFixtureDef.restitution = 0.6f; // Make it bounce a little bit
    //playerFixtureDef.userData.pointer = reinterpret_cast <std::uintptr_t>(&playerBoxData);
    body->CreateFixture(&playerFixtureDef);

}

void Bouncer::update() {
    
    std::cout << "Bouncer position [" << body->GetPosition().x << ":" << body->GetPosition().y 
        << "]|shape position [" << shape.getPosition().x << ":" << shape.getPosition().y << "]" << std::endl;
    
 //   // Get the position of the body
 //   b2Vec2 bodyPos = body->GetPosition();
 //   // Translate meters to pixels
 //   sf::Vector2f graphicPosition = 
 //   // Set the position of the Graphic object
	//shape.setPosition(graphicPosition);
 //   shape.setRotation(SFML_Utilities::radToDeg(body->GetAngle()));


    const auto& b2Position = body->GetPosition();
    shape.setPosition(Game::metersToPixels(b2Position));
    const auto b2rotation = body->GetAngle();
    shape.setRotation(-1.0f * SFML_Utilities::radToDeg(b2rotation));
    
}

void Bouncer::render() {
	window.draw(shape);
}
