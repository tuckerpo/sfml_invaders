#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>


// Collidable class
class Collidable : public Entity
{
public:
	Collidable() = default;
	Collidable(float w, float h);
	virtual ~Collidable() = default;
	virtual const sf::Vector2f& getPosition() const = 0;
	bool tryCollide(Collidable& other);
	sf::FloatRect getHitBox() const;


	virtual void onCollide(Collidable& other) = 0;

private:
	sf::Vector2f m_box;
};

