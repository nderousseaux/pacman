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

		/* Variable statique */
		static const int DOTS[188][2]; // Liste des coordonnées des points

		/* Méthode statique */
		static void create_dots(std::vector<Dot *> & dots); // Place les points sur le terrain

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
};
