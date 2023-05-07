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
    static const int SCATTER_X = 664;
    static const int SCATTER_Y = 856;

  protected:
    /* Getters/Setters */
    SDL_Rect * get_specific_sprites() override {return (SDL_Rect *)SPRITES;}
    Intersection * get_start() override {return START;}
    Direction which_dir(vector<Direction> dir, FantomState state) override; // Methode pour indiquer comment régir pour le fantôme
    void set_destination(Intersection * new_destination);
    SDL_Rect maj_target(Direction d, SDL_Rect * P_pos, SDL_Rect * B_pos);


  private:
    /* Variables de classe */
    static const SDL_Rect SPRITES[8]; // Liste des sprites du fantôme
};