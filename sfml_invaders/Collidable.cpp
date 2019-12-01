#include "Collidable.h"

bool Collidable::tryCollide(Collidable& other)
{
	if (this->getHitBox().intersects(other.getHitBox())) {
		this->onCollide(other);
		other.onCollide(*this);
		return true;
	}
	return false;
}

sf::FloatRect Collidable::getHitBox()
{
	return sf::FloatRect(
		this->getPosition().x,
		this->getPosition().y,
		0.0f,
		0.0f
	);
}
