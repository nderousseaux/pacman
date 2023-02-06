#include <iostream>

#include <SDL2/SDL.h>

#include "includes/game.h"
SDL_Surface* win_surf = nullptr;

SDL_Rect src_bg = { 200,3, 168,216 }; // x,y, w,h (0,0) en haut a gauche
SDL_Rect bg = { 4,4, 672,864 }; // ici scale x4

SDL_Rect ghost_r = { 3,123, 16,16 }; 
SDL_Rect ghost_l = { 37,123, 16,16 }; 
SDL_Rect ghost_d = { 105,123, 16,16 }; 
SDL_Rect ghost_u = { 71,123, 16,16 }; 
SDL_Rect ghost = { 34,34, 32,32 };     // ici scale x2

int count;


// fonction qui met à jour la surface de la fenetre "win_surf"
void Game::draw()
{
    SDL_SetColorKey(_sprites, false, 0);
    SDL_BlitScaled(_sprites, &src_bg, get_surface(), &bg);

    // petit truc pour faire tourner le fantome
    SDL_Rect* ghost_in = nullptr;
    switch (count/128)
    {
        case 0:
            ghost_in = &(ghost_r);
            ghost.x++;
            break;
        case 1:
            ghost_in = &(ghost_d);
            ghost.y++;
            break;
        case 2:
            ghost_in = &(ghost_l);
            ghost.x--;
            break;
        case 3:
            ghost_in = &(ghost_u);
            ghost.y--;
            break;
    }
    count =(count+1)%(512);

    // ici on change entre les 2 sprites sources pour une jolie animation.
    SDL_Rect ghost_in2 = *ghost_in;
    if ((count/4)%2)
        ghost_in2.x += 17;
        
    // couleur transparente
    SDL_SetColorKey(_sprites, true, 0);
    // copie du sprite zoomé
	SDL_BlitScaled(_sprites, &ghost_in2, get_surface(), &ghost);
}

Game::Game(SDL_Window * window): _window(window)
{
  // On charges les sprites
  _sprites = SDL_LoadBMP("src/sprites.bmp");

  count = 0;
  // On met dessine une fois pour initialiser la surface
  draw();
  // BOUCLE PRINCIPALE
  bool quit = false;
  while (!quit)
  {
    SDL_Event event;
    while (!quit && SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            quit = true;
            break;
        default: break;
        }
    }

    // Gestion du clavier        
    int nbk;
    const Uint8* keys = SDL_GetKeyboardState(&nbk);
    if (keys[SDL_SCANCODE_ESCAPE])
        quit = true;
    if (keys[SDL_SCANCODE_LEFT])
        puts("LEFT");
    if (keys[SDL_SCANCODE_RIGHT])
        puts("RIGHT");

    // AFFICHAGE
    draw();
    SDL_UpdateWindowSurface(_window); 
    // LIMITE A 60 FPS
    SDL_Delay(16); // utiliser SDL_GetTicks64() pour plus de precisions
  }
  SDL_Quit(); // ON SORT
}

Game::~Game() {
}

// Getters/Setters
SDL_Surface * Game::get_surface() {
  return SDL_GetWindowSurface(_window);
}