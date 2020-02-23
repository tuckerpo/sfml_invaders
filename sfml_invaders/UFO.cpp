#include "UFO.h"

UFO::UFO()
	: m_animation(16, 8)
{
	m_Type = EntityType::UFO;
	m_ufo_state = UFOState::None;
	m_sprite.setSize({ 72, 36 });
	m_sprite.setPosition(0, 45);
	m_texture.loadFromFile("res\\txrs\\si\\ufo.png");
	m_sprite.setTexture(&m_texture);
	for (uint8_t i = 0; i < 3; i++) {
		m_animation.addFrame(i, sf::seconds(0.2f));
	}
};

void UFO::update(float dt)
{
	auto getX = [](sf::RectangleShape& sprite) {
		return sprite.getPosition().x;
	};
	switch (m_ufo_state) {
	case UFOState::None:
		getInitialDir();
		break;
	case UFOState::Flying: 
		m_sprite.move(m_speed* dt, 0.f);
		if (getX(m_sprite) > 1500 || getX(m_sprite) < -1 - (m_sprite.getGlobalBounds().width)) {
			m_ufo_state = UFOState::None;
		}
		break;
	case UFOState::Destroyed:
		m_ufo_state = UFOState::None;
		break;
	case UFOState::Paused:
		break;
	default:
		break;
	}
}

void UFO::input(Keyboard& kb)
{
	if (kb.is_key_down(sf::Keyboard::Key::Pause))
		m_ufo_state = UFOState::Paused;
	return;
}

const EntityType UFO::getType() const
{
	return m_Type;
}

void UFO::draw(sf::RenderTarget& target)
{
	m_sprite.setTextureRect(m_animation.getFrame());
	target.draw(m_sprite);
}

void UFO::onCollide(Collidable& other)
{
	if (other.getType() == EntityType::Projectile) {
		m_ufo_state = UFOState::Destroyed;
	}
}

const sf::Vector2f& UFO::getPosition() const
{
	return m_sprite.getPosition();
}

void UFO::getInitialDir() {
	srand(time(NULL));
	m_speed = rand() % (200 + 1 - 100) + 100;
	int randNum = rand() % 2;
	if (randNum % 2 == 0) {
		m_dir = UFODir::FromLeft;
		m_sprite.setPosition(0 - m_sprite.getGlobalBounds().width, 45);
	} else {
		m_dir = UFODir::FromRight;
		m_sprite.setPosition(1500, 45);
		m_speed *= -1;
	}
	m_ufo_state = UFOState::Flying;
}

const bool UFO::isAlive() const {
	return m_ufo_state != UFOState::Destroyed;
}