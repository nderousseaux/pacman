#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "moveable.h"

using namespace std;

// Classe représentant pacman
class Pacman: public virtual Moveable {
  private:
    /* Variable de classe */
    static const SDL_Rect SPRITES[9]; // Liste des sprites de pacman
    static const int SPEED = 4; // Vitesse de déplacement
    static const int ZOOM = 2; // Zoom des sprites

  protected:
    /* Getters/Setters */
    SDL_Rect * get_sprites() override {return (SDL_Rect *)SPRITES;}
    int get_speed() override {return SPEED;}
    int get_zoom() override {return ZOOM;}
    
    /* Méthodes */
    void think() override; // Fait réfléchir pacman
    void animate() override; // Change le sprite de pacman

  public:
    /* Constructeur/Destructeur */
    Pacman(int x, int y);
    ~Pacman();  
};