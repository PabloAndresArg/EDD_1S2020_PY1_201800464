#pragma once
#include<iostream>
#include"Jugador.h"
using namespace std; 
class NodoArbol {
private:
	Jugador* jugador;
	NodoArbol* izq;
	NodoArbol* der;
public: 
	NodoArbol() {	this->jugador = NULL; 	this->der = NULL; 	this->izq = NULL; }
	NodoArbol(Jugador* jugador_) { this->jugador = jugador_; 	this->der = NULL; 	this->izq = NULL; }
	inline Jugador* getJugador() { return this->jugador; };
	inline NodoArbol* getIzq() { return this->izq; }
	inline NodoArbol* getDer() { return this->der; }
	inline void setJugador(Jugador* nuevo) { this->jugador = nuevo; };
	inline void setIzq(NodoArbol* nuevo) { this->izq = nuevo; };
	inline void setDer(NodoArbol* nuevo) { this->der = nuevo; };
	
};
