#pragma once
#include<string>
#include"Casilla.h"
#include"nodoT.h"
#include<iostream>
using namespace std; 
class ListaCasillas{
private: 
	nodoT* inicio;
	nodoT* ultimo; 
public:
	ListaCasillas() {
		this->inicio = NULL; 
		this->ultimo = NULL;
	}
	inline nodoT* getInicio() {
		return this->inicio;
	}
	inline void Vaciar() {
		this->inicio = NULL; 
	}
	inline nodoT* getUltimo() {
		return this->ultimo;
	}
	inline void add(Casilla* casilla_) {
		nodoT* nuevo_nodo = new nodoT(casilla_); 
		if (this->inicio == NULL) {
			this->inicio = nuevo_nodo; 
			this->ultimo = nuevo_nodo;
		}
		else {
			nuevo_nodo->sig = this->ultimo;
			this->ultimo = nuevo_nodo;
		}
	}
	inline Casilla* buscar(int posx , int posy) {
		if (this->inicio == NULL) {
			nodoT* aux = this->inicio;
			while (aux!= NULL) {
				if (aux->casilla->posX == posx && aux->casilla->posY == posy) {
					return aux->casilla;
				}
				aux = aux->sig;
			}
		}
		else {
			return NULL;
		}
	
	}
	inline void imprimir() {
		nodoT* aux = this->ultimo;
		cout << "---CASILLAS DE LA MATRIZ---\n";
		while (aux != NULL)
		{
			cout <<"posX "<<aux->casilla->posX << " posY "<< aux->casilla->posY <<" se multiplica por: "<<aux->casilla->tipo<<endl;
			aux = aux->sig;
		}
	}

	inline bool esCasillaEspecial(int x , int y) { // NO NECESARIO 

		nodoT* aux = this->ultimo;
		while (aux != NULL)
		{
			if (x == aux->casilla->posX && y == aux->casilla->posY) {
				return true;
			}
			aux = aux->sig;
		}
		return false; 
	}

	inline int retornaValorCasillaEspecial(int x , int y) {// lo puedo ejecutar siempre y no afecta
		nodoT* aux = this->ultimo;
		while (aux != NULL)
		{
			if (x == aux->casilla->posX && y == aux->casilla->posY) {
				return aux->casilla->tipo;
			}
			aux = aux->sig;
		}
		return 1;
	}
	
};