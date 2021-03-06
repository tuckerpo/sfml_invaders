#pragma once
#include "Keyboard.h"

#include <SFML/Graphics.hpp>
#include <vector>

enum class EntityType {
    None = 0,
    Player,
    Invader,
    UFO,
    Projectile,
    NumEntityTypes,
};

// Entity class
class Entity {
public:
    Entity() = default;
    virtual ~Entity() = default;
    virtual const EntityType getType() const = 0;
    virtual void draw(sf::RenderTarget&) = 0;
    virtual void update(float dt) = 0;
    virtual void input(Keyboard&) = 0;
    virtual const bool isAlive() const = 0;

private:
    sf::Sprite m_Sprite;
    sf::Vector2f m_Pos;
    sf::Vector2u m_Size;
    EntityType m_entityType;
};
