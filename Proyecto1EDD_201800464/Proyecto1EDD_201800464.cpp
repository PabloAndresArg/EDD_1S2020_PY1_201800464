// Proyecto1EDD_201800464.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<stdlib.h>
#include"Arbol.h"
#include"Jugador.h"
#include"ListaSimpleOrdenada.h"
#include"RegistroPuntaje.h"
#include "IO_Archivos.h"
int main()
{
    system("color a");
   /* Arbol* nuevaInstancia = new Arbol();
    Jugador* j1 = new Jugador("Pablo"); 
    Jugador* j2 = new Jugador("Anthony");
    Jugador* j3 = new Jugador("Juan");
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
    nuevaInstancia->recorrido_PostOrder(); */
    ListaSimpleOrdenada* L = new ListaSimpleOrdenada();
    RegistroPuntaje* d1 = new RegistroPuntaje("", 10);
    RegistroPuntaje* d2 = new RegistroPuntaje("", 20);
    RegistroPuntaje* d3 = new RegistroPuntaje("", 5);
    RegistroPuntaje* d4 = new RegistroPuntaje("", 60);
    RegistroPuntaje* d5 = new RegistroPuntaje("", 55);
    L->add(d1);
    L->add(d2);
    L->add(d3);
    L->add(d4);
    L->add(d5);
    L->imprimir();
    system("PAUSE");
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
