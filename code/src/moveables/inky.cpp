#include "../../includes/moveables/inky.h"

// /* Variables de classe */
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

/* Constructeur/Destructeur */
Inky::Inky():
	Fantom(INITIAL_X, INITIAL_Y) {}

Inky::~Inky() {}