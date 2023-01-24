// Module contenant du code utile en tout genre

#include "../includes/imports.hpp"

/* Fonction pour incrémenter une variable*/
void incremente(int& x){ // param par ref
    x=x+1;
}

/* Affichage sur la sortie standard */
template <typename T>
void printObj(const T& obj){
    cout << obj << std::endl;
}

/* Fonction de cast vers int */
template <typename T>
int to_int(T value) {
    return static_cast<int>(value);
}

/* Retourne le max entre deux valeurs avec comme type T1 pour la val retournée */
template <typename T1, typename T2>
T1 max(T1 a, T2 b) {
    return (a > b) ? a : b;
}

