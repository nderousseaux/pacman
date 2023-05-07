#include "fantom.h"
#include "pacman.h"
#include "window.h"

#include <iostream>

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

void Fantom::set_fantoms_state(FantomState state)
{
	for (Element * element : Window::get_instance()->get_elements()) {
		if (Fantom * fantom = dynamic_cast<Fantom*>(element))
			fantom->set_state(state);
	}
}


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
	for (unsigned long i = 0; i < directions.size(); i++){
		if (directions[i] == Direction_utils::opposite(_direction)){
			directions.erase(directions.begin() + i);
			break;
		}
	}
	// En fonction du mode de jeux
	_next_direction = which_dir(directions, _state);
	if(_state == FANTOM_EATEN){
		SPEED = 6;
	}
	else if(_state == FANTOM_FRIGHTENED){
		SPEED = 2;
	}
	else{
		SPEED = 3;
	}
	

}

SDL_Rect Fantom::maj_pos(Direction d, int x_pos, int y_pos){
	switch(d){
      case UP:
        y_pos-=10;
        break;
      case DOWN:
        y_pos+=10;
        break;
      case RIGHT:
        x_pos+=10;
        break;
      case LEFT:
        x_pos-=10;
        break;
      default:
       break;
    }
	SDL_Rect new_pos = {x_pos,y_pos,0,0};
	return (new_pos);
}

Direction Fantom::get_dir_choisie(int min_dist, SDL_Rect target, vector <Direction> dir){
	Direction dir_choisie;
	for(Direction d: dir) {
		SDL_Rect new_pos = maj_pos(d, this->get_pos()->x, this->get_pos()->y);
		int res = calc_distances(&new_pos, &target);
		if(res < min_dist){
			min_dist = res;
			dir_choisie = d;
		}
	}
	return dir_choisie;
}

void Fantom::switch_state(SDL_Rect init){
	SDL_Rect * pos = this->get_pos();
	if(
		(pos->x <= init.x + 10 && pos->x >= init.x - 10) &&
		(pos->y <= init.y + 10 && pos->y >= init.y - 10)){
			this->set_state(FANTOM_CHASE);
	}
}

Direction Fantom::get_random_dir(vector <Direction> dir){
	return(dir[rand() % dir.size()]);
}

int Fantom::calc_distances(SDL_Rect * F, SDL_Rect * P){
	int X = P->x - F->x;
	int Y = P->y - F->y;
	return sqrt((X*X) + (Y*Y));
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

			if (_animation == 511) // Au bout de 7 secones, on passe en mode normal
				_state = FANTOM_CHASE;

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
	_animation %= 512;
}
/* #endregion */