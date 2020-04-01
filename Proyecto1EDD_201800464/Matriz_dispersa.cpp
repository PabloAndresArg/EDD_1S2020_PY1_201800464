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
		for(nMatrix* nodo : this->vector_de_nodos) {
			palabraFormada += nodo->getLetra();
		}
		cout <<"///////////////////////////////////////////////////////////////////////////////"<<endl;
		cout << "PALABRA INGRESADA: "<<palabraFormada<<endl;
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		bool valida =  diccionario->aparece_en_diccionario(palabraFormada);
		if (valida) {
			cout << "si se acepta" << endl;
			// paso a darle su respectivo valor  
			int puntos_generados=0;
			for (int i = 0; i < palabraFormada.size(); i++)
			{
				char letra = palabraFormada[i];
				int valor =this->getValor_ficha(letra);
				puntos_generados += valor;
			}
			puntosParaJugador = puntos_generados;
			cout << "=====================================";
			cout << "PUNTOS GENERADOS: "<<puntos_generados;
			cout << "=====================================";
			return true;
		}
		else {
			

			cout << "PALABRA INVALIDA " << endl; 

		}

	}
	else {
		// TENGO QUE VALIDAR QUE SEA ADYACENTE A LAS FICHAS VIEJAS , LUEGO QUE PALABRA FORMA , LUEGO SUMA DE PUNTOS 



	}
	return false;
}

bool Matriz_dispersa:: es_palabra_adyacente() {

	for (nMatrix* n : this->vector_de_nodos) {
		cout << "---REVISANDO EL NODO----"<< n->getLetra() << endl;
		if (n->getDer() != NULL) {
			cout << " CASO DERECHA " << n->getDer()->getPos_x() << " - " << n->getPos_x() << " = " << (n->getDer()->getPos_x() - n->getPos_x())<<endl;
			if ((n->getDer()->getPos_x() - n->getPos_x()) == 1 && n->getDer()->getIs_nueva() == false) { // 3 -2 = 1 
			cout << " ADYACENTE  "<<n->getLetra()<<" TIENE A LA DERECHA A "<< n->getDer()->getLetra()<<endl;// a la derecha nunca podria tener una cab
			//return true; 
			}
		}
		if (n->getIzq() != NULL) {
			cout << " CASO IZQ "<<n->getIzq()->getPos_x() << " - " << n->getPos_x()<<  " = "<< (n->getIzq()->getPos_x() - n->getPos_x())<<endl;
			if ((n->getIzq()->getPos_x() - n->getPos_x()) == -1 && n->getIzq()->getIs_nueva() == false  && n->getIzq()->getPos_x() != -1) {
				cout << " ADYACENTE  " << n->getLetra() << " TIENE A LA IZQUIERDA " << n->getIzq()->getLetra()<<endl;
				//return true;
			}
		}
		 if (n->getDown() != NULL){
			cout << " CASO ABAJO " << n->getDown()->getPos_y() << " - " << n->getPos_y() <<" = "<< (n->getDown()->getPos_y() - n->getPos_y()) << endl;
			if ((n->getDown()->getPos_y() - n->getPos_y()) == 1 && n->getDown()->getIs_nueva() == false) {
				cout << "ADYACENTE  " << n->getLetra() << "  TIENE ABAJO A  " << n->getDown()->getLetra()<<endl;
				//return true;
			}
		}
		 if (n->getUp() != NULL) {
			cout << " CASO ARRIBA "<< n->getUp()->getPos_y()<< " - "<< n->getPos_y()<< " = " << (n->getUp()->getPos_y() - n->getPos_y())<<endl;
			if ((n->getUp()->getPos_y() - n->getPos_y()) == -1 && n->getUp()->getIs_nueva() == false && n->getUp()->getPos_y() != -1) {
				cout << "ADYACENTE  " << n->getLetra() << " TIENE ARRIBA A  " << n->getUp()->getLetra()<<endl;
				//return true;
			}
		}
		cout << "----------" << endl;
		// tener en cuenta que la adyacencia con las cabeceras y columnas no valen  , las pos negativas las descartan 
	}
//	cout << "NO ES ADYACENTE" <<endl ;
	return false; // si ninguno de los nodos nuevos tiene adyacencia con los viejo esta palabra es invalida 
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




int Matriz_dispersa::getValor_ficha(char letra) {

	/*if (letra == 'a' || letra =='e' || letra == 'o' || letra == 'i' || letra == 's' || letra == 'n' || letra =='r'|| letra == 'u' || letra == 't') {
		return 1;
	}*/
	if (letra == 'd' || letra == 'g') {
		return 2;
	}
	else if (letra == 'c' || letra == 'b' || letra == 'm' || letra == 'p') {
		return 3;
	}
	else if (letra == 'h' || letra == 'f' || letra == 'v' || letra == 'y') {
		return 4;
	}
	else if (letra == 'q') {
		return 5;
	}
	else if (letra == 'z') {
		return 10;
	}
	else if (letra == 'j' || letra == 'x') {
		return 8;
	}
	else {
		return 1;
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
							}
						}
						aux = aux->getDer();
					}
				}
				col_principal = col_principal->getDown();
			}
	}

