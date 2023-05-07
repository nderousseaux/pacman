#pragma once
#include "blinky.h"
#include "element.h"

#include <SDL2/SDL.h>

enum GameState { 
  GAME_PLAY,
  GAME_PAUSE
};

enum GameMode { //TODO: Ranger
  MODE_CHASE,
  MODE_SCATTER
};

// Classe représentant une partie
class Game {
  private:
    /* Variables de classe */
    static Game * _instance; // Instance unique de la classe

    /* Variables d'instance */
    GameState _state = GAME_PLAY; // Etat du jeu
    GameMode _mode = MODE_SCATTER;

    /* Méthodes internes */
    void load_elements(); // Charge les éléments sur la fenêtre
    bool control();       // Gestion du clavier
    void main_loop();     // Boucle principale du jeu

  public:
    /* Constructeur/Destructeur */
    Game();
    ~Game();

    /* Getters/Setters */
    GameMode get_mode() {return _mode;} //TODO : RANGER
    void set_mode(GameMode mode) {_mode = mode;} // Change le mode de jeu


    static Game * get_instance() {return _instance;};
    GameState get_state() {return _state;}; // Renvoie l'état du jeu
    void set_state(GameState state) {_state = state;}; // Change l'état du jeu
    template<class T> T* get_element(); // Getter d'un élément par son type
    
    /* Méthodes */
    Element * check_collision(Element * element); // Vérifie si l'élément est en collision avec un autre élément
    void toggle_pause();
    void win(); // Gère la victoire
    void restart(bool with_dot_reset); // Redémarre la partie
    void quit(); // Quitte le jeu
};
