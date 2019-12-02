#include "Invader.h"


Invader::Invader() {
	m_type = EntityType::Invader;
	m_InvaderState = InvaderState::Alive;
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