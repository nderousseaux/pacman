#pragma once

#include "dot.h"
#include "gomme.h"

#include <SDL2/SDL.h>
#include <vector>


using namespace std;

// Classe représentant le terrain
class Field: public Element {
  public:
    /* Constructeur/Destructeur */
    Field();
    ~Field() override;

    /* Méthodes */
    void create_gommes_dots(); // Met tout les points et les gommes dans le vecteur
    void remove_dot(Dot * dot); // Supprime un point du terrain
    void remove_gomme(Gomme * gomme); // Supprime une gomme du terrain
    bool is_empty(); // Retourne vrai si le terrain est vide

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
    std::vector<Gomme *> _gommes; // Liste des gommes du terrain
};