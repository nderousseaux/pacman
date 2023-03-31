#include "game.h"
#include "window.h"
#include "blinky.h"
#include "pinky.h"
#include "inky.h"
#include "clyde.h"
#include "dot.h"

/* #region Variables de classe */
Game * Game::_instance = nullptr;
/* #endregion */

/* #region Constructeur/Destructeur */
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
/* #endregion */

/* #region Méthodes */
// Charge les éléments sur la fenêtre
void Game::load_elements() {

  // On ajoute le terrain
  _field = new Field();
  Window::get_instance()->add_element(_field);

  // On ajoute pacman
  _pacman = new Pacman();
  Window::get_instance()->add_element(_pacman);

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

// Redémarre la partie
void Game::restart(bool with_dot_reset) {
  (void)with_dot_reset;

  // On fait respawn les fantomes
  for (Element * element : Window::get_instance()->get_elements()) {
    if (Fantom * fantom = dynamic_cast<Fantom*>(element))
      fantom->spawn();
    if (Pacman * pacman = dynamic_cast<Pacman*>(element))
      pacman->spawn();
  }

  // On redemarre la partie
  set_state(GAME_PLAY);
}

// Gestion du clavier, renvoie false si on appuie sur ESCAPE
bool Game::control() {
  // Gestion du clavier        
  int nbk;
  const Uint8* keys = SDL_GetKeyboardState(&nbk);

  // Échap
  if (keys[SDL_SCANCODE_ESCAPE])
    return false;
  // P
  else if (keys[SDL_SCANCODE_P]) {
    if (get_state() == GAME_PLAY)
      set_state(GAME_PAUSE);
    else if (get_state() == GAME_PAUSE)
      set_state(GAME_PLAY);
  }

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

// On a gagné la partie
void Game::win() {
  // On arrête pacman
  _pacman->set_direction(STOP);
  // On arrête les fantomes
  set_state(GAME_PAUSE);

  // On lance l'animation de victoire
  _field->set_state(FIELD_WIN);
}

// On quite l'application
void Game::quit() {
  Window::get_instance()->quit();
}
/* #endregion */
