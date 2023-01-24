// Module contenant du code utile en tout genre
#include "imports.hpp"

/* Fonction pour incrémenter une variable*/
void incremente(int& x);

/* Affichage sur la sortie standard */
/* Penser à préciser le type de variable avec printObj<int> par ex */
template <typename T>
void printObj(const T& obj);

/* Fonction de cast vers int */
template <typename T>
int to_int(T value);

/* Retourne le max entre deux valeurs avec comme type T1 pour la val retournée */
template <typename T1, typename T2> 
T1 max(T1 a, T2 b);

