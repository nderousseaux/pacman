#include "inky.h"
#include "game.h"

/* #region Variables de classe */
const SDL_Rect Inky::SPRITES[8] = {
  { 72, 160, 14, 14 },  // Haut 1
  { 89, 160, 14, 14 },  // Haut 2
  { 106, 160, 14, 14 }, // Bas 1
  { 123, 160, 14, 14 }, // Bas 2
  { 4, 160, 14, 14 },   // Droite 1
  { 21, 160, 14, 14 },  // Droite 2
  { 38, 160, 14, 14 },  // Gauche 1
  { 55, 160, 14, 14 }   // Gauche 2
};

Intersection * Inky::START = nullptr; // Intersection de départ de Inky (initialisée par Intersection)
/* #endregion */
 
/* #region Constructeur/Destructeur */
Inky::Inky():
	Fantom(INITIAL_X, INITIAL_Y) {
    _destination = START;
  }

Inky::~Inky() {}
/* #endregion */

/* #region Méthodes */
 // Retourne la cible du fantôme en mode chase
SDL_Rect * Inky::get_target_chase() {
  SDL_Rect * pacman_pos = Game::get_instance()->get_element<Pacman>()->get_pos();

  // 2 fois la distance entre blinky et pacman + 2 cases
  int x = pacman_pos->x;
  int y = pacman_pos->y;
  switch(Game::get_instance()->get_element<Pacman>()->get_direction()){
    case RIGHT:
      x+=48;
      break;
    case DOWN:
      y+=48;
      break;    
    case LEFT:
      x-=48;
      break;    
    case UP:
      y-=48;
      break;
    default:
      break; 
  }
  // On calcule la position de la cible (Prolongation du vecteur Blinky-Pacman)
  SDL_Rect * blinky_pos = Game::get_instance()->get_element<Blinky>()->get_pos();  
  return  new SDL_Rect{2*x - blinky_pos->x, 2*y - blinky_pos->y,0,0};
}
// Retourne la cible du fantôme en mode scatter
SDL_Rect * Inky::get_target_scatter() {
  return new SDL_Rect{SCATTER_X, SCATTER_Y, 0, 0};
}
// Retourne la cible du fantôme en mode eaten
SDL_Rect * Inky::get_target_origin() {
  return new SDL_Rect{INITIAL_X, INITIAL_Y, 0, 0};
}
/* #endregion */