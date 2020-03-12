#pragma once
#include"NodoArbol.h"
#include<iostream>
using namespace std;
class Arbol
{
private: 
	NodoArbol* raiz;
public:
	Arbol() {
		this->raiz = NULL;
	}
	void add(NodoArbol*);
	void recursive_add(NodoArbol*, NodoArbol*);
	int compararAlfabeticamente(string , string ); // CAMBIAR A QUE RETORNE UN ENTERO PARA MANEJAR LO DEL ERROR 
	void recorrido_inOrder();
	void recursive_inOrder(NodoArbol*);
	void inline recorrido_PreOrder() { cout << "recorrido PREORDER: "; recursive_PreOrder(this->raiz); cout << endl; };
	void recursive_PreOrder(NodoArbol*);
	void recorrido_PostOrder() { cout << "recorrido POSTORDER "; recursive_PostOrder(this->raiz); cout << endl; }
	void recursive_PostOrder(NodoArbol*);
};

