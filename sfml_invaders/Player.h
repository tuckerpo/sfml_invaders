#pragma once
#include "Collidable.h"
#include "Entity.h"
#include "Keyboard.h"
#include "Projectile.h"

#include <chrono>
#include <vector>

enum class PlayerState {
    None = 0,
    Alive,
    Dead,
    Paused,
    PlayerStateEnd,
};

class Player : public Collidable {
public:
    Player();
    virtual ~Player() = default;
    virtual const EntityType getType() const;
    virtual void onCollide(Collidable& other) override;
    void draw(sf::RenderTarget& target) override;
    void update(float ft) override;
    void input(Keyboard& kb);
    virtual const bool isAlive() const override;
    virtual const sf::Vector2f& getPosition() const override;
    sf::Vector2f getFirePosition() const;
    virtual void DoFire();

private:
    const uint16_t getNumLives() const;
    const uint16_t getScore() const;

private:
    EntityType m_Type;
    PlayerState m_PlayerState;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_BeginFireTime;
    std::vector<Projectile> m_Projectiles;
    uint16_t m_numLives;
    uint16_t m_score;
    sf::Texture m_texture;
    sf::RectangleShape m_sprite;
    sf::Vector2f m_velocity;
};
