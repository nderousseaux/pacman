#include "field.h"
#include "intersection.h"

/* #region Variables de classe */
const SDL_Rect Field::SPRITES[3] = {
	{ 201,4, 166,214 },
	{ 370,4, 166,214 },
	{ 541,4, 166,214 }
};
/* #endregion */

/* #region Constructeur/Destructeur */
Field::Field(): Element(0,0) {
	set_current_sprite(1);
	// On génère les intersections
	Intersection::create_intersections();
}

Field::~Field() {}
/* #endregion */

/* #region Méthodes */
// Fait réagir le terrain
void Field::react() {}

// Change le sprite du terrain
void Field::animate() {}
/* #endregion */