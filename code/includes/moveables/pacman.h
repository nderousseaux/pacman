#pragma once
#include "moveable.h"
#include "intersection.h"

#include <SDL2/SDL.h>

enum PacmanState {
  PACMAN_NORMAL,
  PACMAN_DEAD
};

// Classe représentant pacman
class Pacman: public virtual Moveable {
  public:
    /* Constructeur/Destructeur */
    Pacman();
    ~Pacman() override;  

    /* Variables de classe */
    static Intersection * START; // Intersection de départ de pacman (initialisée par Intersection)
    static const int INITIAL_X = 318; // Position initiale de pacman
    static const int INITIAL_Y = 638; // Position initiale de pacman

    /* Méthodes */
    void spawn() override; // Fait réapparaître pacman

  protected:
    /* Getters/Setters communs à tous les éléments */
    SDL_Rect * get_sprites() override {return (SDL_Rect *)SPRITES;}
    int get_zoom() override {return ZOOM;}


    /* Getters/Setters communs à tous les moveables */
    int get_speed() override {return SPEED;}
    Intersection * get_start() override {return START;}
    
    /* Méthodes */
    // React
    void react() override; // Fait réagir pacman (entrée clavier) puis collision
    void keybord_react(); // Fait réagir pacman (entrée clavier)
    void collision_react(); // Fait réagir pacman (collision)
    void dead();  // Fait mourir pacman

    // Animate
    void animate() override; // Change le sprite de pacman
    void animate_normal(); // Change le sprite de pacman en mode normal
    void animate_dead(); // Change le sprite de pacman en mode mort

  private:
    /* Variables de classe */
    static const SDL_Rect SPRITES[19]; // Liste des sprites de pacman
    static const int SPEED = 4; // Vitesse de déplacement
    static const int ZOOM = 2; // Zoom des sprites

    /* Variables d'instance */
    PacmanState _state = PACMAN_NORMAL; // État de pacman
};