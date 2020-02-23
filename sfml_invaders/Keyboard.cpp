#include "Keyboard.h"


// initialize keymap
Keyboard::Keyboard()
{
	for (int i = 0; i < sf::Keyboard::KeyCount; i++)
	{
		m_keymap.insert(
			std::make_pair<sf::Keyboard::Key, bool>(static_cast<sf::Keyboard::Key>(i), false)
			);
	}

	m_DebounceDt = std::chrono::steady_clock::now();
}

void Keyboard::update(sf::Event e)
{
	switch (e.type)
	{
		case sf::Event::KeyPressed:
		{
			printf("key pressed\n");
			m_keymap.at(e.key.code) = true;
			break;
		}
		case sf::Event::KeyReleased:
		{
			printf("key released\n");
			m_keymap.at(e.key.code) = false;
			break;
		}
		default:
		{
			break;
		}
	}
}

bool Keyboard::is_key_down(sf::Keyboard::Key k)
{
	return m_keymap.at(k);
}

bool Keyboard::is_key_up(sf::Keyboard::Key k)
{
	return !m_keymap.at(k);
}