#include "Arbol.h"
#include"NodoArbol.h"
#include<iostream>
#include<string>
using namespace std; 
void Arbol::add(NodoArbol* nuevo) {
	if (this->raiz == NULL) {
		this->raiz = nuevo;
	}
	else {
		recursive_add(this->raiz, nuevo); // minuto 43
	}
}
void Arbol::recursive_add(NodoArbol* actual, NodoArbol* nuevo) {

}