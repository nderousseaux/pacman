#include "window.h"

#include <iostream>

/* #region Variables de classe */
const char * Window::WINDOW_TITLE = "PacMan"; // Titre de la fenêtre
const int Window::WINDOW_WIDTH = 664; // Largeur de la fenêtre
const int Window::WINDOW_HEIGHT = 856; // Hauteur de la fenêtre
/* #endregion */

/* #region Code */
/* Constructeur/Destructeur */
Window::Window() {
  // On démarre une fenetre
  if (SDL_Init(SDL_INIT_VIDEO) != 0 ) {
    std::cerr <<"Echec de l'initialisation de la SDL "<<SDL_GetError() << std::endl;
    exit(1);
  }
  _window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
}

Window::~Window() {
  SDL_DestroyWindow(_window);
  SDL_Quit();
}

/* Méthodes */
// Démarre une fenêtre (menu)
void Window::init() {
  print_menu();
}

// Affiche le menu
void Window::print_menu() {
  
  // // On affiche le menu
  // SDL_Surface * surface = SDL_GetWindowSurface(_window);
  // SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 10, 255, 255));
  // SDL_UpdateWindowSurface(_window);
  
  // // On bloque la fenêtre
  // SDL_Event event;
  // bool quit = false;
  // while (!quit) {
  //   SDL_WaitEvent(&event);
  //   switch (event.type) {
  //     case SDL_QUIT:
  //       quit = true;
  //       break;
  //     case SDL_KEYDOWN:
  //       switch (event.key.keysym.sym) {
  //         case SDLK_ESCAPE:
  //           quit = true;
  //           break;
  //         case SDLK_RETURN:
  //           print_game();
  //           break;
  //       }
  //       break;
  //   }
  // } 
}

// Affiche le jeu
void Window::print_game() {
}
/* #endregion */