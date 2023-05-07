#pragma once
#include "element.h"
#include "direction.h"
#include "intersection.h"

#include <SDL2/SDL.h>

// Classe représentant les éléments qui peuvent se déplacer
class Moveable: public Element {
  public:
    /* Constructeur/Destructeur */
    Moveable(int x, int y);
    virtual ~Moveable() override;

    /* Getter/setters */
    void set_direction(Direction direction) {_direction = direction;}
    Direction get_direction(){return _direction;}

    /* Méthodes */
    virtual void spawn();   // Fait réapparaître l'élément

    /* Méthodes statique */
    // Retourne la distance entre deux éléments (en nombre de pixels)
    static int get_distance(SDL_Rect * m1, SDL_Rect * m2);

  protected:
    /* Variables d'instance */
    Intersection * _destination = nullptr; // Destination de l'objet en mouvement
    Direction _direction = STOP;           // Direction de déplacement de l'élément
    Direction _next_direction = STOP;      // Direction prise à l'arrivée de la prochaine intersection

    /* Getters/Setters communs à tout les Moveables */
    virtual int get_speed() = 0;
    virtual Intersection * get_start() = 0;
    Intersection * get_destination(){return _destination;};
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