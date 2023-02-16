#include <iostream>

#include <SDL2/SDL.h>

#include "../includes/window.h"


// Fonction d'entrée du programme
int main() {

  // On lance une instance du jeu
  Window * win = new Window();

  // On démarre le jeu
  win->start();

  // On libère la mémoire
  delete win;

  return 0;
}
