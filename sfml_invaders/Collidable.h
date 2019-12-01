#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>


// Collidable class
class Collidable : public Entity
{
public:
	Collidable() = default;
	virtual ~Collidable() = default;
	
	bool tryCollide(Collidable& other);
	sf::FloatRect getHitBox();

	virtual void onCollide(Collidable& other) = 0;
};

