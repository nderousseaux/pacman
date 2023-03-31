#pragma once
#include "element.h"

#include <SDL2/SDL.h>

#include <vector>

using namespace std;

// Classe représentant une fenêtre
class Window {
  private:
    /* Variables de classe */
    static Window * _instance; // Instance unique de la classe
    static const char * WINDOW_TITLE; // Titre de la fenêtre
    static const char * SPRITES_PATH; // Chemin vers les sprites

    /* Variables d'instance */
    SDL_Window * _window; // Fenêtre
    SDL_Surface * _sprites; // Surface des sprites
    std::vector<Element *> _elements; // Liste des éléments affichés sur la fenêtre

  public:
    /* Variables de classe */
    static const int WINDOW_WIDTH = 664; // Largeur de la fenêtre
    static const int WINDOW_HEIGHT = 856; // Hauteur de la fenêtre

    /* Constructeur/Destructeur */
    Window();
    ~Window();

    /* Getters/Setters */
    static Window * get_instance() { return _instance; }
    std::vector<Element *> get_elements() { return _elements; }
    void add_element(Element * element) { _elements.push_back(element); }
    void remove_element(Element * element);

    /* Méthodes */
    void start(); // Démarre le jeu
    void update(); // Update la fenêtre
    bool handle_events(); // Gère les évènements, retourne true si on doit continuer
    void add_to_window(Element * element); // Ajoute un élément à la fenêtre
    void quit(); // Quitte le jeu
};
