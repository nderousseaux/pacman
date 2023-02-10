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

  protected:
    /* Getters/Setters */
    SDL_Rect * get_specific_sprites() {return (SDL_Rect *)SPRITES;}

  public:
    /* Constructeur/Destructeur */
    Clyde(int x, int y);
    ~Clyde();
};