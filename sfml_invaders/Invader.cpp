#include "Invader.h"


Invader::Invader(uint8_t idx) {
	m_type = EntityType::Invader;
	m_InvaderState = InvaderState::Alive;
	m_sprite.setSize({ 48, 34 });
	m_sprite.setPosition({ 
		(0) + 55 * static_cast<float>(idx), 1000 - 800.f });
	if (!m_texture.loadFromFile("res\\txrs\\si\\invaders.png")) {
		printf("Invader::Invader() texture loading failed\n");
	}
	m_sprite.setTexture(&m_texture);
	m_sprite.setTextureRect({ 0, 0, 12, 8 });
}

void Invader::onCollide(Collidable& other) {
	m_InvaderState = InvaderState::Destroyed;
}

void Invader::draw(sf::RenderTarget& target) {
	target.draw(m_sprite);
}

void Invader::update(float dt) {
	switch (m_InvaderState) {
	case InvaderState::None:
		break;
	case InvaderState::Paused:
		break;
	case InvaderState::Destroyed:
		break;
	}
}

void Invader::input(Keyboard& kb) {
	if (kb.is_key_down(sf::Keyboard::Key::Pause)) {
		m_InvaderState = InvaderState::Paused;
	}
}

const EntityType Invader::getType() const {
	return m_type;
}