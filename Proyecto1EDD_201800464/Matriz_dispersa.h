#pragma once
#include <iostream>
#include <string>
#include"nMatrix.h"
#include"nodoT.h"
#include"ListaCasillas.h"
#include"ListaDobleCircular.h"
#include"ListaCasillas.h"
#include<vector>
using namespace std; 
class Matriz_dispersa
{
private:
	ListaCasillas lista_casillas;
	int cantidad_nodos;
	nMatrix* root; 
	int maximo;
	int centro;
	bool centrolleno;
	vector<nMatrix*> vector_de_nodos; 
public:


	Matriz_dispersa() {
		this->root = new nMatrix();// reservo memoria 
		this->cantidad_nodos = 0;
		this->root->setLetra('R');// c de cabeza 
		this->root->setPos_y(-1);// pos en y que nunca usaria 
		this->root->setPos_x(-1);// una pos en x que nunca usaria
		this->maximo = NULL;
		this->centro = NULL;
		this->centrolleno = false;
	}

	Matriz_dispersa* clonar(Matriz_dispersa* clon);
	inline void setCasiTodo(ListaCasillas lista_casillas, int centro, int maximo , bool centro_lleno) {
		this->lista_casillas = lista_casillas;
		this->centro = centro;
		this->maximo = maximo;
		this->centrolleno = centro_lleno;
		vector<nMatrix*> nuevo;
		this->vector_de_nodos = nuevo;
	}
	
	nMatrix* BuscarNodo(int x ,  int y);

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
	 bool el_centro_esta_lleno();
	 bool es_palabra_adyacente();
	 bool validarPalabra(ListaDobleCircular* diccionario);// necesito una Lista de posiciones recorridas y la lista del diccionario 
	 void add(char letra, int x,  int y); // letra x , y
	 void add_ilusion(char letra , int x , int y); // ingresan como nuevas 
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
	void extraerCasillasNuevas(ListaCasillas* lista_casillas_nuevas);
	void extraerCasillasNuevas();
	void imprimirVector();
};



	


