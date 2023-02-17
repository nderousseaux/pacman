#pragma once
#include "moveable.h"

enum PacmanState {
  PACMAN_NORMAL,
  PACMAN_DEAD
};

// Classe représentant pacman
class Pacman: public virtual Moveable {
  private:
    /* Variable de classe */
    static const SDL_Rect SPRITES[19]; // Liste des sprites de pacman
    static const int SPEED = 4; // Vitesse de déplacement
    static const int ZOOM = 2; // Zoom des sprites
    static const int INITIAL_X = 318; // Position initiale de pacman
    static const int INITIAL_Y = 638; // Position initiale de pacman

    /* Variables d'instance */
    PacmanState _state = PACMAN_NORMAL; // État de pacman

  protected:
    /* Getters/Setters */
    SDL_Rect * get_sprites() override {return (SDL_Rect *)SPRITES;}
    int get_speed() override {return SPEED;}
    int get_zoom() override {return ZOOM;}
    
    /* Méthodes */
    void spawn(); // Fait réapparaître pacman
    void dead(); // Fait mourir pacman
    void react() override; // Fait réagir pacman (entrée clavier) puis collision
    void keybord_react(); // Fait réagir pacman (entrée clavier)
    void collision_react(); // Fait réagir pacman (collision)
    void animate() override; // Change le sprite de pacman
    void animate_normal(); // Change le sprite de pacman en mode normal
    void animate_dead(); // Change le sprite de pacman en mode mort

  public:
    /* Constructeur/Destructeur */
    Pacman();
    ~Pacman() override;  
};