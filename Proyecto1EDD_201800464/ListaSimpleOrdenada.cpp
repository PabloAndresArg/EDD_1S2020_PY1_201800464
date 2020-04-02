#include "ListaSimpleOrdenada.h"
#include"RegistroPuntaje.h"
#include<iostream>
#include"NodoSimple.h"
#include"IO_Archivos.h"
using namespace std;
void ListaSimpleOrdenada::add(RegistroPuntaje * registro) {
	NodoSimple* nuevo = new NodoSimple(registro);
	if (this->cabeza == NULL) {
		this->cabeza = nuevo; 
		this->tamanio++;
	}
	else {
		// recorro porque ingresare ordenadamente 
		NodoSimple* aux = this->cabeza; 
		NodoSimple* ant = new NodoSimple; 
												// 5                       // 10 , 20 , 60 
		while (aux != NULL &&  registro->getPuntaje() < aux->getRegistro()->getPuntaje()) {
			ant = aux;
			aux = aux->getSig();
		}
		
		if (aux == NULL) {// inserto de ultimo 
			ant->setSig(nuevo);
			this->tamanio++;
		}
		else if (aux == this->cabeza) {
			nuevo->setSig(this->cabeza);
			this->cabeza = nuevo;
		}
		else{
			
			ant->setSig(nuevo);
			nuevo->setSig(aux); 
			this->tamanio++;
		}
	
	}
}

void ListaSimpleOrdenada::imprimir() {
	NodoSimple* aux = this->cabeza; 
	while (aux != NULL) {
		cout << "nombre: " << aux->getRegistro()->getNombre() << " puntaje: " << aux->getRegistro()->getPuntaje() << endl;
		aux = aux->getSig();
	}
}

void ListaSimpleOrdenada::getGraphviz_porJugador(string nom) {
	IO_Archivos obj;
	obj.PuntajePorJugador(this->cabeza , nom);
}

void ListaSimpleOrdenada::graph_scooreBoard_general() {
	IO_Archivos obj;
	obj.Graph_scoreboard(this->cabeza);
}
void  ListaSimpleOrdenada::pruebaGraph() {
	IO_Archivos obj;
	obj.graph_winner("PRUEBA");
}

