#pragma once
#include "ListaDoble.h"
#include<iostream>
#include<string>
#include"NodoD.h"
#include"Ficha.h"


using namespace std;
class ListaDoble
{
private: 
	NodoD * inicio;
	NodoD* ultimo;
public:
	ListaDoble() { this->inicio = NULL; this->ultimo = NULL; };
	void add( Ficha* );
	NodoD* buscar(char);
	void eliminar(NodoD*&); // para este metodo se tiene que realizar un buscar previamente 
	int getPuntaje();
	void vaciar();
	void getGraphviz();
	void imprimir();
	void InsertarPrimero(Ficha*);

	inline void  setUltimo(NodoD* n) { this->ultimo = n; }
	inline void setInicio(NodoD* n) { this->inicio = n;  }
	inline NodoD* getInicio() { return this->inicio; }
	inline NodoD* getUltimo() { return this->ultimo; }
};

