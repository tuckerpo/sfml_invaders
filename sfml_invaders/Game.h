#pragma once

enum class GameState {
	None = 0,
	Paused = 1,
	Playing = 2,
	Over = 3,
};

class Game {
public:
	Game() = default;
	virtual ~Game() = default;
	virtual void run() = 0;
	virtual void handleEvent() = 0;
	virtual const std::string& getName() const = 0;
};