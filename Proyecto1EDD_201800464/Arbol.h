#pragma once
#include"NodoArbol.h"
#include<iostream>
#include"ListaSimpleOrdenada.h"
using namespace std;
class Arbol
{
private: 
	NodoArbol* raiz;
	string Graph;
	int indice;
	ListaSimpleOrdenada listaPreOder;
	ListaSimpleOrdenada listaInOrder;
	ListaSimpleOrdenada listaPostOrder;

	ListaSimpleOrdenada lista_Scooreboard;
public:
	Arbol() {
		this->raiz = NULL;
		Graph = "";
		indice = 0;
		// TAMANIO Y CON ESO UN ARREGLO PARA NO TENER QUE CREAR UNA LISTA SIMPLE DIFERENTE 
	}
	inline NodoArbol* getRoot() { return this->raiz; }; 
	void limpiarListasAux();
	void add(NodoArbol*);
	void recursive_add(NodoArbol*, NodoArbol*);
	int compararAlfabeticamente(string , string ); // CAMBIAR A QUE RETORNE UN ENTERO PARA MANEJAR LO DEL ERROR 
	void recorrido_inOrder();
	void recursive_inOrder(NodoArbol*);
	void inline recorrido_PreOrder() { cout << "recorrido PREORDER: "; recursive_PreOrder(this->raiz); cout << endl; };
	void recursive_PreOrder(NodoArbol*);
	void recorrido_PostOrder() { cout << "recorrido POSTORDER "; recursive_PostOrder(this->raiz); cout << endl; }
	void recursive_PostOrder(NodoArbol*);
	void getGraphviz(); 
	void getGraphviz(NodoArbol*); // recolecto en preorder raiz izq derecha
	string convertirTodoMinuscula(string);
	Jugador* buscar(string);
	NodoArbol* buscarRecursivo(NodoArbol*,string);
	void llenarListasSimples();
	void llenarListaPreOrder(NodoArbol*); 
	void llenarListaInOrder(NodoArbol*);
	void llenarListaPostOrder(NodoArbol*);
	void setJugador(Jugador* regresa_jugador);

	inline ListaSimpleOrdenada & getlistaPrueba() {
		return this->listaInOrder;
	}
	void vaciar();

	void getScoreBoard();
	void getScoreBoard(NodoArbol* root_temp);

};

