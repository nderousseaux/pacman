#pragma once

#include "fantom.h"

// Classe représentant Clyde (le fantôme rose)
class Clyde: public virtual Fantom {
  public:
    /* Constructeur/Destructeur */
    Clyde();
    ~Clyde() override;

    static Intersection * START; // Intersection de départ de Clyde (initialisée par Intersection)
    static const int INITIAL_X = 352; // Position initiale de Clyde
    static const int INITIAL_Y = 400;

  protected:
    /* Getters/Setters */
    SDL_Rect * get_specific_sprites() override {return (SDL_Rect *)SPRITES;}
    Intersection * get_start() override {return START;}

  private:
    /* Variables de classe */
    static const SDL_Rect SPRITES[8]; // Liste des sprites du fantôme
    


};