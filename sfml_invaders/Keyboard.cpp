#include "Keyboard.h"

// initialize keymap
Keyboard::Keyboard() {
    for (std::size_t i = 0; i < sf::Keyboard::KeyCount; i++) {
        m_keymap.insert(
            std::make_pair<sf::Keyboard::Key, bool>(static_cast<sf::Keyboard::Key>(i), false));
    }

    m_DebounceDt = std::chrono::steady_clock::now();
}

void Keyboard::Update(sf::Event e) {
    switch (e.type) {
        case sf::Event::KeyPressed: {
            m_keymap.at(e.key.code) = true;
            break;
        }
        case sf::Event::KeyReleased: {
            m_keymap.at(e.key.code) = false;
            break;
        }
        default: {
            break;
        }
    }
}

bool Keyboard::is_key_down(sf::Keyboard::Key k) { return m_keymap.at(k); }

bool Keyboard::is_key_up(sf::Keyboard::Key k) { return !m_keymap.at(k); }