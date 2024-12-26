#include "Card.h"

Card::Card(std::string name, std::string description, sf::Texture texture, sf::Vector2f position) :
	mName(name), 
	mDescription(description), 
	mTexture(texture), 
	mPosition(position)
{
	mSprite.setTexture(mTexture);
	mSprite.setPosition(mPosition);
}
