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

Direction Inky::which_dir(vector<Direction> dir, FantomState state){
  Direction dir_choisie;
  int min_dist = 10000;

      switch(state){

        case FANTOM_CHASE:{
          switch(Game::get_instance()->get_mode()){
            case MODE_CHASE:{
              Direction pac_dir;
              SDL_Rect target;
              SDL_Rect * Pac_pos = Game::get_instance()->get_pacman()->get_pos(); // Pos Pacman
              SDL_Rect * Blinky_pos = Game::get_instance()->get_blinky()->get_pos();
              pac_dir = Game::get_instance()->get_pacman()->get_dir();
              target = maj_target(pac_dir, Pac_pos, Blinky_pos);
              dir_choisie = get_dir_choisie(min_dist,target,dir);
              break;
            }
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
          dir_choisie = get_random_dir(dir);
          break;
        }
        
        case FANTOM_EATEN:{
          // Inky se dirige vers sa position initiale afin de changer d'état
          SDL_Rect init = {INITIAL_X, INITIAL_Y, 0, 0};
          dir_choisie = get_dir_choisie(min_dist,init,dir);
          switch_state(init);
          break;
        }

      default:
        break;
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