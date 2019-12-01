#include "SpaceInvaders.h"

SpaceInvaders::SpaceInvaders()
	: Game(), m_window(sf::VideoMode(1500, 1000), "Space Invaders") {
	m_window.setPosition({ m_window.getPosition().x, 0 });
	m_window.setFramerateLimit(60);
	kb = new Keyboard();
	m_entities.push_back(new Player());
	m_entities.push_back(new UFO());
}

SpaceInvaders::~SpaceInvaders() {
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

		handleEvent();
		
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