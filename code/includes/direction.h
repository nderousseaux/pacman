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
		static Direction opposite(Direction dir); // Retourne la direction opposée à dir
    static Direction from_keys(const Uint8 * keys); // Retourne la direction correspondant aux touches appuyées
};