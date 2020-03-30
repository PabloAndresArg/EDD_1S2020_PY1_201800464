#include "Cola.h"
#include"NodoCola.h"
#include "IO_Archivos.h"
using namespace std; 
void Cola::encolar(Ficha* dato) {
	NodoCola* nuevo = new NodoCola(dato);// sig = null y guarda el dato 
	if (this->cabeza == NULL) {// vacia 
		this->cabeza = nuevo; 
		this->ultimo = nuevo;
	}
	else {// insertemos de ultimo 
			this->ultimo->setSig(nuevo);
			this->ultimo = nuevo;	
	}
	this->tamanio++; 
}

void Cola::desencolar() {
	if (this->cabeza != NULL) {
		this->cabeza = this->cabeza->getSig();
		this->tamanio--;
	}	
}

void Cola::vaciar() {
	this->cabeza = NULL;
	this->tamanio = 0;
}

NodoCola* Cola::buscar(char letter) {
	NodoCola* aux = this->cabeza;
	while (aux != NULL && aux->getFicha()->getLetra() != letter) {
		aux = aux->getSig();
	}
	if (aux == NULL) {
		cout << "NO SE ENCONTRO LA LETRA ESPECIFICADA ADENTRO DE SU COLA " << endl;
		NodoCola* n = new NodoCola();
		return n;
		/* si lo que devuelve es nulo donde lo llame 
		tengo que validar que no arruine mi programa 
		*/
	}
	else {
		return aux;
	}
}



void Cola::imprimir() {
	int x = 0; 
	NodoCola* aux = this->cabeza;
	cout << endl;
	while (aux != NULL) {
		x++;
		cout << x<< ". LETRA: " << aux->getFicha()->getLetra();
		cout << " puntaje: " << aux->getFicha()->getPuntaje();
		cout<< endl;
		aux = aux->getSig();
	}
}

void Cola::getGraphviz() {
	IO_Archivos*  llama = new IO_Archivos(); 
	llama->GraficaCola(this->cabeza);
}

