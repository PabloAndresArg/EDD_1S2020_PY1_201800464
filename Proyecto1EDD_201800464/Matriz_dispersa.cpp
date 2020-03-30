#include "Matriz_dispersa.h"
#include<string>
#include"nMatrix.h"
#include"IO_Archivos.h"
#include"Ficha.h"
#include<iostream>
#include<fstream>
using namespace std; 
/*
Pasos para construir una matris dispersa: 
1. constructor definir la raiz la cual no se puede eliminar
2. metodos de insercion Ordenados  para las listas que estan en enlace directo con ROOT
3. crar filas y columnas 
4. metodo insertar Nodo
*/

// creando filas y columnas
nMatrix* Matriz_dispersa::generaFila(int y) {
	nMatrix* raiz = this->root , * F; // ver si no da error
	F = this->insertarOrdenadoFila(new nMatrix(-1, y, 'F'), raiz);
	return F;
}
nMatrix* Matriz_dispersa::generaColumna(int x) {
	nMatrix* raiz = this->root , *c;
    c = this->insertarOrdenandoColumna(new nMatrix(x, -1, 'C'), raiz);
	return c;
}

// verificando existecia de filas y columnas
nMatrix* Matriz_dispersa::existeFIla(int y) { // convertir en recursivo 
	nMatrix* temp = new nMatrix();
	temp = this->root; 	
	return recursive_existeFila(temp, y);
}

nMatrix* Matriz_dispersa::recursive_existeFila(nMatrix* nodo ,  int y) {
	if (nodo == NULL) {
		return NULL;
	}
	else if (nodo->getPos_y() == y) {
		return nodo;
	}
	else {
		return recursive_existeFila(nodo->getDown() ,  y );
	}
}


nMatrix* Matriz_dispersa::existeColumna(int x) { //Veo si existe la columna
	nMatrix* temp = new nMatrix();
	temp = this->root;
	return recursive_existeColumna(temp, x);
}
nMatrix* Matriz_dispersa::recursive_existeColumna( nMatrix* nodo , int x){
	if (nodo == NULL) {
		return NULL;
	}
	else if (nodo->getPos_x() == x) {
		return nodo;
	}
	else {
		return recursive_existeColumna(nodo->getDer(), x);
	}
}

// insercion existen 4 casos----------------------------------------------------------


nMatrix* Matriz_dispersa::insertarOrdenadoFila(nMatrix* nuevo, nMatrix* Cabecera_fila) {
	bool bandera = false;
	nMatrix* temp = new nMatrix();
	temp = Cabecera_fila;
	while (true)
	{
		if (temp->getPos_y() == nuevo->getPos_y()) 
		{// sobreescribe
			temp->setPos_x(nuevo->getPos_x());
			temp->setLetra(nuevo->getLetra());
			return temp; 
		}
		else if (temp->getPos_y() > nuevo->getPos_y()) 
		{
			//Al nuevo lo inserto antes que temp
			bandera = true;
			break;
		}
		if (temp->getDown() != NULL) //Me permite mover hasta que no sea nulo
		{
			temp = temp->getDown();
		}
		else //Quiere decir que el que sigue es nulo, nunca cambió la bandera, entonces inserto después de temp
		{
			break;
		}
	}

	if (bandera)
	{
		//Caso antes de un nodo 
		nuevo->setAbajo(temp);
		temp->getUp()->setAbajo(nuevo);
		nuevo->setArriba(temp->getUp());
		temp->setArriba(nuevo);
	}
	else
	{// after de un node :v 
		temp->setAbajo(nuevo);
		nuevo->setArriba(temp);
	}

	return nuevo;

}

nMatrix* Matriz_dispersa::insertarOrdenandoColumna(nMatrix* nuevo, nMatrix* cabeza_columna) {
	bool bandera = false;
	nMatrix* temp = new nMatrix();
	temp = cabeza_columna;
	while (true)
	{
		if (temp->getPos_x() == nuevo->getPos_x()) //Solo sobreescribo el temporal
		{
			temp->setPos_y(nuevo->getPos_y());
			temp->setLetra(nuevo->getLetra());
			return temp; //Retorno puntero
		}
		else if (nuevo->getPos_x() < temp->getPos_x()) //Al nuevo lo inserto antes que temp
		{
			bandera = true;
			break;
		}
		if (temp->getDer() != NULL) 
		{
			temp = temp->getDer();
		}
		else //Quiere decir que el que sigue es nulo, nunca cambió la bandera, entonces inserto después de temp
		{
			break;
		}
	}

	if (bandera)
	{// inserte antes de..
		nuevo->setDerecha(temp);
		temp->getIzq()->setDerecha(nuevo);
		nuevo->setIzq(temp->getIzq());
		temp->setIzq(nuevo);
	}
	else
	{
		temp->setDerecha(nuevo);
		nuevo->setIzq(temp);
	}

	return nuevo;

}

void Matriz_dispersa::add(char letra, int x , int y ) {

	if (x < this->maximo && y < this->maximo) {

		nMatrix* nuevo_nodo = new nMatrix(x, y, letra);
		nMatrix* cabecera_columna = existeColumna(x);// cabeceras  hacia abajo 
		nMatrix* cabeceraFila = existeFIla(y);// cabecera hacia derecha
		int caso = 0; 

		if (cabecera_columna == NULL && cabeceraFila == NULL) {// caso 1 
			caso = 1;
		}
		else if (cabecera_columna == NULL && cabeceraFila != NULL) { // caso 2 
			// entonces creo la columna 
			caso = 2;
		}
		else if (cabecera_columna != NULL && cabeceraFila == NULL) { // case3
			caso = 3; 
		}
		else if (cabecera_columna != NULL && cabeceraFila != NULL) {// case4
			caso = 4;
		}
		switch (caso)
		{
		case 1:
			cabecera_columna = this->generaColumna(x);
			cabeceraFila = this->generaFila(y);
			nuevo_nodo = this->insertarOrdenandoColumna(nuevo_nodo, cabeceraFila);
			nuevo_nodo = this->insertarOrdenadoFila(nuevo_nodo, cabecera_columna);
			return;
		break;
		case 2:
			cabecera_columna = this->generaColumna(x);
			nuevo_nodo = this->insertarOrdenandoColumna(nuevo_nodo, cabeceraFila);
			nuevo_nodo = this->insertarOrdenadoFila(nuevo_nodo, cabecera_columna);
			return;
		break;

		case 3:
			cabeceraFila = this->generaFila(y);
			nuevo_nodo = this->insertarOrdenandoColumna(nuevo_nodo, cabeceraFila);
			nuevo_nodo = this->insertarOrdenadoFila(nuevo_nodo, cabecera_columna);
			return;
		break;

		case 4:
			nuevo_nodo = this->insertarOrdenandoColumna(nuevo_nodo, cabeceraFila);
			nuevo_nodo = this->insertarOrdenadoFila(nuevo_nodo, cabecera_columna);
			return;
		break;
		default:
			break;
		}
		this->cantidad_nodos++;
	}
	else {
		cout << "no entra porque coloco una posicion fuera del rango establecido..." << endl;
	}
 
}

void Matriz_dispersa::llenar_al_maximo() {
	for (int i = 0; i < this->maximo; i++)
	{
		for (int j = 0; j < this->maximo; j++)
		{
			this->add('A', i, j);
		}
	}
}
void Matriz_dispersa::llenar_al_maximo(int max) {
	for (int i = 0; i < max; i++)
	{
		for (int j = 0; j < max; j++)
		{
			this->add('A', i, j);
		}
	}
}



bool validarPalabra(ListaCasillas casillasVisitadas, ListaDobleCircular diccionario , string dir) {
	// tengo que buscar y cocatenar  el camino de recorrido de las letras 

	return false;
}


void Matriz_dispersa::getGraphviz() {
	IO_Archivos * llama = new  IO_Archivos();
	llama->grafica_MATRIX(this->root);
}


Matriz_dispersa* Matriz_dispersa:: clonar(Matriz_dispersa* clon) {
	clon->setCasiTodo(this->lista_casillas, this->centro, this->maximo ,this->centrolleno);
	nMatrix* aux = root;
	nMatrix* aux2 = NULL;
	while (aux != NULL) {
		if (aux->getDer() != NULL)
		{
			aux2 = aux->getDer();
			while (aux2 != NULL)
			{
				if (aux2->getPos_y() != -1) {// si mi pos en x es negativa en y si voy a tener 
					clon->add(aux2->getLetra(), aux2->getPos_x() , aux->getPos_y());
					
				}
				aux2 = aux2->getDer();
			}
		}
		aux = aux->getDown();
	}
	
	return clon;
}