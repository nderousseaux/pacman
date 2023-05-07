#include "window.h"
#include "game.h"
#include "moveable.h"

/* #region Constructeurs/Destructeurs */
Moveable::Moveable(int x, int y):
  Element(x, y) {}

Moveable::~Moveable() {}
/* #endregion */


/* #region Getters/Setters */
void Moveable::set_x(int x) { 
  Element::_pos->x = x;
  // Si le sprite est entièrement sorti de la fenêtre, on le replace à l'autre bout
  if (x < -Element::_pos->w) {
    Element::_pos->x = Window::get_instance()->get_width();
  }
  else if (x > Window::get_instance()->get_width()) {
    Element::_pos->x = -Element::_pos->w;
  }
}

void Moveable::set_y(int y) {
  // On vérifie que le sprite ne sorte pas de la fenêtre
  if (y < 0) {
    y = 0; 
    _direction = STOP;
  }
  else if (y > Window::get_instance()->get_height() - Element::_pos->h) {
    y = Window::get_instance ()->get_height() - Element::_pos->h;
    _direction = STOP;
  }
    
  Element::_pos->y = y;
}
/* #endregion */

/* #region Méthodes */
// Fait apparaître l'élément
void Moveable::spawn() {
  _destination = get_start();
  _direction = STOP;
  _next_direction = _direction;
  _animation = 0;
  set_x(_destination->get_pos_x());
  set_y(_destination->get_pos_y());
}

// Met à jour l'élément (react + animate + move) (appelée à chaque tick)
void Moveable::update() {
  Element::update();
  if (Game::get_instance()->get_state() != GAME_PAUSE)
    move();

}

// Déplace l'élément
void Moveable::move() {
  // On déplace l'objet dans la direction voulue
  switch (_direction) {
    case UP:
      set_y(Element::_pos->y - get_speed());
      break;
    case DOWN:
      set_y(Element::_pos->y + get_speed());
      break;
    case LEFT:
      set_x(Element::_pos->x - get_speed());
      break;
    case RIGHT:
      set_x(Element::_pos->x + get_speed());
      break;
    case STOP:
      break;
    default:
      break;
  }

  // Si l'objet à dépassé sa destination, on le replace dessus
  if (_direction == UP && Element::_pos->y < _destination->get_pos_y() && Element::_pos->y > _destination->get_pos_y() - 10)
    set_y(_destination->get_pos_y());
  else if (_direction == DOWN && Element::_pos->y > _destination->get_pos_y() && Element::_pos->y < _destination->get_pos_y() + 10)
    set_y(_destination->get_pos_y());
  else if (_direction == LEFT && Element::_pos->x < _destination->get_pos_x() && Element::_pos->x > _destination->get_pos_x() - 10)
    set_x(_destination->get_pos_x());
  else if (_direction == RIGHT && Element::_pos->x > _destination->get_pos_x() && Element::_pos->x < _destination->get_pos_x() + 10)
    set_x(_destination->get_pos_x());

  // Si l'objet est arrivée à destination, on change sa destination
  if (_pos->y == _destination->get_pos_y() && _pos->x == _destination->get_pos_x())
    set_dest();
}
/* #endregion */

/* #region Methodes pour utilisées pour factoriser la méthode move() */
// Choisi une nouvelle destination
void Moveable::set_dest() {
  Intersection * next_dest = nullptr;

  switch (_next_direction) {
    case UP:
      next_dest = _destination->get_top();
      break;
    case DOWN:
      next_dest = _destination->get_bottom();
      break;
    case LEFT:
      next_dest = _destination->get_left();
      break;
    case RIGHT:
      next_dest = _destination->get_right();
      break;
    default:
      break;
  }

  // Si il y a une intersection dans la direction voulue, on la prend
  if (next_dest != nullptr) {
    _destination = next_dest;
    _direction = _next_direction;
  }
  // Sinon, on continue sur le même axe
  else
    set_dest_prolonge();
}

// Prend comme destination la destination dans le prolongement de la direction actuelle
 void Moveable::set_dest_prolonge() {
  Intersection * next_dest = nullptr;

  switch(_direction) {
    case UP:
      next_dest = _destination->get_top();
      break;
    case DOWN:
      next_dest = _destination->get_bottom();
      break;
    case LEFT:
      next_dest = _destination->get_left();
      break;
    case RIGHT:
      next_dest = _destination->get_right();
      break;
    default:
      break;
  }

  // Si il y a une intersection dans la direction actuelle, on la prend
  if (next_dest != nullptr)
    _destination = next_dest;
  // Sinon, on prend la destination dans le prolongement de la direction opposée
  else
    _direction = STOP;
}
/* #endregion */
