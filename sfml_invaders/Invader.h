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
public:
	Invader() = default;

	Invader(uint8_t idx);

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
	const uint8_t m_rowShiftModulo = 11;
	const uint8_t m_columnShiftModulo = 5;
	const float m_initialYOff = 800.f;
	static float m_YGap;
	const float m_XGap = 75.f;
};

