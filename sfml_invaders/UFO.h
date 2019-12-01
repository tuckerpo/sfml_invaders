#pragma once
#include "Entity.h"
#include "Collidable.h"
#include "Animation.h"

enum class UFOState
{
	None = 0,
	Paused,
	Flying,
	Destroyed,
	NumUfoStates
};

enum class UFODir {
	None = 0,
	FromLeft,
	FromRight,
};

class UFO : public Collidable
{
public:
	UFO();

	virtual ~UFO() = default;

	void update(float dt) override;

	void input(Keyboard&) override;
	
	const EntityType getType() const override;

	void draw(sf::RenderTarget& target) override;

	virtual void onCollide(Collidable& other) override;

protected:
	void getInitialDir();

private:
	UFOState m_ufo_state;
	EntityType m_Type;
	sf::Texture m_texture;
	sf::RectangleShape m_sprite;
	sf::Vector2f m_velocity;
	Animation m_animation;
	UFODir m_dir;
	float m_speed;
};

