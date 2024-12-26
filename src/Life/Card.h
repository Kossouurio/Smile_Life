#pragma once
#include <SFML/Graphics.hpp>
#include <string>

/// <summary>
/// Card has a name, a description and a special effect when played by a player
/// </summary>
class Card
{
protected:
	std::string mName;
	std::string mDescription;
	sf::Texture mTexture;
	sf::Sprite mSprite;
	sf::Vector2f mPosition;

public:
	std::string GetName() { return mName; }
	std::string GetDescription() { return mDescription; }
	sf::Texture GetTexture() { return mTexture; }
	sf::Sprite GetSprite() { return mSprite; }
	sf::Vector2f GetPosition() { return mPosition; }

	void setName(std::string name) { mName = name; }
	void setDescription(std::string description) { mDescription = description; }
	void SetPosition(sf::Vector2f position) { mPosition = position; }

	Card(std::string name, std::string description, sf::Texture texture, sf::Vector2f position);
	~Card() = default;

private:
	virtual void Update() {};
	virtual void Initialize() {};
	virtual void SpecialEffect() {};
	//void Draw();
};



//enum type
//{
//	ETUDE,
//	METIER,
//	SALAIRE,
//	FLIRT,
//	MARIAGE,
//	ADULTERE,
//	ENFANT,
//	MALUS,
//	SPECIAL,
//	MAISON,
//	VOYAGE,
//	ANIMAL,
//	GRAND_PRIX_D_EXCELLENCE,
//	LEGION_D_HONNEUR
//};