#pragma once
#include<string>
#include"NodoCola.h"
using namespace std; 
class Cola
{
private: 
	NodoCola* cabeza; 
	NodoCola* ultimo; // para no hacer un ciclo
public:
	Cola() { this->cabeza = NULL; this->ultimo = NULL; }
	inline NodoCola* getCabeza() { return this->cabeza; }
	inline void setCabeza(NodoCola* nuevaCAbeza) {this->cabeza = nuevaCAbeza;}
	void encolar(Ficha*);
	void desencolar();
	void imprimir();
	NodoCola* buscar(char); // no sirve de nada XD 
	void getGraphviz();
	void vaciar();
};
