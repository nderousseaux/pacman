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
    static const int INITIAL_X = 318; // Position initiale de Inky
    static const int INITIAL_Y = 400;

  protected:
    /* Getters/Setters */
    SDL_Rect * get_specific_sprites() override {return (SDL_Rect *)SPRITES;}

  public:
    /* Constructeur/Destructeur */
    Inky();
    ~Inky() override;
};