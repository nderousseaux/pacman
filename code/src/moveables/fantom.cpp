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
// Phases des modes de poursuite des fantômes (pair: scatter, impair: chase)
const int Fantom::PHASES[8] = {7, 20, 7, 20, 5, 20, 5, -1};
ChaseMode Fantom::CHASE_MODE = CHASE;
int Fantom::PHASE = 0;
Uint32 Fantom::timer_phase_id = 0;
/* #endregion */

/* #region Méthodes de statique */
void Fantom::set_fantoms_state(FantomState state)
{
	for (Element * element : Window::get_instance()->get_elements()) {
		if (Fantom * fantom = dynamic_cast<Fantom*>(element))
			fantom->set_state(state);
	}
}

// Appelé à chaque changement de mode de poursuite
Uint32 Fantom::timer_chase_mode(Uint32 interval, void * param) {
	(void ) interval;
	(void ) param;
	// Si c'est pair, c'est le mode scatter
	set_chase_mode((PHASE % 2 == 0) ? SCATTER : CHASE);
	PHASE++;

	// On rapelle la fonction dans le bon délai
	if (PHASES[PHASE] != -1)
		set_timer_phase_id(
			SDL_AddTimer(PHASES[PHASE-1] * 1000, timer_chase_mode, nullptr)
		);

	printf("la phase est %d\n", PHASE);
	return 0;
}

// Réinitialise la phase
void Fantom::reset_phase() {
	PHASE = 0;
	SDL_RemoveTimer(get_timer_phase_id());
	// On traite les changements de mode de poursuite
  Fantom::timer_chase_mode(0, nullptr);
}

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
int i = 0;
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

	// On change la vitesse en fonction de l'état du fantôme
	switch (_state) {
		case FANTOM_FRIGHTENED:
			_speed = 2;
			break;
		case FANTOM_EATEN:
			_speed = 6;
			break;
		default:
			_speed = 3;
			break;
	}
	
	set_next_direction(directions);
}

// Défini la prochaine direction du fantôme
void Fantom::set_next_direction(vector<Direction> directions) {

	// On défini la target en fonction de l'état du fantôme
	SDL_Rect * target;
	switch (get_state()){
		case FANTOM_CHASE:
			if (get_chase_mode() == CHASE)
      	target = get_target_chase();
			else
				target = get_target_scatter();
      break;
    case FANTOM_FRIGHTENED:
			target = nullptr;
      break;
    case FANTOM_EATEN:
			target = get_target_origin();
			SDL_Rect * pos = this->get_pos();
			// On retourne à l'état chase si on est arrivé à l'origine
			if(
				(pos->x <= target->x + 10 && pos->x >= target->x - 10) &&
				(pos->y <= target->y + 10 && pos->y >= target->y - 10)){
					this->set_state(FANTOM_CHASE);
			}
      break;
	}

	// On défini la direction en fonction de l'état du fantôme
	if (get_state() == FANTOM_FRIGHTENED)
		// Si le fantôme est effrayé, on choisi une direction aléatoire
		_next_direction = get_random_direction(directions);
	else
		// Si le fantôme n'est pas effrayé, on choisi la direction qui nous rapproche le plus de la target
		_next_direction = choose_direction(directions, target);
	
}
// Choisi aléatoirement une direction parmis les directions proposées
Direction Fantom::get_random_direction(vector<Direction> directions){
	return(directions[rand() % directions.size()]);
}

// Choisi la direction qui nous rapproche le plus de la target
Direction Fantom::choose_direction(vector <Direction> directions, SDL_Rect * target){
	int min_dist = 100000;
	Direction dir_choisie;
	for(Direction d: directions) {
		SDL_Rect * new_pos = translate_pos(d, this->get_pos());
		int res = Moveable::get_distance(new_pos, target);
		if(res < min_dist){
			min_dist = res;
			dir_choisie = d;
		}
	}
	return dir_choisie;
}

// Décalle une position en fonction d'une direction (de 10pixels) pour choisir le chemin le plus court
SDL_Rect * Fantom::translate_pos(Direction d, SDL_Rect * pos){
	int x = pos->x;
	int y = pos->y;
	switch(d){
		case UP:
			y-=10;
			break;
		case DOWN:
			y+=10;
			break;
		case RIGHT:
			x+=10;
			break;
		case LEFT:
			x-=10;
			break;
		default:
			break;
	}
	return new SDL_Rect{x,y,0,0};
}

// Fonction qui fait réapparaître le fantôme
void Fantom::spawn() {
	Moveable::spawn();
	_state = FANTOM_CHASE;
	set_chase_mode(CHASE);
	set_current_sprite(0);
}

// Changement du sprite du fantôme
void Fantom::animate() {
	// Phase de l'animation
	int phase = _animation / 4; // On change de sprite toutes les 4 frames

	switch (_state) {
		case FANTOM_CHASE: // Le fantôme est en mode chasse
			if (get_chase_mode() == CHASE){
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
			}
			else {
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