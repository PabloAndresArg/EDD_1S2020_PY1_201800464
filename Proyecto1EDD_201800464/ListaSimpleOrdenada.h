#pragma once
#include<iostream>
#include"NodoSimple.h"
#include"RegistroPuntaje.h"
#include <string.h>
using namespace std; 
class ListaSimpleOrdenada
{
private:
	NodoSimple* cabeza;
	int tamanio;
public:
	// solo necesito un insertar,
	ListaSimpleOrdenada() { this->cabeza = NULL; this->tamanio = 0; }
	void add(RegistroPuntaje*);
	void imprimir();
	inline NodoSimple* getCabeza() { return this->cabeza; };
	void getGraphviz(); // el metodo GENERAL PARA LOS MEJORES PUNTEOS 
};

