#pragma once

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <map>
#include <iostream>

// Class that holds the state of key events
class Keyboard
{
public:

	Keyboard();

	virtual ~Keyboard() = default;

	void update(sf::Event e);

	bool is_key_down(sf::Keyboard::Key k);

	bool is_key_up(sf::Keyboard::Key k);

private:
	std::map<sf::Keyboard::Key, bool> m_keymap;
};

