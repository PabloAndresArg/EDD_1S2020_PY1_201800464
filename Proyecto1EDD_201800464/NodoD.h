#pragma once
#include"Ficha.h"
#include<iostream>
#include<stdlib.h>
using namespace std; 
class NodoD {
private:
	Ficha* dato;
	NodoD* ant;
	NodoD* sig;
public:
	NodoD() { this->ant = NULL; this->sig = NULL; this->dato = NULL; }
	NodoD(Ficha* F) { this->ant = NULL; this->sig = NULL; this->dato = F; }
	inline Ficha* getDato() { return this->dato; }
	inline NodoD* getAnt() { return this->ant; }
	inline NodoD* getSig() { return this->sig; }

	inline void setSig(NodoD* n ){
		this->sig = n; 
	}
	inline void setAnt(NodoD* m) {
		this->ant = m; 
	}
}; 
