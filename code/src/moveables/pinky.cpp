#include "../../includes/moveables/pinky.h"

// /* Variables de classe */
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

/* Constructeur/Destructeur */
Pinky::Pinky():
	Fantom(INITIAL_X, INITIAL_Y) {}

Pinky::~Pinky() {}