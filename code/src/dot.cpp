#include "dot.h"
#include "window.h"

/* #region Variables de classe */
const SDL_Rect Dot::SPRITES[1] = {
	{ 4,81, 2,2 }
};
/* #endregion */

/* #region Constructeur/Destructeur */
Dot::Dot(int x, int y): Element(x,y) {
	set_current_sprite(0);
}

Dot::~Dot() {}
/* #endregion */

/* #region Méthodes statique */
// Crée tout les points
void Dot::create_dots(std::vector<Dot *> * dots) {
	// On génère les points
	// Colonne 1 et n
	for(int c : { 40, 616 } ) {
		dots->push_back(add_dot(new Dot(  c,  40)));
		dots->push_back(add_dot(new Dot(  c,  72)));
		dots->push_back(add_dot(new Dot(  c, 136)));
		dots->push_back(add_dot(new Dot(  c, 168)));
		dots->push_back(add_dot(new Dot(  c, 200)));
		dots->push_back(add_dot(new Dot(  c, 232)));
		dots->push_back(add_dot(new Dot(  c, 264)));
		dots->push_back(add_dot(new Dot(  c, 584)));
		dots->push_back(add_dot(new Dot(  c, 616)));
		dots->push_back(add_dot(new Dot(  c, 744)));
		dots->push_back(add_dot(new Dot(  c, 776)));
		dots->push_back(add_dot(new Dot(  c, 808)));	
	}
	

	// Colonne 2 et n-1
	for(int c: { 72, 584 } ) {
		dots->push_back(add_dot(new Dot(  c,  40)));
		dots->push_back(add_dot(new Dot(  c, 168)));
		dots->push_back(add_dot(new Dot(  c, 264)));
		dots->push_back(add_dot(new Dot(  c, 584)));
		dots->push_back(add_dot(new Dot(  c, 648)));
		dots->push_back(add_dot(new Dot(  c, 744)));
		dots->push_back(add_dot(new Dot(  c, 808)));
	}

	// Colonne 3 et n-2
	for(int c: { 104, 552 } ) {
		dots->push_back(add_dot(new Dot(  c,  40)));
		dots->push_back(add_dot(new Dot(  c, 168)));
		dots->push_back(add_dot(new Dot(  c, 264)));
		dots->push_back(add_dot(new Dot(  c, 584)));
		dots->push_back(add_dot(new Dot(  c, 648)));
		dots->push_back(add_dot(new Dot(  c,	680)));
		dots->push_back(add_dot(new Dot(  c,	712)));
		dots->push_back(add_dot(new Dot(  c, 744)));
		dots->push_back(add_dot(new Dot(  c, 808)));
	}

	// Colonne 4 et n-3
	for(int c: { 136, 520 } ) {
		dots->push_back(add_dot(new Dot(  c,  40)));
		dots->push_back(add_dot(new Dot(  c, 168)));
		dots->push_back(add_dot(new Dot(  c, 264)));
		dots->push_back(add_dot(new Dot(  c, 584)));
		dots->push_back(add_dot(new Dot(  c, 744)));
		dots->push_back(add_dot(new Dot(  c, 808)));
	}

	// Colonne 5 et n-4
	for(int c: { 168, 488 } ) {
		dots->push_back(add_dot(new Dot(  c,  40)));
		dots->push_back(add_dot(new Dot(  c,  72)));
		dots->push_back(add_dot(new Dot(  c, 104)));
		dots->push_back(add_dot(new Dot(  c, 136)));
		dots->push_back(add_dot(new Dot(  c, 168)));
		dots->push_back(add_dot(new Dot(  c, 200)));
		dots->push_back(add_dot(new Dot(  c, 232)));
		dots->push_back(add_dot(new Dot(  c, 264)));
		dots->push_back(add_dot(new Dot(  c, 296)));
		dots->push_back(add_dot(new Dot(  c, 328)));
		dots->push_back(add_dot(new Dot(  c, 360)));
		dots->push_back(add_dot(new Dot(  c, 392)));
		dots->push_back(add_dot(new Dot(  c, 424)));
		dots->push_back(add_dot(new Dot(  c, 456)));
		dots->push_back(add_dot(new Dot(  c, 488)));
		dots->push_back(add_dot(new Dot(  c, 520)));
		dots->push_back(add_dot(new Dot(  c, 552)));
		dots->push_back(add_dot(new Dot(  c, 584)));
		dots->push_back(add_dot(new Dot(  c, 616)));
		dots->push_back(add_dot(new Dot(  c, 648)));
		dots->push_back(add_dot(new Dot(  c, 680)));
		dots->push_back(add_dot(new Dot(  c, 712)));
		dots->push_back(add_dot(new Dot(  c, 744)));
		dots->push_back(add_dot(new Dot(  c, 808)));
	}

	// Colonne 6 et n-5
	for(int c: { 200, 456 } ) {
		dots->push_back(add_dot(new Dot(  c,  40)));
		dots->push_back(add_dot(new Dot(  c, 168)));
		dots->push_back(add_dot(new Dot(  c, 584)));
		dots->push_back(add_dot(new Dot(  c, 648)));
		dots->push_back(add_dot(new Dot(  c, 808)));
	}

	// Colonne 7 et n-6
	for(int c: { 232, 424 } ) {
		dots->push_back(add_dot(new Dot(  c,  40)));
		dots->push_back(add_dot(new Dot(  c, 168)));
		dots->push_back(add_dot(new Dot(  c, 200)));
		dots->push_back(add_dot(new Dot(  c, 232)));
		dots->push_back(add_dot(new Dot(  c, 264)));
		dots->push_back(add_dot(new Dot(  c, 584)));
		dots->push_back(add_dot(new Dot(  c, 648)));
		dots->push_back(add_dot(new Dot(  c, 680)));
		dots->push_back(add_dot(new Dot(  c, 712)));
		dots->push_back(add_dot(new Dot(  c, 744)));
		dots->push_back(add_dot(new Dot(  c, 808)));
	}

	// Colonne 8 et n-7
	for(int c: { 264, 392 } ) {
		dots->push_back(add_dot(new Dot(  c,  40)));
		dots->push_back(add_dot(new Dot(  c, 168)));
		dots->push_back(add_dot(new Dot(  c, 264)));
		dots->push_back(add_dot(new Dot(  c, 584)));
		dots->push_back(add_dot(new Dot(  c, 648)));
		dots->push_back(add_dot(new Dot(  c, 744)));
		dots->push_back(add_dot(new Dot(  c, 808)));
	}

	// Colonne 9 et n-8
	for(int c: { 296, 360 } ) {
		dots->push_back(add_dot(new Dot(  c,  40)));
		dots->push_back(add_dot(new Dot(  c,  72)));
		dots->push_back(add_dot(new Dot(  c, 104)));
		dots->push_back(add_dot(new Dot(  c, 136)));
		dots->push_back(add_dot(new Dot(  c, 168)));
		dots->push_back(add_dot(new Dot(  c, 264)));
		dots->push_back(add_dot(new Dot(  c, 584)));
		dots->push_back(add_dot(new Dot(  c, 616)));
		dots->push_back(add_dot(new Dot(  c, 648)));
		dots->push_back(add_dot(new Dot(  c, 744)));
		dots->push_back(add_dot(new Dot(  c, 776)));
		dots->push_back(add_dot(new Dot(  c, 808)));
	}
	
	// Colonne centrale
	dots->push_back(add_dot(new Dot( 328, 168)));
	dots->push_back(add_dot(new Dot( 328, 808)));

}

// Ajoute le point à la fenêtre et à la liste des points
Dot * Dot::add_dot(Dot * dot) {
	Window::get_instance()->add_element(dot);
	return dot;
}


/* #endregion */

/* #region Méthodes */
// Fait réagir le point
void Dot::react() {}

// Change le sprite du point
void Dot::animate() {}

// On supprime le point
void Dot::remove() {
	Window::get_instance()->remove_element(this);
	delete this;
}
/* #endregion */
