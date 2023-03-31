#pragma once

#include "element.h"
#include "dot.h"

#include <SDL2/SDL.h>
#include <vector>

using namespace std;

enum FieldState {
  FIELD_NORMAL,
  FIELD_WIN
};

// Classe représentant le terrain
class Field: public Element {
  public:
    /* Constructeur/Destructeur */
    Field();
    ~Field() override;

    /* Getter/setters */
    void set_state(FieldState state) {_state = state;} // Change l'état du terrain

    /* Méthodes */
    void create_dots(); // Place les points sur le terrain
    void remove_all_dots(); // Supprime tout les points du terrain
    void remove_dot(Dot * dot); // Supprime un point du terrain

  protected:
    /* Getters/Setters communs à tous les éléments */
    SDL_Rect * get_sprites() override {return (SDL_Rect *)SPRITES;}
    int get_zoom() override {return ZOOM; }

    /* Méthodes */
    void react() override; // Fait réagir le terrain
    void animate() override; // Change le sprite du terrain

  private:
    /* Variables de classe communs à tous les éléments */
    static const int INITIAL_X = 0; // Position initiale du terrain
    static const int INITIAL_Y = 0; // Position initiale du terrain
    static const SDL_Rect SPRITES[3]; // Liste des sprites du terrain
    static const int ZOOM = 4;

    /* Variables d'instance */
    std::vector<Dot *> _dots; // Liste des points du terrain
    FieldState _state = FIELD_NORMAL; // État du terrain
};