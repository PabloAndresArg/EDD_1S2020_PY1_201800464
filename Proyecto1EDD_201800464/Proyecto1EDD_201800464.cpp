// Proyecto1EDD_201800464.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<stdlib.h>
#include"Arbol.h"
#include"Jugador.h"
#include"ListaSimpleOrdenada.h"
#include"RegistroPuntaje.h"
#include "IO_Archivos.h"
#include"ListaDobleCircular.h"
#include"NodoDobleC.h"
int main()
{ // NOTA AL ARBOL TENGO QUE VALIDAR QUE TODO ENTRE EN MINUSCULA 
    system("color a");
    Arbol* nuevaInstancia = new Arbol();
    Jugador* j1 = new Jugador("Pablo"); 
    Jugador* j2 = new Jugador("Anthony");
    Jugador* j3 = new Jugador("Zeta");
    Jugador* j4 = new Jugador("Javier");
    Jugador* j5 = new Jugador("Javier");
    NodoArbol* nuevo = new NodoArbol(j1);
    NodoArbol* nuevo2 = new NodoArbol(j2);
    NodoArbol* nuevo3 = new NodoArbol(j3);
    NodoArbol* nuevo4 = new NodoArbol(j4);
    NodoArbol* nuevo5 = new NodoArbol(j5);
    nuevaInstancia->add(nuevo);
    nuevaInstancia->add(nuevo2);
    nuevaInstancia->add(nuevo3);
    nuevaInstancia->add(nuevo4);
    nuevaInstancia->add(nuevo5);
    cout << endl;
    cout << endl;
    cout << endl;
    nuevaInstancia->recorrido_inOrder();
    nuevaInstancia->recorrido_PreOrder(); 
    nuevaInstancia->recorrido_PostOrder();
    nuevaInstancia->getGraphviz();
  /*  ListaSimpleOrdenada* L = new ListaSimpleOrdenada();
    RegistroPuntaje* d1 = new RegistroPuntaje("", 10);
    RegistroPuntaje* d2 = new RegistroPuntaje("", 20);
    RegistroPuntaje* d3 = new RegistroPuntaje("", 5);
    RegistroPuntaje* d4 = new RegistroPuntaje("", 77);
    RegistroPuntaje* d5 = new RegistroPuntaje("", 55);
    RegistroPuntaje* d6 = new RegistroPuntaje("", 8);
    L->add(d1);
    L->add(d2);
    L->add(d3);
    L->add(d4);
    L->add(d5);
    L->add(d6); 
    L->getGraphviz();
    L->imprimir();*/
   /* ListaDobleCircular LC; 
    LC.add("pablo");
    LC.add("ANDRES"); 
    LC.add("argueta"); 
    LC.imprimeparaAdelnate();
    LC.imprimeparaAtras();
    LC.getGraphviz();*/

    system("PAUSE");
}
