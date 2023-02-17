#pragma once

#include "element.h"

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
    void update() override; // Met à jour l'élément (react + animate + move)

  public:
    /* Constructeur/Destructeur */
    Moveable(int x, int y);
    virtual ~Moveable() override;
};