#pragma once

#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

// Classe représentant une fenêtre
class Window {
  private:
    /* Variables de classe */
		static const int WINDOW_WIDTH; // Largeur de la fenêtre
    static const int WINDOW_HEIGHT; // Hauteur de la fenêtre
    static const char * WINDOW_TITLE; // Titre de la fenêtre

    /* Variables d'instance */
    SDL_Window * _window; // Fenêtre
    Menu * _menu = nullptr; // Menu
    Game * _game = nullptr; // Jeu

  public:
    /* Constructeur/Destructeur */
    Window();
    ~Window();

		/* Méthodes */
    void init(); // Initialise la fenêtre (affiche le menu)
    void print_menu();
    void print_game();
};
