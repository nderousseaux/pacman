#pragma once

#include "moveable.h"
#include "pacman.h"

enum FantomState {
  FANTOM_CHASE,        // Chasse pacman
  FANTOM_FRIGHTENED,   // Fuit pacman
  FANTOM_EATEN,        // Est mangé par pacman
};

// Classe représentant un fantôme
class Fantom: public Moveable {
  public:
    /* Constructeur/Destructeur */
    Fantom(int x, int y);
    virtual ~Fantom() override;

    /* Méthode statique */
    static void set_fantoms_state(FantomState state); // Change l'état de tous les fantômes

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
    int get_speed() override {return SPEED;}

    /* Getters/Setters */
    virtual SDL_Rect * get_specific_sprites() = 0; // Retourne les sprites spécifiques au fantôme

    /* Méthodes */
    void react() override; // Fait réagir le fantôme
    void animate() override; // Change le sprite du fantôme
    SDL_Rect maj_pos(Direction d, int x_pos, int y_pos);
    Direction get_dir_choisie(int min_dist, SDL_Rect target, vector<Direction> dir);
    // void virtual where_dest() = 0;
    Direction get_random_dir(vector <Direction> dir);
    Direction virtual which_dir(vector<Direction> direction, FantomState _state) = 0;
    void switch_state(SDL_Rect init);
    int calc_distances(SDL_Rect * F, SDL_Rect * P);



  private:
    /* Variables de classe */
    static const SDL_Rect SPRITES[8]; // Sprites commun à tous les fantômes
    int SPEED = 3; // Vitesse de déplacement
    static const int ZOOM = 2; // Zoom des sprites

    /* Variables d'instance */
    FantomState _state = FANTOM_CHASE; // État du fantôme
    SDL_Rect _sprites[16]; // Liste de tout les sprites du fantôme
};