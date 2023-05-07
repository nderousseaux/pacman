#pragma once
#include "blinky.h"
#include "element.h"

#include <SDL2/SDL.h>

enum GameState { 
  GAME_PLAY,
  GAME_PAUSE,
  GAME_WIN,
};

// Classe représentant une partie
class Game {
  private:
    /* Variables de classe */
    static Game * _instance; // Instance unique de la classe
    static int mode_timer;
    static int phase_count;
    static const int scatter_duration[];
    static const int chase_duration;

    /* Variables d'instance */
    GameState _state = GAME_PLAY; // Etat du jeu

    /* Méthodes internes */
    void load_elements(); // Charge les éléments sur la fenêtre
    bool control();       // Gestion du clavier
    void main_loop();     // Boucle principale du jeu
    void update_game_mode(); // Met à jour le mode de jeu
    void reset_game_mode(); // Réinitialise l'horloge des phases

  public:
    /* Constructeur/Destructeur */
    Game();
    ~Game();

    /* Getters/Setters */
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
