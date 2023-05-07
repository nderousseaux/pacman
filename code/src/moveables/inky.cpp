#include "inky.h"
#include "game.h"
#include "blinky.h"
#include "window.h"
#include "iostream"

/* #region Variables de classe */
const SDL_Rect Inky::SPRITES[8] = {
  { 72, 160, 14, 14 },  // Haut 1
  { 89, 160, 14, 14 },  // Haut 2
  { 106, 160, 14, 14 }, // Bas 1
  { 123, 160, 14, 14 }, // Bas 2
  { 4, 160, 14, 14 },   // Droite 1
  { 21, 160, 14, 14 },  // Droite 2
  { 38, 160, 14, 14 },  // Gauche 1
  { 55, 160, 14, 14 }   // Gauche 2
};

Intersection * Inky::START = nullptr; // Intersection de départ de Inky (initialisée par Intersection)
/* #endregion */
 

void Inky::set_destination(Intersection * new_destination){
  _destination = new_destination;
}

 
SDL_Rect Inky::maj_target(Direction d, SDL_Rect * P_pos, SDL_Rect * B_pos){
  int Pac_x = P_pos->x;
  int Pac_y = P_pos->y;
  SDL_Rect alter_target;
  SDL_Rect final_target;
  switch(d){
    case RIGHT:
      Pac_x+=48;
      break;
    case DOWN:
      Pac_y+=48;
      break;    
    case LEFT:
      Pac_x-=48;
      break;    
    case UP:
      Pac_y-=48;
      break;
    default:
      break; 
  }
  alter_target = {Pac_x,Pac_y,0,0};
  final_target = {2*alter_target.x - B_pos->x, 2*alter_target.y - B_pos->y,0,0};
  return final_target;
}

Direction Inky::which_dir(vector<Direction> dir){
  Direction dir_choisie;
  int min_dist = 10000;
  int res;
  Direction pac_dir;
  SDL_Rect target;
  for(Direction d: dir){
    int x = this->get_destination()->get_pos_x();
    int y = this->get_destination()->get_pos_y();
    SDL_Rect * Pac_pos = Game::get_instance()->get_element<Pacman>()->get_pos(); // Pos Pacman
    pac_dir = Game::get_instance()->get_element<Pacman>()->get_dir(); // Direction de Pacman
    SDL_Rect * Blinky_pos = Game::get_instance()->get_element<Blinky>()->get_pos();
    target = maj_target(pac_dir, Pac_pos, Blinky_pos);
    SDL_Rect new_pos = maj_pos(d,x,y);
    res = calc_distances(&new_pos, &target);
    if(res < min_dist){
      min_dist = res;
      dir_choisie = d;
    }
  }
  return dir_choisie;
  }


/* #region Constructeur/Destructeur */
Inky::Inky():
	Fantom(INITIAL_X, INITIAL_Y) {
    _destination = START;
  }

Inky::~Inky() {}
/* #endregion */