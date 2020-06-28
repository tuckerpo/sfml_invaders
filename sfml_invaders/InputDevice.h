#pragma once
#include <SFML/Window/Event.hpp>

class InputDevice {
public:
    InputDevice() = default;
    virtual ~InputDevice() = default;
    virtual void Update(sf::Event) = 0;

private:
};
