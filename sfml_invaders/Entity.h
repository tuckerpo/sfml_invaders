#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Keyboard.h"

enum class EntityType
{
	None = 0,
	Player,
	Alien,
	UFO,
	Projectile,
	NumEntityTypes,
};

// Entity class
class Entity
{
public:
	Entity() = default;
	virtual ~Entity() = default;
	virtual const sf::Vector2f& getPosition() const;
	virtual const EntityType getType() const = 0;
	virtual void draw(sf::RenderTarget&) = 0;
	virtual void update(float dt) = 0;
	virtual void input(Keyboard&) = 0;
private:
	sf::Sprite m_Sprite;
	sf::Vector2f m_Pos;
	sf::Vector2u m_Size;
	EntityType m_entityType;
};

