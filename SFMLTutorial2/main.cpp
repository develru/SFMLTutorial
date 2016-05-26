#include <SFML\Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(480, 180), "SFML 2");

	window.setFramerateLimit(60);

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

		// Render cycle
		window.clear(sf::Color::Black);
		
		// Render objects
		window.display();
	}
}