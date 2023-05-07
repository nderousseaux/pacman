#include "game.h"
#include "element.h"

/* #region Constructeur/Destructeur */
Element::Element(int x, int y): _pos(new SDL_Rect) {
  _pos->x = x;
  _pos->y = y;
}
Element::~Element() {
  delete _pos;
}
/* #endregion */

/* #region Getters/Setters */
void Element::set_current_sprite(int index) {
  _current_sprite = get_sprites() + index;
  _pos->w = _current_sprite->w * get_zoom();
  _pos->h = _current_sprite->h * get_zoom();
}
/* #endregion */

/* #region Méthodes */
// Met à jour l'élément (react + animate)
void Element::update() {
  // On ne réagit pas si le jeu est en pause
  if (Game::get_instance()->get_state() != GAME_PAUSE)
    react();
  animate();
}
/* #endregion */