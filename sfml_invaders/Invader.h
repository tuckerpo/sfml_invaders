#pragma once
#include "Collidable.h"
#include "Projectile.h"

#include <chrono>

enum class InvaderState {
    None = 0,
    Paused,
    Alive,
    Destroyed,
    NumInvaderStates,
};

enum class FiringState {
    None = 0,
    Firing = 1,
};

class Invader : public Collidable {
public:
    Invader() = default;
    Invader(uint8_t idx);
    virtual ~Invader() = default;
    virtual void onCollide(Collidable& other) override;
    virtual const EntityType getType() const override;
    virtual void draw(sf::RenderTarget&) override;
    virtual void update(float dt) override;
    virtual void input(Keyboard&) override;
    sf::Vector2f getFirePosition() const;
    virtual const sf::Vector2f& getPosition() const override;
    const bool isAlive() const override;
    virtual void DoFire();
    virtual bool IsFiring() const;
    virtual std::vector<Projectile> GetProjectiles() const;

private:
    sf::Texture m_texture;
    sf::Vector2f m_velocity;
    sf::RectangleShape m_sprite;
    InvaderState m_InvaderState;
    FiringState m_FiringState;
    EntityType m_type;
    std::vector<Projectile> m_Projectiles;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_BeginFireTime;
    const uint8_t m_rowShiftModulo = 11;
    const uint8_t m_columnShiftModulo = 5;
    const float m_initialYOff = 800.f;
    static float m_YGap;
    const float m_XGap = 75.f;
};
