#include "Invader.h"

float Invader::m_YGap = 0.f;

Invader::Invader(uint8_t idx) 
	: Collidable(48, 32)
{
	m_type = EntityType::Invader;
	m_InvaderState = InvaderState::Alive;
	m_sprite.setSize({ 48, 34 });
	if (idx % m_rowShiftModulo == 0) {
		m_YGap += 50.f;
	}
	m_sprite.setPosition({ 
		((1500 / 2) / 2 ) + m_XGap * static_cast<float>(idx % m_rowShiftModulo), 1000 - m_initialYOff + m_YGap 
	});

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
		m_sprite.move({ -10000, -10000 });
		break;
	}
}

void Invader::input(Keyboard& kb) {
	if (kb.is_key_down(sf::Keyboard::Key::Pause)) {
		m_InvaderState = InvaderState::Paused;
	}
}

sf::Vector2f Invader::getFirePosition() const {
	printf("m_sprite.getPosition().x = %f, m_sprite.getGlobalBounds().width = %f\n", m_sprite.getPosition().x, m_sprite.getGlobalBounds().width / 2);
	return sf::Vector2f(m_sprite.getPosition().x + m_sprite.getGlobalBounds().width / 2, m_sprite.getPosition().y);
}

const sf::Vector2f& Invader::getPosition() const
{
	return m_sprite.getPosition();
}

const EntityType Invader::getType() const {
	return m_type;
}

const bool Invader::isAlive() const {
	return m_InvaderState != InvaderState::Destroyed;
}