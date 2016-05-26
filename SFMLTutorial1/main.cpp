#include <SFML\Graphics.hpp>

void initShape(sf::RectangleShape& shape, sf::Vector2f const& pos, sf::Color const& color)
{
	shape.setFillColor(color);
	shape.setPosition(pos);
	shape.setOrigin(shape.getSize() * 0.5f);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(480, 180), "Bad Squares");

	window.setFramerateLimit(60);

	sf::Vector2f startPos = sf::Vector2f(50, 50);
	sf::RectangleShape playerRect(sf::Vector2f(50, 50));
	initShape(playerRect, startPos, sf::Color::Green);
	sf::RectangleShape targetRect(sf::Vector2f(50, 50));
	initShape(targetRect, sf::Vector2f(400, 50), sf::Color::Blue);
	sf::RectangleShape badRect(sf::Vector2f(50, 100));
	initShape(badRect, sf::Vector2f(250, 50), sf::Color::Red);

	while (window.isOpen())
	{
		// Handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if ((event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape) || 
				event.type == sf::Event::EventType::Closed)
			{
				window.close();
			}
		}

		// Update scene
		
		// Always move right
		playerRect.move(1, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		{
			playerRect.move(0, 1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		{
			playerRect.move(0, -1);
		}

		// Target reached. You win. Exit the game.
		if (playerRect.getGlobalBounds().intersects(targetRect.getGlobalBounds()))
		{
			window.close();
		}
		// Bad square intersect. You lose. Restart.
		if (playerRect.getGlobalBounds().intersects(badRect.getGlobalBounds()))
		{
			playerRect.setPosition(startPos);
		}

		// Render cycle
		window.clear(sf::Color::Black);
		window.draw(playerRect);
		window.draw(badRect);
		window.draw(targetRect);

		// Render objects
		window.display();
	}
}