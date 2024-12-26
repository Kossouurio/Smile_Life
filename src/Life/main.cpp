#include <SFML/Graphics.hpp>
#include <iostream>

#include "Player.h"
#include "Card.h"

#define PLAYERS 2

std::list<Card*> deck; // Deck is a list of cards (200 cards) that the player can draw from
//std::list<Card> trashcan; // Trashcan is a list of cards that the player has played or discard and are now in the trashcan
//std::list<Card> hand; // Hand is a list of cards (5 cards) that the player can play

int main()
{
	/// creer un deck de 200 Card (25 ETUDEs dont 3 doubles, 30 METIERs, 40 SALAIREs (10 par niveaux de revenus (10, 20, 30, 40)), 20 FLIRTs, 7 MARIAGEs, 3 ADULTEREs, 10 ENFANTs, 37 MALUS, 10 SPECIALs, 5 MAISONs, 5 VOYAGEs, 5 ANIMAL, 2 GRAND_PRIX_D_EXCELLENCEs, 1 LEGION_D_HONNEUR)
	
	sf::Texture T;
	T.loadFromFile("../../../res/Backcard.png");
	// ETUDEs
	for (int i = 1; i < 26; i++)
	{
		Card* card = new Card("ETUDE", "Draw 2 cards", T, sf::Vector2f(50 * i, 50));
		deck.push_back(card);
	}


	sf::RenderWindow window(sf::VideoMode(1366, 768), "Life Game");

	while (window.isOpen())
	{
		window.setFramerateLimit(60);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) // sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)
				window.close();
		}
		window.clear(sf::Color::Cyan);

		for (auto card : deck)
		{
			window.draw(card->GetSprite());
		}

		window.display();
	}

	return 0;
}
