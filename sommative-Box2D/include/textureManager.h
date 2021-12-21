
#pragma once

#include <string>
#include "SFML/Graphics.hpp"

class TextureManager
{
protected:
    TextureManager();

    static TextureManager* textureManager_;

    sf::Texture m_earthTexture;
    sf::Texture m_bouncerTexture;
    sf::Texture m_gameOverTexture;
    sf::Texture m_backgroundTexture;

public:

  
    TextureManager(TextureManager& other) = delete;
  
    void operator=(const TextureManager&) = delete;

  
    static TextureManager* Instance();
	


    
    sf::Texture& getEarthTexture();
    sf::Texture& getBouncerTexture();
    sf::Texture& getBackgroundTexture();
};