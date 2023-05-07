#pragma once
#include <SDL2/SDL.h>

class Game;

// Classe représentant un élément affichable sur la fenêtre (pure virtual)
class Element {
  public:
    /* Constructeur/Destructeur */
    Element(int x, int y);
    virtual ~Element();

    /* Getters/Setters */
    SDL_Rect * get_pos() { return _pos; }
    const SDL_Rect * get_current_sprite() { return _current_sprite; }

    /* Méthodes */
    void virtual update(); // Met à jour l'élément (react + animate)

  protected:
    /* Variables d'instance */
    SDL_Rect * _pos;      // Position de l'élément sur la fenêtre
    int _animation = 0; // État de l'animation de l'élément

    /* Getters/Setters */
    virtual SDL_Rect * get_sprites() = 0;
    virtual int get_zoom() = 0;
    void set_current_sprite(int index);
    
    /* Méthodes */
    void virtual react() = 0; // Fait reagir l'élément
    void virtual animate() = 0; // Change le sprite de l'élément
  
  private:
    /* Variables d'instance */
    const SDL_Rect * _current_sprite; // Sprite actuel de l'élément
};