#pragma once
#include "moveable.h"

enum FantomState {
  FANTOM_CHASE,        // Chasse pacman
  FANTOM_FRIGHTENED,   // Fuit pacman
  FANTOM_EATEN,        // Est mangé par pacman
};

enum ChaseMode {
  CHASE,
  SCATTER,
};

// Classe représentant un fantôme
class Fantom: public Moveable {
  public:
    /* Constructeur/Destructeur */
    Fantom(int x, int y);
    virtual ~Fantom() override;

    /* Méthode statique */
    static void set_fantoms_state(FantomState state); // Change l'état de tous les fantômes
    static ChaseMode get_chase_mode(){return CHASE_MODE;}
    static void set_chase_mode(ChaseMode mode){CHASE_MODE = mode;} // Change le mode de poursuite des fantômes

    /* Getters/Setters */
    FantomState get_state() {return _state;}
    void set_state(FantomState state) {_state = state;}

    /* Méthodes */
    void spawn() override; // Fait réapparaître le fantôme

  protected:
    /* Getters/Setters communs à tous les éléments */
    SDL_Rect * get_sprites() override;
    int get_zoom() override {return ZOOM;}

    /* Getters/Setters communs à tous les moveables */
    int get_speed() override {return _speed;}

    /* Getters/Setters */
    virtual SDL_Rect * get_specific_sprites() = 0; // Retourne les sprites spécifiques au fantôme

    /* Méthodes */
    void react() override; // Fait réagir le fantôme
    void animate() override; // Change le sprite du fantôme

    /* Méthodes spécifiques aux fantômes */
    // Défini la prochaine direction à prendre
    void set_next_direction(vector<Direction> directions);
    Direction choose_direction(vector<Direction> directions, SDL_Rect * target); // Choisi la direction qui nous rapproche le plus de la cible
    Direction get_random_direction(vector <Direction> directions); // Choisi aléatoirement une direction parmis les directions proposées
    SDL_Rect * translate_pos(Direction d, SDL_Rect * pos); // Décalle une position en fonction d'une direction (de 10pixels) pour choisir le chemin le plus court

    virtual SDL_Rect * get_target_chase() = 0; // Retourne la cible du fantôme en mode chase
    virtual SDL_Rect * get_target_scatter() = 0; // Retourne la cible du fantôme en mode scatter
    virtual SDL_Rect * get_target_origin() = 0; // Retourne la cible du fantôme en mode eaten


  private:
    /* Variables de classe */
    static const SDL_Rect SPRITES[8]; // Sprites commun à tous les fantômes
    static const int ZOOM = 2; // Zoom des sprites
    static ChaseMode CHASE_MODE; // Mode de chase du fantôme

    /* Variables d'instance */
    FantomState _state = FANTOM_CHASE; // État du fantôme
    int _speed = 3; // Vitesse de déplacement
    SDL_Rect _sprites[16]; // Liste de tout les sprites du fantôme
};