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

