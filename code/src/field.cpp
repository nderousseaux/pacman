#include "field.h"
#include "intersection.h"
#include "game.h"
#include <algorithm>

/* #region Variables de classe */
const SDL_Rect Field::SPRITES[3] = {
	{ 201,4, 166,214 },
	{ 370,4, 166,214 },
	{ 541,4, 166,214 }
};
// Instance unique de la classe
Field * Field::_instance = nullptr;
/* #endregion */

/* 1 tiles fait 166/28 = 5,9 environ soit pour 8 tiles 47,4285 */

/* #region Constructeur/Destructeur */
Field::Field(): Element(0,0) {
	if (_instance != nullptr)
    throw "Field already exists";
  Field::_instance = this;
	set_current_sprite(1);
	// On génère les intersections
	Intersection::create_intersections();

	// On génère les points
	create_dots();
}

Field::~Field() {}
/* #endregion */

/* #region Méthodes */
// Met tout les points dans le vecteur
void Field::create_dots() {
	// On génère les points
	Dot::create_dots(_dots);

	Gomme::create_gommes(_gommes);
}


// Supprime un point du terrain
void Field::remove_dot(Dot * dot) {
	// On supprime le point de la liste
	_dots.erase(std::remove(_dots.begin(), _dots.end(), dot), _dots.end());
}

// Supprime un point du terrain
void Field::remove_gomme(Gomme * gomme) {
	// On supprime le point de la liste
	_gommes.erase(std::remove(_gommes.begin(), _gommes.end(), gomme), _gommes.end());
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

			// On recommence le jeu
			Game::get_instance()->restart(true);

		}
		else {
			_animation++;
		}
	}

}
/* #endregion */