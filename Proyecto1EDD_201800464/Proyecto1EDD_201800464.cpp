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
#include"Ficha.h"
#include"Global.h"
#include"nMatrix.h"
#include"Matriz_dispersa.h"
using namespace std; 



int main()
{ 
  /*  Matriz_dispersa* m = new Matriz_dispersa();
    m->setTamanioMaximo(80);
    m->add('2',4 ,1 );
    m->add('3',4 ,2 );
    m->add('2', 80, 7);
    m->add('3', 6,4);
    m->add('3', 4, 15);
    m->add('3', 10, 3);
    m->getGraphviz();*/
    system("color a");
    while (true) {
        menuPrincipal();
    }

   /* Arbol* nuevaInstancia = new Arbol();
    Jugador* j1 = new Jugador("Pablo"); 
    Jugador* j2 = new Jugador("Anthony");
    Jugador* j3 = new Jugador("Zeta");
    Jugador* j4 = new Jugador("Javier");
    Jugador* j5 = new Jugador("Javier");
    Jugador* j6 = new Jugador("Pancho");
    Jugador* j7 = new Jugador("JIMENA");
    NodoArbol* nuevo = new NodoArbol(j1);
    NodoArbol* nuevo2 = new NodoArbol(j2);
    NodoArbol* nuevo3 = new NodoArbol(j3);
    NodoArbol* nuevo4 = new NodoArbol(j4);
    NodoArbol* nuevo5 = new NodoArbol(j5);
    NodoArbol* nuevo6 = new NodoArbol(j6);
    NodoArbol* nuevo7 = new NodoArbol(j7);
    nuevaInstancia->add(nuevo);
    nuevaInstancia->add(nuevo2);
    nuevaInstancia->add(nuevo3);
    nuevaInstancia->add(nuevo4);
    nuevaInstancia->add(nuevo5);
    nuevaInstancia->add(nuevo6);
    nuevaInstancia->add(nuevo7);
    Jugador* busque = nuevaInstancia->buscar("pablo");
    RegistroPuntaje* reg = new RegistroPuntaje(100);
    busque->getListaPuntajes().add(reg);
    RegistroPuntaje* reg2 = new RegistroPuntaje(200);
    busque->getListaPuntajes().add(reg2);
    RegistroPuntaje* reg3 = new RegistroPuntaje(50);
    busque->getListaPuntajes().add(reg3);
    RegistroPuntaje* reg4 = new RegistroPuntaje(600);
    busque->getListaPuntajes().add(reg4);
    RegistroPuntaje* reg5 = new RegistroPuntaje(10);
    busque->getListaPuntajes().add(reg5);

    nuevaInstancia->setJugador(busque);

    Jugador* prueba = nuevaInstancia->buscar("pablo");
    prueba->getListaPuntajes().getGraphviz_porJugador(busque->getNombre());

   /* cout << endl;
    cout << endl;
    cout << endl;
    nuevaInstancia->recorrido_inOrder();
    nuevaInstancia->recorrido_PreOrder(); 
    nuevaInstancia->recorrido_PostOrder();
    nuevaInstancia->getGraphviz();*/
    

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

