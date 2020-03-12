#pragma once
#include"NodoArbol.h"
#include<iostream>
using namespace std;
class Arbol
{
private: 
	NodoArbol* raiz;
	string Graph;
public:
	Arbol() {
		this->raiz = NULL;
		Graph = "";
		// TAMANIO Y CON ESO UN ARREGLO PARA NO TENER QUE CREAR UNA LISTA SIMPLE DIFERENTE 
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
	void getGraphviz(); 
	void getGraphviz(NodoArbol*); // recolecto en preorder raiz izq derecha 
};

