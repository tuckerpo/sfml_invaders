#include "Projectile.h"

Projectile::Projectile() {
	m_entityType = EntityType::Projectile;
	m_ProjectileState = ProjectileState::None;
}

Projectile::Projectile(const sf::Vector2f& vec, const ProjectileDirection& dir)
	: Collidable(12 / 1.5, 12)
{
	m_entityType = EntityType::Projectile;
	m_ProjectileState = ProjectileState::Active;
	m_projDir = dir;
	m_sprite.setSize({ 44, 32 });
	m_sprite.setPosition(vec);
	if (!m_texture.loadFromFile("res\\txrs\\si\\projectile.png")) {
		printf("Projectile::Projectile() - could not load texture\n");
	}
	m_sprite.setTexture(&m_texture);
	m_sprite.setTextureRect({ 0, 0, 7, 3 });
	m_velocity.y = 15;
}

void Projectile::onCollide(Collidable& other)
{
	m_ProjectileState = ProjectileState::Destroyed;
}

const EntityType Projectile::getType() const
{
	return m_entityType;
}

void Projectile::draw(sf::RenderTarget& target)
{
	target.draw(m_sprite);
}

void Projectile::update(float dt)
{
	switch (m_ProjectileState) {
	case ProjectileState::Active:
		m_velocity.y += 600 * static_cast<float>(m_projDir) * dt;
		m_sprite.move(m_velocity * dt);
		printf("Projectile %f %f\n", m_velocity.x, m_velocity.y);
		break;
	case ProjectileState::Destroyed:
		m_velocity.y *= 18388345857834; //TODO: fix this
		break;
	case ProjectileState::None:
	default:
		break;
	}
}

void Projectile::input(Keyboard&)
{
	return;
}
