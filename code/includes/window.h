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
    static const int WINDOW_WIDTH = 664; // Largeur de la fenêtre
    static const int WINDOW_HEIGHT = 856; // Hauteur de la fenêtre
    static const char * SPRITES_PATH; // Chemin vers les sprites

    /* Variables d'instance */
    SDL_Window * _window; // Fenêtre SDL
    SDL_Surface * _sprites; // Surface des sprites
    std::vector<Element *> _elements; // Liste des éléments affichés sur la fenêtre

    /* Méthodes internes */
    void print_in_surface(Element * element); // Affiche un élément dans la surface de la fenêtre

  public:
    /* Constructeur/Destructeur */
    Window();
    ~Window();

    /* Getters/Setters */
    static Window * get_instance() { return _instance; }
    int get_width() { return WINDOW_WIDTH; }
    int get_height() { return WINDOW_HEIGHT; }
    std::vector<Element *> get_elements() { return _elements; }
    void add_element(Element * element) { _elements.push_back(element); }
    void insert_element(Element * element) { _elements.insert(_elements.begin(), element); }
    void remove_element(Element * element);

    /* Méthodes */
    void start(); // Démarre le jeu
    void update(); // Update la fenêtre
    bool handle_events(); // Gère les évènements, retourne true si on doit continuer
    void quit(); // Quitte le jeu
};
