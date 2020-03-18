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
	inline string aMinuscula(string cadena) {
		string nuevoNombre = "";
		int lon = (int)cadena.size();
		for (int i = 0; i < lon; i++)
		{char letra = tolower(cadena[i]);	nuevoNombre += letra;	}
		return nuevoNombre;
	};


};

