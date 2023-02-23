#pragma once

#include "element.h"

#include <SDL2/SDL.h>

// Classe représentant le terrain
class Field: public Element {
  public:
    /* Constructeur/Destructeur */
    Field();
    ~Field() override;

  protected:
    /* Getters/Setters communs à tous les éléments */
    SDL_Rect * get_sprites() override {return (SDL_Rect *)SPRITES;}
    int get_zoom() override {return ZOOM; }

    /* Méthodes */
    void react() override; // Fait réagir le terrain
    void animate() override; // Change le sprite du terrain

  private:
    /* Variables de classe communs à tous les éléments */
    static const int INITIAL_X = 0; // Position initiale du terrain
    static const int INITIAL_Y = 0; // Position initiale du terrain
    static const SDL_Rect SPRITES[3]; // Liste des sprites du terrain
    static const int ZOOM = 4;
};