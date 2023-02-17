#pragma once

#include "element.h"

// Classe représentant le terrain
class Field: public Element {
  private:
    /* Variables de classe */
    static const SDL_Rect SPRITES[3]; // Liste des sprites du terrain
    static const int ZOOM = 4;

  protected:
    /* Getters/Setters */
    SDL_Rect * get_sprites() override {return (SDL_Rect *)SPRITES;}
    int get_zoom() override {return ZOOM; }

    /* Méthodes */
    void react() override; // Fait réagir le terrain
    void animate() override; // Change le sprite du terrain


  public:
    /* Constructeur/Destructeur */
    Field();
    ~Field() override;
};