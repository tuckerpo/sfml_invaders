#include <SFML/Graphics.hpp>
#include "Keyboard.h"
#include "SpaceInvaders.h"

int main() {
	SpaceInvaders *si = new SpaceInvaders();
	si->run();
	delete si;
}