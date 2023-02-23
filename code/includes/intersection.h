#pragma once

#include "direction.h"
#include <vector>

using namespace std;

// Classe représentant une intersection
class Intersection {
	public:
		Intersection(int x, int y);
		~Intersection();

		/* Getters/Setters */
		Intersection * get_top() {return _top;}
		Intersection * get_bottom() {return _bottom;}
		Intersection * get_left() {return _left;}
		Intersection * get_right() {return _right;}
		int get_pos_x() {return _pos_x;}
		int get_pos_y() {return _pos_y;}

		/* Méthodes de classe */
		static void create_intersections(); // Ajoute toutes les intersections et les relie entre elles

		/* Méthodes d'instances */
		std::vector<Direction> get_directions(); // Retourne les directions possibles à partir de l'intersection
		Intersection * get_from_direction(Direction direction); // Retourne l'intersection dans la direction donnée

	private:
		/* Variable d'instance */
		Intersection * _top = nullptr; 		// Intersection du haut
		Intersection * _bottom = nullptr; // Intersection du bas
		Intersection * _left = nullptr; 	// Intersection de gauche
		Intersection * _right = nullptr; 	// Intersection de droite
		int _pos_x = 0;
		int _pos_y = 0;

		/* Getters/Setters */
		void set_top(Intersection * top) {_top = top;}
		void set_bottom(Intersection * bottom) {_bottom = bottom;}
		void set_left(Intersection * left) {_left = left;}
		void set_right(Intersection * right) {_right = right;}
};