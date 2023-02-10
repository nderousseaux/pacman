#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "../element.h"
#include "../window.h"

using namespace std;

enum Direction {
  UP,
  DOWN,
  LEFT,
  RIGHT,
  STOP,
};

// Classe représentant les éléments qui peuvent se déplacer
class Moveable: public Element {
  protected:
    /* Variables d'instance */
    Direction _direction = STOP; // Direction de déplacement de l'élément

    /* Getters/Setters */
    void set_x(int x);
    void set_y(int y);
    void set_direction(Direction direction) {_direction = direction;}
    virtual int get_speed() = 0;
  
    /* Méthodes */
    void move(); // Déplace l'élément
    void update() override; // Fait réagir l'élément (think + animate + move)

  public:
    /* Constructeur/Destructeur */
    Moveable(int x, int y);
    ~Moveable();
};