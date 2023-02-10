#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "moveables/pacman.h"
#include "moveables/blinky.h"
#include "moveables/pinky.h"
#include "moveables/inky.h"
#include "moveables/clyde.h"
#include "field.h"
#include "window.h"

using namespace std;

// Classe représentant une partie
class Game {
  private:
    /* Variables d'instance */
    Window * _window; // Fenêtre

    /* Méthodes */
    void load_elements(); // Charge les éléments sur la fenêtre
    bool control(); // Gestion du clavier


  public:
    /* Constructeur/Destructeur */
    Game(Window * window);
    ~Game();

    /* Méthodes */
    void main_loop(); // Boucle principale du jeu
};
