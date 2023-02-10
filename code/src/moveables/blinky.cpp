#include "../../includes/moveables/blinky.h"

// /* Variables de classe */
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

/* Constructeur/Destructeur */
Blinky::Blinky(int x, int y):
	Fantom(x,y) {}

Blinky::~Blinky() {}