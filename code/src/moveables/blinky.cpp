#include "blinky.h"

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