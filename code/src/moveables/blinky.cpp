#include "blinky.h"
#include "game.h"

/* #region Variables de classe */
const SDL_Rect Blinky::SPRITES[8] = {
  { 72, 124, 14, 14 },  // Haut 1
  { 89, 124, 14, 14 },  // Haut 2
  { 106, 124, 14, 14 }, // Bas 1
  { 123, 124, 14, 14 }, // Bas 2
  { 4, 124, 14, 14 },   // Droite 1
  { 21, 124, 14, 14 },  // Droite 2
  { 38, 124, 14, 14 },  // Gauche 1
  { 55, 124, 14, 14 }   // Gauche 2
};

Intersection * Blinky::START = nullptr; // Intersection de départ de Blinky (initialisée par Intersection)
/* #endregion */

/* #region Constructeur/Destructeur */
Blinky::Blinky():
	Fantom(INITIAL_X, INITIAL_Y) {
    _destination = START;
  }

Blinky::~Blinky() {}
/* #endregion */

/* #region Méthodes */
 // Retourne la cible du fantôme en mode chase
SDL_Rect * Blinky::get_target_chase() {
  return Game::get_instance()->get_element<Pacman>()->get_pos();
}
// Retourne la cible du fantôme en mode scatter
SDL_Rect * Blinky::get_target_scatter() {
  return new SDL_Rect{SCATTER_X, SCATTER_Y, 0, 0};
}
// Retourne la cible du fantôme en mode eaten
SDL_Rect * Blinky::get_target_origin() {
  return new SDL_Rect{INITIAL_X, INITIAL_Y, 0, 0};
}
/* #endregion */