#pragma once
#include "element.h"
#include "field.h"
#include "pacman.h"
#include "fantom.h"

#include <SDL2/SDL.h>

enum GameState { 
  GAME_PLAY,
  GAME_PAUSE
};

// Classe représentant une partie
class Game {
  public:
    /* Constructeur/Destructeur */
    Game();
    ~Game();

    /* Getters/Setters */
    static Game * get_instance() {return _instance;} // Renvoie l'instance unique de la classe
    GameState get_state() {return _state;} // Renvoie l'état du jeu
    void set_state(GameState state) {_state = state;} // Change l'état du jeu
    Field * get_field() {return _field;} // Renvoie le terrain

    /* Méthodes */
    void main_loop(); // Boucle principale du jeu
    Element * check_collision(Element * element); // Vérifie si l'élément est en collision avec un autre élément
    void restart(bool with_dot_reset); // Redémarre la partie
    void set_fantom_state(FantomState state); // Change l'état des fantomes
    void win(); // Gère la victoire
    void quit(); // Quitte le jeu

  private:
    /* Variables de classe */
    static Game * _instance; // Instance unique de la classe

    /* Variables d'instance */
    GameState _state = GAME_PLAY; // Etat du jeu
    Field * _field; // Terrain
    Pacman * _pacman; // Pacman

    /* Méthodes */
    void load_elements(); // Charge les éléments sur la fenêtre
    bool control();       // Gestion du clavier
};
