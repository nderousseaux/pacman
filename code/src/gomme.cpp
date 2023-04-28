#include "gomme.h"
#include "window.h"
#include "field.h"

/* #region Variables de classe */
const SDL_Rect Gomme::SPRITES[1] = {
	{ 9,79, 7,7 }
};

// Liste des coordonnées des points
const int Gomme::GOMMES[4][2] = {
	{ 30, 93 },
	{ 30, 638 },
	{ 606, 93 },
	{ 606, 638 },
};

/* #endregion */

/* #region Constructeur/Destructeur */
Gomme::Gomme(int x, int y): Element(x,y) {
	set_current_sprite(0);
	Window::get_instance()->insert_element(this);
}

Gomme::~Gomme() {
	Window::get_instance()->remove_element(this);
	// On se supprime du field
	Field::get_instance()->remove_gomme(this);
	
}
/* #endregion */

/* #region Méthodes statique */
// Crée tout les points
void Gomme::create_gommes(std::vector<Gomme *> & gommes) {
	for (int i = 0; i < 4; i++) {
		gommes.push_back(new Gomme(Gomme::GOMMES[i][0], Gomme::GOMMES[i][1]));
	}
}

/* #endregion */

/* #region Méthodes */
// Fait réagir le point
void Gomme::react() {}

// Change le sprite du point
void Gomme::animate() {}

/* #endregion */
