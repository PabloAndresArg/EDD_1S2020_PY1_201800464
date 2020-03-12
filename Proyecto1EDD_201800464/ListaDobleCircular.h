#pragma once
#include<string>
#include<iostream>
#include"NodoDobleC.h"
using namespace std;
class ListaDobleCircular
{

private:
	NodoDobleC* inicio;
	NodoDobleC* ultimo;
	int tamanio; 
public:
	ListaDobleCircular() { this->inicio = NULL; this->ultimo = NULL; this->tamanio = 0; };
	void add(string);
	NodoDobleC* getUltimo();
	void getGraphviz();
	void imprimeparaAdelnate(); 
	void imprimeparaAtras();
};

