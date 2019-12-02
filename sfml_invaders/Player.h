#pragma once
#include "Entity.h"
#include "Collidable.h"
#include "Keyboard.h"

enum class PlayerState {
	None = 0,
	Alive,
	Dead,
	Paused,
	PlayerStateEnd,
};
class Player : public Collidable
{
public:
	Player();
	virtual ~Player() = default;
	virtual const EntityType getType() const;
	virtual void onCollide (Collidable& other) override;
	void draw(sf::RenderTarget& target) override;
	void update(float ft) override;
	void input(Keyboard& kb);
	sf::Vector2f getFirePosition() const;
protected:
	const uint16_t getNumLives() const;
	const uint16_t getScore() const;
private:
	EntityType m_Type;
	PlayerState m_PlayerState;
	uint16_t m_numLives;
	uint16_t m_score;
	sf::Texture m_texture;
	sf::RectangleShape m_sprite;
	sf::Vector2f m_velocity;
};

