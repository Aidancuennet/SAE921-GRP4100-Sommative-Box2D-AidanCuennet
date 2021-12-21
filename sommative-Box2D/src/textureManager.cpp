#include "textureManager.h"

TextureManager* TextureManager::textureManager_ = nullptr;

TextureManager::TextureManager()
{
    m_earthTexture.loadFromFile("./data/Terran.png");
    m_bouncerTexture.loadFromFile("./data/Ship.png");
    m_backgroundTexture.loadFromFile("./data/Space Background.png");

}

    	
    TextureManager* TextureManager::Instance()
    {
        
        if (textureManager_ == nullptr) {
            textureManager_ = new TextureManager();
        }
        return textureManager_;
    }

    sf::Texture& TextureManager::getEarthTexture() {
        return m_earthTexture;
    }
    sf::Texture& TextureManager::getBouncerTexture() {
        return m_bouncerTexture;
    }
    sf::Texture& TextureManager::getBackgroundTexture()
    {
        return m_backgroundTexture;
    }
