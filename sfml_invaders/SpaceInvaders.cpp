#include "SpaceInvaders.h"

// Original arcade game had a 5 x 11 grid of invaders, two rows of each unique sprite
#define NUM_INVADERS 5 * 11

SpaceInvaders::SpaceInvaders()
	: Game(), m_window(sf::VideoMode(1500, 1000), "Space Invaders") {
	// Window init
	m_window.setPosition({ m_window.getPosition().x, 0 });
	m_window.setFramerateLimit(60);
	// Keyboard, player, UFO objects
	kb = new Keyboard();
	m_entities.push_back(new Player());
	m_entities.push_back(new UFO());
	// Invader init
	for (uint8_t i = 0; i < NUM_INVADERS; i++) {
		m_entities.push_back(new Invader(i));
	}

}

SpaceInvaders::~SpaceInvaders() {
	// Free all new'd objects
	if (kb) delete kb;
	for (Entity* entity : m_entities) {
		if (entity) delete entity;
	}
}

void SpaceInvaders::run() {
	const sf::Time update = sf::seconds(1.f / 30.f);
	sf::Clock timer;

	auto lastTime = sf::Time::Zero;
	auto lag = sf::Time::Zero;

	// main game loop
	while (m_window.isOpen()) {
		m_window.clear();

		auto time = timer.getElapsedTime();
		auto elapsed = time - lastTime;
		lastTime = time;
		lag += elapsed;

		// Handle input events
		handleEvent();
		
		// Handle input & business logic for all entities, and update the display
		for (const auto& entity : m_entities) {
			entity->input(*kb);
			entity->update(elapsed.asSeconds());
			entity->draw(m_window);
		}
		m_window.display();
	}
}

void SpaceInvaders::handleEvent() {
	sf::Event e;
	while (m_window.pollEvent(e)) {
		kb->update(e);
		switch (e.type) {
		case sf::Event::Closed:
			m_window.close();
			break;

		default:
			break;
		}
	}
}

const std::string& SpaceInvaders::getName() const
{
	return m_name;
}