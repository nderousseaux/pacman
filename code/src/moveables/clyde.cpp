#include "clyde.h"

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