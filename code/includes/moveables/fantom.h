#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "moveable.h"

using namespace std;

enum FantomState {
  CHASE,        // Chasse pacman
  FRIGHTENED,   // Fuit pacman
  EATEN,        // Est mangé par pacman
};

// Classe représentant un fantôme
class Fantom: public Moveable {
  private:
    /* Variables de classe */
    static const int SPEED = 3; // Vitesse de déplacement
    static const int ZOOM = 2; // Zoom des sprites
    static const SDL_Rect SPRITES[8]; // Sprites commun à tous les fantômes

    /* Variables d'instance */
    FantomState _state = CHASE; // État du fantôme
    SDL_Rect _sprites[16]; // Liste de tout les sprites du fantôme

  protected:
    /* Getters/Setters */
    int get_speed() override {return SPEED;}
    int get_zoom() override {return ZOOM;}
    virtual SDL_Rect * get_specific_sprites() = 0; // Retourne les sprites spécifiques au fantôme
    SDL_Rect * get_sprites() override;

    /* Méthodes */
    void think() override; // Fait réfléchir le fantôme
    void animate() override; // Change le sprite du fantôme

  public:
    /* Constructeur/Destructeur */
    Fantom(int x, int y);
    virtual ~Fantom() override;
};