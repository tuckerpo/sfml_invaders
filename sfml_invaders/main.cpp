#include <SFML/Graphics.hpp>
#include "Keyboard.h"
#include "SpaceInvaders.h"

int main()
{
#if 0
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Invaders");

	sf::Event event;
	std::unique_ptr<Keyboard> kb = std::make_unique<Keyboard>();
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			kb->update(event);
			switch (event.type)
			{
				case sf::Event::Closed:
				{
					window.close();
				}
			}
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
	}
	return 0;
#endif

	SpaceInvaders *si = new SpaceInvaders();
	si->run();
	delete si;
}