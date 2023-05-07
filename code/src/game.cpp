#include "game.h"
#include "window.h"
#include "field.h"
#include "pacman.h"
#include "blinky.h"
#include "pinky.h"
#include "inky.h"
#include "clyde.h"


/* #region Variables de classe */
Game * Game::_instance = nullptr;
/* #endregion */

/* #region Constructeur/Destructeur */
Game::Game() {
  if (_instance != nullptr) // Singleton
    throw "Game already exists";
  Game::_instance = this;

  // On ajoute tout les sprites à la fenêtre
  load_elements();

  // On lance la boucle principale de jeu
  main_loop();
}

Game::~Game() {}
/* #endregion */

/* #region Getters/Setters */
// Getter d'un élément par son type
template<class T> T* Game::get_element() {
  for (Element * element : Window::get_instance()->get_elements()) {
    T * t = dynamic_cast<T *>(element);
    if (t != nullptr)
      return t;
  }
  return nullptr;
}
/* #endregion */

/* #region Méthodes internes */
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
    if (!running)
      break;

    // Fait "réagir" chaque élément
    for (Element * element : Window::get_instance()->get_elements())
      element->update();

    // On met à jour la fenêtre
    Window::get_instance()->update();
    
    // On attend 16ms
		SDL_Delay(16);
	}
}
/* #endregion */

/* #region Méthodes */
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

// On a gagné la partie // TODO: Améliorer avec le polymorphisme
void Game::win() {
  // On arrête pacman
  get_element<Pacman>()->set_direction(STOP);
  get_element<Blinky>()->set_direction(STOP);

  // On arrête les fantomes
  set_state(GAME_PAUSE);

  // On lance l'animation de victoire
  get_element<Field>()->set_state(FIELD_WIN);
}

// Redémarre la partie // TODO: Améliorer avec le polymorphisme
void Game::restart(bool with_dot_reset) {
  // On fait respawn les fantomes
  for (Element * element : Window::get_instance()->get_elements()) {
    if (Fantom * fantom = dynamic_cast<Fantom*>(element))
      fantom->spawn();
    if (Pacman * pacman = dynamic_cast<Pacman*>(element))
      pacman->spawn();
  }

  if (with_dot_reset) {
    Field::get_instance()->create_dots();
  }

  // On redemarre la partie
  set_state(GAME_PLAY);
}

// On quite l'application
void Game::quit() {
  Window::get_instance()->quit();
}
/* #endregion */
