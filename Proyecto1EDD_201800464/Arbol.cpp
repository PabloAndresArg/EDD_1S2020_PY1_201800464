#include "Arbol.h"
#include"NodoArbol.h"
#include<iostream>
#include<stdlib.h>
#include<string>
#include"IO_Archivos.h"
using namespace std; 
void Arbol::add(NodoArbol* nuevo) { // todo los nombre que agregue deben de ir en minusculas :o 
	if (this->raiz == NULL) {
		this->raiz = nuevo;
	}
	else {
		recursive_add(this->raiz, nuevo); // minuto 43
	}
}
void Arbol::recursive_add(NodoArbol* actual, NodoArbol* nuevo) {
    if ((compararAlfabeticamente(actual->getJugador()->getNombre() , nuevo->getJugador()->getNombre())) == 1) {
        cout << actual->getJugador()->getNombre()<<" es mayor alfabeticamente que :"<< nuevo->getJugador()->getNombre()<< "se va por la izq"<<endl ; // si es mas grande el actual pues me voy por la izq 
        if (actual->getIzq() != NULL) {
            recursive_add(actual->getIzq(),nuevo);
        }
        else {
            actual->setIzq(nuevo);
        }
    }
    else if((compararAlfabeticamente(actual->getJugador()->getNombre(), nuevo->getJugador()->getNombre())) == 0) {
        cout << actual->getJugador()->getNombre() << " es menor alfabeticamente que :" << nuevo->getJugador()->getNombre() << "se va por la der" << endl;
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
    if (p1.compare(p2) == 0 ) {
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
            cout << "la letra: " << letra1 << " VA ANTES QUE : " << letra2 << endl;
            palabraOrdenada = p1;
            return 0;
        }
        else if (letra1 > letra2) {
            cout << "AVANZA DE NODO " << letra1 << endl;
            palabraOrdenada = p2;
            return 1;
        }
    }
    cout << "LA PALABRA QUE IRIA PRIMERO ES : " << palabraOrdenada << endl;
    return 1;

    }
}

// RECORRIDOS 
void Arbol:: recorrido_inOrder() {
    cout << "recorrido INORDER: ";
    recursive_inOrder(this->raiz); 
    cout << endl;
}

void Arbol:: recursive_inOrder(NodoArbol* actual) {
    if (actual->getIzq() != NULL) {
        recursive_inOrder(actual->getIzq());
    }

    cout <<actual->getJugador()->getNombre() <<" -> ";

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
    this->Graph += "}";
    IO_Archivos* llama = new IO_Archivos(); 
    llama->graficaArbol(this->Graph);
    this->Graph = ""; 
    // tener en cuenta que tengo que recolectar 3 recorridos diferentes 
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

