#pragma once
#include<ctime>
#include<cstdlib>
#include<vector>
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
#include<stdlib.h>
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
// REVISAR EL ARBOL 

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
void menu_dentro_turno();
void terminarJUEGO();
void llenar_atriles_jugador(int posJugador);
void excepcion_centro(int);
void recordar_llenar_Centro_movimiento1();
void encabezado_insertar_juego(int posJugador);
void agregarFichasOriginal(ListaCasillas* casillaTemp);
void regresarFIchas_al_atril_por_mala_jugada(ListaCasillas* casillaTemp , int posJugador);
void reporte_historial_por_jugador();
void prueba_rep();
void arte_ascii();
// estructuras estaticas y arreglos 
Matriz_dispersa* TABLERO = new Matriz_dispersa();
Ficha* fichas[95];
Cola* BOLSA = new Cola();
Arbol* ARBOL_JUGADORES = new Arbol();
ListaDobleCircular* DICCIONARIO = new ListaDobleCircular();
ListaSimpleOrdenada* SCOREBOARD = new ListaSimpleOrdenada();
vector<Casilla*> vector_casillas;

static int cont = 0;



void Leer_Json() {
    cout << "|||| INGRESE LA DIRECCION DEL JSON ||||" << endl;
    cout << "RUTA: ";
    string enrutador = "";//  C:\Users\Pablo\Downloads\Library.json
    cin >> enrutador;
    extraerDatos(enrutador);
}

void menuPrincipal() {
    system("color a");
   // prueba_rep();
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

void prueba_rep() {

    Jugador* pa = new Jugador("pablo");
    Ficha* a = new Ficha(0, 'n');
    Ficha* b = new Ficha(0, 'o');
    Ficha* s = new Ficha(0, 'a');
    Ficha* i = new Ficha(0, 'e');
    Ficha* simon1 = new Ficha(0, 's');
    Ficha* simon2 = new Ficha(0, 'i');
    Ficha* simon3 = new Ficha(0, 'm');
    Ficha* simon4 = new Ficha(0, 'o');
    Ficha* simon5 = new Ficha(0, 'n');
    pa->getListaFichas().add(a);
    pa->getListaFichas().add(b);
    pa->getListaFichas().add(simon1);
    pa->getListaFichas().add(simon2);
    pa->getListaFichas().add(simon3);
    pa->getListaFichas().add(simon4);
    pa->getListaFichas().add(simon5);
    NodoArbol* n = new NodoArbol(pa);
    ARBOL_JUGADORES->add(n);
    Jugador* busque = ARBOL_JUGADORES->buscar("pablo");
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
    ARBOL_JUGADORES->setJugador(busque);

    Jugador* peco = new Jugador("peco");
    NodoArbol* no = new NodoArbol(peco);
    ARBOL_JUGADORES->add(no);
    Jugador* bu2 = ARBOL_JUGADORES->buscar("peco");
    RegistroPuntaje* r1 = new RegistroPuntaje(1000);
    bu2->getListaPuntajes().add(r1);
    RegistroPuntaje* r2 = new RegistroPuntaje(1500);
    bu2->getListaPuntajes().add(r2);
    RegistroPuntaje* r3 = new RegistroPuntaje(3);
    bu2->getListaPuntajes().add(r3);
    ARBOL_JUGADORES->setJugador(bu2);

    Jugador* val = new Jugador("val");
    Ficha* sol1 = new Ficha(0, 's');
    Ficha* sol2 = new Ficha(0, 'o');
    Ficha* sol3 = new Ficha(0, 'l');
    val->getListaFichas().add(s);
    val->getListaFichas().add(i);
    val->getListaFichas().add(a);
    val->getListaFichas().add(b);
    val->getListaFichas().add(sol1);
    val->getListaFichas().add(sol2);
    val->getListaFichas().add(sol3);

    NodoArbol* nod = new NodoArbol(val);
    ARBOL_JUGADORES->add(nod);
    Jugador* bu3 = ARBOL_JUGADORES->buscar("val");
    RegistroPuntaje* r4 = new RegistroPuntaje(2500);
    bu3->getListaPuntajes().add(r4);
    RegistroPuntaje* r5 = new RegistroPuntaje(700);
    bu3->getListaPuntajes().add(r5);
    RegistroPuntaje* r6 = new RegistroPuntaje(80);
    bu3->getListaPuntajes().add(r6);
    ARBOL_JUGADORES->setJugador(bu3);

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
    Ficha* NN = new Ficha(6, 'i'); // quite la ñ por la i ya que no vendra la ñ en el json 
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
    cout <<"\n\n \n\n";
    cout << "                             *******************************" << endl;
    cout << "                             **        USUARIO CREADO      **" << endl;
    cout << "                             *******************************" << endl;
    cout <<"\n\n \n\n";
    cout << "NOTA: si el usuario ya estaba creado no se ingresara al arbol de nuevo...\n";
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
    cout << " 6. regresar Menu Principal " << endl;
    int op = 0;
    cout << "ingrese un Numero: ";
    cin >> op;
    switch (op - 1) {
    case 0:// diccionario 
        system("cls");
        DICCIONARIO->getGraphviz();
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
        reporte_historial_por_jugador();
        system("cls");
        menuReportes();
        break;
    case 4:// Scoreboard
        ARBOL_JUGADORES->getScoreBoard();
        system("cls");
        menuReportes();
        break;
    case 5: // volver menu principal 
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

void reporte_historial_por_jugador() {
    cout << "HISTORIAL DE PUNTAJES POR JUGADOR" << endl;
    if (ARBOL_JUGADORES->getRoot() != NULL) {
        ARBOL_JUGADORES->recorrido_inOrder();
        cout << endl;
    }
    else {
        cout << "NO TIENE JUGADORES CREADOS\n";
    }
    cout << "Ingrese el nombre: " << endl;
    string nombre = ""; 
    cin >> nombre;
    Jugador* temporal = ARBOL_JUGADORES->buscar(nombre);
    if (temporal->getNombre().compare("ERROR") == 0 ) {
        cout << "JUGADOR NO ENCONTRADO" << endl;
    }
    else {
        temporal->getListaPuntajes().getGraphviz_porJugador(temporal->getNombre());
    }
}

void mezclarFichas_e_ingresar_Cola() {
    BOLSA->vaciar();
    int aleatorio = 0;
    Ficha* temp = new Ficha(0, '0');
    srand(time(NULL));
    for (int i = 1; i < 95; i++)
    {
        aleatorio = rand() % (16 - 0 + 1) + 0;
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
        else if (aleatorio == 16) {
            temp = fichas[0];
            fichas[0] = fichas[i];
            fichas[i] = temp;
        }
    }

    for (int i = 0; i < 95; i++) //////////////////////////////////////////////--------------------------------------------
    {
        BOLSA->encolar(fichas[i]);
    }
}

void extraerDatos(string nombre_de_archivo) {
    vector<Casilla*> nuevo;
    vector_casillas = nuevo;
    DICCIONARIO->vaciar();
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
        TABLERO->add('2',posX, posY);
        TABLERO->getLista_Casillas().add(new Casilla(posX , posY , 2));
        vector_casillas.push_back(new Casilla(posX, posY, 2));
    }
    tripleJs = Todo_el_juego["casillas"]["triples"];
    cout << "COORDENADAS TRIPLES" << endl;
    for (const auto cordenada : tripleJs) {
        posX = cordenada["x"];
        posY = cordenada["y"];
        cout << "Punto (" << posX << "," << posY << ")" << endl;
        TABLERO->add('3', posX, posY);
        TABLERO->getLista_Casillas().add(new Casilla(posX, posY, 3));
        vector_casillas.push_back(new Casilla(posX, posY, 3));
    }
    JsonPalabras_diccionario = Todo_el_juego["diccionario"];
    cout << "PALABRAS QUE INGRESARAN AL DICCIONARIO:" << endl;
    for (const auto informacion : JsonPalabras_diccionario) {
        cout << "{" << informacion["palabra"] <<"}\n";
        DICCIONARIO->add(informacion["palabra"]);
    }

    TABLERO->getLista_Casillas().imprimir();
    TABLERO->getGraphviz();
    cout << "\n \n Se termino de leer el Archivo...  \n \n" << endl;
    system("pause");
    system("cls");
}


//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||| LOGICA DEL JUEGO |||||||||||||||||||||||||||||||||||||||||||||


Jugador* jugadoresActuales[2];
Matriz_dispersa* ilusion = new Matriz_dispersa();
bool primerMovimiento = true;
bool CICLO_TODO_EL_JUEGO;


void INICIAR_JUEGO() {
       

        mezclarFichas_e_ingresar_Cola();
        limipiarJugadoresActuales();
        if (ARBOL_JUGADORES->getRoot() != NULL) {
            ARBOL_JUGADORES->recorrido_inOrder();
        }
        else {
            cout << "POR EL MOMENTO NO TIENE JUGADORES CREADOS , LO RETORNAREMOS AL MENU DEL JUEGO DONDE PODRA CREARLOS" << endl; 
            system("pause");
            menuJuego();
            menuPrincipal();
        }
        
        llenarJugadoresActuales();
        int respuesta = escogerQuienVaPrimero(); cout <<" \n\n\n\n\n";
        system("pause");
        system("cls"); 

        CICLO_TODO_EL_JUEGO = true;
        primerMovimiento = true;
        do {     // ahora imprimo la lista del diccionario y el contador de puntos del jugador 
           
        if (respuesta == 0) { 
            system("color 3");
            respuesta = 1;// cambia turno
            realizarJugada(0);// JUGADOR 1
        }
        else {
            system("color e");
            respuesta = 0;// cambia turno
            realizarJugada(1);// JUGADOR 2 
        }

        // preguntar si ya termino el juego para acabarlo
        if (CICLO_TODO_EL_JUEGO == false || BOLSA->getCabeza() == NULL || BOLSA->getTamanio() <= 0 ) {
            CICLO_TODO_EL_JUEGO = false;
            if(BOLSA->getCabeza() == NULL || BOLSA->getTamanio() <= 0){
                cout << "******************************************************************************************************" << endl;
                cout << "                      EL JUEGO FINALIZO PORQUE YA NO HAY FICHAS EN LA COLA " << endl;
                cout << "******************************************************************************************************" << endl;
            }
            terminarJUEGO();
        }

        
        } while (CICLO_TODO_EL_JUEGO);
}
void menu_dentro_turno() {
    cout << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << "                                MENU FUNCIONALIDADES, INGRESE UN NUMERO                                "<<endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << "1. insertar fichas al tablero " << endl;
    cout << "2. Intercambiar fichas (le valdra el turno)" << endl;
    cout << "3. ver reporte de lista Doble de las fichas de los dos jugadores" << endl;
    cout << "4. abandonar la partida " << endl;
}
void terminarJUEGO() {
    // cuando el juego termina se consultan los atriles  y las fichas que hayan se le restan al los puntajes de los jugadores 
    // se registran en las listas personales de puntaje 
    // se determina quien gano 
    // LIMPEAR TODO EL JUEGO  tablero , contadores y lista de fichas por jugador 
    // set en arbol 


    int resultado = 0; 
    int puntos_actuales = jugadoresActuales[0]->getContador();
    resultado = puntos_actuales;
 
    int resultado_2 = 0;
    int puntos_actuales_2 = jugadoresActuales[1]->getContador();
    resultado_2 = puntos_actuales_2;
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    cout << "puntos del jugador " << jugadoresActuales[0]->getNombre() << ": " << resultado << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    cout << "puntos del jugador " << jugadoresActuales[1]->getNombre() << ": " << resultado_2 << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;

    IO_Archivos llama;
    if (resultado > resultado_2) {
        
        llama.graph_winner(jugadoresActuales[0]->getNombre());
        cout << "GANO EL JUGADOR " << jugadoresActuales[0]->getNombre() << endl;
    }
    else if (resultado_2 > resultado) {
        
        llama.graph_winner(jugadoresActuales[1]->getNombre());
        cout << "GANO EL JUGADOR " << jugadoresActuales[1]->getNombre() << endl;
    }
    else {
        cout << "EMPATES";
    }


    if (resultado < 0) {
        cout << "si el retultado es negativo en su registro tendra un  punteo de: 0" << endl;
        resultado = 0;
    }
    if (resultado_2 < 0) {
        cout << "si el retultado 2 es negativo en su registro tendra un  punteo de: 0" << endl;
        resultado_2 = 0; 
    }



    // ver si es menor a cero meto puntos como cero
    RegistroPuntaje* registro1 = new RegistroPuntaje(resultado);
    jugadoresActuales[0]->getListaPuntajes().add(registro1);
    RegistroPuntaje* registro2 = new RegistroPuntaje(resultado_2);
    jugadoresActuales[1]->getListaPuntajes().add(registro2);
    // limpiando 
    jugadoresActuales[0]->getListaFichas().vaciar();
    jugadoresActuales[1]->getListaFichas().vaciar();
    jugadoresActuales[0]->setContador(0);
    jugadoresActuales[1]->setContador(0);
    int tamanioMax = TABLERO->getTamanioMax();
    TABLERO->vaciar();
    TABLERO->setTamanioMaximo(tamanioMax);
    for (Casilla* cass : vector_casillas) {
        int x = cass->posX; 
        int y = cass->posY;
        int tipo = cass->tipo;
        if (tipo == 2) {
            TABLERO->getLista_Casillas().add(new Casilla(x, y, 2));
            TABLERO->add('2',x,y);
        }
        else if (tipo == 3) {
            TABLERO->getLista_Casillas().add(new Casilla(x, y, 3));
            TABLERO->add('3', x, y);
        }
    }
    

    ARBOL_JUGADORES->setJugador(jugadoresActuales[0]);
    ARBOL_JUGADORES->setJugador(jugadoresActuales[1]);
    arte_ascii();
    system("pause");
    system("cls");
}


void realizarJugada(int posJugador) {
    

    if (jugadoresActuales[posJugador]->getListaFichas().getCantidad_fichas() < 7) {
        int veces = 7 - jugadoresActuales[posJugador]->getListaFichas().getCantidad_fichas();
        Ficha* fic = NULL;
        for (int i = 0; i < veces; i++) // recorrer 7 veces le atril 
        {
            if (BOLSA->getCabeza() != NULL) {
                Ficha* fic = BOLSA->getCabeza()->getFicha();
                BOLSA->desencolar();
                jugadoresActuales[posJugador]->getListaFichas().add(fic);
            }
        }cout << endl;
    }
 
        if (jugadoresActuales[posJugador]->getListaFichas().getInicio() == NULL) {
            cout << "ENTRA ACA " << endl;
        }
        else{
            bool turno = true;
            bool primerPalabra;
            ListaCasillas* casillaTemp = new ListaCasillas();
            TABLERO->el_centro_esta_lleno();
            ilusion = TABLERO->clonar(ilusion); // BACKUP
            while (turno) {
                
                // sub-menu  para ver si inserto fichas o si intercambio o si quiero ver el reporte 
                cout << endl;
                cout << "RECORDATORIO: revisa tu lista antes de intentar insertar de lo contrario no podras intercambiar fichas" << endl;
                jugadoresActuales[posJugador]->getListaFichas().imprimir(jugadoresActuales[posJugador]->getNombre());
                menu_dentro_turno();
                int menu_por_turno = 4;
                cin >> menu_por_turno;
                system("cls");
                if (menu_por_turno == 1) { // INSERTAR 
                    bool metiendo_fichas = true;
                    while (metiendo_fichas) {
                        primerPalabra = ilusion->getCentroLLeno();            // solo en la primer palabra viene false , una vez se llena siempre sera TRUE
                        encabezado_insertar_juego(posJugador);
                        cout << "SELECCIONES QUE LETRA VA A INGRESAR" << endl;
                        string aux_lexico = "";
                        char letra = ' ';
                        cin >> letra;
                        if (jugadoresActuales[posJugador]->getListaFichas().existe_en_mi_lista(letra)) {
                            int x, y;
                            cout << "INGRESE LA POSICION X: "; cin >> x; cout << "\n";
                            cout << "INGRESE LA POSICION Y: "; cin >> y;
                            ilusion->add_ilusion(letra, x, y);
                            ilusion->SET_NUEVA(x, y);
                            if (x <ilusion->getTamanioMax() && y < ilusion->getTamanioMax()) {
                                Casilla* cass = new Casilla(x, y, 1);
                                cass->letra = letra;
                                casillaTemp->add(cass);
                                NodoD* eliminar = jugadoresActuales[posJugador]->getListaFichas().buscar(letra);
                                jugadoresActuales[posJugador]->getListaFichas().eliminar(eliminar);
                                ilusion->getGraphviz();
                            }
                           
                            cout << "//////////////////////////////////////////////////////////////////////////////////////////"<<endl;
                            cout << "                                      DESEA TERMINAR SU TURNO?"<<endl;
                            cout<<  "                           PRESIONE 1 para seguir sino presione otro numero" << endl;
                            cout << "/////////////////////////////////////////////////////////////////////////////////////////" << endl;
                            int opcion = 0; cin >> opcion;
                            if (opcion != 1) {

                                metiendo_fichas = false;
                                turno = false;
                                if (ilusion->el_centro_esta_lleno()) {
                                    primerMovimiento = false;
                                    ilusion->extraerCasillasNuevas();      
                                   // ilusion->imprimirVector();
                                    int puntosParaJugador = 0;
                                    bool valida = ilusion->validarPalabra(DICCIONARIO, primerPalabra , puntosParaJugador);
                                    if (valida) {
                                       // cout << "in metodo global : " << puntosParaJugador<<endl;
                                        agregarFichasOriginal(casillaTemp);
                                        jugadoresActuales[posJugador]->setContador(jugadoresActuales[posJugador]->getContador() + puntosParaJugador);
                                    }
                                    else {
                                        regresarFIchas_al_atril_por_mala_jugada(casillaTemp , posJugador);
                                    }
                                    // forme alguna palabra correcta ? si es asi le doy puntos sino paso de turno y retiro lo ingresado
                                    // es vertical o horizontal  caso 1 solo una letra , caso 2 vertical , case 3 horizontal  SI ESTA CORRECTO YA GUARDO EN MI MATRIZ ORIGINAL
                                   
                                
                                    cout << "\n\n" << endl;
                                    system("pause");
                                }
                                else {
                                    regresarFIchas_al_atril_por_mala_jugada(casillaTemp, posJugador);
                                    excepcion_centro(posJugador);
                                }

                            }
                            system("cls");
                        }
                        else {
                            cout << "\n\n*** esa letra NO ESTA EN TU LISTA " << endl;
                            system("PAUSE");
                            system("cls");
                        }

                    }


                } else if (menu_por_turno == 2) { // INTERCAMBIAR 
                    jugadoresActuales[posJugador]->getListaFichas().imprimir(jugadoresActuales[posJugador]->getNombre());
                    cout << "cuantas fichas desea cambiar?" << endl; 
                    int numero_de_fichas_cambiar = 0; 
                    cin >> numero_de_fichas_cambiar; 
                    if (BOLSA->Is_empty() == false) {
                        if (BOLSA->getTamanio() >= numero_de_fichas_cambiar) {
                            for (int z = 0; z < numero_de_fichas_cambiar; z++)
                            {

                                cout << "Seleccione la ficha " << (z + 1) << " que desea sacar por medio de la letra: " << endl;
                                char letra_afuera;
                                cin >> letra_afuera;
                                if (jugadoresActuales[posJugador]->getListaFichas().existe_en_mi_lista(letra_afuera)) {
                                    NodoD* eliminado = jugadoresActuales[posJugador]->getListaFichas().buscar(letra_afuera);
                                    jugadoresActuales[posJugador]->getListaFichas().eliminar(eliminado);
                                }
                                else {
                                    cout << "NO TIENES ESA LETRA EN TU LISTA" << endl;
                                    z--;
                                }
                                jugadoresActuales[posJugador]->getListaFichas().imprimir(jugadoresActuales[posJugador]->getNombre());
                            }

                            turno = false;
                            llenar_atriles_jugador(posJugador);
                            cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°LISTA RESULTANTE CON NUEVAS FICHAS °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
                            jugadoresActuales[posJugador]->getListaFichas().imprimir(jugadoresActuales[posJugador]->getNombre());
                            cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
                        }
                        else {
                            cout << "           *****************************************************************   " << endl;
                            cout << "           *** No es posible cambiar tantas , la bolsa solo cuenta con: "<<BOLSA->getTamanio()<<" ***"<<endl;
                            cout << "           *****************************************************************    " << endl;
                        }
                        

                    }else {
                        cout << "***********************"<< endl;
                        cout << "       BOLSA VACIA     "<< endl;
                        cout << "***********************"<<endl;
                    }
                
                    system("pause");
                    system("cls");

                }else if (menu_por_turno == 3) { // VER REPORTE
                IO_Archivos* archi = new IO_Archivos(); 
                archi->Graph_LISTA_DOBLE(jugadoresActuales[posJugador]->getListaFichas().getInicio() , jugadoresActuales[posJugador]->getListaFichas().getUltimo(), jugadoresActuales[posJugador]->getNombre());
        
                }


                else if (menu_por_turno == 4 ) {// abandonar :'v
                CICLO_TODO_EL_JUEGO = false;
                turno = false;
                system("cls");
                }


                else {
                    cout << "ingreso algo INCORRECTO"<<endl<<endl;
                }
               

            } 
        }
  
}


int escogerQuienVaPrimero() {
    // 0 = primero jugador  1 = segundo jugador 
    cout << endl;
    cout << "FICHA DEL JUGADOR 1 : \n";
    Ficha* letra1 = BOLSA->getCabeza()->getFicha();
    BOLSA->desencolar();
    cout << "*******" << endl;
    cout << "** "<< letra1->getLetra()<<" **" << endl;
    cout << "*******" << endl;
    
    cout << "FICHA DEL JUGADOR 2 : \n";
    Ficha* letra2 = BOLSA->getCabeza()->getFicha();
    BOLSA->desencolar();
    cout << "*******" << endl;
    cout << "** " << letra2->getLetra() << " **" << endl;
    cout << "*******" << endl;

    if (letra1->getLetra() == letra2->getLetra()) {
        cout << "repetidas se vuelve a sacar 2 fichas de la bolsa\n";
        return escogerQuienVaPrimero();
    }
    else {
        if (letra1->getLetra() < letra2->getLetra()) {
            cout << "\n";
            cout << "                             *******************************" << endl;
            cout << "                                     COMIENZA JUGADOR 1     " << endl;
            cout << "                             *******************************" << endl;
            cout << "\n\n";
            return 0;
        }
        else {
            cout << "\n";
            cout << "                             *******************************" << endl;
            cout << "                                     COMIENZA JUGADOR 2     " << endl;
            cout << "                             *******************************" << endl;
            cout << "\n\n ";
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
        Jugador* encontrado = ARBOL_JUGADORES->buscar(nomBuscar);
        if (encontrado->getNombre().compare("ERROR")==0) {
            cout << " USUARIO NO ENCONTRADO , INGRESE UN NOMBRE DE NUEVO "<<endl;
            i--;
        }
        else {
            jugadoresActuales[i] = encontrado;
        }
    }
}

void excepcion_centro(int posJugador_) {
    system("color c");
    cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
    cout << "\n\n                                 EL CENTROOO NO SE LLENOOO        \n" << endl; 
        cout << "PASA DE TURNO..."<<endl;
    cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
   
    system("pause");
    if (posJugador_ == 0) {
        system("color 3");
    }
    else { system("color e");
    }
  
}
void recordar_llenar_Centro_movimiento1() {
    if (primerMovimiento == true) {
        cout << "Como es el primer turno tiene que POR LO MENOS pasar una ficha por el CENTRO..." << endl;
        cout << "POSICION  CENTRO " << " (" << TABLERO->getCentro() << "," << TABLERO->getCentro() << ")\n\n";

    }
}

void llenar_atriles_jugador(int posJugador) {

    if (jugadoresActuales[posJugador]->getListaFichas().getCantidad_fichas() < 7) {
        int veces = 7 - jugadoresActuales[posJugador]->getListaFichas().getCantidad_fichas();
        Ficha* fic = NULL;
        for (int i = 0; i < veces; i++) // recorrer 7 veces le atril 
        {
            if (BOLSA->getCabeza() != NULL) {
                Ficha* fic = BOLSA->getCabeza()->getFicha();
                BOLSA->desencolar();
                jugadoresActuales[posJugador]->getListaFichas().add(fic);
            }
        }cout << endl;
    }
}


void encabezado_insertar_juego(int posJugador) {
    recordar_llenar_Centro_movimiento1();
    DICCIONARIO->imprimeparaAdelnate(); cout << "\n";
    cout << "Cantidad de Fichas en la Bolsa: " << BOLSA->getTamanio() << endl;
    cout << "                                                                                                       ===============" << endl;
    cout << "                                                                                                       PUNTAJE: " << jugadoresActuales[posJugador]->getContador()<<endl;
    cout << "                                                                                                       ===============" << endl;
    jugadoresActuales[posJugador]->getListaFichas().imprimir(jugadoresActuales[posJugador]->getNombre());
}

void agregarFichasOriginal(ListaCasillas* casillaTemp) {
    nodoT* aux_casillas = casillaTemp->getUltimo();
    while (aux_casillas != NULL)
    {
        TABLERO->add(aux_casillas->casilla->letra, aux_casillas->casilla->posX, aux_casillas->casilla->posY);
        aux_casillas = aux_casillas->sig;
    }
    
}

void regresarFIchas_al_atril_por_mala_jugada(ListaCasillas* casillaTemp, int posJugador) {
    nodoT* aux_casillas = casillaTemp->getUltimo();
    while (aux_casillas != NULL)
    {
        Ficha* fic = new Ficha(TABLERO->getValor_ficha(aux_casillas->casilla->letra , 1),aux_casillas->casilla->letra);
        jugadoresActuales[posJugador]->getListaFichas().add(fic);
        aux_casillas = aux_casillas->sig;
    }
}

   








void arte_ascii() {
    system("pause"); 
    system("cls");
    cout << "\n\n";

    
    cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
    cout << "°************** ************** ******          ****** **************°" << endl;
    cout << "°**°°°°°°°°°°** **°°°°°°°°°°** **°°**************°°** **°°°°°°°°°°**°" << endl;
    cout << "°**°°********** **°°******°°** **°°°°°°°°°°°°°°°°°°** **°°**********°" << endl;
    cout << "°**°°**         **°°**  **°°** **°°******°°******°°** **°°**        °" << endl;
    cout << "°**°°**         **°°******°°** **°°**  **°°**  **°°** **°°**********°" << endl;
    cout << "°**°°**  ****** **°°°°°°°°°°** **°°**  **°°**  **°°** **°°°°°°°°°°**°" << endl;
    cout << "°**°°**  **°°** **°°******°°** **°°**  ******  **°°** **°°**********°" << endl;
    cout << "°**°°**  **°°** **°°**  **°°** **°°**          **°°** **°°**        °" << endl;
    cout << "°**°°******°°** **°°**  **°°** **°°**          **°°** **°°**********°" << endl;
    cout << "°**°°°°°°°°°°** **°°**  **°°** **°°**          **°°** **°°°°°°°°°°**°" << endl;
    cout << "°************** ******  ****** ******          ****** **************°" << endl;
    cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
    cout << endl;

    cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
    cout << "°**************° ************** *************  ****************  °" << endl;
    cout << "°**          **° **°°  °°  °°** **°°°°°°°°°°** **°°°°°°°°°°°°**  °" << endl;
    cout << "°**  °°°°°°  **° **°°  °°  °°** **°°********** **°°********°°**  °" << endl;
    cout << "°**  °°**°°  **° **°°  °°  °°** **°°**         **°°**    **°°**  °" << endl;
    cout << "°**  °°**°°  **° **°°  °°  °°** **°°********** **°°********°°**  °" << endl;
    cout << "°**  °°**°°  **° **°°  °°  °°** **°°°°°°°°°°** **°°°°°°°°°°°°**  °" << endl;
    cout << "°**  °°**°°  **° **°°  °°  °°** **°°********** **°°******°°****  °" << endl;
    cout << "°**  °°**°°  **° **°°°°  °°°°** **°°**         **°°**  **°°**    °" << endl;
    cout << "°**  °°°°°°  **° ****°°°°°°**** **°°********** **°°**  **°°******°" << endl;
    cout << "°**          **°   ****°°****   **°°°°°°°°°°** **°°**  **°°°°°°**°" << endl;
    cout << "°**************°     ******     ************** ******  **********°" << endl;
    cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
    cout << "\n\n";
    
}