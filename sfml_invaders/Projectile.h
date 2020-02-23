#pragma once
#include "Collidable.h"
#include <SFML/Graphics.hpp>

enum class ProjectileDirection {
	Up = -1,
	None = 0,
	Down = 1,
};

enum class ProjectileState {
	None = 0,
	Active,
	Destroyed,
	Paused,
	NumProjectileStates,
};

class Projectile : public Collidable
{
public:
	Projectile();
	Projectile(const sf::Vector2f&, const ProjectileDirection&);
	virtual ~Projectile() = default;
	virtual void onCollide(Collidable& other) override;
	virtual const EntityType getType() const override;
	virtual void draw(sf::RenderTarget&) override;
	virtual void update(float dt) override;
	virtual void input(Keyboard&) override;
	virtual const sf::Vector2f& getPosition() const override;
	virtual const bool isAlive() const override;
private:
	sf::Texture m_texture;
	sf::RectangleShape m_sprite;
	sf::Vector2f m_velocity;
	EntityType m_entityType;
	ProjectileState m_ProjectileState;
	ProjectileDirection m_projDir;
};

