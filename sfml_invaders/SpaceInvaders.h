#pragma once
#include "Game.h"
#include "Invader.h"
#include "Keyboard.h"
#include "Player.h"
#include "Projectile.h"
#include "UFO.h"

#include <SFML/Graphics.hpp>

// Extends the Game interface for the game Space Invaders
class SpaceInvaders : public Game {
public:
    SpaceInvaders();
    virtual ~SpaceInvaders();
    // main game loop
    virtual void run() override;
    void handleEvent() override;
    virtual const std::string& getName() const override;

private:
    std::vector<Entity*> getEntitiesByType(const EntityType& et);
    void invadersFire();
    void doCollisions();
    void playerFire();
    bool IsGamePaused();
    GameState m_GameState;
    std::chrono::steady_clock::time_point m_InvaderFired;
    std::chrono::steady_clock::time_point m_LastPausedTime;
    std::unique_ptr<Keyboard> kb;
    std::vector<Collidable*> m_entities;
    std::vector<Projectile> m_projectiles;
    sf::RenderWindow m_window;
    const std::string m_name = "Space Invaders";
};
