#pragma once
#include "element.h"
#include "intersection.h"
#include "direction.h"

#include <SDL2/SDL.h>

// Classe représentant les éléments qui peuvent se déplacer
class Moveable: public Element {
  public:
    /* Constructeur/Destructeur */
    Moveable(int x, int y);
    virtual ~Moveable() override;

    /* Méthodes */
    virtual void spawn();   // Fait réapparaître l'élément
    Direction get_dir(){return _direction;}

  protected:
    /* Variables d'instance */
    Intersection * _destination = nullptr; // Destination de l'objet en mouvement
    Direction _direction = STOP;           // Direction de déplacement de l'élément
    Direction _next_direction = STOP;      // Direction prise à l'arrivée de la prochaine intersection

    /* Getters/Setters commun à tout les moveables */
    virtual int get_speed() = 0;
    virtual Intersection * get_start() = 0;
    Intersection * get_destination(){return _destination;};

    /* Getters/Setters */
    void set_x(int x);
    void set_y(int y);

    /* Méthodes */
    void update() override; // Met à jour l'élément (react + animate + move) (appelée à chaque tick)
    void move();            // Déplace l'élément


  private:
    /* Methodes pour utilisées pour factoriser la méthode move() */
    void set_dest();          // Choisi une nouvelle destination
    void set_dest_prolonge(); // Prend comme destination la destination dans le prolongement de la direction actuelle
};