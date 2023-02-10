#include "../../includes/moveables/moveable.h"

/* Constructeur/Destructeur */
Moveable::Moveable(int x, int y):
  Element(x, y) {}

Moveable::~Moveable() {}

/* Getters/Setters */
void Moveable::set_x(int x) {
  // On vérifie que le sprite ne sorte pas de la fenêtre
  if (x < 0) {
    x = 0; 
    _direction = STOP;
  }
  else if (x > Window::WINDOW_WIDTH - Element::_pos.w) {
    x = Window::WINDOW_WIDTH - Element::_pos.w;
    _direction = STOP;
  }

  Element::_pos.x = x;
}
void Moveable::set_y(int y) {
  // On vérifie que le sprite ne sorte pas de la fenêtre
  if (y < 0) {
    y = 0; 
    _direction = STOP;
  }
  else if (y > Window::WINDOW_HEIGHT - Element::_pos.h) {
    y = Window::WINDOW_HEIGHT - Element::_pos.h;
    _direction = STOP;
  }
    
  Element::_pos.y = y;
}

/* Méthodes */
void Moveable::move() {
  switch (_direction) {
    case UP:
      set_y(_pos.y - get_speed());
      break;
    case DOWN:
      set_y(_pos.y + get_speed());
      break;
    case LEFT:
      set_x(_pos.x - get_speed());
      break;
    case RIGHT:
      set_x(_pos.x + get_speed());
      break;
    case STOP:
      break;
  }
}

//Fait "réagir" l'élément (think + animate + move)
void Moveable::update() {
  Element::update();
  move();
}
