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
    std::vector<Dot *> & get_dots() {return _dots;} // Retourne la liste des points du terrain
    static Field * get_instance() { return _instance; } // Retourne l'instance unique de la classe
    FieldState get_state() {return _state;} // Retourne l'état du terrain

    /* Méthodes */
    void remove_dot(Dot * dot); // Supprime un point du terrain
    void create_dots(); // Met tout les points dans le vecteur

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
    static Field * _instance; // Instance unique de la classe

    /* Variables d'instance */
    FieldState _state = FIELD_NORMAL; // État du terrain
    std::vector<Dot *> _dots; // Liste des points du terrain
};