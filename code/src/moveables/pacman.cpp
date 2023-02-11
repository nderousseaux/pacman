#include "../../includes/moveables/pacman.h"

/* Variable de classe */
const SDL_Rect Pacman::SPRITES[9] = {
  { 80, 90, 14, 14 },   // Haut 1
  { 97, 90, 14, 14 },   // Haut 2
  { 114, 91, 14, 14 },  // Bas 1
  { 131, 95, 14, 14 },  // Bas 2
  { 21, 90, 14, 14 },   // Droite 1
  { 36, 90, 14, 14 },   // Droite 2
  { 49, 90, 14, 14 },   // Gauche 1
  { 63, 90, 14, 14 },   // Gauche 2
  { 4, 90, 14, 14 },    // Immobile
};

/* Constructeur/Destructeur */
Pacman::Pacman(int x, int y):
	Moveable(x, y) {}

Pacman::~Pacman() {}

/* Méthodes */
// Fonction qui fait réfléchir pacman (entrée clavier)
void Pacman::think() {
  // On récupère les touches pressées
  const Uint8 * keys = SDL_GetKeyboardState(NULL);
  // On change la direction de pacman
  if (keys[SDL_SCANCODE_UP])
    Moveable::_direction = UP;
  else if (keys[SDL_SCANCODE_DOWN])
    Moveable::_direction = DOWN;
  else if (keys[SDL_SCANCODE_RIGHT])
    Moveable::_direction = RIGHT;
  else if (keys[SDL_SCANCODE_LEFT])
    Moveable::_direction = LEFT;
}


// Changement du sprite de pacman
void Pacman::animate() {

  // Phase de l'animation
  int phase = _animation / 4; // On change de sprite toutes les 4 frames

  if (phase != 3) {
    phase = phase % 2; // On a 2 sprites par phase

    // On change l'image de pacman
    switch(Moveable::_direction) {
      case UP:
        set_current_sprite(0+phase);
        break;
      case DOWN:
        set_current_sprite(2+phase);
        break;
      case RIGHT:
        set_current_sprite(4+phase);
        break;
      case LEFT:
        set_current_sprite(6+phase);
        break;
      case STOP:
        set_current_sprite(8);
        break;
    }
  }
  else {
    set_current_sprite(8);
  }

  // On incrémente l'animation
  _animation++;
  _animation %= 16;
}