#include "ListaDobleCircular.h"
#include<string>
#include<iostream>
#include"NodoDobleC.h"
#include"IO_Archivos.h"
using namespace std;
void ListaDobleCircular::add(string palabra) {
	palabra = aMinuscula(palabra);
	NodoDobleC* nuevo = new NodoDobleC();
	nuevo->dato = palabra;
	if (this->inicio == NULL) {
		this->inicio = nuevo;
		this->ultimo = nuevo;
		this->inicio->sig = nuevo; 
		this->ultimo->sig = nuevo;
		this->tamanio++;
	}
	else {
		nuevo->ant = this->ultimo;
		this->ultimo->sig = nuevo;
		this->ultimo = nuevo; // refrescamos cual es el ultimo ahora 
		this->ultimo->sig = this->inicio;
		this->inicio->ant = this->ultimo;
		this->tamanio++;
	}
}
void ListaDobleCircular::imprimeparaAdelnate() {
	cout <<"XXXXXXXXXXXXXXXXXXXX DICCIONARIO XXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	if (this->inicio != NULL) {
		NodoDobleC* aux = this->ultimo;
		int numeral = 1;
		int formato = 0;
		for (int i = this->tamanio; i > 0; i--)
		{
			cout << numeral << ". " + aux->dato << "     ";
			numeral++;
			formato++;
			if (formato == 5) {
				cout << endl;
				formato = 0;
			}
			aux = aux->ant;
		}
		cout << endl;
	}
	cout <<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
}
bool ListaDobleCircular::aparece_en_diccionario(string palabra_buscar) {
	if (this->inicio != NULL) {
		NodoDobleC* aux = this->ultimo;
		for (int i = this->tamanio; i > 0; i--)
		{
			if (aux->dato.compare(palabra_buscar)==0) {
				return true;
			}
			aux = aux->ant;
		}
	}
	return false;
}
void ListaDobleCircular::imprimeparaAtras() {
	if (this->inicio!= NULL) {
		NodoDobleC* aux = this->ultimo;
		for (int i = this->tamanio; i > 0; i--)
		{
			cout << "PALABRA: " + aux->dato << " ";
			aux = aux->ant;
		}
		cout << endl;
	}

}

void ListaDobleCircular::getGraphviz() {
	IO_Archivos* llama = new IO_Archivos();

	llama->DobleCircular(this->inicio, this->ultimo, this->tamanio);
}
