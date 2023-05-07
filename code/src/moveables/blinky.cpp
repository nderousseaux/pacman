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



Direction Blinky::which_dir(vector<Direction> dir, FantomState state){
  Direction dir_choisie;
  int min_dist = 10000;
  switch(state){
    case FANTOM_CHASE:{
      switch(Game::get_instance()->get_mode()){
        //Mode Chase
        case MODE_CHASE:{
          SDL_Rect * target = Game::get_instance()->get_element<Pacman>()->get_pos();
          dir_choisie = get_dir_choisie(min_dist,*target, dir);
          break;
        }
        //Mode Scatter
        case MODE_SCATTER:{
          dir_choisie = get_dir_choisie(min_dist,{SCATTER_X,SCATTER_Y,0,0}, dir);
          break;
        }
        default:
          break;
      }
      break;
    }
    case FANTOM_FRIGHTENED:{
      // On choisi une direction aléatoire parmis les directions restantes
      dir_choisie = get_random_dir(dir);
      break;
    }
    case FANTOM_EATEN:{
      // Blinky se dirige vers sa position initiale afin de changer d'état
      SDL_Rect init = {INITIAL_X, INITIAL_Y, 0, 0};
      dir_choisie = get_dir_choisie(min_dist,init,dir);
      switch_state(init);
      break;
    }
  }
  return dir_choisie;
}

 

Blinky::~Blinky() {}
/* #endregion */