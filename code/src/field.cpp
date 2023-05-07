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

	// On génère les intersections
	Intersection::create_intersections();

	// On génère les points/gommes
	create_gommes_dots();
}

Field::~Field() {}
/* #endregion */

/* #region Méthodes */
// Met tout les points/gommes dans les vecteurs
void Field::create_gommes_dots() {
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

// Retourne vrai si le terrain est vide
bool Field::is_empty() {
	return _dots.size() == 0 && _gommes.size() == 0;
}

// Fait réagir le terrain
void Field::react() {}

// Change le sprite du terrain
void Field::animate() {
	// Si on est en train de jouer, le sprite est 1.
	if (Game::get_instance()->get_state() != GAME_WIN )
		set_current_sprite(1);

	// Sinon, on a gagné, le sprite clignote
	else if (Game::get_instance()->get_state() == GAME_WIN) {

		// On change le sprite toutes les 10 frames
		int phase = (_animation / 10)%2;

		set_current_sprite(phase + 1);

		// Si on a fini l'animation, on recommence le jeu
		if (_animation == 100) {
			_animation = 0;
			Game::get_instance()->restart(true);
			return;
		}
		_animation++;
	}

}
/* #endregion */