#include "pinky.h"
#include "game.h"
#include <iostream>


/* region Variables de classe */
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

void Pinky::set_destination(Intersection * new_destination){
  _destination = new_destination;
}


SDL_Rect Pinky::maj_target(Direction d, SDL_Rect * P_pos){
  int Pac_x = P_pos->x;
  int Pac_y = P_pos->y;
  SDL_Rect target;
  switch(d){
    case RIGHT:
      Pac_x+=96;
      break;
    case DOWN:
      Pac_y+=96;
      break;    
    case LEFT:
      Pac_x-=96;
      break;    
    case UP:
      Pac_x-=96;
      Pac_y-=96;
      break;
    default:
      break;    
  }
  target = {Pac_x,Pac_y,0,0};
  return (target);
}

Direction Pinky::which_dir(vector<Direction> dir){
  Direction dir_choisie;
  int min_dist = 10000;
  int res_maj;
  Direction pac_dir;
  SDL_Rect target;
  for(Direction d: dir){
    int x = this->get_destination()->get_pos_x();
    int y = this->get_destination()->get_pos_y();
    SDL_Rect * Pac_pos = Game::get_instance()->get_Pacman()->get_pos(); // Pos Pacman
    pac_dir = Game::get_instance()->get_Pacman()->get_dir(); // Direction de Pacman
    target = maj_target(pac_dir, Pac_pos);
    SDL_Rect new_pos = maj_pos(d,x,y);
    res_maj = calc_distances(&new_pos,&target);
    if(res_maj < min_dist){
      min_dist = res_maj;
      dir_choisie = d;
    }
  }
  return dir_choisie;
  }



Intersection * Pinky::START = nullptr; // Intersection de départ de Pinky (initialisée par Intersection)
/* endregion */

/* #region Constructeur/Destructeur */
Pinky::Pinky():
	Fantom(INITIAL_X, INITIAL_Y) {
    _destination = START;
  }

Pinky::~Pinky() {}
/* #endregion */