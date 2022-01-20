#include "game.h"
#include "textureManager.h"
const float Game::pixelsMetersRatio = 100.0f;

Game::Game() : theBall(*this, this->window_)
{
}

void Game::init() {

	window_.create(sf::VideoMode(1280, 720), "SAE Platformer");
	window_.setVerticalSyncEnabled(true);
	window_.setFramerateLimit(60.0f);

	//TextureManager* texManager = TextureManager::Instance();
	//m_sprite.setTexture(texManager->getBackgroundTexture());
	//m_sprite.setOrigin(texManager->getBackgroundTexture().getSize().x * 2.0f, texManager->getBackgroundTexture().getSize().y * 2.0f);

	addBouncer(sf::Vector2f(100, 360), 45, 200);
	addBouncer(sf::Vector2f(380, 230), 45, 200);
	addBouncer(sf::Vector2f(400, 660), 45, 200);
	addBouncer(sf::Vector2f(1000, 560), 90, 200);




	// Init all elements
	theBall.init();
}

void Game::loop()
{

	while (window_.isOpen())
	{

		sf::Event event;

		while (window_.pollEvent(event))
		{
			// Windows events -------------------------------------------------------------------------------
			if (event.type == sf::Event::Closed)
			{
				window_.close();
				return;
			}
			if (event.type == sf::Event::Resized)
			{
				auto view = window_.getView();
				view.setSize(event.size.width, event.size.height);
				window_.setView(view);


			}


			// Mouse events ---------------------------------------------------------------------------------
			if (event.type == sf::Event::MouseButtonReleased)
			{
				theBall.setPixelsPosition(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
			}

			/*window_.draw(m_sprite);
			window_.display();*/
		}




		// Updating the world with a delay
		float timeStep = 1.0f / 60.0f;
		int32 velocityIterations = 6;
		int32 positionIterations = 2;
		world_.Step(timeStep, velocityIterations, positionIterations);

		// Update the elements
		theBall.update();
		for (auto b = bouncers.begin(); b != bouncers.end(); b++) {
			b->update();
		}




		// Clear all background
		window_.clear();
		// Render All elements
		theBall.render();
		for (auto b = bouncers.begin(); b != bouncers.end(); b++) {
			b->render();
		}

		// Display all elements
		window_.display();


	}
}


void Game::addBouncer(sf::Vector2f centre, float angle, float size)
{
	Bouncer newBouncer(*this, this->window_, centre, angle, size);
	bouncers.push_back(newBouncer);
}

b2Vec2 Game::pixelsToMeters(sf::Vector2f pixels)
{
	return b2Vec2(pixels.x / pixelsMetersRatio, -1.0f * pixels.y / pixelsMetersRatio);
}

b2Vec2 Game::pixelsToMeters(sf::Vector2u pixels)
{
	return b2Vec2(pixels.x / pixelsMetersRatio, -1.0f * pixels.y / pixelsMetersRatio);
}

float Game::pixelsToMeters(float pixels)
{
	return pixels / pixelsMetersRatio;
}

sf::Vector2f Game::metersToPixels(b2Vec2 meters)
{
	return sf::Vector2f(meters.x * pixelsMetersRatio, -1.0f * meters.y * pixelsMetersRatio);
}


void Game::clearBouncers()
{

	for (auto myBouncer = bouncers.begin(); myBouncer != bouncers.end(); myBouncer++)
	{
		// First remove bodies from the physical world
		world_.DestroyBody(myBouncer->getBody());
		// Notice that the iterator is decremented after it is passed
		// to `erase()` but before `erase()` is executed
		//bouncers.erase(myBouncer--);
	}

	bouncers.clear();

}