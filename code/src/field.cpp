#include "../includes/field.h"

/* Variables de classe */
const SDL_Rect Field::SPRITES[3] = {
	{ 201,4, 166,214 },
	{ 370,4, 166,214 },
	{ 541,4, 166,214 }
};

/* Constructeur/Destructeur */
Field::Field(): Element(0,0) {
	set_current_sprite(0);
}

Field::~Field() {}

/* Méthodes */
// Fait réagir le terrain
void Field::think() {}

// Change le sprite du terrain
void Field::animate() {}