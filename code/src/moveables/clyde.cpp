#include "clyde.h"
#include "game.h"
#include <iostream>

/* #region Variables de classe */
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

  void Clyde::set_destination(Intersection * new_destination){
    _destination = new_destination;
  }

  Direction Clyde::which_dir(vector<Direction> dir){
    Direction dir_choisie;
    int min_dist =10000;
    int x_corner = 0;
    int y_corner = 856;
    int res;
    int res_maj;
    res = calc_distances(get_pos(), Game::get_instance()->get_element<Pacman>()->get_pos());
    for(Direction d: dir) {
      int x = this->get_destination()->get_pos_x();
      int y = this->get_destination()->get_pos_y();
      if (res > 188){ /* 47 * 4 (a cause du zoom)*/
        SDL_Rect new_pos = maj_pos(d,x,y);
        res_maj = calc_distances(&new_pos, Game::get_instance()->get_element<Pacman>()->get_pos());
        }
      else{
          SDL_Rect pos_corner = {x_corner,y_corner,0,0};
          SDL_Rect new_pos_else = maj_pos(d,x,y);
          res_maj = calc_distances(&new_pos_else, &pos_corner);
          }
      if(res_maj < min_dist){
        min_dist = res_maj;
        dir_choisie = d;
        }
      }
    return dir_choisie;
    }




Intersection * Clyde::START = nullptr; // Intersection de départ de Clyde (initialisée par Intersection)
/* #endregion */

/* #region Constructeur/Destructeur */
Clyde::Clyde():
	Fantom(INITIAL_X, INITIAL_Y) {
    _destination = START;
  }

Clyde::~Clyde() {}
/* #endregion */