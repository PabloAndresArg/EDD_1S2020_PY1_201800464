// Proyecto1EDD_201800464.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<stdlib.h>
#include"Arbol.h"
#include"Jugador.h"
int main()
{
    system("color a");
    Arbol* nuevaInstancia = new Arbol();
    Jugador* j1 = new Jugador("Pablo"); 
    Jugador* j2 = new Jugador("Anthony");
    Jugador* j3 = new Jugador("Juan");
    Jugador* j4 = new Jugador("Javier");
    NodoArbol* nuevo = new NodoArbol(j1);
    NodoArbol* nuevo2 = new NodoArbol(j2);
    NodoArbol* nuevo3 = new NodoArbol(j3);
    NodoArbol* nuevo4 = new NodoArbol(j4);
    nuevaInstancia->add(nuevo);
    nuevaInstancia->add(nuevo2);
    nuevaInstancia->add(nuevo3);
    nuevaInstancia->add(nuevo4);
    nuevaInstancia->recorrido_inOrder();
    nuevaInstancia->recorrido_PreOrder(); 
    nuevaInstancia->recorrido_PostOrder(); 
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
