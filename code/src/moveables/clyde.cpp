#include "../../includes/moveables/clyde.h"

// /* Variables de classe */
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

/* Constructeur/Destructeur */
Clyde::Clyde(int x, int y):
	Fantom(x,y) {}

Clyde::~Clyde() {}