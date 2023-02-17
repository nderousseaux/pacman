#include "field.h"
#include "pacman.h"
#include "blinky.h"
#include "pinky.h"
#include "inky.h"
#include "clyde.h"
#include "game.h"

/* Variables de classe */
Game * Game::_instance = nullptr;

/* Constructeur/Destructeur */
Game::Game() {
  if (_instance != nullptr)
    throw "Game already exists";
  Game::_instance = this;

  // On ajoute tout les sprites à la fenêtre
  load_elements();

  // On lance la boucle principale de jeu
  main_loop();
}

Game::~Game() {}

/* Méthodes */
// Charge les éléments sur la fenêtre
void Game::load_elements() {

  // On ajoute le terrain
  Window::get_instance()->add_element(new Field());

  // On ajoute pacman
  Window::get_instance()->add_element(new Pacman());

  // On ajoute les fantomes
  Window::get_instance()->add_element(new Blinky());
  Window::get_instance()->add_element(new Pinky());
  Window::get_instance()->add_element(new Inky());
  Window::get_instance()->add_element(new Clyde());
}

// Boucle principale du jeu
void Game::main_loop() {
	bool running = true;
	while (running) {

    // Gestion des évènements
    running = Window::get_instance()->handle_events();
    if (!running)
      break;

    // Gestion du clavier        
    running = control();

    // Fait "réagir" chaque élément
    for (Element * element : Window::get_instance()->get_elements())
      element->update();

    // On met à jour la fenêtre
    Window::get_instance()->update();
    
    // On attend 16ms
		SDL_Delay(16);
	}
}

// Gestion du clavier, renvoie false si on appuie sur ESCAPE
bool Game::control() {
  // Gestion du clavier        
  int nbk;
  const Uint8* keys = SDL_GetKeyboardState(&nbk);

  // Échap
  if (keys[SDL_SCANCODE_ESCAPE])
    return false;

  return true;
}

// Vérifie si l'élément est en collision avec un autre élément
Element * Game::check_collision(Element * element) {
  // On regarde si il y a un élément à la même position
  for (Element * other : Window::get_instance()->get_elements()) {
    //Si l'élément n'est pas lui même, et qu'il n'est pas un champ
    if (other == element || dynamic_cast<Field*>(other) != nullptr)
      continue;
    if (
      element->get_pos()->x + element->get_pos()->w >= other->get_pos()->x && element->get_pos()->x <= other->get_pos()->x + other->get_pos()->w &&
      element->get_pos()->y + element->get_pos()->h >= other->get_pos()->y && element->get_pos()->y <= other->get_pos()->y + other->get_pos()->h
    )
      return other;
  }
  return nullptr;

}
