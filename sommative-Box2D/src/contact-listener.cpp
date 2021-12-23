#include "contact-listener.h"

#include <iostream>

#include "game.h"
#include "userData.h"


MyContactListener::MyContactListener(Game& game) : game_(game)
{

}

void MyContactListener::BeginContact(b2Contact* contact)
{
    std::cout << "Contact Begin!" << std::endl;

}

void MyContactListener::EndContact(b2Contact* contact)
{
    std::cout << "Contact End!" << std::endl;
}

