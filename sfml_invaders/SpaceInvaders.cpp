#include "SpaceInvaders.h"

// Original arcade game had a 5 x 11 grid of invaders, two rows of each unique sprite
#define NUM_INVADERS 5 * 11

SpaceInvaders::SpaceInvaders()
	: Game(), m_window(sf::VideoMode(1500, 1000), "Space Invaders") {
	// Window init
	m_GameState = GameState::Playing;
	m_window.setPosition({ m_window.getPosition().x, 0 });
	m_window.setFramerateLimit(60);
	// Keyboard, player, UFO objects
	kb = std::make_unique<Keyboard>();
	m_entities.push_back(new Player());
	m_entities.push_back(new UFO());
	// Invader init
	for (uint8_t i = 0; i < NUM_INVADERS; i++) {
		m_entities.push_back(new Invader(i));
	}
	m_projectiles.reserve(1024);
	m_InvaderFired = std::chrono::steady_clock::now();
	m_LastPausedTime = std::chrono::steady_clock::now();
}

SpaceInvaders::~SpaceInvaders() {
	// Free all new'd objects
	for (Entity* entity : m_entities) {
		if (entity) delete entity;
	}
}

bool SpaceInvaders::IsGamePaused() {
	std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
	if (now - m_LastPausedTime > std::chrono::milliseconds(500)) {
		m_LastPausedTime = now;
		return m_GameState == GameState::Paused;
	}

	if (kb->is_key_down(sf::Keyboard::Key::Pause))
	{
		printf("DId I see the key go down?\n");
		if (m_GameState == GameState::Paused)
		{
			printf("setting game state back to playing\n");
			m_GameState = GameState::Paused;
		}
		else
		{
			m_GameState = GameState::Paused;
		}
	}

	return m_GameState == GameState::Paused;
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

		if (IsGamePaused())
		{
			printf("game is paused\n");
			continue;
		}

		// Handle player firing events
		playerFire();

		invadersFire();

		// Handle projectile collisions;
		// doCollisions();
		
		// Handle input & business logic for all entities, and update the display
		for (const auto& entity : m_entities) {
			entity->input(*kb);
			entity->update(elapsed.asSeconds());
			entity->draw(m_window);
		}

		for (auto& projectile : m_projectiles) {
			projectile.input(*kb);
			projectile.update(elapsed.asSeconds());
			projectile.draw(m_window);
		}
		m_window.display();
	}
}

std::vector<Entity*> SpaceInvaders::getEntitiesByType(const EntityType& et)
{
	std::vector<Entity*> vec;
	for (const auto& entity : m_entities) {
		if (entity->getType() == et) {
			vec.push_back(entity);
		}
	}
	return vec;
}

void SpaceInvaders::invadersFire() {
	size_t i;
	Invader* invader;
	auto invaders = getEntitiesByType(EntityType::Invader);
	for (i = invaders.size() - 1; i != 0; --i) {
		invader = dynamic_cast<Invader*>(invaders[i]);
		if (invader->IsFiring())
			continue;
		invader->DoFire();
	}
}

void SpaceInvaders::playerFire() {
	if (kb->is_key_down(sf::Keyboard::Key::Space)) {
		auto players = getEntitiesByType(EntityType::Player);
		for (auto& player : players) {
			dynamic_cast<Player*>(player)->DoFire();
		}
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

void SpaceInvaders::doCollisions() {
	for (auto& projectile : m_projectiles) {
		for (auto& entity : m_entities) {
			if (projectile.tryCollide(*entity)) {
				m_projectiles.clear();
			}
		}
	}
}

const std::string& SpaceInvaders::getName() const
{
	return m_name;
}