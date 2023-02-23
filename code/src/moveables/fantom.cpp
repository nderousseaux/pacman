#include "fantom.h"

/* #region Variables de classe */
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
/* #endregion */

/* #region Constructeur/Destructeur */
Fantom::Fantom(int x, int y):
	Moveable(x,y) {}

Fantom::~Fantom() {}
/* #endregion */


/* #region Getters/Setters */
SDL_Rect * Fantom::get_sprites() {
	for (int i = 0; i < 8; i++) {
		_sprites[i] = get_specific_sprites()[i];
		_sprites[i+8] = SPRITES[i];
	}
	return _sprites;
}
/* #endregion */

/* #region Méthodes */
// Fonction qui fait réagir le fantôme
void Fantom::react() {

  // On choisi une direction parmis les directions proposées par la destination
	vector<Direction> directions = _destination->get_directions();
	// On supprime la direction opposée à la direction actuelle (un fantôme ne peut pas reculer)
	for (unsigned long i = 0; i < directions.size(); i++)
		if (directions[i] == Direction_utils::opposite(_direction)){
			directions.erase(directions.begin() + i);
			break;
		}

	// On choisi une direction aléatoire parmis les directions restantes
	_next_direction = directions[rand() % directions.size()];
	

  // A chaque tick, il y a une chance sur 100 qu'il change d'état
  // if (rand() % 100 == 0)
  //   _state = (FantomState)(rand() % 3);
}

// Fonction qui fait réapparaître le fantôme
void Fantom::spawn() {
	Moveable::spawn();
	_state = FANTOM_CHASE;
	set_current_sprite(0);
}

// Changement du sprite du fantôme
void Fantom::animate() {
	// Phase de l'animation
	int phase = _animation / 4; // On change de sprite toutes les 4 frames

	switch (_state) {
		case FANTOM_CHASE: // Le fantôme est en mode chasse
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
		case FANTOM_FRIGHTENED: // Le fantôme est en mode peur
			phase %= 4; // Il y a 4 sprites pour le mode peur
			set_current_sprite(8+phase);
			break;
		case FANTOM_EATEN:
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
/* #endregion */