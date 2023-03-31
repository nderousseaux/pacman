#pragma once
#include "element.h"

#include <vector>
#include <SDL2/SDL.h>

using namespace std;

class Dot: public virtual Element {
	public:
		/* Constructeur/Destructeur */
		Dot(int x, int y);
		~Dot() override;

		/* Méthodes de classe */
		static void create_dots(std::vector<Dot *> * dots); // Place les points sur le terrain

		/* Méthode d'instances */
		void remove(); // On supprime le point

	protected:
		/* Getters/Setters communs à tous les éléments */
		SDL_Rect * get_sprites() override {return (SDL_Rect *)SPRITES;}
		int get_zoom() override {return ZOOM; }

		/* Méthodes */
		void react() override; // Fait réagir le point
		void animate() override; // Change le sprite du point

	private:
		/* Variables de classe communs à tous les éléments */
		static const SDL_Rect SPRITES[1]; // Liste des sprites du point
		static const int ZOOM = 4;

		/* Méthodes de classe */
		static Dot * add_dot(Dot * dot); // Ajoute le point à la fenêtre et à la liste des points
};
