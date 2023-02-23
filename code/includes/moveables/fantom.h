#pragma once

#include "moveable.h"

enum FantomState {
  FANTOM_CHASE,        // Chasse pacman
  FANTOM_FRIGHTENED,   // Fuit pacman
  FANTOM_EATEN,        // Est mangé par pacman
};

// Classe représentant un fantôme
class Fantom: public Moveable {
  public:
    /* Constructeur/Destructeur */
    Fantom(int x, int y);
    virtual ~Fantom() override;

    /* Getters/Setters */
    FantomState get_state() {return _state;}

    /* Méthodes */
    void spawn() override; // Fait réapparaître le fantôme

  protected:
    /* Getters/Setters communs à tous les éléments */
    SDL_Rect * get_sprites() override;
    int get_zoom() override {return ZOOM;}

    /* Getters/Setters communs à tous les moveables */
    int get_speed() override {return SPEED;}

    /* Getters/Setters */
    virtual SDL_Rect * get_specific_sprites() = 0; // Retourne les sprites spécifiques au fantôme

    /* Méthodes */
    void react() override; // Fait réagir le fantôme
    void animate() override; // Change le sprite du fantôme


  private:
    /* Variables de classe */
    static const SDL_Rect SPRITES[8]; // Sprites commun à tous les fantômes
    static const int SPEED = 3; // Vitesse de déplacement
    static const int ZOOM = 2; // Zoom des sprites

    /* Variables d'instance */
    FantomState _state = FANTOM_CHASE; // État du fantôme
    SDL_Rect _sprites[16]; // Liste de tout les sprites du fantôme
};