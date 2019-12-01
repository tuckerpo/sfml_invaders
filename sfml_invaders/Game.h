#pragma once

class Game {
public:
	Game() = default;
	virtual ~Game() = default;
	virtual void run() = 0;
	virtual void handleEvent() = 0;
	virtual const std::string& getName() const = 0;
};