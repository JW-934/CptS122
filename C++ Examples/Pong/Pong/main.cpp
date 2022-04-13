// This example will use SFML libraries to implement
// the game of Pong

// History: 4/16 - Started from the SFML tutorial code that draws
//                a circle in the window.

#include <SFML/Graphics.hpp>

#include "Paddle.h"
#include "Ball.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	sf::CircleShape shape(100.f);
	Paddle p1Paddle(sf::Vector2f(0, 0), sf::Vector2f(50, 100), sf::Color::Magenta),
		p2Paddle(sf::Vector2f(450, 0), sf::Vector2f(50, 100), sf::Color::Cyan);

	Ball gameBall(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2),
		p1Paddle.getSize().y / 6, sf::Color::Green);

	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(p1Paddle);
		window.draw(p2Paddle);
		window.draw(gameBall);
		window.display();
	}

	return 0;
}