#pragma once
#include "Collidable.h"

enum class InvaderState {
	None = 0,
	Paused,
	Alive,
	Destroyed,
	NumInvaderStates,
};

class Invader : public Collidable
{
	Invader();
	virtual ~Invader() = default;

	virtual void onCollide(Collidable& other) override;

	virtual const EntityType getType() const override;

	virtual void draw(sf::RenderTarget&) override;

	virtual void update(float dt) override;

	virtual void input(Keyboard&) override;

private:
	sf::Texture m_texture;
	sf::Vector2f m_velocity;
	sf::RectangleShape m_sprite;
	InvaderState m_InvaderState;
	EntityType m_type;
};

