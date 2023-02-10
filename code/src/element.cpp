#include "../includes/element.h"

/* Constructeur/Destructeur */
Element::Element(int x, int y) {
  _pos.x = x;
  _pos.y = y;
}

Element::~Element() {}

/* Getters/Setters */
const SDL_Rect * Element::get_current_sprite() {
  return _current_sprite;
}
void Element::set_current_sprite(int index) {
  _current_sprite = get_sprites() + index;
  _pos.w = _current_sprite->w * get_zoom();
  _pos.h = _current_sprite->h * get_zoom();
}
SDL_Rect * Element::get_pos() {
  return &_pos;
}

/* Méthodes */
// Fait réagir l'élément (think + animate)
void Element::update() {
  think();
  animate();
}