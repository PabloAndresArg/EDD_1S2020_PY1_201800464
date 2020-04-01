#include "Arbol.h"
#include"NodoArbol.h"
#include<iostream>
#include<stdlib.h>
#include<string>
#include"IO_Archivos.h"
#include <sstream>
#include"RegistroPuntaje.h"
#include<ctype.h> // para usar el tolower
using namespace std; 
void Arbol::add(NodoArbol* nuevo) { // todo los nombre que agregue deben de ir en minusculas :o 
    string nombre = nuevo->getJugador()->getNombre();
    nuevo->getJugador()->setNombre(convertirTodoMinuscula(nuevo->getJugador()->getNombre()));
    if (this->raiz == NULL) {
		this->raiz = nuevo;
	}
	else {
		recursive_add(this->raiz, nuevo); // minuto 43
	}
}

Jugador* Arbol::buscar(string nombre) {
    nombre = convertirTodoMinuscula(nombre);
    NodoArbol* encontrado = buscarRecursivo(this->raiz , nombre);
    if (encontrado != NULL) {
        return encontrado->getJugador();
    }
    Jugador* empty = new Jugador();
    return empty;
}

NodoArbol* Arbol::buscarRecursivo(NodoArbol* actual , string nombre) {
    // 1 me voy por la izquierda actual > busqueda
    // 0 por la derecha  actual < busqueda
    //y 2 son iguales  actual == busqueda 

    if (actual == NULL) {
        return actual; //va retornar un vacio
    }
    if (compararAlfabeticamente(actual->getJugador()->getNombre(), nombre) == 2) {
        return actual;  
    }
    if (compararAlfabeticamente(actual->getJugador()->getNombre(), nombre) == 1) {
        return buscarRecursivo(actual->getIzq() , nombre);
    }
    if (compararAlfabeticamente(actual->getJugador()->getNombre(), nombre) == 0) {
        return buscarRecursivo(actual->getDer(), nombre);
    }

}

void Arbol::setJugador(Jugador* regresa_jugador) {
    NodoArbol* nodo = buscarRecursivo(this->raiz, regresa_jugador->getNombre());
    if (nodo != NULL) {
        nodo->setJugador(regresa_jugador);
    }
}


string Arbol::convertirTodoMinuscula(string nombre) {
    string nuevoNombre = "";
    int lon = (int)nombre.size();
    for (int i = 0; i < lon ; i++)
    {
        char letra = tolower(nombre[i]);
        nuevoNombre += letra;
    }
  //  cout << "nombre en minuscula: " << nuevoNombre << endl;
    return nuevoNombre;
}


void Arbol::recursive_add(NodoArbol* actual, NodoArbol* nuevo) {
    if ((compararAlfabeticamente(actual->getJugador()->getNombre() , nuevo->getJugador()->getNombre())) == 1) {
       // cout << actual->getJugador()->getNombre()<<" es mayor alfabeticamente que :"<< nuevo->getJugador()->getNombre()<< "se va por la izq"<<endl ; // si es mas grande el actual pues me voy por la izq 
        if (actual->getIzq() != NULL) {
            recursive_add(actual->getIzq(),nuevo);
        }
        else {
            actual->setIzq(nuevo);
        }
    }
    else if((compararAlfabeticamente(actual->getJugador()->getNombre(), nuevo->getJugador()->getNombre())) == 0) {
       // cout << actual->getJugador()->getNombre() << " es menor alfabeticamente que :" << nuevo->getJugador()->getNombre() << "se va por la der" << endl;
        if (actual->getDer() != NULL) {
            recursive_add(actual->getDer(), nuevo);
        }
        else {
            actual->setDer(nuevo);
        }
    }
    else {
        cout << "REPETIDO: " + nuevo->getJugador()->getNombre();
    }
}




int Arbol::compararAlfabeticamente(string p1, string p2) {
    // p1 nuevo  , p2 de la lista 
    // retorno true para seguir buscando , retorno false si ya enccontre le nodo donde deseo ingresar 
    if (p1.compare(p2) == 0) {
        return 2; 
    }else{
    string palabraOrdenada = "";
    int repeticiones = 0, p1_size, p2_size;
    p1_size = (int)p1.size();
    p2_size = (int)p2.size();
    if (p1_size > p2_size) {
        repeticiones = (int)p2.size();
        palabraOrdenada = p2;
    }
    else if (p2_size > p1_size) {
        repeticiones = (int)p1.size();
        palabraOrdenada = p1;
    }
    else { // si son iguales en longitud 
        repeticiones = (int)p1.size();
    }


    for (int i = 0; i < repeticiones; i++) {// lo hara hasta la letra mas pequeña
        char letra1 = p1[i];
        char letra2 = p2[i];
        if (letra1 == letra2) {
        }
        else if (letra2 > letra1) { // palabra 1 va antes que palabra 2 
      //      cout << "la letra: " << letra1 << " VA ANTES QUE : " << letra2 << endl;
            palabraOrdenada = p1;
            return 0;
        }
        else if (letra1 > letra2) {
      //      cout << "AVANZA DE NODO " << letra1 << endl;
            palabraOrdenada = p2;
            return 1;
        }
    }
  //  cout << "LA PALABRA QUE IRIA PRIMERO ES : " << palabraOrdenada << endl;

    // caso en que la similitud es muy grande y no hay mas letras para comparar 

    int logitud_raiz = (int)p1.size();
    int logitud_nuevo = (int)p2.size();
    if (logitud_raiz>logitud_nuevo) {
        return 1; // lo inserto a la izq
    }
    else {
        return 0;
    }
    // si son iguales a la derecha
    return 1;




    }
}

// RECORRIDOS 
void Arbol:: recorrido_inOrder() {
    cout << "------ LISTA DE JUGADORES --------";
    cout << endl;
    recursive_inOrder(this->raiz); 
}

void Arbol:: recursive_inOrder(NodoArbol* actual) {
    if (actual->getIzq() != NULL) {
        recursive_inOrder(actual->getIzq());
    }

    cout <<actual->getJugador()->getNombre() <<"  ";

    if (actual->getDer() != NULL) {
        recursive_inOrder(actual->getDer());
    }
}

void Arbol::recursive_PreOrder(NodoArbol* actual) {
    cout << actual->getJugador()->getNombre() << " -> ";
    if (actual->getIzq() != NULL) {
        recursive_inOrder(actual->getIzq());
    }

    if (actual->getDer() != NULL) {
        recursive_inOrder(actual->getDer());
    }
}

void Arbol::recursive_PostOrder(NodoArbol* actual) {

    if (actual->getIzq() != NULL) {
        recursive_inOrder(actual->getIzq());
    }

    if (actual->getDer() != NULL) {
        recursive_inOrder(actual->getDer());
    }
    cout << actual->getJugador()->getNombre() << " -> ";
}

void  Arbol::getGraphviz() {
    
  
    this->Graph += "digraph ARBOL { rankdir=TB; style = filled;bgcolor = white;color = lightgrey;node[style = filled, color = green, shape = record];   \n ";
    getGraphviz(this->raiz);
    llenarListasSimples(); // llen mis listas limples 
    IO_Archivos* llama = new IO_Archivos(); 
    llama->graficaArbol(this->Graph, listaPreOder.getCabeza(), listaInOrder.getCabeza(), listaPostOrder.getCabeza());
  //  listaPreOder.getGraphviz();
    this->Graph = "";
    this->indice = 0;
    limpiarListasAux();
    
}

void Arbol::llenarListaPreOrder(NodoArbol* actual) {
    RegistroPuntaje* nodoRaiz = new RegistroPuntaje(actual->getJugador()->getNombre() , this->indice);
    this->listaPreOder.add(nodoRaiz);
    this->indice++;
    if (actual->getIzq() != NULL) {
        llenarListaPreOrder(actual->getIzq());
    }
    if (actual->getDer() != NULL) {
        llenarListaPreOrder(actual->getDer());
    }
}
void Arbol::llenarListaInOrder(NodoArbol* actual) {

    if (actual->getIzq() != NULL) {
        llenarListaInOrder(actual->getIzq());
    }
    RegistroPuntaje* nodoRaiz = new RegistroPuntaje(actual->getJugador()->getNombre(), this->indice);
    this->listaInOrder.add(nodoRaiz);
    this->indice++;
    if (actual->getDer() != NULL) {
        llenarListaInOrder(actual->getDer());
    }
}
void Arbol::llenarListaPostOrder(NodoArbol* actual) {

    if (actual->getIzq() != NULL) {
        llenarListaPostOrder(actual->getIzq());
    }
    if (actual->getDer() != NULL) {
        llenarListaPostOrder(actual->getDer());
    }
    RegistroPuntaje* nodoRaiz = new RegistroPuntaje(actual->getJugador()->getNombre(), this->indice);
    this->listaPostOrder.add(nodoRaiz);
    this->indice++;
}
void Arbol::llenarListasSimples() {
    llenarListaPreOrder(this->raiz);
    llenarListaInOrder(this->raiz); 
    llenarListaPostOrder(this->raiz);
}



void Arbol::getGraphviz(NodoArbol* R_actual) {
    this->Graph += ""+ R_actual->getJugador()->getNombre() +"[label = \" <C0>|" + R_actual->getJugador()->getNombre() + "|<C1>"+ "\" ];   \n ";
    //cout << actual->getJugador()->getNombre() << " -> ";
    if (R_actual->getIzq() != NULL) {
        //nodo9:C0->nodo10
        this->Graph += R_actual->getJugador()->getNombre() +":C0->" + R_actual->getIzq()->getJugador()->getNombre()+ " [arrowhead = none color = black];   \n ";
        getGraphviz(R_actual->getIzq());
    }

    if (R_actual->getDer() != NULL) {
        this->Graph += R_actual->getJugador()->getNombre() + ":C1->" + R_actual->getDer()->getJugador()->getNombre() + " [arrowhead = none color = black];   \n ";
        getGraphviz(R_actual->getDer());
    }
}

void Arbol::limpiarListasAux() {
    this->listaPreOder.vaciar(); 
    this->listaInOrder.vaciar(); 
    this->listaPostOrder.vaciar();
}


void Arbol::vaciar() {
    this->raiz = NULL;
}