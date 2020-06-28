#pragma once

#include "ICommand.h"
#include "InputDevice.h"

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <chrono>
#include <iostream>
#include <map>

constexpr std::chrono::milliseconds DEFAULT_DEBOUNCE_MS = std::chrono::milliseconds(500);

// Class that holds the state of key events
class Keyboard : public InputDevice {
public:
    Keyboard();
    virtual ~Keyboard() = default;
    void Update(sf::Event e) override;
    bool is_key_down(sf::Keyboard::Key k);
    bool is_key_up(sf::Keyboard::Key k);

private:
    std::map<sf::Keyboard::Key, bool> m_keymap;
    std::chrono::steady_clock::time_point m_DebounceDt;
};
