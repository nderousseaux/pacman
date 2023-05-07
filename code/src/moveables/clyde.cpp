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

  Direction Clyde::which_dir(vector<Direction> dir, FantomState state){
    int res;
    Direction dir_choisie;
    int min_dist = 10000;
    res = calc_distances(get_pos(), Game::get_instance()->get_pacman()->get_pos());
        switch(state){

          case FANTOM_CHASE:{
            
            switch(Game::get_instance()->get_mode()){
              
              case MODE_CHASE:{
                if(res > 188){ // 47*4 (a cause du zoom)
                  SDL_Rect * target = Game::get_instance()->get_pacman()->get_pos();
                  dir_choisie = get_dir_choisie(min_dist,*target,dir);
                  break;
                }
                else{
                  SDL_Rect corner = {SCATTER_X,SCATTER_Y,0,0};
                  dir_choisie = get_dir_choisie(min_dist,corner,dir);
                  break;
                }


              case MODE_SCATTER:{
                dir_choisie = get_dir_choisie(min_dist,{SCATTER_X,SCATTER_Y,0,0}, dir);
                break;
              }

              default:
                break;
              }
            }
            break;
          }

          case FANTOM_FRIGHTENED:{
            dir_choisie = get_random_dir(dir);
            break;
          }

          case FANTOM_EATEN:{
            // Clyde se dirige vers sa position initiale afin de changer d'état
            SDL_Rect init = {INITIAL_X,INITIAL_Y, 0,0};
            dir_choisie = get_dir_choisie(min_dist,init,dir);
            switch_state(init);
            break;
          }
        default:
          break;
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