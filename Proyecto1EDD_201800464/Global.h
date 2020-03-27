#pragma once
#include<ctime>
#include<cstdlib>
#include<stdlib.h>
#include"Arbol.h"
#include"Jugador.h"
#include"ListaSimpleOrdenada.h"
#include"RegistroPuntaje.h"
#include "IO_Archivos.h"
#include"ListaDobleCircular.h"
#include"NodoDobleC.h"
#include"Ficha.h"
#include"NodoCola.h"
#include"Cola.h"

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <sstream>
#include"Matriz_dispersa.h"
#include"nMatrix.h"

#include "/Users//Pablo/Downloads/json.hpp";
using namespace std;
int posX = 0;
int posY = 0;
using json = nlohmann::json;
json Todo_el_juego;
json json_dimension;
json casillas_dobles;
json tripleJs;
json JsonPalabras_diccionario;


int tamanio_tablero = 0;

// prototipos
void extraerDatos(string);
void Leer_Json();

void menuPrincipal();
void llenarFichas();
void menuJuego(); 
void menuReportes();
void mezclarFichas_e_ingresar_Cola();
void addFicha_a_fichero(Ficha* f);
void imprimirFichas();
                            // menu-juego
void crearJugador();
int escogerQuienVaPrimero();
void INICIAR_JUEGO();
void limipiarJugadoresActuales();
void llenarJugadoresActuales();
void realizarJugada(int);
// estructuras estaticas y arreglos 
Matriz_dispersa* TABLERO = new Matriz_dispersa();
Ficha* fichas[95];
Cola* BOLSA = new Cola();
Arbol* ARBOL_JUGADORES = new Arbol();
ListaDobleCircular* diccionario = new ListaDobleCircular();
static int cont = 0;



void Leer_Json() {
    cout << "|||| INGRESE LA DIRECCION DEL JSON ||||" << endl;
    cout << "RUTA: ";
    string enrutador = "";//  C:\Users\Pablo\Downloads\Library.json
    cin >> enrutador;
    extraerDatos(enrutador);
}

void menuPrincipal() {
    /*llenarFichas();
    imprimirFichas();
    mezclarFichas_e_ingresar_Cola();
    imprimirFichas();
    */

    llenarFichas();
    mezclarFichas_e_ingresar_Cola();
    cout << "  UNIVERSIDAD DE SAN CARLOS DE GUATEMALA" << endl; 
    cout << "  FACULTAD DE INGENIERIA" << endl; 
    cout << "  ESTRUCTURAS DE DATOS" << endl;
    cout << "  |||| PROYECTO 1 ||||" << endl; 
    cout << "  PABLO ANDRES ARGUETA HERNANDEZ" << endl; 
    cout << "  Carnet: 201800464" << endl;
    cout << "  MENU PRINCIPAL" << endl;
    cout << "  1.Lectura de Archivo" << endl; 
    cout << "  2.Juego" << endl; 
    cout << "  3.Reportes" << endl; 
    cout << "  4.salir" << endl;
    int opcion = 0;
    cout << "ingrese un Numero: ";
    cin >> opcion;
    switch (opcion - 1) {
    case 0:// lectura de archivo
        system("cls"); 
        Leer_Json();
        break;
    case 1:// Juego
        system("cls");
        menuJuego(); 
        break;
    case 2://Reportes
        system("cls");
        menuReportes();
        break;
    case 3:// SALIR 
        system("cls");
        exit(0);
        break;

    default:
        cout << "ERROR OPCION NO VALIDA" << endl;
        break;
    }
}

void addFicha_a_fichero(Ficha* f) {
    if (cont < 95) {
        fichas[cont] = f;
        cont++;
    }
}

void imprimirFichas() {
    for (int i = 0; i < 95; i++)
    {
        char l = fichas[i]->getLetra();
        cout << l << " ";

        if (i == 9 || i == 19 || i == 29 || i == 39 || i == 49 || i == 59 || i == 69 || i == 79 || i == 89 || i == 94) {
            cout <<"\n";
        }
    }

    system("pause");
}


void llenarFichas() {
    // de 1 punto 
    for (int i = 0; i < 12; i++)
    {
        Ficha* A = new Ficha(1, 'a');
        addFicha_a_fichero(A);
        Ficha* E = new Ficha(1, 'e');
        addFicha_a_fichero(E);
    }
    for (int i = 0; i < 9; i++)
    {
        Ficha* O = new Ficha(1, 'o');
        addFicha_a_fichero(O);
    }
    for (int i = 0; i < 6; i++)
    {
        Ficha* I = new Ficha(1, 'i');
        addFicha_a_fichero(I);
        Ficha* S = new Ficha(1, 's');
        addFicha_a_fichero(S);
    }
    for (int i = 0; i < 5; i++)
    {
        Ficha* N = new Ficha(1, 'n');
        addFicha_a_fichero(N);
        Ficha* R = new Ficha(1, 'r');
        addFicha_a_fichero(R);
        Ficha* U = new Ficha(1, 'u');
        addFicha_a_fichero(U);
        Ficha* D = new Ficha(2, 'd');
        addFicha_a_fichero(D);
    }
    for (int i = 0; i < 4; i++)
    {
        Ficha* L = new Ficha(1, 'l');
        addFicha_a_fichero(L);
        Ficha* T = new Ficha(1, 't');
        addFicha_a_fichero(T);
        Ficha* C = new Ficha(3, 'c');
        addFicha_a_fichero(C);
    }
    for (int i = 0; i < 2; i++)
    {
        Ficha* G = new Ficha(2, 'g');
        addFicha_a_fichero(G);
        // 3 PUNTOS 
        Ficha* B = new Ficha(3, 'b');
        addFicha_a_fichero( B);
        Ficha* M = new Ficha(3, 'm');
        addFicha_a_fichero( M);
        Ficha* P = new Ficha(3, 'p');
        addFicha_a_fichero( P);
        // 4 PUNTOS
        Ficha* H = new Ficha(4, 'h');
        addFicha_a_fichero(H);
    }
    Ficha* F = new Ficha(4, 'f');
    addFicha_a_fichero( F);
    Ficha* V = new Ficha(4, 'v');
    addFicha_a_fichero( V);
    Ficha* Y = new Ficha(4, 'y');
    addFicha_a_fichero( Y);
    // 5 PUNTOS 
    Ficha* Q = new Ficha(5, 'q');
    addFicha_a_fichero( Q);
    // 8 PUNTOS 
    Ficha* J = new Ficha(8, 'j');
    addFicha_a_fichero( J);
    Ficha* NN = new Ficha(8, char(-92));
    addFicha_a_fichero( NN);
    Ficha* X = new Ficha(8, 'x');
    addFicha_a_fichero( X);
    // 10 PUNTOS
    Ficha* Z = new Ficha(10, 'z');
    addFicha_a_fichero( Z);
}



void menuJuego() {
    cout << " |||||||| MENU DE JUEGO ||||||||" << endl;
    cout << " 1.Crear Jugador" << endl;
    cout << " 2.Jugar" << endl;
    cout << " 3.regresar" << endl;
    int op = 0;
    cout << "ingrese un Numero: ";
    cin >> op;
    switch (op - 1) {
    case 0:// new jugador
        system("cls");
        crearJugador();
        menuJuego();
        break;
    case 1:// jugar
        system("cls");
        INICIAR_JUEGO(); 
        break;
    case 2:// regresar
        system("cls");
        menuPrincipal();
        break;

    default:
        system("cls");
        cout << "ERROR OPCION NO VALIDA" << endl;
        menuJuego();
        break;
    }
}

void crearJugador() {
    cout << "Ingresa un nombre: ";
    string nombre = "";
    cin >> nombre;
    Jugador* nuevo_jugador = new Jugador(nombre);
    NodoArbol* nuevo_nodo = new NodoArbol(nuevo_jugador);
    ARBOL_JUGADORES->add(nuevo_nodo);
    cout <<"  \nProceso Realizado... \n";
    system("pause");
    system("cls");
}


void menuReportes() {
    cout << " *******************************" << endl;
    cout << "          MENU REPORTES         " << endl;
    cout << " *******************************" << endl;
    cout << " 1. Palabras de Diccionario" << endl;
    cout << " 2. Cola de fichas" << endl;// solo las disponibles
    cout << " 3. Arbol de Jugadores" << endl;
    cout << " 4. Historial de Puntajes por Jugador"<< endl;
    cout << " 5. Scoreboard" << endl;
    cout << " 6. Matriz Dispersa estado del tablero en memoria" << endl;
    cout << " 7. 2 Listas que contienen a las fichas de los jugadores" << endl; // solo para dos jugadores
    cout << " 8. regresar Menu Principal " << endl;
    cout << " 9. volver al juego " << endl;
    int op = 0;
    cout << "ingrese un Numero: ";
    cin >> op;
    switch (op - 1) {
    case 0:// diccionario 
        system("cls");
        diccionario->getGraphviz();
        menuReportes();
        break;
    case 1:// cola fichas 
        system("cls");
        BOLSA->getGraphviz();
        menuReportes();
        break;
    case 2:// arbol
        system("cls");
        ARBOL_JUGADORES->getGraphviz();
        menuReportes();
        break;
    case 3:// historial de puntajes por jugador
        system("cls");
        break;
    case 4:// Scoreboard
        system("cls");
        break;
    case 5:// Matriz
        system("cls");
        break;
    case 6://2 Listas que contienen a las fichas de los jugadores
        system("cls");
        break;
    case 7: // volver menu principal 
        system("cls");
        menuPrincipal();
        break;
    case 8: // volver al juego 
        system("cls");
        break;
    default:
        system("cls");
        cout << "ERROR OPCION NO VALIDA" << endl;
        menuJuego();
        break;
    }
}


void mezclarFichas_e_ingresar_Cola() {
    BOLSA->vaciar();
    int aleatorio = 0;
    Ficha* temp = new Ficha(0, '0');
    srand(time(NULL));
    for (int i = 1; i < 95; i++)
    {
        aleatorio = rand() % (15 - 0 + 1) + 0;
        if (aleatorio == 0) { // cambia la pos actual con el de en medio 
            temp = fichas[i];
            fichas[i] = fichas[12];
            fichas[12] = temp;
        }
        else if (aleatorio == 1) {
            temp = fichas[i];
            fichas[i] = fichas[24];
            fichas[24] = temp;
        }
        else if (aleatorio == 2) {
            temp = fichas[i];
            fichas[i] = fichas[0];
            fichas[0] = temp;
        }
        else if (aleatorio == 3) {
            temp = fichas[i];
            fichas[i] = fichas[8];
            fichas[8] = temp;
        }
        else if (aleatorio == 4) {
            temp = fichas[i];
            fichas[i] = fichas[7];
            fichas[7] = temp;
        }
        else if (aleatorio == 5) {
            temp = fichas[i];
            fichas[i] = fichas[10];
            fichas[10] = temp;
        }
        else if (aleatorio == 6) {
            temp = fichas[i];
            fichas[i] = fichas[0];
            fichas[0] = temp;
        }
        else if (aleatorio == 7) {
            temp = fichas[i];
            fichas[i] = fichas[40];
            fichas[40] = temp;
        }
        else if (aleatorio == 8) {
            temp = fichas[i];
            fichas[i] = fichas[80];
            fichas[80] = temp;
        }
        else if (aleatorio == 9 ) {
            temp = fichas[i];
            fichas[i] = fichas[85];
            fichas[85] = temp;
        }
        else if (aleatorio == 10) {
            temp = fichas[i];
            fichas[i] = fichas[94];
            fichas[94] = temp;
        }
        else if (aleatorio == 11) {
            temp = fichas[82];
            fichas[82] = fichas[1];
            fichas[1] = temp;
        }
        else if (aleatorio == 12) {
            temp = fichas[i];
            fichas[i] = fichas[1];
            fichas[1] = temp;
        }
        else if (aleatorio == 13) {
            temp = fichas[3];
            fichas[3] = fichas[45];
            fichas[45] = temp;
        }
        else if (aleatorio == 14) {
            temp = fichas[i];
            fichas[i] = fichas[45];
            fichas[45] = temp;
        }
        else if (aleatorio == 15) {
            temp = fichas[15];
            fichas[15] = fichas[i];
            fichas[i] = temp;
        }
    }

    for (int i = 0; i < 95; i++)
    {
        BOLSA->encolar(fichas[i]);
    }
}

void extraerDatos(string nombre_de_archivo) {
    diccionario->vaciar();
    std::ifstream file(nombre_de_archivo);
    file >> Todo_el_juego;
    cout << "se esta extrayendo datos del archivo:  \n \n" << endl;
    json_dimension = Todo_el_juego["dimension"];

    //extrae las dimensiones del tablero
    tamanio_tablero = json_dimension;// guarda mi tamaño del tablero
    TABLERO->setTamanioMaximo(tamanio_tablero);
    cout << "DIMENSION: " << tamanio_tablero << "\n";
    casillas_dobles = Todo_el_juego["casillas"]["dobles"];
    //extrae las pos dobles del json 
    cout << "COORDENADAS DOBLES \n";
    for (const auto cordenada : casillas_dobles) {
        posX = cordenada["x"];
        posY = cordenada["y"];
        cout << "Punto (" << posX << "," << posY << ")" << endl;
        TABLERO->getLista_Casillas().add(new Casilla(posX , posY , 2));
    }
    tripleJs = Todo_el_juego["casillas"]["triples"];
    cout << "COORDENADAS TRIPLES" << endl;
    for (const auto cordenada : tripleJs) {
        posX = cordenada["x"];
        posY = cordenada["y"];
        cout << "Punto (" << posX << "," << posY << ")" << endl;
        TABLERO->getLista_Casillas().add(new Casilla(posX, posY, 3));
    }
    JsonPalabras_diccionario = Todo_el_juego["diccionario"];
    cout << "PALABRAS QUE INGRESARAN AL DICCIONARIO:" << endl;
    for (const auto informacion : JsonPalabras_diccionario) {
        cout << "{" << informacion["palabra"] <<"}\n";
        diccionario->add(informacion["palabra"]);
    }
    TABLERO->getLista_Casillas().imprimir();
    cout << "\n \n Se termino de leer el Archivo...  \n \n" << endl;
    system("pause");
    system("cls");
}


//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||| LOGICA DEL JUEGO |||||||||||||||||||||||||||||||||||||||||||||

Jugador* jugadoresActuales[2];
void INICIAR_JUEGO() {
   
        limipiarJugadoresActuales();
        ARBOL_JUGADORES->recorrido_inOrder();
        llenarJugadoresActuales();
        int respuesta = escogerQuienVaPrimero(); cout <<" \n";
        system("pause");
        system("cls");
        bool ciclo = true;
        do {     // ahora imprimo la lista del diccionario y el contador de puntos del jugador 
            diccionario->imprimeparaAdelnate();
        if (respuesta == 0) { 
            respuesta = 1;// cambia turno
            realizarJugada(0);// JUGADOR 1
        }
        else {
            respuesta = 0;// cambia turno
            realizarJugada(1);// JUGADOR 2 
        }
        system("pause");
        } while (ciclo);
}
int escogerQuienVaPrimero() {
    // 0 = primero jugador  1 = segundo jugador 
    cout << "FICHA DEL JUGADOR 1 : ";
    Ficha* letra1 = BOLSA->getCabeza()->getFicha();
    BOLSA->desencolar();
    cout << letra1->getLetra()<<endl;
    cout << "FICHA DEL JUGADOR 2 : ";
    Ficha* letra2 = BOLSA->getCabeza()->getFicha();
    BOLSA->desencolar();
    cout << letra2->getLetra() << endl;
    if (letra1->getLetra() == letra2->getLetra()) {
        cout << "repetidas se vuelve a sacar 2 fichas de la bolsa\n";
        return escogerQuienVaPrimero();
    }
    else {
        if (letra1->getLetra() < letra2->getLetra()) {
            cout << "el jugador 1 comienza" << endl; 
            return 0;
        }
        else {
            cout << "el jugador 2 comienza" << endl;
            return 1;
        }
    }
    
}
void limipiarJugadoresActuales() {
    for (int i = 0; i < 2; i++)
    {
        jugadoresActuales[i] = NULL;
    }
}
void llenarJugadoresActuales() {
    string nomBuscar = "";
    for (int i = 0; i < 2; i++)
    {
        cout << "\nselecciona Jugador" << (i + 1) << ":" << endl;
        cin >> nomBuscar;
        jugadoresActuales[i] = ARBOL_JUGADORES->buscar(nomBuscar);
    }
}