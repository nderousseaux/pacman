#include "field.h"
#include "intersection.h"
#include "game.h"

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

	// On génère les points
	create_dots();
}

Field::~Field() {}
/* #endregion */

/* #region Méthodes */
// Place les points sur le terrain
void Field::create_dots() {
	// On génère les points
	Dot::create_dots(&_dots);
}

// Supprime tout les points du terrain
void Field::remove_all_dots() {
	for (Dot *dot : _dots) {
		dot->remove();
	}
	_dots.clear();
}

// Supprime un point du terrain
void Field::remove_dot(Dot *dot) {
	// On supprime le point
	_dots.erase(std::remove(_dots.begin(), _dots.end(), dot), _dots.end());

	dot->remove();
	// Si on a plus de points, on a gagné
	if(_dots.size() == 0 && _state != FIELD_WIN) {
		Game::get_instance()->win();
	}
}

// Fait réagir le terrain
void Field::react() {}

// Change le sprite du terrain
void Field::animate() {
	if (_state == FIELD_NORMAL) {
		set_current_sprite(1);
	} else if (_state == FIELD_WIN) {
		// On change le sprite toutes les 10 frames
		int phase = (_animation / 10)%2;		
		set_current_sprite(phase + 1);

		if (_animation == 100) {
			_state = FIELD_NORMAL;
			_animation = 0;
			// On efface les points
			remove_all_dots();

			// On quite l'application
			Game::get_instance()->quit();
		}
		else {
			_animation++;
		}
	}

}
/* #endregion */