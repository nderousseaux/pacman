#pragma once

#include "fantom.h"

// Classe représentant blinky (le fantôme rouge)
class Blinky: public virtual Fantom {
  private:
    /* Variables de classe */
    static const SDL_Rect SPRITES[8]; // Liste des sprites du fantôme
    static const int INITIAL_X = 318; // Position initiale de Blinky
    static const int INITIAL_Y = 318;

  protected:
    /* Getters/Setters */
    SDL_Rect * get_specific_sprites() override {return (SDL_Rect *)SPRITES;}

  public:
    /* Constructeur/Destructeur */
    Blinky();
    ~Blinky() override;
};