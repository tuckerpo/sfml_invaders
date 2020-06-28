#include "Invader.h"

float Invader::m_YGap = 0.f;

Invader::Invader(uint8_t idx) : Collidable(48, 32) {
    m_type = EntityType::Invader;
    m_InvaderState = InvaderState::Alive;
    m_FiringState = FiringState::None;
    m_BeginFireTime = std::chrono::steady_clock::now();
    m_sprite.setSize({48, 34});
    if (idx % m_rowShiftModulo == 0) {
        m_YGap += 50.f;
    }
    m_sprite.setPosition({((1500 / 2) / 2) + m_XGap * static_cast<float>(idx % m_rowShiftModulo),
                          1000 - m_initialYOff + m_YGap});

    if (!m_texture.loadFromFile("res\\txrs\\si\\invaders.png")) {
        printf("Invader::Invader() texture loading failed\n");
    }
    m_sprite.setTexture(&m_texture);
    m_sprite.setTextureRect({0, 0, 12, 8});
}

void Invader::onCollide(Collidable& other) {
    if (other.getType() != this->getType()) {
        m_InvaderState = InvaderState::Destroyed;
    }
}

void Invader::draw(sf::RenderTarget& target) {
    target.draw(m_sprite);
    for (auto& projectile : m_Projectiles) {
        projectile.draw(target);
    }
}

void Invader::update(float dt) {
    for (auto& projectile : m_Projectiles) {
        projectile.update(dt);
    }

    switch (m_InvaderState) {
        case InvaderState::None:
            break;
        case InvaderState::Paused:
            break;
        case InvaderState::Destroyed:
            m_sprite.move({-10000, -10000});
            break;
    }
}

void Invader::input(Keyboard& kb) {
    for (auto& projectile : m_Projectiles) {
        projectile.input(kb);
    }
    if (kb.is_key_down(sf::Keyboard::Key::Pause)) {
        m_InvaderState = InvaderState::Paused;
    }
}

sf::Vector2f Invader::getFirePosition() const {
    return sf::Vector2f(m_sprite.getPosition().x + m_sprite.getGlobalBounds().width / 2,
                        m_sprite.getPosition().y);
}

const sf::Vector2f& Invader::getPosition() const { return m_sprite.getPosition(); }

const EntityType Invader::getType() const { return m_type; }

const bool Invader::isAlive() const { return m_InvaderState != InvaderState::Destroyed; }

void Invader::DoFire() {
    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    if (now > m_BeginFireTime + std::chrono::milliseconds(1000)) {
        m_Projectiles.emplace_back(getFirePosition(), ProjectileDirection::Down);
        m_BeginFireTime = now;
        m_FiringState = FiringState::Firing;
    }
}

bool Invader::IsFiring() const { return m_FiringState == FiringState::Firing; }

std::vector<Projectile> Invader::GetProjectiles() const { return m_Projectiles; }