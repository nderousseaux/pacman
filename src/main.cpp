#include <iostream>

#include <SDL2/SDL.h>

#include "includes/game.h"

// Initialise une fenetre SDL
SDL_Window* init_sdl(const char* title, int width, int height) {
    // On démarre une fenetre
    if (SDL_Init(SDL_INIT_VIDEO) != 0 ) {
		std::cerr <<"Echec de l'initialisation de la SDL "<<SDL_GetError() << std::endl;
		exit(1);
    }

    return SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
}

// Fonction d'entrée du programme
int main() {

    // On démarre une fenetre
    SDL_Window * window = init_sdl("PacMan", 700, 900);

    // On lance une partie
    Game game(window);
    return 0;
}
