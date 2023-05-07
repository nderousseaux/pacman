#include "pinky.h"
#include "game.h"

/* region Variables de classe */
const SDL_Rect Pinky::SPRITES[8] = {
  { 72, 142, 14, 14 }, // Haut 1
  { 89, 142, 14, 14 }, // Haut 2
  { 106, 142, 14, 14 }, // Bas 1
  { 123, 142, 14, 14 }, // Bas 2
  { 4, 142, 14, 14 }, // Droite 1
  { 21, 142, 14, 14 }, // Droite 2
  { 38, 142, 14, 14 }, // Gauche 1
  { 55, 142, 14, 14 }  // Gauche 2
};

Intersection * Pinky::START = nullptr; // Intersection de départ de Pinky (initialisée par Intersection)
/* endregion */

/* #region Constructeur/Destructeur */
Pinky::Pinky():
	Fantom(INITIAL_X, INITIAL_Y) {
    _destination = START;
  }

Pinky::~Pinky() {}
/* #endregion */

/* #region Méthodes */
// Retourne la cible du fantôme en mode chase
SDL_Rect * Pinky::get_target_chase() {
  // pacman + 4 cases
  SDL_Rect * pacman_pos = Game::get_instance()->get_element<Pacman>()->get_pos();
  int x = pacman_pos->x;
  int y = pacman_pos->y;
  switch(Game::get_instance()->get_element<Pacman>()->get_direction()){
    case RIGHT:
      x+=96;
      break;
    case DOWN:
      y+=96;
      break;    
    case LEFT:
      x-=96;
      break;    
    case UP:
      y-=96;
      x-=96;
      break;
    default:
      break; 
  }
  return new SDL_Rect{x, y, 0, 0};
}
// Retourne la cible du fantôme en mode scatter
SDL_Rect * Pinky::get_target_scatter() {
  return new SDL_Rect{SCATTER_X, SCATTER_Y, 0, 0};
}
// Retourne la cible du fantôme en mode eaten
SDL_Rect * Pinky::get_target_origin() {
  // return new SDL_Rect{INITIAL_X, INITIAL_Y, 0, 0};
  return new SDL_Rect{Game::get_instance()->get_element<Blinky>()->INITIAL_X,Game::get_instance()->get_element<Blinky>()->INITIAL_Y,0,0};
}
/* #endregion */