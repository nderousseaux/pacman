#include "../includes/game.h"

/* Constructeur/Destructeur */
Game::Game(Window * window):
  _window(window) {
  
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
  _window->add_element(new Field());

  // On ajoute pacman
  _window->add_element(new Pacman());

  // On ajoute les fantomes
  _window->add_element(new Blinky());
  _window->add_element(new Pinky());
  _window->add_element(new Inky());
  _window->add_element(new Clyde());
}

// Boucle principale du jeu
void Game::main_loop() {
	bool running = true;
	while (running) {

    // Gestion des évènements
    running = _window->handle_events();
    if (!running)
      break;

    // Gestion du clavier        
    running = control();

    // Fait "réagir" chaque élément
    for (Element * element : _window->get_elements())
      element->update();
    
    // On met à jour la fenêtre
    _window->update();
    
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