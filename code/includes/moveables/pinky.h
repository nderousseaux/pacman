#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "fantom.h"

using namespace std;

// Classe représentant Pinky (le fantôme rose)
class Pinky: public virtual Fantom {
  private:
    /* Variables de classe */
    static const SDL_Rect SPRITES[8]; // Liste des sprites du fantôme
    static const int INITIAL_X = 284; // Position initiale de Pinky
    static const int INITIAL_Y = 400;

  protected:
    /* Getters/Setters */
    SDL_Rect * get_specific_sprites() {return (SDL_Rect *)SPRITES;}

  public:
    /* Constructeur/Destructeur */
    Pinky();
    ~Pinky();
};