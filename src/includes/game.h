#include <iostream>

#include <SDL2/SDL.h>

class Game {
  public:
    // Fonction qui met à jour la surface de la fenetre "win_surf"
    void draw();

    // Constructeur
    Game(SDL_Window * window);

    // Destructeur
    ~Game();

    // Getters/Setters
    SDL_Surface * get_surface();

  private:
    // Pointeur vers la fenêtre
    SDL_Window * _window;

    // Surface des sprites
    SDL_Surface * _sprites;
};
