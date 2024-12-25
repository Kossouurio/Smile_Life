#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

#define PLAYERS 2

class Player; // Player has a hand of 5 cards, a name, and a life total
class Card; // Card has a type, a name, and a description
class Life; // Life regroups all cards the player has played for himself
//std::list<Card> deck;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1366, 768), "Life Game");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) // sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)
				window.close();
		}
		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}
