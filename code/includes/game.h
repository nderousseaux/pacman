#pragma once
#include "element.h"
#include "pacman.h"
#include "blinky.h"

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
    Pacman * get_Pacman() {return _Pac;} // Renvoie les coordonnées de Pacman 
    Blinky * get_Blinky() {return _Blinky;}

    /* Méthodes */
    void main_loop(); // Boucle principale du jeu
    Element * check_collision(Element * element); // Vérifie si l'élément est en collision avec un autre élément
    void restart();       // Redémarre la partie

  private:
    /* Variables de classe */
    static Game * _instance; // Instance unique de la classe
    Pacman * _Pac; // Attribut Pacman pour obtenir les coord de ce dernier
    Blinky * _Blinky; // Attribut Blinky pour obtenir les coord de ce dernier
    /* Variables d'instance */
    GameState _state = GAME_PLAY; // Etat du jeu

    /* Méthodes */
    void load_elements(); // Charge les éléments sur la fenêtre
    bool control();       // Gestion du clavier
};
