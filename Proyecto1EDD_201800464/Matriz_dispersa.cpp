#include "Matriz_dispersa.h"
#include<string>
#include"nMatrix.h"
#include"IO_Archivos.h"
#include"Jugador.h"
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
nMatrix* Matriz_dispersa::BuscarNodo(int x, int y) {
	nMatrix* col_principal = this->root;
	nMatrix* aux = NULL;
		while (col_principal != NULL) {

			if (col_principal->getDer() != NULL) {

				while (aux != NULL) {
					if (aux->getPos_x() == x && aux->getPos_y() == y) {
						return aux;
					}
					aux = aux->getDer();
				}
			}
			col_principal = col_principal->getDown();
		}
		return NULL;
}
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






void Matriz_dispersa::getGraphviz() {
	IO_Archivos * llama = new  IO_Archivos();
	llama->grafica_MATRIX(this->root);
}


Matriz_dispersa* Matriz_dispersa:: clonar(Matriz_dispersa* clon) {

	clon->getRoot()->setDerecha(NULL);
	clon->getRoot()->setAbajo(NULL);
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



void Matriz_dispersa::add_ilusion(char letra, int x, int y) {

	if (x < this->maximo && y < this->maximo) {

		nMatrix* nuevo_nodo = new nMatrix(x, y, letra);
		nuevo_nodo->setIs_nueva(true);
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

// como usar la libreria VECTOR 
// para agregar push_back (  );
/*
para recorrer es de la siguiente manera 
for(const auto nombreo_bjeto : nombre_vector){ // la palabra auto deduce el tipo  , no es necesario el const 

}

for(int i ; i < nombreVector.size() ; i++){
}

// suponiendo un vector llamado vect
for(std::vector<int>::iterator it = vect.begin();  it != vect.end() ; ++it ){
cout<<*it<<endl; // porque el iterator no es una posicion es un apuntador   
}

for(auto it = vect.begin();  it != vect.end() ; ++it ){
cout<<*it<<endl; // porque el iterator no es una posicion es un apuntador
}

// EL MAS SIMPLE 

for(tipo_elemento nombre_elemento : nombre_vector){

}
*/

void Matriz_dispersa :: extraerCasillasNuevas(ListaCasillas* lista_casillas_nuevas) {
	nodoT* aux = lista_casillas_nuevas->getInicio();
	while (aux != NULL) {
		nMatrix* temporal = this->BuscarNodo(aux->casilla->posX , aux->casilla->posY);
		if (temporal != NULL) { // tons lo metemos al vector 
			this->vector_de_nodos.push_back(temporal);
		}
		aux = aux->sig;
	}
	this->imprimirVector();
}
void Matriz_dispersa::extraerCasillasNuevas() {
	nMatrix* col_principal = this->root;
	nMatrix* aux = NULL;
	while (col_principal != NULL) {

		if (col_principal->getDer() != NULL) {
			aux = col_principal->getDer();
			while (aux != NULL) {

				if (aux->getIs_nueva() == true) {
					this->vector_de_nodos.push_back(aux);
				}
				aux = aux->getDer();
			}
		}
		col_principal = col_principal->getDown();
	}
}
void  Matriz_dispersa::imprimirVector() {
	cout << " °°°°°°°°°°°°°°°°°°°°°°°°°° ESTOS NODOS TIENE MI VECTOR :O  °°°°°°°°°°°°°°°°°°°°°°°°°°" << endl; 
	for (nMatrix* n : this->vector_de_nodos) {
		cout << "LETRA: "<<n->getLetra() << " X: "<<n->getPos_x() <<" Y: "<< n->getPos_y() <<" es nueva: "<<n->getIs_nueva() <<endl;
	}
	cout << " °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
	system("pause");
}

bool Matriz_dispersa:: validarPalabra(ListaDobleCircular* diccionario,  bool primerPalabra , int & puntosParaJugador){
	// si encuentra al menos una palabra valida tiene que retornar que el metodo es valido
	// primero tengo que ver si tiene fichas adyacentes 
	// la unica forma donde no me interes si hay adyacencia es cuando el centro esta lleno 
	if (primerPalabra == false) { // en la primera vez manda false , despues simpre es true
		// como no hay adyacencia solo valido que forme una palabra correcta 
		string palabraFormada = "";
		int puntos_generados = 0;
		for(nMatrix* nodo : this->vector_de_nodos) {
			palabraFormada += nodo->getLetra();
			int valor = this->getValor_ficha(nodo->getLetra(),this->lista_casillas.Get_valor_casilla(nodo->getPos_x(), nodo->getPos_y()));
			puntos_generados += valor;
		}
		cout <<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
		cout << "PALABRA INGRESADA: "<<palabraFormada<<endl;
		cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
		bool valida =  diccionario->aparece_en_diccionario(palabraFormada);
		if (valida) {
			cout << "si se acepta" << endl;
			// paso a darle su respectivo valor  
			puntosParaJugador = puntos_generados;
			cout << "=====================================\n";
			cout << "PUNTOS GENERADOS: "<<puntos_generados<<endl;
			cout << "por ser la primer palabra recibes +50pts EXTRA" << endl;
			cout << "=====================================\n";
			puntosParaJugador += 50;
			return true;
		}
		else {
			cout << "LO SIENTO NO ES PALABRA VALIDA... PASA DE TURNO" << endl;
		}

	}
	else {
		// TENGO QUE VALIDAR QUE SEA ADYACENTE A LAS FICHAS VIEJAS , LUEGO QUE PALABRA FORMA , LUEGO SUMA DE PUNTOS 
		if (this->es_palabra_adyacente()) {
			// siempre la primera posicion de mi vector es la primera posicion de una posible palabra 
			// NOTA: SI LA PRIMERA LETRA NO TIENE ADYACENCIA  con ninguna palabra vieja 
			// ver si es horizontal o vertical o solo 1 letra 
			// ver si formo una palabra coherente mi primera palabra tiene adyacencia ?  
			// ver si hay intersecciones 
			if (this->vector_de_nodos.size() > 1) {
				
				// vertical o horizontal ? 
				if (this->vector_de_nodos[0]->getPos_x() == this->vector_de_nodos[this->vector_de_nodos.size()-1]->getPos_x() ) {
				//es vertical
					puntosParaJugador = 0; // lo limpio 
					if (this->hay_adyacencia_up(this->vector_de_nodos[0]) == false) { // concateno hasta encontrar mi ultimo nodo
						cout << " VERTICAL SIMPLE " << endl;
						string p_vertical = "";
						nMatrix* nodoRecorredor = this->vector_de_nodos[0];
						int puntos_temporales = 0; 
						int contador_verificador = 0;
						bool VALIDA = false;
						
						while (this->puedoBajar(nodoRecorredor)) {
							contador_verificador += esta_en_vector_nodos(nodoRecorredor->getPos_x() , nodoRecorredor->getPos_y());
							p_vertical += nodoRecorredor->getLetra();
							int valor = this->getValor_ficha(nodoRecorredor->getLetra(), this->lista_casillas.Get_valor_casilla(nodoRecorredor->getPos_x(), nodoRecorredor->getPos_y()));
							puntos_temporales += valor;
							bool valida = diccionario->aparece_en_diccionario(p_vertical);
							//cout << "------------------------------------" << endl;
							//cout << "palabra:  " << p_vertical << endl;
							//cout << "------------------------------------" << endl;
							if (valida) {
								if (contador_verificador == this->vector_de_nodos.size()) {
									/*cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
									cout << "PALABRA ADENTRO DE VALIDA:  " << p_vertical << endl;
									cout << "cont " << contador_verificador << " = " << this->vector_de_nodos.size() << endl;
									cout << "si se acepta" << endl;
									cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
									puntosParaJugador = puntos_temporales;*/
									cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
									cout << "COMPARA  ref: " << puntosParaJugador << " temp :" << puntos_temporales << endl;
									cout << "PALABRA ADENTRO DE VALIDA:  " << p_vertical << endl;
									cout << "cont " << contador_verificador << " = " << this->vector_de_nodos.size() << endl;
									cout << "si se acepta" << endl;
									cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
									if (puntosParaJugador < puntos_temporales) {
										puntosParaJugador = puntos_temporales;
										cout << "PUNTAJE DE LA PALABRA: " << puntos_temporales << endl;
									}

									VALIDA = true;
									 
								}
							}
							nodoRecorredor = nodoRecorredor->getDown();
						}

						contador_verificador += esta_en_vector_nodos(nodoRecorredor->getPos_x(), nodoRecorredor->getPos_y());
						p_vertical += nodoRecorredor->getLetra();
						int valor = this->getValor_ficha(nodoRecorredor->getLetra(), this->lista_casillas.Get_valor_casilla(nodoRecorredor->getPos_x(), nodoRecorredor->getPos_y()));
						puntos_temporales += valor;
						bool valida2 = diccionario->aparece_en_diccionario(p_vertical);
						/*cout << "------------------------------------" << endl;
						cout << "palabra:  " << p_vertical << endl;
						cout << "------------------------------------" << endl;*/
						if (valida2) {

							if (contador_verificador == this->vector_de_nodos.size()) {
								cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
								cout << "COMPARA  ref: " << puntosParaJugador << " temp :" << puntos_temporales << endl;
								cout << "PALABRA ADENTRO DE VALIDA:  " << p_vertical << endl;
								cout << "cont " << contador_verificador << " = " << this->vector_de_nodos.size() << endl;
								cout << "si se acepta" << endl;
								cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
								if (puntosParaJugador < puntos_temporales) {
									puntosParaJugador = puntos_temporales;
									cout << "PUNTAJE DE LA PALABRA: " << puntos_temporales << endl;
								}
								VALIDA = true;

							}
						}



						if (VALIDA) {
							// tengo que guardar lo que tiene puntos para Jugador 
							
							int guarda = puntosParaJugador;
							cout << "puntos Guardados "<<guarda << endl;
							this->acumulaPuntosInterseccionesHORIZONTALES(diccionario, puntosParaJugador);
							cout << puntosParaJugador << "+" << guarda << endl;
							puntosParaJugador += guarda;
							cout << "===========================================================================\n";
							cout << "TOTAL DE PUNTOS GENERADOS: " << puntosParaJugador << endl;
							cout << "===========================================================================\n";
							return true; // podria levantar una bandera y guardar estos datos
							// busco intersecciones 



						}
						cout << "NO SE ACEPTA" << endl;
						return false;
					
						// FALTA INTERSECCIONES 



					}
					else {
						// PREGUNTAR QUE PALABRA DESEABA FORMAR 
						cout << "VERTICAL NO simple" << endl;
						nMatrix* nodoSubidor = this->vector_de_nodos[0];
						puntosParaJugador = 0; // lo limpio 
						while (this->puedoSubir(nodoSubidor)) {
							nodoSubidor = nodoSubidor->getUp();
						}// nodoSubidor es el NODO MAS ALTO POSIBLE el punto fijo de partida 
						//cout << "NODO MAS ALTO" << nodoSubidor->getLetra()<< endl;

						nMatrix* puntoFijo = new nMatrix();
						puntoFijo = nodoSubidor;
						int cont_verificador_2 = 0;
						bool VALIDA = false;
						while (this->puedoBajar(puntoFijo)) {
							//cout << "down..."<< puntoFijo->getLetra() <<" ("<<puntoFijo->getPos_x()<<","<< puntoFijo->getPos_y()<<")"<< endl;
							
							cont_verificador_2 = 0;
							cont_verificador_2 += esta_en_vector_nodos(puntoFijo->getPos_x(), puntoFijo->getPos_y());
							//cout <<"cont: "<<cont_verificador_2 << endl;
							string temp = "";
							int punteo_temp1 = 0;
							nMatrix* aux = puntoFijo->getDown();
							// primera interacion 
							temp += puntoFijo->getLetra();
							punteo_temp1 += this->getValor_ficha(puntoFijo->getLetra(), this->lista_casillas.Get_valor_casilla(puntoFijo->getPos_x(), puntoFijo->getPos_y()));
							while (this->puedoBajar(aux)) {
								
								cont_verificador_2 += esta_en_vector_nodos(aux->getPos_x(), aux->getPos_y());
								//cout << "contw: " << cont_verificador_2 << endl;
								temp += aux->getLetra();
								punteo_temp1 += this->getValor_ficha(aux->getLetra(), this->lista_casillas.Get_valor_casilla(aux->getPos_x(), aux->getPos_y()));
								// pregunto 
								/*cout << "----------------------------------" << endl;
								cout << "palabra:  " << temp << endl;
								cout << "CONT: " << cont_verificador_2 << endl;
								cout << "----------------------------------" << endl;*/
								bool valida = diccionario->aparece_en_diccionario(temp);
								if (valida) {

									if (cont_verificador_2 == this->vector_de_nodos.size()) { 
										
										
										cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
										cout << " SI VALIDA , PALABRA:  " << temp << endl;
										cout << "COMPARA  ref: " << puntosParaJugador << " temp :" << punteo_temp1 << endl;
										//cout << "cont " << cont_verificador_2 << " = " << this->vector_de_nodos.size() << endl;
										cout << "si se acepta" << endl;
										cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
										if (puntosParaJugador < punteo_temp1) {
											puntosParaJugador = punteo_temp1;
											cout << "PUNTAJE DE LA PALABRA: " << punteo_temp1 << endl;
										}

										VALIDA = true;
										 // podria levantar una bandera y guardar estos datos 
									}
								}
								aux = aux->getDown();
								//cout << endl;
							}
							//cout << "------- ULTIMA INTERACION------------" << endl;
							cont_verificador_2 += esta_en_vector_nodos(aux->getPos_x(), aux->getPos_y());
							temp += aux->getLetra();
							punteo_temp1 += this->getValor_ficha(aux->getLetra(), this->lista_casillas.Get_valor_casilla(aux->getPos_x(), aux->getPos_y()));
							// pregunto 
							/*cout << "------------------------------------" << endl;
							cout << "palabra:  " << temp << endl;
							cout << "afuera CONT: "<<cont_verificador_2  << endl;
							cout << "------------------------------------" << endl;*/
							bool valida = diccionario->aparece_en_diccionario(temp);
							if (valida) {

								if (cont_verificador_2 == this->vector_de_nodos.size()) {
									cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
									cout << " SI VALIDA , PALABRA:  " << temp << endl;
									cout << "COMPARA  ref: " << puntosParaJugador << " temp :" << punteo_temp1 << endl;
									if (puntosParaJugador < punteo_temp1) {
										puntosParaJugador = punteo_temp1;
										cout << "PUNTAJE DE LA PALABRA: " << punteo_temp1 << endl;
									}
									/*cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
									cout << "PALABRA:  " << temp << endl;
									cout << "cont " << cont_verificador_2 << " = " << this->vector_de_nodos.size() << endl;
									cout << "si se acepta" << endl;
									cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
									puntosParaJugador = punteo_temp1;*/

									VALIDA = true;
									// podria levantar una bandera y guardar estos datos 
								}
							}
							//----------------
							puntoFijo = puntoFijo->getDown();
						}





						if (VALIDA) {
							int guarda = puntosParaJugador;
							cout << "puntos Guardados " << guarda << endl;
							this->acumulaPuntosInterseccionesHORIZONTALES(diccionario, puntosParaJugador);
							cout << puntosParaJugador << "+" << guarda << endl;
							puntosParaJugador += guarda;
							cout << "=================\n";
							cout << "PUNTOS GENERADOS: " << puntosParaJugador << endl;
							cout << "=================\n";
							return true;
						}
						

						cout << "No se acepta"<<endl;
						return false;

					} // fin caso 
				}else if (this->vector_de_nodos[0]->getPos_y() == this->vector_de_nodos[this->vector_de_nodos.size() - 1]->getPos_y()) {
					//---------------------------------------horizontal

					if (this->hay_adyacencia_izq(this->vector_de_nodos[0]) == false) {
						cout << " HORIZONTAL simple" << endl;
						string p_horizontal = "";
						nMatrix* nodoRecorredor = this->vector_de_nodos[0];
						puntosParaJugador = 0; // lo limpio 
						int contador_verificador = 0; 
						int puntos_temporales = 0;
						bool VALIDA = false;
						while (this->puedoDer(nodoRecorredor)) {
							contador_verificador += esta_en_vector_nodos(nodoRecorredor->getPos_x(), nodoRecorredor->getPos_y());
							p_horizontal += nodoRecorredor->getLetra(); 
							int valor = this->getValor_ficha(nodoRecorredor->getLetra(), this->lista_casillas.Get_valor_casilla(nodoRecorredor->getPos_x(), nodoRecorredor->getPos_y()));
							puntos_temporales += valor;
							bool valida = diccionario->aparece_en_diccionario(p_horizontal);
							/*cout << "------------------------------------" << endl;
							cout << "palabra:  " << p_horizontal << endl;
							cout << "------------------------------------" << endl;*/
							if (valida) {
								
								if (contador_verificador == this->vector_de_nodos.size()) {

									cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
									cout << "COMPARA  ref: " << puntosParaJugador << " temp :" << puntos_temporales << endl;
									cout << "PALABRA ADENTRO DE VALIDA:  " << p_horizontal << endl;
									if (puntosParaJugador < puntos_temporales) {
										puntosParaJugador = puntos_temporales;
										cout << "PUNTAJE DE LA PALABRA: " << puntos_temporales << endl;
									}
									cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
								/*	cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
									cout << "PALABRA ADENTRO DE VALIDA:  " << p_horizontal << endl;
									cout << "cont " << contador_verificador << " = " << this->vector_de_nodos.size() << endl;
									cout << "si se acepta" << endl;
									cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
									puntosParaJugador = puntos_temporales;*/
									VALIDA = true;

								}
							}
							nodoRecorredor = nodoRecorredor->getDer();
						}
						contador_verificador += esta_en_vector_nodos(nodoRecorredor->getPos_x(), nodoRecorredor->getPos_y());
						p_horizontal += nodoRecorredor->getLetra();
						int valor = this->getValor_ficha(nodoRecorredor->getLetra(), this->lista_casillas.Get_valor_casilla(nodoRecorredor->getPos_x(), nodoRecorredor->getPos_y()));
						puntos_temporales += valor;
						bool valida2 = diccionario->aparece_en_diccionario(p_horizontal);
						/*cout << "extra-------------------------------" << endl;
						cout << "palabra:  " << p_horizontal << endl;
						cout << "extra----------------------------------" << endl;*/
						if (valida2) {
						
							if (contador_verificador == this->vector_de_nodos.size()) {
								cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
								cout << "COMPARA  ref: " << puntosParaJugador << " temp :" << puntos_temporales << endl;
								if (puntosParaJugador < puntos_temporales) {
									puntosParaJugador = puntos_temporales;
									cout << "PUNTAJE DE LA PALABRA: " << puntos_temporales << endl;
								}
								cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
							/*	cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
								cout << "PALABRA ADENTRO DE VALIDA:  " << p_horizontal << endl;
								cout << "cont " << contador_verificador << " = " << this->vector_de_nodos.size() << endl;
								cout << "si se acepta" << endl;
								cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
								puntosParaJugador = puntos_temporales;*/
								VALIDA = true;

							}
						}




						if (VALIDA) {
							int guarda = puntosParaJugador;
							cout << "puntos Guardados " << guarda << endl;
							this->acumulaPuntosInterseccionesVERTICALES(diccionario, puntosParaJugador);
							cout << puntosParaJugador << "+" << guarda << endl;
							puntosParaJugador += guarda;
							cout << "================================================================================\n";
							cout << "PUNTOS GENERADOS: " << puntosParaJugador << endl;
							cout << "================================================================================\n";
							return true; // podria levantar una bandera y guardar estos datos
						}
						cout << "NO SE ACEPTA" << endl;
						return false;
						



					}
					else {
						cout << " HORIZONTAL NO simple" << endl;
						nMatrix* nodo_masIzq = this->vector_de_nodos[0];
						puntosParaJugador = 0; // lo limpio 
						while (this->puedoIzq(nodo_masIzq)) {

							nodo_masIzq = nodo_masIzq->getIzq();
						}// nodoSubidor es el NODO MAS IZQUIERDO POSIBLE el punto fijo de partida
						//cout << "MAS IZQUIERDO " << nodo_masIzq->getLetra()<<endl;

						nMatrix* puntoFijo = new nMatrix();
						puntoFijo = nodo_masIzq;
						int cont_verificador_2 = 0;
						bool VALIDA = false;
						while (this->puedoDer(puntoFijo)) {
						//	cout << "DER-->>>" << puntoFijo->getLetra() << " (" << puntoFijo->getPos_x() << "," << puntoFijo->getPos_y() << ")" << endl;

							cont_verificador_2 = 0;
							cont_verificador_2 += esta_en_vector_nodos(puntoFijo->getPos_x(), puntoFijo->getPos_y());
						//	cout << "cont: " << cont_verificador_2 << endl;
							string temp = "";
							int punteo_temp1 = 0;
							nMatrix* aux = puntoFijo->getDer();
							// primera interacion 
							temp += puntoFijo->getLetra();
							punteo_temp1 += this->getValor_ficha(puntoFijo->getLetra(), this->lista_casillas.Get_valor_casilla(puntoFijo->getPos_x(), puntoFijo->getPos_y()));
							while (this->puedoDer(aux)) {

								cont_verificador_2 += esta_en_vector_nodos(aux->getPos_x(), aux->getPos_y());
								//cout << "contw: " << cont_verificador_2 << endl;
								temp += aux->getLetra();
								punteo_temp1 += this->getValor_ficha(aux->getLetra(), this->lista_casillas.Get_valor_casilla(aux->getPos_x(), aux->getPos_y()));
								// pregunto 
								/*cout << "----------------------------------" << endl;
								cout << "palabra:  " << temp << endl;
								cout << "CONT: " << cont_verificador_2 << endl;
								cout << "----------------------------------" << endl;*/
								bool valida = diccionario->aparece_en_diccionario(temp);
								if (valida) {
									
									if (cont_verificador_2 == this->vector_de_nodos.size()) {
										cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
										cout << "COMPARA  ref: " << puntosParaJugador << " temp :" << punteo_temp1 << endl;
										if (puntosParaJugador < punteo_temp1) {
											puntosParaJugador = punteo_temp1;
											cout << "PUNTAJE DE LA PALABRA: " << punteo_temp1 << endl;
										}
										cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
										//cout << " SI VALIDA , PALABRA:  " << temp << endl;
										//cout << "cont " << cont_verificador_2 << " = " << this->vector_de_nodos.size() << endl;
										//cout << "si se acepta" << endl;
										VALIDA = true;
										// podria levantar una bandera y guardar estos datos 
									}
								}
								aux = aux->getDer();
								cout << endl;
							}
							cout << "------- ULTIMA INTERACION------------" << endl;
							cont_verificador_2 += esta_en_vector_nodos(aux->getPos_x(), aux->getPos_y());

							temp += aux->getLetra();
							punteo_temp1 += this->getValor_ficha(aux->getLetra(), this->lista_casillas.Get_valor_casilla(aux->getPos_x(), aux->getPos_y()));
							// pregunto 
							/*cout << "------------------------------------" << endl;
							cout << "palabra:  " << temp << endl;
							cout << "afuera CONT: " << cont_verificador_2 << endl;
							cout << "------------------------------------" << endl;*/
							bool valida = diccionario->aparece_en_diccionario(temp);
							if (valida) {
								
								if (cont_verificador_2 == this->vector_de_nodos.size()) {
									cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
									cout << "COMPARA  ref: " << puntosParaJugador << " temp :" << punteo_temp1 << endl;
									if (puntosParaJugador < punteo_temp1) {
										puntosParaJugador = punteo_temp1;
										cout << "PUNTAJE DE LA PALABRA: " << punteo_temp1 << endl;
									}
									//cout << "PALABRA:  " << temp << endl;
									//cout << "cont " << cont_verificador_2 << " = " << this->vector_de_nodos.size() << endl;
									//cout << "si se acepta" << endl;
									cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;

									VALIDA = true;
									// podria levantar una bandera y guardar estos datos 
								}
							}
							//----------------
							puntoFijo = puntoFijo->getDer();
						}


						if (VALIDA) {
							int guarda = puntosParaJugador;
							cout << "puntos Guardados " << guarda << endl;
							this->acumulaPuntosInterseccionesVERTICALES(diccionario, puntosParaJugador);
							cout << puntosParaJugador << "+" << guarda << endl;
							puntosParaJugador += guarda;
							cout << "===============================================================================\n";
							cout << "TOTAL PUNTOS GENERADOS: " << puntosParaJugador << endl;
							cout << "================================================================================\n";
							return true;
						}


						cout << "No se acepta" << endl;
						return false;
					
					}
				}
				else {
					// invalida

					cout << " ERROR: LA PALABRA NO ESTA EN UN MISMO REGLON ";
				}
			


			

			}
			else {
				// solo 1 letra 
				cout << "SOLO COLOCO UNA LETRA " << endl;
				this->acumulaPuntosInterseccionesVERTICALES(diccionario, puntosParaJugador);
				int guarda1 = puntosParaJugador;
				
				this->acumulaPuntosInterseccionesHORIZONTALES(diccionario, puntosParaJugador);
				cout << puntosParaJugador << "+" << guarda1;
				puntosParaJugador += guarda1;
				cout <<" = "<<puntosParaJugador << endl;
				

				if (puntosParaJugador != 0 ) {
					cout << "===============================================================================\n";
					cout << "TOTAL PUNTOS GENERADOS: " << puntosParaJugador << endl;
					cout << "================================================================================\n";
					return true;
				}
				else {
					cout << "PUNTOS PARA JUGAR-FIN " << puntosParaJugador << endl;
					cout << "No formo ninguna palabra" << endl;
					return false;
				}
				









			}

		}
		else {
			cout << "PALABRA INVALIDA POR FALTA DE ADYACENCIA" << endl;
		}


	}
	return false;
}






int Matriz_dispersa::esta_en_vector_nodos(int x, int y) {
	int suma = 0; 
	for (nMatrix* n : this->vector_de_nodos) {
		//cout << n->getLetra() << " (" << n->getPos_x() << "," << n->getPos_y() << ") COMPARA externo "<<"("<<x<<","<<y<<")"<< endl;
		if (n->getPos_x() == x && n->getPos_y() == y) {
			//cout << "MATCH" << endl;
			return suma +1;
		}
	}
	return suma;
}





















bool Matriz_dispersa:: es_palabra_adyacente() { // busco por lo menos 1 adyacencia 

	for (nMatrix* n : this->vector_de_nodos) {
		//cout << "---REVISANDO EL NODO----"<< n->getLetra() << endl;
		if (n->getDer() != NULL) {
			//cout << " CASO DERECHA " << n->getDer()->getPos_x() << " - " << n->getPos_x() << " = " << (n->getDer()->getPos_x() - n->getPos_x())<<endl;
			if ((n->getDer()->getPos_x() - n->getPos_x()) == 1 && n->getDer()->getIs_nueva() == false && n->getDer()->getLetra() != '2' && n->getDer()->getLetra() != '3') { // 3 -2 = 1 
			//cout << " ADYACENTE  "<<n->getLetra()<<" TIENE A LA DERECHA A "<< n->getDer()->getLetra()<<endl;// a la derecha nunca podria tener una cab
			return true; 
			}
		}
		if (n->getIzq() != NULL) {
			//cout << " CASO IZQ "<<n->getIzq()->getPos_x() << " - " << n->getPos_x()<<  " = "<< (n->getIzq()->getPos_x() - n->getPos_x())<<endl;
			if ((n->getIzq()->getPos_x() - n->getPos_x()) == -1 && n->getIzq()->getIs_nueva() == false  && n->getIzq()->getPos_x() != -1 && n->getIzq()->getLetra() != '2' && n->getIzq()->getLetra() != '3') {
				//cout << " ADYACENTE  " << n->getLetra() << " TIENE A LA IZQUIERDA " << n->getIzq()->getLetra()<<endl;
				return true;
			}
		}
		 if (n->getDown() != NULL){
		//	cout << " CASO ABAJO " << n->getDown()->getPos_y() << " - " << n->getPos_y() <<" = "<< (n->getDown()->getPos_y() - n->getPos_y()) << endl;
			if ((n->getDown()->getPos_y() - n->getPos_y()) == 1 && n->getDown()->getIs_nueva() == false && n->getDown()->getLetra() != '2' && n->getDown()->getLetra() != '3') {
				//cout << "ADYACENTE  " << n->getLetra() << "  TIENE ABAJO A  " << n->getDown()->getLetra()<<endl;
				return true;
			}
		}
		 if (n->getUp() != NULL) {
			//cout << " CASO ARRIBA "<< n->getUp()->getPos_y()<< " - "<< n->getPos_y()<< " = " << (n->getUp()->getPos_y() - n->getPos_y())<<endl;
			if ((n->getUp()->getPos_y() - n->getPos_y()) == -1 && n->getUp()->getIs_nueva() == false && n->getUp()->getPos_y() != -1 && n->getUp()->getLetra() != '2' && n->getUp()->getLetra() != '3') {
				//cout << "ADYACENTE  " << n->getLetra() << " TIENE ARRIBA A  " << n->getUp()->getLetra()<<endl;
				return true;
			}
		}
		//cout << "----------" << endl;
		// tener en cuenta que la adyacencia con las cabeceras y columnas no valen  , las pos negativas las descartan 
	}
	return false; // si ninguno de los nodos nuevos tiene adyacencia con los viejo esta palabra es invalida 
}

//---------------- ESTOS NO CUENTAN PALABRAS NUEVAS SOLO ES PARA VERIFICAR LA ADYACENCIA 

bool Matriz_dispersa::hay_adyacencia_up(nMatrix* n) {
	if (n->getUp() != NULL) {
		
		if ((n->getUp()->getPos_y() - n->getPos_y()) == -1 && n->getUp()->getIs_nueva() == false && n->getUp()->getPos_y() != -1 && n->getUp()->getLetra() != '2' && n->getUp()->getLetra() != '3') {
			
			return true;
		}
	}
	return false;
}
bool Matriz_dispersa::hay_adyacencia_down(nMatrix* n) {
	if (n->getDown() != NULL) {
		if ((n->getDown()->getPos_y() - n->getPos_y()) == 1 && n->getDown()->getIs_nueva() == false && n->getDown()->getLetra() != '2' && n->getDown()->getLetra() != '3') {
			return true;
		}
	}
	return false;
}
bool Matriz_dispersa::hay_adyacencia_der(nMatrix* n) {
	if (n->getDer() != NULL) {
		if ((n->getDer()->getPos_x() - n->getPos_x()) == 1 && n->getDer()->getIs_nueva() == false && n->getDer()->getLetra() != '2' && n->getDer()->getLetra() != '3') { // 3 -2 = 1 
			return true; 
		}
	}
	
		return false;

}
bool Matriz_dispersa::hay_adyacencia_izq(nMatrix* n) {
	if (n->getIzq() != NULL) {
		if ((n->getIzq()->getPos_x() - n->getPos_x()) == -1 && n->getIzq()->getIs_nueva() == false && n->getIzq()->getPos_x() != -1 && n->getDer()->getLetra() != '2' && n->getDer()->getLetra() != '3') {
			return true;
		}
	}
		return false;
}

//-------------------------------------- incluye casillas nueva s

bool Matriz_dispersa::puedoBajar(nMatrix* n) {
	if (n->getDown() != NULL) {
		if ((n->getDown()->getPos_y() - n->getPos_y()) == 1 && n->getDown()->getLetra() != '2' && n->getDown()->getLetra() != '3') {
			return true;
		}
	}
	return false;
}
bool Matriz_dispersa::puedoSubir(nMatrix* n) {
	if (n->getUp() != NULL) {

		if ((n->getUp()->getPos_y() - n->getPos_y()) == -1  && n->getUp()->getPos_y() != -1 && n->getUp()->getLetra() != '2' && n->getUp()->getLetra() != '3') {

			return true;
		}
	}
	return false;
}
bool Matriz_dispersa::puedoIzq(nMatrix* n) {
	if (n->getIzq() != NULL) {
		if ((n->getIzq()->getPos_x() - n->getPos_x()) == -1 && n->getIzq()->getPos_x() != -1 && n->getIzq()->getLetra() != '2' && n->getIzq()->getLetra() != '3') {
			return true;
		}
	}
	return false;
}
bool Matriz_dispersa::puedoDer(nMatrix* n) {
	if (n->getDer() != NULL) {

		if ((n->getDer()->getPos_x() - n->getPos_x()) == 1 && n->getDer()->getLetra() != '2' && n->getDer()->getLetra() != '3') { // 3 -2 = 1 
			return true;
		}
	}

	return false;
}







bool Matriz_dispersa::hay_adyacencia_paraNodoPrimero(nMatrix* n) { // tambien quitar es aonda de espciales 
	//cout << "REVISANDO  EL PRIMER NODO DE MI PALABRA" << endl;
	if (n->getDer() != NULL) {
		if ((n->getDer()->getPos_x() - n->getPos_x()) == 1 && n->getDer()->getIs_nueva() == false) { // 3 -2 = 1 
			//cout << " ADYACENTE  " << n->getLetra() << " TIENE A LA DERECHA A " << n->getDer()->getLetra() << endl;// a la derecha nunca podria tener una cab
			return true;
		}
	}
	if (n->getIzq() != NULL) {
		if ((n->getIzq()->getPos_x() - n->getPos_x()) == -1 && n->getIzq()->getIs_nueva() == false && n->getIzq()->getPos_x() != -1) {
			//cout << " ADYACENTE  " << n->getLetra() << " TIENE A LA IZQUIERDA " << n->getIzq()->getLetra() << endl;
			return true;
		}
	}
	if (n->getDown() != NULL) {
		//cout << " CASO ABAJO " << n->getDown()->getPos_y() << " - " << n->getPos_y() << " = " << (n->getDown()->getPos_y() - n->getPos_y()) << endl;
		if ((n->getDown()->getPos_y() - n->getPos_y()) == 1 && n->getDown()->getIs_nueva() == false) {
			//cout << "ADYACENTE  " << n->getLetra() << "  TIENE ABAJO A  " << n->getDown()->getLetra() << endl;
			return true;
		}
	}
	if (n->getUp() != NULL) {
		if ((n->getUp()->getPos_y() - n->getPos_y()) == -1 && n->getUp()->getIs_nueva() == false && n->getUp()->getPos_y() != -1) {
		//	cout << "ADYACENTE  " << n->getLetra() << " TIENE ARRIBA A  " << n->getUp()->getLetra() << endl;
			return true;
		}
	}
	return false;
}


bool Matriz_dispersa:: el_centro_esta_lleno() {

	nMatrix* col_principal = this->root;
	nMatrix* aux = NULL;
	if (this->centrolleno == false) {
		while (col_principal != NULL) {
			if (col_principal->getDer() != NULL) {
				aux = col_principal->getDer();
				while (aux != NULL) {
					if (aux->getPos_x() == this->centro && aux->getPos_y() == this->centro) {
						this->centrolleno = true;
						return true;
					}
					aux = aux->getDer();
				}
			}
			col_principal = col_principal->getDown();
		}
	}
	else {
		return true;
	}
}





int Matriz_dispersa::getValor_ficha(char letra , int n) {



	if (letra == 'a' || letra =='e' || letra == 'o' || letra == 'i' || letra == 's' || letra == 'n' || letra =='r'|| letra == 'u' || letra == 't') {
		return 1 *n;
	}
	if (letra == 'd' || letra == 'g') {
		return 2*n;
	}
	else if (letra == 'c' || letra == 'b' || letra == 'm' || letra == 'p') {
		return 3*n;
	}
	else if (letra == 'h' || letra == 'f' || letra == 'v' || letra == 'y') {
		return 4*n;
	}
	else if (letra == 'q') {
		return 5*n;
	}
	else if (letra == 'z') {
		return 10*n;
	}
	else if (letra == 'j' || letra == 'x') {
		return 8*n;
	}
	else {
		return 1*n;
	}
}

	void Matriz_dispersa:: SET_NUEVA(int x, int y) {
		nMatrix* col_principal = this->root;
		nMatrix* aux = NULL;

			while (col_principal != NULL) {

				if (col_principal->getDer() != NULL) {
					aux = col_principal->getDer();
					while (aux != NULL) {
						if (aux->getPos_x() == x && aux->getPos_y() == y) {
							
							Casilla * encuentra = this->lista_casillas.buscar(x,y);
							if (encuentra != NULL) {
								aux->setIs_nueva(true);
								cout << "                                                 ||||||||||||||||||||||||" << endl;
								cout << "                                                 BIEN ES CASILLA ESPECIAL " << endl;
								cout << "                                                 |||||||||||||||||||||||| " << endl;
							}
							else {
								
							}
						}
						aux = aux->getDer();
					}
				}

				col_principal = col_principal->getDown();
			}
	}









	void  Matriz_dispersa:: acumulaPuntosInterseccionesHORIZONTALES(ListaDobleCircular* diccionario, int& puntosParaJugador) {
		int acumulador = 0; 
		cout << "--- BUSCANDO INTERSECCIONES  HORIZONTALES " << endl;

		for (nMatrix* nodo_masIzq : this->vector_de_nodos) {
			puntosParaJugador = 0; // lo limpio 
			while (this->puedoIzq(nodo_masIzq)) {
				nodo_masIzq = nodo_masIzq->getIzq();
			}
			cout << "NODO MAS A LA IZQUIERDA           " << nodo_masIzq->getLetra()<<endl;
			nMatrix* puntoFijo = new nMatrix();
			puntoFijo = nodo_masIzq;
			int cont_verificador_2 = 0;
			bool VALIDA = false;
			while (this->puedoDer(puntoFijo)) {
				//cout << "DER-->>>" << puntoFijo->getLetra() << " (" << puntoFijo->getPos_x() << "," << puntoFijo->getPos_y() << ")" << endl;

				cont_verificador_2 = 0;
				cont_verificador_2 += esta_en_vector_nodos(puntoFijo->getPos_x(), puntoFijo->getPos_y());
				//cout << "cont: " << cont_verificador_2 << endl;
				string temp = "";
				int punteo_temp1 = 0;
				nMatrix* aux = puntoFijo->getDer();
				// primera interacion
				temp += puntoFijo->getLetra();
				punteo_temp1 += this->getValor_ficha(puntoFijo->getLetra(), this->lista_casillas.Get_valor_casilla(puntoFijo->getPos_x(), puntoFijo->getPos_y()));
				while (this->puedoDer(aux)) {

					cont_verificador_2 += esta_en_vector_nodos(aux->getPos_x(), aux->getPos_y());
					//cout << "contw: " << cont_verificador_2 << endl;
					temp += aux->getLetra();
					punteo_temp1 += this->getValor_ficha(aux->getLetra(), this->lista_casillas.Get_valor_casilla(aux->getPos_x(), aux->getPos_y()));
					// pregunto
					/*cout << "----------------------------------" << endl;
					cout << "palabra:  " << temp << endl;
					cout << "CONT: " << cont_verificador_2 << endl;
					cout << "----------------------------------" << endl;*/
					bool valida = diccionario->aparece_en_diccionario(temp);
					if (valida) {

						if (cont_verificador_2 > 0) {
							cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
							cout << " SI VALIDA , PALABRA:  " << temp << endl;
							cout << "COMPARA  ref: " << puntosParaJugador << " temp :" << punteo_temp1 << endl;
							if (puntosParaJugador < punteo_temp1) {
								puntosParaJugador = punteo_temp1;
								cout << "PUNTAJE de la palabra " << puntosParaJugador << endl;
							}

					//		cout << "cont " << cont_verificador_2 << " = " << this->vector_de_nodos.size() << " igual a 1 si es una letra " << endl;
					//		cout << "si se acepta" << endl;
							cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
						
							VALIDA = true;
							// podria levantar una bandera y guardar estos datos
						}
					}
					aux = aux->getDer();
					cout << endl;
				}
				//cout << "------- ULTIMA INTERACION------------" << endl;
				cont_verificador_2 += esta_en_vector_nodos(aux->getPos_x(), aux->getPos_y());

				temp += aux->getLetra();
				punteo_temp1 += this->getValor_ficha(aux->getLetra(), this->lista_casillas.Get_valor_casilla(aux->getPos_x(), aux->getPos_y()));
				// pregunto
				/*cout << "------------------------------------" << endl;
				cout << "palabra:  " << temp << endl;
				cout << "afuera CONT: " << cont_verificador_2 << endl;
				cout << "------------------------------------" << endl;*/
				bool valida = diccionario->aparece_en_diccionario(temp);
				if (valida) {
					if (cont_verificador_2 > 0) {
						cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
						cout << " SI VALIDA , PALABRA:  " << temp << endl;
						cout << "COMPARA  ref: " << puntosParaJugador << " temp :" <<punteo_temp1 <<endl;
							system("pause");
						if (puntosParaJugador < punteo_temp1) {
							puntosParaJugador = punteo_temp1;
							cout << "PUNTAJE de la palabra "<< puntosParaJugador << endl;
						}
						//cout << "cont " << cont_verificador_2 << " = " << this->vector_de_nodos.size() << "igual a 1 si es una letra " << endl;
						//cout << "si se acepta" << endl;
						cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
					

						VALIDA = true;
						// podria levantar una bandera y guardar estos datos
					}
				}
				//----------------
				puntoFijo = puntoFijo->getDer();
			}


			if (VALIDA) {
				acumulador += puntosParaJugador;
				cout << "=================\n";
				cout << "SE AGREGARAN : " << puntosParaJugador <<" pts"<< endl;
				cout << "=================\n";
			}
			else {
				cout << "no genera nada horizontalmente" << endl;
			}





		}// FIN FOR

		cout << "---" << endl;
		puntosParaJugador = acumulador;
	
	} 










	void Matriz_dispersa:: acumulaPuntosInterseccionesVERTICALES(ListaDobleCircular* diccionario, int& puntosParaJugador) {
		int acumulador = 0; 
		cout << "--- BUSCANDO INTERSECCIONES VERTICALES" << endl;
		for (nMatrix* nodoSubidor : this->vector_de_nodos) {
			puntosParaJugador = 0; // lo limpio 

			while (this->puedoSubir(nodoSubidor)) {
				nodoSubidor = nodoSubidor->getUp();
			}// nodoSubidor es el NODO MAS ALTO POSIBLE el punto fijo de partida 
			cout << "NODO MAS ALTO " << nodoSubidor->getLetra() << endl;
			nMatrix* puntoFijo = new nMatrix();
			puntoFijo = nodoSubidor;
			int cont_verificador_2 = 0;
			bool VALIDA = false;
			while (this->puedoBajar(puntoFijo)) {
				//cout << "down..." << puntoFijo->getLetra() << " (" << puntoFijo->getPos_x() << "," << puntoFijo->getPos_y() << ")" << endl;
				cont_verificador_2 = 0; // --------------------- IMPOSIBLE QUE ESTE CONTADOR SEA 2 
				cont_verificador_2 += esta_en_vector_nodos(puntoFijo->getPos_x(), puntoFijo->getPos_y());
				//cout << "cont: " << cont_verificador_2 << endl;
				string temp = "";
				int punteo_temp1 = 0;
				nMatrix* aux = puntoFijo->getDown();
				// primera interacion 
				temp += puntoFijo->getLetra();
				punteo_temp1 += this->getValor_ficha(puntoFijo->getLetra(), this->lista_casillas.Get_valor_casilla(puntoFijo->getPos_x(), puntoFijo->getPos_y()));



				while (this->puedoBajar(aux)) {

					cont_verificador_2 += esta_en_vector_nodos(aux->getPos_x(), aux->getPos_y());
					//cout << "contw: " << cont_verificador_2 << endl;
					temp += aux->getLetra();
					punteo_temp1 += this->getValor_ficha(aux->getLetra(), this->lista_casillas.Get_valor_casilla(aux->getPos_x(), aux->getPos_y()));
					// pregunto 
					/*cout << "---------------------------------- ANTES DE ACEPTAR---------------" << endl;
					cout << "palabra:  " << temp << endl;
					cout << "CONT: " << cont_verificador_2 << endl;
					cout << "-------------------------------------------------------------------" << endl;*/
					bool valida = diccionario->aparece_en_diccionario(temp);
					if (valida) {
						if (cont_verificador_2 > 0) {
							cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
							cout << " SI VALIDA , PALABRA:  " << temp << endl;
							cout << "COMPARA  ref: " << puntosParaJugador << " temp :" << punteo_temp1 << endl;
							if (puntosParaJugador < punteo_temp1) {
								puntosParaJugador = punteo_temp1;
								cout << "PUNTAJE DE LA PALABRA: " << punteo_temp1 <<endl;
							}
							//cout << "cont " << cont_verificador_2 << " = " << this->vector_de_nodos.size() << "   igual a 1 si era una sola letra " << endl;
							//cout << "si se acepta" << endl;
							cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
							
							VALIDA = true;
							// podria levantar una bandera y guardar estos datos 
						}
					}
					aux = aux->getDown();
					cout << endl;
				}
				//cout << "------- ULTIMA INTERACION------------" << endl;
				cont_verificador_2 += esta_en_vector_nodos(aux->getPos_x(), aux->getPos_y());
				temp += aux->getLetra();
				punteo_temp1 += this->getValor_ficha(aux->getLetra(), this->lista_casillas.Get_valor_casilla(aux->getPos_x(), aux->getPos_y()));
				// pregunto 
			/*	cout << "------------------------------------" << endl;
				cout << "palabra:  " << temp << endl;
				cout << "afuera CONT: " << cont_verificador_2 << endl;
				cout << "------------------------------------" << endl;*/
				bool valida = diccionario->aparece_en_diccionario(temp);
				if (valida) {

					if (cont_verificador_2 > 0) {
						cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
						cout << " SI VALIDA , PALABRA:  " << temp << endl;
						cout << "COMPARA  ref: " << puntosParaJugador << " temp :" << punteo_temp1 << endl;
						if (puntosParaJugador < punteo_temp1) {
							puntosParaJugador = punteo_temp1;
							cout << "PUNTAJE DE LA PALABRA: " << punteo_temp1 << endl;
						}
						//cout << "cont " << cont_verificador_2 << " = " << this->vector_de_nodos.size() << "   igual a 1 si era una sola letra " << endl;
						//cout << "si se acepta" << endl;
						cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
						

						VALIDA = true;
						// podria levantar una bandera y guardar estos datos 
					}
				}
				//----------------
				puntoFijo = puntoFijo->getDown();
			}// FIN PRIMER WHILE PUEDO BAJAR 
			if (VALIDA) {
				VALIDA = false;
				acumulador += puntosParaJugador;
				cout << "=================\n";
				cout << "SE AGREGARAN : " << puntosParaJugador << " pts" << endl;
				cout << "=================\n";
			}

		}// fin del for 
		cout << "---" << endl;
		puntosParaJugador = acumulador;

	}












	void Matriz_dispersa::interseccionesVerticales(ListaDobleCircular* diccionario, int& puntosParaJugador) { // para la letra los puntos de jugador tienen que cambiar 

		cout << "--- BUSCANDO INTERSECCIONES VERTICALES" << endl;
		for (nMatrix* nodoSubidor : this->vector_de_nodos) {
			puntosParaJugador = 0; // lo limpio 
			while (this->puedoSubir(nodoSubidor)) {
				nodoSubidor = nodoSubidor->getUp();
			}// nodoSubidor es el NODO MAS ALTO POSIBLE el punto fijo de partida 
			//cout << "NODO MAS ALTO " << nodoSubidor->getLetra() << endl;
			nMatrix* puntoFijo = new nMatrix();
			puntoFijo = nodoSubidor;
			int cont_verificador_2 = 0;
			bool VALIDA = false;
			while (this->puedoBajar(puntoFijo)) {
				//cout << "down..." << puntoFijo->getLetra() << " (" << puntoFijo->getPos_x() << "," << puntoFijo->getPos_y() << ")" << endl;
				cont_verificador_2 = 0; // --------------------- IMPOSIBLE QUE ESTE CONTADOR SEA 2 
				cont_verificador_2 += esta_en_vector_nodos(puntoFijo->getPos_x(), puntoFijo->getPos_y());
				//cout << "cont: " << cont_verificador_2 << endl;
				string temp = "";
				int punteo_temp1 = 0;
				nMatrix* aux = puntoFijo->getDown();
				// primera interacion 
				temp += puntoFijo->getLetra();
				punteo_temp1 += this->getValor_ficha(puntoFijo->getLetra(), this->lista_casillas.Get_valor_casilla(puntoFijo->getPos_x(), puntoFijo->getPos_y()));



				while (this->puedoBajar(aux)) {

					cont_verificador_2 += esta_en_vector_nodos(aux->getPos_x(), aux->getPos_y());
					//cout << "contw: " << cont_verificador_2 << endl;
					temp += aux->getLetra();
					punteo_temp1 += this->getValor_ficha(aux->getLetra(), this->lista_casillas.Get_valor_casilla(aux->getPos_x(), aux->getPos_y()));
					// pregunto 
					/*cout << "---------------------------------- ANTES DE ACEPTAR---------------" << endl;
					cout << "palabra:  " << temp << endl;
					cout << "CONT: " << cont_verificador_2 << endl;
					cout << "-------------------------------------------------------------------" << endl;*/
					bool valida = diccionario->aparece_en_diccionario(temp);
					if (valida) {
						if (cont_verificador_2 > 0) {
							cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
							cout << " SI VALIDA , PALABRA:  " << temp << endl;
							cout << "cont " << cont_verificador_2 << " = " << this->vector_de_nodos.size() << "   igual a 1 si era una sola letra " << endl;
							cout << "si se acepta" << endl;
							cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
							puntosParaJugador = punteo_temp1;
							VALIDA = true;
							// podria levantar una bandera y guardar estos datos 
						}
					}
					aux = aux->getDown();
					cout << endl;
				}
				//cout << "------- ULTIMA INTERACION------------" << endl;
				cont_verificador_2 += esta_en_vector_nodos(aux->getPos_x(), aux->getPos_y());
				temp += aux->getLetra();
				punteo_temp1 += this->getValor_ficha(aux->getLetra(), this->lista_casillas.Get_valor_casilla(aux->getPos_x(), aux->getPos_y()));
				// pregunto 
			/*	cout << "------------------------------------" << endl;
				cout << "palabra:  " << temp << endl;
				cout << "afuera CONT: " << cont_verificador_2 << endl;
				cout << "------------------------------------" << endl;*/
				bool valida = diccionario->aparece_en_diccionario(temp);
				if (valida) {

					if (cont_verificador_2 > 0) {
						cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
						cout << "PALABRA:  " << temp << endl;
						cout << "cont " << cont_verificador_2 << " = " << this->vector_de_nodos.size() << "   igual a 1 si era una sola letra " << endl;
						cout << "si se acepta" << endl;
						cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
						puntosParaJugador = punteo_temp1;

						VALIDA = true;
						// podria levantar una bandera y guardar estos datos 
					}
				}
				//----------------
				puntoFijo = puntoFijo->getDown();
			}// FIN PRIMER WHILE PUEDO BAJAR 
			if (VALIDA) {
				VALIDA = false;
				cout << "==============================================================\n";
				cout << "PUNTOS GENERADOS ACUMULADOR: " << puntosParaJugador << endl;
				cout << "==============================================================\n";
			}

		}// fin del for 
		cout << "---" << endl;
	}









































































	void Matriz_dispersa::interseccionesHorizontales(ListaDobleCircular* diccionario, int& puntosParaJugador) {
		cout << "--- BUSCANDO INTERSECCIONES  HORIZONTALES " << endl;

		for (nMatrix* nodo_masIzq : this->vector_de_nodos) {
			while (this->puedoIzq(nodo_masIzq)) {
				nodo_masIzq = nodo_masIzq->getIzq();
			}
			cout << "NODO MAS A LA IZQUIERDA " << nodo_masIzq->getLetra();
			nMatrix* puntoFijo = new nMatrix();
			puntoFijo = nodo_masIzq;
			int cont_verificador_2 = 0;
			bool VALIDA = false;
			while (this->puedoDer(puntoFijo)) {
				//cout << "DER-->>>" << puntoFijo->getLetra() << " (" << puntoFijo->getPos_x() << "," << puntoFijo->getPos_y() << ")" << endl;

				cont_verificador_2 = 0;
				cont_verificador_2 += esta_en_vector_nodos(puntoFijo->getPos_x(), puntoFijo->getPos_y());
				//cout << "cont: " << cont_verificador_2 << endl;
				string temp = "";
				int punteo_temp1 = 0;
				nMatrix* aux = puntoFijo->getDer();
				// primera interacion
				temp += puntoFijo->getLetra();
				punteo_temp1 += this->getValor_ficha(puntoFijo->getLetra(), this->lista_casillas.Get_valor_casilla(puntoFijo->getPos_x(), puntoFijo->getPos_y()));
				while (this->puedoDer(aux)) {

					cont_verificador_2 += esta_en_vector_nodos(aux->getPos_x(), aux->getPos_y());
					//cout << "contw: " << cont_verificador_2 << endl;
					temp += aux->getLetra();
					punteo_temp1 += this->getValor_ficha(aux->getLetra(), this->lista_casillas.Get_valor_casilla(aux->getPos_x(), aux->getPos_y()));
					// pregunto
					/*cout << "----------------------------------" << endl;
					cout << "palabra:  " << temp << endl;
					cout << "CONT: " << cont_verificador_2 << endl;
					cout << "----------------------------------" << endl;*/
					bool valida = diccionario->aparece_en_diccionario(temp);
					if (valida) {

						if (cont_verificador_2 > 0) {
							cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
							cout << " SI VALIDA , PALABRA:  " << temp << endl;
							cout << "cont " << cont_verificador_2 << " = " << this->vector_de_nodos.size() << " igual a 1 si es una letra " << endl;
							cout << "si se acepta" << endl;
							cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
							puntosParaJugador = punteo_temp1;
							VALIDA = true;
							// podria levantar una bandera y guardar estos datos
						}
					}
					aux = aux->getDer();
					cout << endl;
				}
				//cout << "------- ULTIMA INTERACION------------" << endl;
				cont_verificador_2 += esta_en_vector_nodos(aux->getPos_x(), aux->getPos_y());

				temp += aux->getLetra();
				punteo_temp1 += this->getValor_ficha(aux->getLetra(), this->lista_casillas.Get_valor_casilla(aux->getPos_x(), aux->getPos_y()));
				// pregunto
				/*cout << "------------------------------------" << endl;
				cout << "palabra:  " << temp << endl;
				cout << "afuera CONT: " << cont_verificador_2 << endl;
				cout << "------------------------------------" << endl;*/
				bool valida = diccionario->aparece_en_diccionario(temp);
				if (valida) {
					if (cont_verificador_2 > 0) {
						cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
						cout << " SI VALIDA , PALABRA:  " << temp << endl;
						cout << "cont " << cont_verificador_2 << " = " << this->vector_de_nodos.size() << "igual a 1 si es una letra " << endl;
						cout << "si se acepta" << endl;
						cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
						puntosParaJugador = punteo_temp1;

						VALIDA = true;
						// podria levantar una bandera y guardar estos datos
					}
				}
				//----------------
				puntoFijo = puntoFijo->getDer();
			}


			if (VALIDA) {

				cout << "=================\n";
				cout << "PUNTOS GENERADOS: " << puntosParaJugador << endl;
				cout << "=================\n";
			}
			else {
				cout << "no genera nada horizontalmente" << endl;
			}





		}// FIN FOR

		cout << "---" << endl;

	}