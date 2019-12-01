#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Player.h"
#include "UFO.h"
#include "Keyboard.h"

class SpaceInvaders : public Game {
public:
	SpaceInvaders();
	virtual ~SpaceInvaders();
	virtual void run() override;
	void handleEvent() override;
	virtual const std::string& getName() const override;
private:
	Keyboard *kb;
	std::vector<Entity*> m_entities;
	sf::RenderWindow m_window;
	const std::string m_name = "Space Invaders";
};
