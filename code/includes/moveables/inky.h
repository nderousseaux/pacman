#pragma once

#include "fantom.h"

// Classe représentant Inky (le fantôme rose)
class Inky: public virtual Fantom {
  public:
    /* Constructeur/Destructeur */
    Inky();
    ~Inky() override;

    static Intersection * START; // Intersection de départ de Inky (initialisée par Intersection)
    static const int INITIAL_X = 284; // Position initiale de Inky
    static const int INITIAL_Y = 400;

  protected:
    /* Getters/Setters */
    SDL_Rect * get_specific_sprites() override {return (SDL_Rect *)SPRITES;}
    Intersection * get_start() override {return START;}

  private:
    /* Variables de classe */
    static const SDL_Rect SPRITES[8]; // Liste des sprites du fantôme
};