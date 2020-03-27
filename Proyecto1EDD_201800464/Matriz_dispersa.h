#pragma once
#include <iostream>
#include <string>
#include"nMatrix.h"
#include"nodoT.h"
#include"ListaCasillas.h"
using namespace std; 
class Matriz_dispersa
{
private:
	ListaCasillas lista_casillas;
	int cantidad_nodos;
	nMatrix* root; 
	int maximo;
	int centro;
public:

	Matriz_dispersa() {
		this->root = new nMatrix();// reservo memoria 
		this->cantidad_nodos = 0;
		this->root->setLetra('R');// c de cabeza 
		this->root->setPos_y(-1);// pos en y que nunca usaria 
		this->root->setPos_x(-1);// una pos en x que nunca usaria
		this->maximo = NULL;
		this->centro = NULL;
	}
	inline void vaciar() {
		this->root = new nMatrix();// reservo memoria 
		this->cantidad_nodos = 0;
		this->root->setLetra('R');// c de cabeza 
		this->root->setPos_y(-1);// pos en y que nunca usaria 
		this->root->setPos_x(-1);// una pos en x que nunca usaria
		this->maximo = NULL;
		this->centro = NULL;
		this->lista_casillas.Vaciar(); 
		ListaCasillas nueva;
		this->lista_casillas = nueva;
	}
	inline ListaCasillas & getLista_Casillas() {
		return lista_casillas;
	}
	inline void refrescaCantidad_nodos(int nueva_cantidad) {
		this->cantidad_nodos = nueva_cantidad; 
	};
	inline int getCentro() {
		return this->centro;
	}

	inline int getCantidad_nodo() {
		return this->cantidad_nodos;
	}
	inline void setTamanioMaximo(int max) {
		this->maximo = max;
		this->centro = max / 2;
	}
	 void add(char, int, int); // letra x , y
	 void getGraphviz();
	 nMatrix* existeColumna(int);
	 nMatrix* recursive_existeColumna(nMatrix* , int);
	 nMatrix* existeFIla(int);
	 nMatrix* recursive_existeFila(nMatrix* , int);
	
	 nMatrix* generaColumna(int);
	 nMatrix* generaFila(int);
	 nMatrix* insertarOrdenadoFila(nMatrix* , nMatrix*);
	 nMatrix* insertarOrdenandoColumna(nMatrix* , nMatrix*);

	inline nMatrix* getRoot() {
		return this->root;
	}

	void llenar_al_maximo(int);
	void llenar_al_maximo();
};



	


