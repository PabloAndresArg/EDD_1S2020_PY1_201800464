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
		this->centro = NULL;
		this->centrolleno = false;
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
	 bool validarPalabra(ListaDobleCircular* diccionario  , bool primerPalabra , int& puntosParaJugador);// necesito una Lista de posiciones recorridas y la lista del diccionario 
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
	inline bool getCentroLLeno() {
		return this->centrolleno;
	}
	inline int getTamanioMax() {
		return this->maximo;
	}
	int  getValor_ficha(char letra , int n );
	void llenar_al_maximo(int);
	void llenar_al_maximo();
	void extraerCasillasNuevas(ListaCasillas* lista_casillas_nuevas);
	void extraerCasillasNuevas();
	void imprimirVector();
	void SET_NUEVA(int x , int y ); // para las casillas ya existentes 



	// para la adyacencia de cada casilla 
	bool hay_adyacencia_up(nMatrix* nodo);
	bool hay_adyacencia_down(nMatrix* nodo);
	bool hay_adyacencia_der(nMatrix* nodo);
	bool hay_adyacencia_izq(nMatrix* nodo);
	bool hay_adyacencia_paraNodoPrimero(nMatrix* nodo);

	bool puedoBajar(nMatrix* nodo);
	bool puedoSubir(nMatrix* nodo);
	bool puedoIzq(nMatrix* nodo);
	bool puedoDer(nMatrix* nodo);
	int esta_en_vector_nodos(int x , int y);
	 // casillas char 2 y 3 no cuentan 

	void interseccionesVerticales(ListaDobleCircular* diccionario ,  int& puntosParaJugador); // van a base del vector de nodos 
	void interseccionesHorizontales(ListaDobleCircular* diccionario , int& puntosParaJugador);





	void acumulaPuntosInterseccionesHORIZONTALES(ListaDobleCircular* diccionario, int& puntosParaJugador); // van a base del vector de nodos 
	void acumulaPuntosInterseccionesVERTICALES(ListaDobleCircular* diccionario, int& puntosParaJugador);


};





	


