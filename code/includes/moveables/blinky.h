#pragma once

#include "fantom.h"

// Classe représentant blinky (le fantôme rouge)
class Blinky: public virtual Fantom {
  public:
    /* Constructeur/Destructeur */
    Blinky();
    ~Blinky() override;

    static Intersection * START; // Intersection de départ de Blinky (initialisée par Intersection)
    static const int INITIAL_X = 318; // Position initiale de Blinky
    static const int INITIAL_Y = 318;
    static const int SCATTER_X = 664;
    static const int SCATTER_Y = 0;


  protected:
    /* Getters/Setters */
    SDL_Rect * get_specific_sprites() override {return (SDL_Rect *)SPRITES;}
    Intersection * get_start() override {return START;}
    void set_destination(Intersection * new_destination);

    /* Méthodes */
    // void where_dest() override; //méthode pour établir la nouvelle destination (pro intersection)
    Direction which_dir(vector<Direction> dir, FantomState state) override; // Methode pour indiquer comment régir pour le fantôme

  private:
    /* Variables de classe */
    static const SDL_Rect SPRITES[8]; // Liste des sprites du fantôme
};