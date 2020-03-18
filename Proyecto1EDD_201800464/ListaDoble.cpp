#include "ListaDoble.h"
#include"NodoD.h"
#include<string>
#include"IO_Archivos.h"
using namespace std; 

void ListaDoble::InsertarPrimero(Ficha* c) {

}

void ListaDoble::add(Ficha* d) { //inserta en la ultima posicion 
	NodoD* nuevo = new NodoD(d);
	cout << "INGRESAR: " << nuevo->getDato();
	if (this->getInicio() == NULL) {
		this->setInicio(nuevo);
		this->setUltimo(nuevo);
		cout << "----"<<endl;
	}
}



void ListaDoble::imprimir() {
	NodoD* aux = this->inicio;
	cout << " LISTA DEL JUGADOR " << endl;
	if (this->inicio == NULL) {
		cout << " no se esta llenando " << endl;
	}
	while (aux != NULL) {
		cout << "letra:" << aux->getDato()->getLetra();

		aux = aux->getSig();
	}

}

void ListaDoble::getGraphviz() {
	IO_Archivos llama; 
	llama.Graph_LISTA_DOBLE(this->inicio , this->ultimo);
}
void ListaDoble::eliminar(NodoD*& nBorrar ) {
	NodoD*& init = this->inicio;
	if (this->inicio != NULL) {// no se puede eliminar un nodo que esta vacio 

		if (this->inicio == this->ultimo) {// elimina toda la lista si solo hay uno 
			init = NULL;
			this->ultimo = NULL;
		}
		else if (this->inicio == nBorrar) {// elimina primero 
			init = init->getSig();
			init->setAnt(NULL);
		}
		else if (this->ultimo == nBorrar) {// elimina ultimo 
			this->ultimo = this->ultimo->getAnt();
			this->ultimo->setSig(NULL);
		}
		else if (nBorrar->getDato() == NULL) {

		}
		else {// elimina cualquiera de enmedio 

			nBorrar->getAnt()->setSig(nBorrar->getSig());
			nBorrar->getSig()->setAnt(nBorrar->getAnt())  ;

		}
	}
}

void ListaDoble::vaciar() {
	this->inicio = NULL;
	this->ultimo = NULL;
}
NodoD* ListaDoble::buscar(char letter) {
	NodoD* aux = this->inicio;
	while (aux != NULL && aux->getDato()->getLetra() != letter) {
		aux = aux->getSig();
	}
	if (aux == NULL) {
		cout << "NO SE ENCONTRO LA LETRA ESPECIFICADA ADENTRO DE SU COLA " << endl;
		NodoD* n = new NodoD();
		return n;
		/* si lo que devuelve es nulo donde lo llame
		tengo que validar que no arruine mi programa
		*/
	}
	else {
		return aux;
	}
}


int ListaDoble :: getPuntaje() { // esto para la lista de los usuarios
	int contadorPuntos = 0;
	NodoD* aux = this->inicio;
	while (aux != NULL) {
		contadorPuntos += aux->getDato()->getPuntaje();
		aux = aux->getSig();
	}
	return contadorPuntos;
}