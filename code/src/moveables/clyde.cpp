#include "clyde.h"
#include "game.h"

/* #region Variables de classe */
const SDL_Rect Clyde::SPRITES[8] = {
  { 72, 178, 14, 14 },  // Haut 1
  { 89, 178, 14, 14 },  // Haut 2
  { 106, 178, 14, 14 }, // Bas 1
  { 123, 178, 14, 14 }, // Bas 2
  { 4, 178, 14, 14 },   // Droite 1
  { 21, 178, 14, 14 },  // Droite 2
  { 38, 178, 14, 14 },  // Gauche 1
  { 55, 178, 14, 14 }   // Gauche 2
};

Intersection * Clyde::START = nullptr; // Intersection de départ de Clyde (initialisée par Intersection)
/* #endregion */

/* #region Constructeur/Destructeur */
Clyde::Clyde():
	Fantom(INITIAL_X, INITIAL_Y) {
    _destination = START;
  }

Clyde::~Clyde() {}
/* #endregion */

/* #region Méthodes */
// Retourne la cible du fantôme en mode chase
SDL_Rect * Clyde::get_target_chase() {
  // Si clyde est proche de pacman, il va à sa position de départ
  if(Moveable::get_distance(get_pos(), Game::get_instance()->get_element<Pacman>()->get_pos()) < 188)
    return get_target_scatter();
  else  
    return Game::get_instance()->get_element<Pacman>()->get_pos();
}
// Retourne la cible du fantôme en mode scatter
SDL_Rect * Clyde::get_target_scatter() {
  return new SDL_Rect{SCATTER_X, SCATTER_Y, 0, 0};
}
// Retourne la cible du fantôme en mode eaten
SDL_Rect * Clyde::get_target_origin() {
  return new SDL_Rect{INITIAL_X, INITIAL_Y, 0, 0};
}
/* #endregion */