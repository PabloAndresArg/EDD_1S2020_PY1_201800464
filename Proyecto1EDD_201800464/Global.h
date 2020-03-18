#pragma once
#include<string>
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
using namespace std;

// prototipos
void menuPrincipal();
void llenarFichas();
void menuJuego(); 
void menuReportes();


// estructuras estaticas y arreglos 
Ficha* fichas[25];
void menuPrincipal() {
    llenarFichas();
   /* for (int i = 0; i < 25; i++)
    {
        char mostrar = toupper(fichas[i]->getLetra());
        cout << mostrar << endl;
    }*/
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




void llenarFichas() {
    // de 1 punto 
    Ficha* A = new Ficha(1, 'a', 12);
    fichas[0] = A;
    Ficha* E = new Ficha(1, 'e', 12);
    fichas[1] = E;
    Ficha* O = new Ficha(1, 'o', 9);
    fichas[2] = O;
    Ficha* I = new Ficha(1, 'i', 6);
    fichas[3] = I;
    Ficha* S = new Ficha(1, 's', 6);
    fichas[4] = S;
    Ficha* N = new Ficha(1, 'n', 5);
    fichas[5] = N;
    Ficha* L = new Ficha(1, 'l', 4);
    fichas[6] = L;
    Ficha* R = new Ficha(1, 'r', 5);
    fichas[7] = R;
    Ficha* U = new Ficha(1, 'u', 5);
    fichas[8] = U;
    Ficha* T = new Ficha(1, 't', 4);
    fichas[9] = T;
    // DOS PUNTOS 
    Ficha* D = new Ficha(2, 'd', 5);
    fichas[10] = D;
    Ficha* G = new Ficha(2, 'g', 2);
    fichas[11] = G;
    // 3 PUNTOS 
    Ficha* C = new Ficha(3, 'c', 4);
    fichas[12] = C;
    Ficha* B = new Ficha(3, 'b', 2);
    fichas[13] = B;
    Ficha* M = new Ficha(3, 'm', 2);
    fichas[14] = M;
    Ficha* P = new Ficha(3, 'p', 2);
    fichas[15] = P;
    // 4 PUNTOS
    Ficha* H = new Ficha(4, 'h', 2);
    fichas[16] = H;
    Ficha* F = new Ficha(4, 'f', 1);
    fichas[17] = F;
    Ficha* V = new Ficha(4, 'v', 1);
    fichas[18] = V;
    Ficha* Y = new Ficha(4, 'y', 1);
    fichas[19] = Y;
    // 5 PUNTOS 
    Ficha* Q = new Ficha(5, 'q', 1);
    fichas[20] = Q;
    // 8 PUNTOS 
    Ficha* J = new Ficha(8, 'j', 1);
    fichas[21] = J;
    Ficha* NN = new Ficha(8, char(-92), 1);
    fichas[22] = NN;
    Ficha* X = new Ficha(8, 'x', 1);
    fichas[23] = X;
    // 10 PUNTOS
    Ficha* Z = new Ficha(10, 'z', 1);
    fichas[24] = Z;

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
        menuJuego();
        break;
    case 1:// jugar
        system("cls");
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
        menuJuego();
        break;
    case 1:// cola fichas 
        system("cls");
        break;
    case 2:// arbol
        system("cls");
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