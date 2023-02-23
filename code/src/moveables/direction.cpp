#include "direction.h"

Direction Direction_utils::opposite(Direction dir) {
	switch (dir) {
		case UP:
			return DOWN;
		case DOWN:
			return UP;
		case LEFT:
			return RIGHT;
		case RIGHT:
			return LEFT;
		default:
			return STOP;
	}
}

Direction Direction_utils::from_keys(const Uint8 * keys) {
	if (keys[SDL_SCANCODE_UP])
		return UP;
	else if (keys[SDL_SCANCODE_DOWN])
		return DOWN;
	else if (keys[SDL_SCANCODE_LEFT])
		return LEFT;
	else if (keys[SDL_SCANCODE_RIGHT])
		return RIGHT;
	else
		return STOP;
}