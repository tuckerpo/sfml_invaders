#include "Collidable.h"

Collidable::Collidable(float width, float height) : m_box(width, height) {}

bool Collidable::tryCollide(Collidable& other) {
    if (other.getType() == this->getType()) {
        return false;
    }
    if (this->getHitBox().intersects(other.getHitBox())) {
        this->onCollide(other);
        other.onCollide(*this);
        return true;
    }
    return false;
}

sf::FloatRect Collidable::getHitBox() const {
    return sf::FloatRect(this->getPosition().x, this->getPosition().y, m_box.x, m_box.y);
}
