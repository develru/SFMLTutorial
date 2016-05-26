#include <SFML\Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "The Title");

	window.setFramerateLimit(60);

	sf::RectangleShape rectangle(sf::Vector2f(50, 50));
	rectangle.setFillColor(sf::Color::Red);
	rectangle.setOrigin(sf::Vector2f(25, 25));
	rectangle.setPosition(sf::Vector2f(50, 50));

	bool moving = false;

	while (window.isOpen())
	{
		// Handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
			{
				moving = true;
			}
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Right) 
			{
				moving = false;
			}
			if ((event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape) || 
				event.type == sf::Event::EventType::Closed)
			{
				window.close();
			}
		}

		// Update scene
		if (moving)
		{
			rectangle.rotate(1.5f);
			rectangle.move(sf::Vector2f(1, 0));
		}

		// Render cycle
		window.clear(sf::Color::Black);
		window.draw(rectangle);

		// Render objects
		window.display();
	}
}