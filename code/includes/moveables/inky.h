#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "fantom.h"

using namespace std;

// Classe représentant Inky (le fantôme rose)
class Inky: public virtual Fantom {
  private:
    /* Variables de classe */
    static const SDL_Rect SPRITES[8]; // Liste des sprites du fantôme

  protected:
    /* Getters/Setters */
    SDL_Rect * get_specific_sprites() {return (SDL_Rect *)SPRITES;}

  public:
    /* Constructeur/Destructeur */
    Inky(int x, int y);
    ~Inky();
};