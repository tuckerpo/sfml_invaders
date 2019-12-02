#include "Collidable.h"


Collidable::Collidable(float width, float height)
	: m_box(width, height)
{
}

bool Collidable::tryCollide(Collidable& other)
{
	if (this->getHitBox().intersects(other.getHitBox())) {
		this->onCollide(other);
		other.onCollide(*this);
		printf("Collision!\n");
		return true;
	}
	return false;
}

sf::FloatRect Collidable::getHitBox()
{
	return sf::FloatRect(
		this->getPosition().x,
		this->getPosition().y,
		m_box.x,
		m_box.y
	);
}
