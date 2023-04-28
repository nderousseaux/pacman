#include "blinky.h"
#include "game.h"
#include <stdio.h>
#include <iostream>

/* #region Variables de classe */
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

Intersection * Blinky::START = nullptr; // Intersection de départ de Blinky (initialisée par Intersection)
/* #endregion */

void Blinky::set_destination(Intersection * new_dest){
  _destination = new_dest;
}



/* #region Constructeur/Destructeur */
Blinky::Blinky():
	Fantom(INITIAL_X, INITIAL_Y) {
    _destination = START;
  }

// void Blinky::where_dest(){
//   SDL_Rect * Pac_pos = Game::get_instance()->get_Pacman(); 
//   int X_pac;
//   int Y_pac;
//   X_pac = Pac_pos->x;
//   Y_pac = Pac_pos->y;
//   Intersection * inter = new Intersection(X_pac,Y_pac);
//   set_destination(inter);
// }

Direction Blinky::which_dir(vector<Direction> dir){
  Direction dir_choisie;
  int min_dist = 10000;
  int res;
  for(Direction d: dir) {
    int x = this->get_destination()->get_pos_x();
    int y = this->get_destination()->get_pos_y();
    SDL_Rect new_pos = maj_pos(d,x,y);
    res = calc_distances(&new_pos, Game::get_instance()->get_Pacman()->get_pos());
    if(res < min_dist){
      min_dist = res;
      dir_choisie = d;
    }
  }
  cout << "==================" << endl;
  return dir_choisie;
}
 

Blinky::~Blinky() {}
/* #endregion */