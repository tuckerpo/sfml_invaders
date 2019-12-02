#include "Player.h"
#include <chrono>
#include <thread>

Player::Player() 
{
	m_Type = EntityType::Player;
	m_score = 0;
	m_numLives = 3;
	m_PlayerState = PlayerState::Alive;
	m_sprite.setSize({ 44, 32 });
	m_sprite.setPosition({ 1000 / 2, 1000 - 40.f });
	if (!m_texture.loadFromFile("res\\txrs\\si\\player.png")) {
		printf("Player::Player() - failed to load texture;");
	}
	m_sprite.setTexture(&m_texture);
	m_sprite.setTextureRect({ 0, 0, 11, 8 });
}


const EntityType Player::getType() const
{
	return m_Type;
}

void Player::update(float dt) {
	float width = m_sprite.getGlobalBounds().width;
	switch (m_PlayerState) {
	case PlayerState::None:
		break;
	case PlayerState::Alive:
		m_sprite.move(m_velocity * dt);
		//printf("Player x %f y %f velocity x %f velocity y %f\n", m_sprite.getPosition().x, m_sprite.getPosition().y, m_velocity.x, m_velocity.y);
		if (m_sprite.getPosition().x <= 0) {
			m_velocity.x = 1.f;
			m_sprite.setPosition(1.f, 1000 - 40.f);
		}
		else if (m_sprite.getPosition().x + width >= 1500) {
			m_velocity.x = -1.f;
			m_sprite.setPosition(1500 - 1.f - width, 1000 - 40.f);
		}
		m_velocity *= 0.95f;
		break;
	case PlayerState::Dead:
		break;
	}
}

void Player::input(Keyboard& kb)
{
	float speed = 20;
	if (kb.is_key_down(sf::Keyboard::Key::LShift))
		speed *= 2;

	if (kb.is_key_down(sf::Keyboard::Key::A)) {
		m_velocity.x -= speed;
	}
	else if (kb.is_key_down(sf::Keyboard::Key::D)) {
		m_velocity.x += speed;
	}
}

const sf::Vector2f& Player::getPosition() const
{
	return m_sprite.getPosition();
}

sf::Vector2f Player::getFirePosition() const
{
	return sf::Vector2f(m_sprite.getPosition().x + m_sprite.getGlobalBounds().width / 2, m_sprite.getPosition().y);
}


void Player::draw(sf::RenderTarget& target)
{
	if (m_numLives > 0) {
		target.draw(m_sprite);
	}
}

void Player::onCollide(Collidable& other)
{
	m_PlayerState = PlayerState::Dead;
}

const uint16_t Player::getNumLives() const {
	return m_numLives;
}

const uint16_t Player::getScore() const {
	return m_score;
}
