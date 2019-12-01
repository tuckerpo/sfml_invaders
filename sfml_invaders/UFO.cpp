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
	switch (m_ufo_state) {
	case UFOState::None:
		getInitialDir();
		break;
	case UFOState::Flying: 
		m_sprite.move(m_speed* dt, 0.f);
		printf("ufo is flyting\n");
		break;
	case UFOState::Destroyed:
		m_ufo_state = UFOState::None;
		break;
	case UFOState::Paused:
		break;
	default:
		printf("Default UFO state\n");
		break;
	}
}

void UFO::input(Keyboard&)
{
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
		printf("UFO got got.\n");
		
	}
}

void UFO::getInitialDir() {
	srand(time(NULL));
	m_speed = rand() % 200;
	int randNum = rand() % 2;
	if (randNum % 2 == 0) {
		m_dir = UFODir::FromLeft;
	} else {
		m_dir = UFODir::FromRight;
	}
	m_ufo_state = UFOState::Flying;

}
