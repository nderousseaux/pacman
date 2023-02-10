#include "../../includes/moveables/fantom.h"

/* Variables de classe */
const SDL_Rect Fantom::SPRITES[8] = {
	{ 4, 196, 14, 14 }, // Appeuré 1, bleu
	{ 21, 196, 14, 14 }, // Appeuré 2, bleu
  { 38, 196, 14, 14 }, // Appeuré 1, blanc
  { 55, 196, 14, 14 }, // Appeuré 2, blanc
  { 72, 196, 14, 14 }, // Mangé droite
  { 89, 196, 14, 14 }, // Mangé gauche
  { 106, 196, 14, 14 }, // Mangé haut
  { 123, 196, 14, 14 }  // Mangé bas
};

/* Constructeur/Destructeur */
Fantom::Fantom(int x, int y):
	Moveable(x,y) {}

Fantom::~Fantom() {}

/* Getters/Setters */
SDL_Rect * Fantom::get_sprites() {
	//On concatène les sprites de fantôme et de fantôme spécial
	SDL_Rect * sprites = new SDL_Rect[16];
	for (int i = 0; i < 8; i++) {
		sprites[i] = get_specific_sprites()[i];
		sprites[i+8] = SPRITES[i];
	}
	return sprites;
}

// Fonction qui fait réfléchir le fantôme
void Fantom::think() {
  // A chaque tick, il y a une chance sur 50 qu'il change de direction
  if (rand() % 50 == 0)
    _direction = (Direction)(rand() % 5);

  // A chaque tick, il y a une chance sur 100 qu'il change d'état
  if (rand() % 100 == 0)
    _state = (FantomState)(rand() % 3);
}

// Changement du sprite du fantôme
void Fantom::animate() {
	// Phase de l'animation
	int phase = _animation / 4; // On change de sprite toutes les 4 frames

	switch (_state) {
		case CHASE: // Le fantôme est en mode chasse
			phase %= 2; // Il n'y a que 2 sprites pour la chasse
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
					set_current_sprite(4+phase);
					break;
			}
			break;
		case FRIGHTENED: // Le fantôme est en mode peur
			phase %= 4; // Il y a 4 sprites pour le mode peur
			set_current_sprite(8+phase);
			break;
		case EATEN:
			// Il n'y a qu'un sprite pour le mode mangé
			switch(Moveable::_direction) {
				case UP:
					set_current_sprite(14);
					break;
				case DOWN:
					set_current_sprite(15);
					break;
				case RIGHT:
					set_current_sprite(12);
					break;
				case LEFT:
					set_current_sprite(13);
					break;
				case STOP:
					set_current_sprite(12);
					break;
			}
			break;
	}
	

	// On incrémente l'animation
	_animation++;
	_animation %= 16;
}