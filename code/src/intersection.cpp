#include "intersection.h"
#include "pacman.h"
#include "blinky.h"
#include "pinky.h"
#include "inky.h"
#include "clyde.h"

/* #region Constructeur/Destructeur */
Intersection::Intersection(int x, int y):
  _pos_x(x), _pos_y(y) {}

Intersection::~Intersection() {}
/* #endregion */

/* #region Méthodes d'instance */
// Retourne les directions possibles à partir de l'intersection
std::vector<Direction> Intersection::get_directions() {
  std::vector<Direction> directions;
  if (_top != nullptr)
    directions.push_back(UP);
  if (_bottom != nullptr)
    directions.push_back(DOWN);
  if (_left != nullptr)
    directions.push_back(LEFT);
  if (_right != nullptr)
    directions.push_back(RIGHT);
  return directions;
}

// Retourne l'intersection dans la direction donnée
Intersection * Intersection::get_from_direction(Direction direction) {
  switch (direction) {
    case UP:
      return _top;
    case DOWN:
      return _bottom;
    case LEFT:
      return _left;
    case RIGHT:
      return _right;
    default:
      return nullptr;
  }
}

/* #endregion */

/* #region Methodes de classe */
// Ajoute toutes les intersections
void Intersection::create_intersections(){

  // On crée l'intersection de départ des objets
  Intersection * pacman_start = new Intersection(Pacman::INITIAL_X, Pacman::INITIAL_Y);
  Pacman::START = pacman_start;
  Intersection * blinky_start = new Intersection(Blinky::INITIAL_X, Blinky::INITIAL_Y);
  Blinky::START = blinky_start;
  Intersection * pinky_start = new Intersection(Pinky::INITIAL_X, Pinky::INITIAL_Y);
  Pinky::START = pinky_start;
  Intersection * inky_start = new Intersection(Inky::INITIAL_X, Inky::INITIAL_Y);
  Inky::START = inky_start;
  Intersection * clyde_start = new Intersection(Clyde::INITIAL_X, Clyde::INITIAL_Y);
  Clyde::START = clyde_start;
  
  /* Declaration des HG */
  Intersection * hg1 = new Intersection(30,30);
  Intersection * hg2 = new Intersection(158,30);
  Intersection * hg3 = new Intersection(286,30);
  Intersection * hg4 = new Intersection(30,158);
  Intersection * hg5 = new Intersection(158,158);
  Intersection * hg6 = new Intersection(222,158);
  Intersection * hg7 = new Intersection(286,158);
  Intersection * hg8 = new Intersection(30,254);
  Intersection * hg9 = new Intersection(158,254);
  Intersection * hg10 = new Intersection(222,254);
  Intersection * hg11 = new Intersection(286,254);
  Intersection * hg12 = new Intersection(222,318);
  Intersection * hg13 = new Intersection(286,318);
  Intersection * hg14 = new Intersection(158,414);
  Intersection * hg15 = new Intersection(222,414);
 
  /* Declaration des HD */
  Intersection * hd1 = new Intersection(350,30);
  Intersection * hd2 = new Intersection(478,30);
  Intersection * hd3 = new Intersection (606,30);
  Intersection * hd4 = new Intersection (350,158);
  Intersection * hd5 = new Intersection (414,158);
  Intersection * hd6 = new Intersection (478,158);
  Intersection * hd7 = new Intersection (606,158);
  Intersection * hd8 = new Intersection (350,254);
  Intersection * hd9 = new Intersection (414,254);
  Intersection * hd10 = new Intersection (478,254);
  Intersection * hd11 = new Intersection (606,254);
  Intersection * hd12 = new Intersection (350,318);
  Intersection * hd13 = new Intersection (414,318);
  Intersection * hd14 = new Intersection (414,414);
  Intersection * hd15 = new Intersection (478,414);

  /* Declaration des BG */
  Intersection * bg1 = new Intersection(222,478);
  Intersection * bg2 = new Intersection(30,574);
  Intersection * bg3 = new Intersection (158,574);
  Intersection * bg4 = new Intersection (222,574);
  Intersection * bg5 = new Intersection (286,574);
  Intersection * bg6 = new Intersection (30,638);
  Intersection * bg7 = new Intersection (94,638);
  Intersection * bg8 = new Intersection (158,638);
  Intersection * bg9 = new Intersection (222,638);
  Intersection * bg10 = new Intersection (286,638);
  Intersection * bg11 = new Intersection (30,734);
  Intersection * bg12 = new Intersection (94,734);
  Intersection * bg13 = new Intersection (158,734);
  Intersection * bg14 = new Intersection (222,734);
  Intersection * bg15 = new Intersection (286,734);
  Intersection * bg16 = new Intersection (30,798);
  Intersection * bg17 = new Intersection (286,798);
  
  /* Declaration des BD */
  Intersection * bd1 = new Intersection(414,478);
  Intersection * bd2 = new Intersection(350,574);
  Intersection * bd3 = new Intersection (414,574);
  Intersection * bd4 = new Intersection (478,574);
  Intersection * bd5 = new Intersection (606,574);
  Intersection * bd6 = new Intersection (350,638);
  Intersection * bd7 = new Intersection (414,638);
  Intersection * bd8 = new Intersection (478,638);
  Intersection * bd9 = new Intersection (542,638);
  Intersection * bd10 = new Intersection (606,638);
  Intersection * bd11 = new Intersection (350,734);
  Intersection * bd12 = new Intersection (414,734);
  Intersection * bd13 = new Intersection (478,734);
  Intersection * bd14 = new Intersection (542,734);
  Intersection * bd15 = new Intersection (606,734);
  Intersection * bd16 = new Intersection (350,798);
  Intersection * bd17 = new Intersection (606,798);

  // Connection des objets
  pacman_start->set_right(bd6);
  pacman_start->set_left(bg10);

  blinky_start->set_right(hd12);
  blinky_start->set_left(hg13);
  blinky_start->set_bottom(pinky_start);

  pinky_start->set_top(blinky_start);
  
  inky_start->set_right(pinky_start);

  clyde_start->set_left(pinky_start);

  /* Setters des HG */
  hg1->set_bottom(hg4);
  hg1->set_right(hg2);

  hg2->set_bottom(hg5);
  hg2->set_left(hg1);
  hg2->set_right(hg3);

  hg3->set_bottom(hg7);
  hg3->set_left(hg2);

  hg4->set_top(hg1);
  hg4->set_bottom(hg8);
  hg4->set_right(hg5);

  hg5->set_top(hg2);
  hg5->set_bottom(hg9);
  hg5->set_left(hg4);
  hg5->set_right(hg6);

  hg6->set_bottom(hg10);
  hg6->set_left(hg5);
  hg6->set_right(hg7);

  hg7->set_top(hg3);
  hg7->set_left(hg6);
  hg7->set_right(hd4);
  
  hg8->set_top(hg4);
  hg8->set_right(hg9);

  hg9->set_top(hg5);
  hg9->set_bottom(hg14);
  hg9->set_left(hg8);

  hg10->set_top(hg6);
  hg10->set_right(hg11);
  
  hg11->set_bottom(hg13);
  hg11->set_left(hg10);

  hg12->set_bottom(hg15);
  hg12->set_right(hg13);

  hg13->set_top(hg11);
  hg13->set_left(hg12);
  hg13->set_right(hd12);
  
  hg14->set_top(hg9);
  hg14->set_bottom(bg3);
  hg14->set_left(hd15);
  hg14->set_right(hg15);

  hg15->set_top(hg12);
  hg15->set_bottom(bg1);
  hg15->set_left(hg14);

  /* Setters des HD */
  hd1->set_bottom(hd4);
  hd1->set_right(hd2);

  hd2->set_bottom(hd6);
  hd2->set_left(hd1);
  hd2->set_right(hd3);

  hd3->set_bottom(hd7);
  hd3->set_left(hd2);

  hd4->set_top(hd1);
  hd4->set_left(hg7);
  hd4->set_right(hd5);

  hd5->set_bottom(hd9);
  hd5->set_left(hd4);
  hd5->set_right(hd6);

  hd6->set_top(hd2);
  hd6->set_bottom(hd10);
  hd6->set_left(hd5);
  hd6->set_right(hd7);

  hd7->set_top(hd3);
  hd7->set_bottom(hd11);
  hd7->set_left(hd6);
  
  hd8->set_bottom(hd12);
  hd8->set_right(hd9);

  hd9->set_top(hd5);
  hd9->set_left(hd8);

  hd10->set_top(hd6);
  hd10->set_bottom(hd15);
  hd10->set_right(hd11);
  
  hd11->set_top(hd7);
  hd11->set_left(hd10);

  hd12->set_top(hd8);
  hd12->set_left(hg13);
  hd12->set_right(hd13);

  hd13->set_bottom(hd14);
  hd13->set_left(hd12);
  
  hd14->set_top(hd13);
  hd14->set_bottom(bd1);
  hd14->set_right(hd15);

  hd15->set_top(hd10);
  hd15->set_bottom(bd4);
  hd15->set_left(hd14);
  hd15->set_right(hg14);

  /* Setters des BG */
  bg1->set_top(hg15);
  bg1->set_bottom(bg4);
  bg1->set_right(bd1);

  bg2->set_bottom(bg6);
  bg2->set_right(bg3);

  bg3->set_top(hg14);
  bg3->set_bottom(bg8);
  bg3->set_left(bg2);
  bg3->set_right(bg4);

  bg4->set_top(bg1);
  bg4->set_left(bg3);
  bg4->set_right(bg5);

  bg5->set_bottom(bg10);
  bg5->set_left(bg4);

  bg6->set_top(bg2);
  bg6->set_right(bg7);

  bg7->set_bottom(bg12);
  bg7->set_left(bg6);
  
  bg8->set_top(bg3);
  bg8->set_bottom(bg13);
  bg8->set_right(bg9);

  bg9->set_bottom(bg14);
  bg9->set_left(bg8);
  bg9->set_right(bg10);

  bg10->set_top(bg5);
  bg10->set_left(bg9);
  bg10->set_right(bd6);
  
  bg11->set_bottom(bg16);
  bg11->set_right(bg12);

  bg12->set_top(bg7);
  bg12->set_left(bg11);
  bg12->set_right(bg13);

  bg13->set_top(bg8);
  bg13->set_left(bg12);
  
  bg14->set_top(bg9);
  bg14->set_right(bg15);

  bg15->set_bottom(bg17);
  bg15->set_left(bg14);

  bg16->set_top(bg11);
  bg16->set_right(bg17);

  bg17->set_top(bg15);
  bg17->set_left(bg16);
  bg17->set_right(bd16);

  /* Setters des BD */
  bd1->set_top(hd14);
  bd1->set_bottom(bd3);
  bd1->set_left(bg1);

  bd2->set_bottom(bd6);
  bd2->set_right(bd3);

  bd3->set_top(bd1);
  bd3->set_left(bd2);
  bd3->set_right(bd4);

  bd4->set_top(hd15);
  bd4->set_bottom(bd8);
  bd4->set_left(bd3);
  bd4->set_right(bd5);

  bd5->set_bottom(bd10);
  bd5->set_left(bd4);

  bd6->set_top(bd2);
  bd6->set_left(bg10);
  bd6->set_right(bd7);

  bd7->set_bottom(bd12);
  bd7->set_left(bd6);
  bd7->set_right(bd8);
  
  bd8->set_top(bd4);
  bd8->set_bottom(bd13);
  bd8->set_left(bd7);

  bd9->set_bottom(bd14);
  bd9->set_right(bd10);

  bd10->set_top(bd5);
  bd10->set_left(bd9);
  
  bd11->set_bottom(bd16);
  bd11->set_right(bd12);

  bd12->set_top(bd7);
  bd12->set_left(bd11);

  bd13->set_top(bd8);
  bd13->set_right(bd14);
  
  bd14->set_top(bd9);
  bd14->set_left(bd13);
  bd14->set_right(bd15);

  bd15->set_bottom(bd17);
  bd15->set_left(bd14);

  bd16->set_top(bd11);
  bd16->set_left(bg17);
  bd16->set_right(bd17);

  bd17->set_top(bd15);
  bd17->set_left(bd16);
}
/* #endregion */
