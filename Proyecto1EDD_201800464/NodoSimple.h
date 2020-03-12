#pragma once
#include<iostream>
#include"RegistroPuntaje.h"
using namespace std; 
class NodoSimple
{
private:
	RegistroPuntaje* dato; 
	NodoSimple* sig; 

public:
	NodoSimple() { this->dato = NULL; this->sig = NULL; };
	NodoSimple(RegistroPuntaje* nuevoDato) { this->dato = nuevoDato; this->sig = NULL; }
	inline	NodoSimple* getSig() { return this->sig; }
	inline void setSig(NodoSimple* nuevo) { this->sig = nuevo; };
	inline RegistroPuntaje* getRegistro() { return this->dato; }

};

