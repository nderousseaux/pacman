#include "dot.h"
#include "window.h"
#include "field.h"

/* #region Variables de classe */
const SDL_Rect Dot::SPRITES[1] = {
	{ 4,81, 2,2 }
};

// Liste des coordonnées des points
const int Dot::DOTS[188][2] = {
	{40, 40},
	{40, 72},
	{40, 136},
	{40, 168},
	{40, 200},
	{40, 232},
	{40, 264},
	{40, 584},
	{40, 616},
	{40, 744},
	{40, 776},
	{40, 808},
	{72, 40},
	{72, 168},
	{72, 264},
	{72, 584},
	{72, 648},
	{72, 744},
	{72, 808},
	{104, 40},
	{104, 168},
	{104, 264},
	{104, 584},
	{104, 648},
	{104, 680},
	{104, 712},
	{104, 744},
	{104, 808},
	{136, 40},
	{136, 168},
	{136, 264},
	{136, 584},
	{136, 744},
	{136, 808},
	{168, 40},
	{168, 72},
	{168, 104},
	{168, 136},
	{168, 168},
	{168, 200},
	{168, 232},
	{168, 264},
	{168, 296},
	{168, 328},
	{168, 360},
	{168, 392},
	{168, 424},
	{168, 456},
	{168, 488},
	{168, 520},
	{168, 552},
	{168, 584},
	{168, 616},
	{168, 648},
	{168, 680},
	{168, 712},
	{168, 744},
	{168, 808},
	{200, 40},
	{200, 168},
	{200, 584},
	{200, 648},
	{200, 808},
	{232, 40},
	{232, 168},
	{232, 200},
	{232, 232},
	{232, 264},
	{232, 584},
	{232, 648},
	{232, 680},
	{232, 712},
	{232, 744},
	{232, 808},
	{264, 40},
	{264, 168},
	{264, 264},
	{264, 584},
	{264, 648},
	{264, 744},
	{264, 808},
	{296, 40},
	{296, 72},
	{296, 104},
	{296, 136},
	{296, 168},
	{296, 264},
	{296, 584},
	{296, 616},
	{296, 648},
	{296, 744},
	{296, 776},
	{296, 808},
	{328, 168},
	{328, 808},
	{360, 40},
	{360, 72},
	{360, 104},
	{360, 136},
	{360, 168},
	{360, 264},
	{360, 584},
	{360, 616},
	{360, 648},
	{360, 744},
	{360, 776},
	{360, 808},
	{392, 40},
	{392, 168},
	{392, 264},
	{392, 584},
	{392, 648},
	{392, 744},
	{392, 808},
	{424, 40},
	{424, 168},
	{424, 200},
	{424, 232},
	{424, 264},
	{424, 584},
	{424, 648},
	{424, 680},
	{424, 712},
	{424, 744},
	{424, 808},
	{456, 40},
	{456, 168},
	{456, 584},
	{456, 648},
	{456, 808},
	{488, 40},
	{488, 72},
	{488, 104},
	{488, 136},
	{488, 168},
	{488, 200},
	{488, 232},
	{488, 264},
	{488, 296},
	{488, 328},
	{488, 360},
	{488, 392},
	{488, 424},
	{488, 456},
	{488, 488},
	{488, 520},
	{488, 552},
	{488, 584},
	{488, 616},
	{488, 648},
	{488, 680},
	{488, 712},
	{488, 744},
	{488, 808},
	{520, 40},
	{520, 168},
	{520, 264},
	{520, 584},
	{520, 744},
	{520, 808},
	{552, 40},
	{552, 168},
	{552, 264},
	{552, 584},
	{552, 648},
	{552, 680},
	{552, 712},
	{552, 744},
	{552, 808},
	{584, 40},
	{584, 168},
	{584, 264},
	{584, 584},
	{584, 648},
	{584, 744},
	{584, 808},
	{616, 40},
	{616, 72},
	{616, 136},
	{616, 168},
	{616, 200},
	{616, 232},
	{616, 264},
	{616, 584},
	{616, 616},
	{616, 744},
	{616, 776},
	{616, 808},
};

/* #endregion */

/* #region Constructeur/Destructeur */
Dot::Dot(int x, int y): Element(x,y) {
	set_current_sprite(0);
	Window::get_instance()->insert_element(this);
}

Dot::~Dot() {
	Window::get_instance()->remove_element(this);
	// On se supprime du field
	Field::get_instance()->remove_dot(this);
	
}
/* #endregion */

/* #region Méthodes statique */
// Crée tout les points
void Dot::create_dots(std::vector<Dot *> & dots) {
	for (int i = 0; i < 188; i++) {
		dots.push_back(new Dot(Dot::DOTS[i][0], Dot::DOTS[i][1]));
	}
}

/* #endregion */

/* #region Méthodes */
// Fait réagir le point
void Dot::react() {}

// Change le sprite du point
void Dot::animate() {}

/* #endregion */