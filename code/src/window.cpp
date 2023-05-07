#include "game.h"
#include "window.h"

#include <iostream>

/* #region Variables de classe */
const char * Window::WINDOW_TITLE = "PacMan";
const char * Window::SPRITES_PATH = "assets/sprites.bmp";
Window * Window::_instance = nullptr;
/* #endregion */

/* #region Constructeur/Destructeur */
Window::Window() {
  if (_instance != nullptr) // Singleton
    throw "Window already exists";
  Window::_instance = this;


   // On démarre une fenetre
  if (SDL_Init(SDL_INIT_VIDEO) != 0 ) {
    std::cerr <<"Echec de l'initialisation de la SDL "<<SDL_GetError() << std::endl;
    exit(1);
  }
  _window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

  // On charge les sprites
  _sprites = SDL_LoadBMP(SPRITES_PATH);
  SDL_SetColorKey(_sprites, true, 0); // On rend le fond transparent
}

Window::~Window() {  
  SDL_DestroyWindow(_window);
  SDL_Quit();
}
/* #endregion */

/* #region Getters/Setters */
void Window::remove_element(Element * element) {
  for (unsigned long i = 0; i < _elements.size(); i++) {
    if (_elements[i] == element) {
      _elements.erase(_elements.begin() + i);
      return;
    }
  }
}
/* #endregion */

/* #region Méthodes */
// Démarre le jeu
void Window::start() {
  Game * game = new Game();
  delete game;
}

// Update la fenêtre
void Window::update() {
  // On efface la fenêtre
  SDL_FillRect(SDL_GetWindowSurface(_window), NULL, SDL_MapRGB(SDL_GetWindowSurface(_window)->format, 0, 0, 0));

  // On affiche tout les éléments
  for (Element * element : _elements)
    print_in_surface(element);

  SDL_UpdateWindowSurface(_window);
}

// Gère les évènements, retourne true si on doit continuer
bool Window::handle_events() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        return false;
        break;
      case SDL_KEYUP:
        switch (event.key.keysym.sym) {
          case SDLK_ESCAPE:
            return false;
            break;
          case SDLK_p:
            Game::get_instance()->toggle_pause();
            break;
          default:
            break;
        }
        break;
      default:
        break;
    }
  }
  return true;
}

// Ajoute un élément à la fenêtre 
void Window::print_in_surface(Element * element) {
  int x = element->get_pos()->x; // On sauvegarde le x, car il va être modifié par SDL_BlitScaled (si il est négatif)
  SDL_BlitScaled(_sprites, element->get_current_sprite(), SDL_GetWindowSurface(_window), element->get_pos());
  element->get_pos()->x = x;
}

// On quite l'application
void Window::quit() {
  SDL_Event event;
  event.type = SDL_QUIT;
  SDL_PushEvent(&event);
}
/* #endregion */