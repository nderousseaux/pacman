#include "../../includes/moveables/pacman.h"

/* Variable de classe */
const SDL_Rect Pacman::SPRITES[19] = {
  { 80,   90,  14, 14  },    // Haut 1
  { 97,   90,  14, 14  },    // Haut 2
  { 114,  91,  14, 14  },    // Bas 1
  { 131,  95,  14, 14  },    // Bas 2
  { 21,   90,  14, 14  },    // Droite 1
  { 36,   90,  14, 14  },    // Droite 2
  { 49,   90,  14, 14  },    // Gauche 1
  { 63,   90,  14, 14  },    // Gauche 2
  { 4,    90,  14, 14  },    // Immobile
  { 4,    104, 16, 16  },    // Dead 1
  { 23,   104, 16, 16  },    // Dead 2
  { 42,   104, 16, 16  },    // Dead 3
  { 61,   104, 16, 16  },    // Dead 4
  { 80,   104, 16, 16  },    // Dead 5
  { 98,   104, 16, 16  },    // Dead 6
  { 113,  104, 16, 16  },    // Dead 7
  { 126,  104, 16, 16  },    // Dead 8
  { 137,  104, 16, 16  },    // Dead 9
  { 151,  105, 16, 16  },    // Dead 10
};
/* Constructeur/Destructeur */
Pacman::Pacman():
	Moveable(INITIAL_X, INITIAL_Y) {}

Pacman::~Pacman() {}

/* Méthodes */
// Fait apparaître pacman
void Pacman::spawn() {
  _state = NORMAL;
  _direction = STOP;
  _animation = 0;
  set_x(INITIAL_X);
  set_y(INITIAL_Y);
  set_current_sprite(8);
}

// Fonction qui fait mourir pacman
void Pacman::dead() {
  _state = DEAD;
  _direction = STOP;
  _animation = 0;
}

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
  else if (keys[SDL_SCANCODE_D]) // Temporaire : D = DEAD
    dead();  
}

// Changement du sprite de pacman
void Pacman::animate() {
  switch(_state ) {
    case NORMAL:
      animate_normal();
      break;
    case DEAD:
      animate_dead();
      break;
  }
}

// Animation normale
void Pacman::animate_normal() {
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
  else
    set_current_sprite(8);

  // On incrémente l'animation
  _animation++;
  _animation %= 16;
}

// Animation de mort
void Pacman::animate_dead() {
  int phase = _animation / 4; // On change de sprite toutes les 4 frames

  // On arrête l'animation si on a fini
  if (phase > 12){
    spawn();
    return;
  }

  // On décale le sprite de 1 pixel car les sprites de mort sont plus grands
  if (_animation == 4) {
    set_x(_pos.x - get_zoom());
    set_y(_pos.y - 2 * get_zoom());
  }
  
  if (phase == 0)
    set_current_sprite(8);
  else if (phase > 10) // On affiche le dernier sprite pendant 3 frames
    set_current_sprite(18);
  else
    set_current_sprite(8+phase);

  // On incrémente l'animation
  _animation++;
}