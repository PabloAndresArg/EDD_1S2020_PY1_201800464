#pragma once
#include "ListaDoble.h"
#include<iostream>
#include<string>
#include"NodoD.h"
#include"Ficha.h"


using namespace std;
class ListaDoble
{
private: 
	NodoD * inicio;
	NodoD* ultimo;
	int cantidad_fichas;
public:
	ListaDoble() { this->inicio = NULL; this->ultimo = NULL; this->cantidad_fichas = 0;};
	void add( Ficha* );
	NodoD* buscar(char);
	void eliminar(NodoD*&); // para este metodo se tiene que realizar un buscar previamente 
	int getPuntaje_restar();
	void vaciar();
	void getGraphviz(string nombre);
	void imprimir(string nombre_del_jugador);
	void llenarAtril();
	bool existe_en_mi_lista(char letra_comprobar);
	inline void  setUltimo(NodoD* n) { this->ultimo = n; }
	inline void setInicio(NodoD* n) { this->inicio = n;  }
	inline NodoD* getInicio() { return this->inicio; }
	inline NodoD* getUltimo() { return this->ultimo; }
	inline int getCantidad_fichas() { return this->cantidad_fichas; }
};

