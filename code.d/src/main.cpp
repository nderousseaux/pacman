#include "window.h"
#include <SDL2/SDL.h>

// Fonction d'entrée du programme
int main() {

  // On lance une instance du jeu
  Window * win = new Window();

  // On démarre le jeu
  win->init();

  // On libère la mémoire
  delete win;

  return 0;
}