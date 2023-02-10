#include "../includes/window.h"

#include "../includes/game.h"

/* Variables de classe */
const char * Window::WINDOW_TITLE = "PacMan";
const char * Window::SPRITES_PATH = "assets/sprites.bmp";

/* Constructeur/Destructeur */
Window::Window() {
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

/* Getters/Setters */
std::vector<Element *> Window::get_elements() {
  return _elements;
}
void Window::add_element(Element * element) {
  _elements.push_back(element);
}

/* Méthodes */
// Démarre le jeu
void Window::start() {
  Game * game = new Game(this);
  delete game;
}

// Update la fenêtre
void Window::update() {
  // On efface la fenêtre
  SDL_FillRect(SDL_GetWindowSurface(_window), NULL, SDL_MapRGB(SDL_GetWindowSurface(_window)->format, 0, 0, 0));

  // On affiche tout les éléments
  for (Element * element : _elements) {
    SDL_BlitScaled(_sprites, element->get_current_sprite(), SDL_GetWindowSurface(_window), element->get_pos());
  }

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
      default:
        break;
    }
  }
  return true;
}