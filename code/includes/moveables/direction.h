#pragma once

#include <SDL2/SDL.h>

enum Direction {
	STOP,
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Direction_utils {
	public:
		static Direction opposite(Direction dir);
    static Direction from_keys(const Uint8 * keys);
};