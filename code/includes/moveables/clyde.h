#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "fantom.h"

using namespace std;

// Classe représentant Clyde (le fantôme rose)
class Clyde: public virtual Fantom {
  private:
    /* Variables de classe */
    static const SDL_Rect SPRITES[8]; // Liste des sprites du fantôme
    static const int INITIAL_X = 352; // Position initiale de Clyde
    static const int INITIAL_Y = 400;

  protected:
    /* Getters/Setters */
    SDL_Rect * get_specific_sprites() {return (SDL_Rect *)SPRITES;}

  public:
    /* Constructeur/Destructeur */
    Clyde();
    ~Clyde();
};