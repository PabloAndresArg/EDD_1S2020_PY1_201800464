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
	inline void recursive_add(NodoArbol*, NodoArbol*);
};

