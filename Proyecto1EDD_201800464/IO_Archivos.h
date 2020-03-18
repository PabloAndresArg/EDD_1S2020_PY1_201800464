#pragma once
#pragma once
#include<iostream>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<fstream>
#include"NodoSimple.h"
#include"NodoDobleC.h"
#include"NodoCola.h"
#include"NodoD.h"
using namespace std;
class IO_Archivos {
private:

public:
	// IMPRIMIR COLA..!!!!!!!!!
	void GraficaCola(NodoCola* inicio) {
			system("cls");
			ofstream w;
			w.open("REPORTES\\cola.txt", ios::out);//si no existe lo crea  y si ya lo reemplaza
			if (w.fail()) {
				cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
				system("pause");
				exit(1);
			}
			if (inicio != NULL) {
				w << "digraph G {graph[nodesep = 0.01];charset = latin1; style = filled; bgcolor = black;color = lightgrey;node[style = filled, color = white, shape = rect];";
				NodoCola* aux = new NodoCola();
				aux = inicio;
				int x = 1; // porque graph no acepta negativos 
				while (aux != NULL) {
					//-91 es Ñ y ñ es -92
				 
					if ((int)aux->getFicha()->getLetra() == -92) {
						w << "a" << x << "[label = \" " << "Ñ" << " x " << aux->getFicha()->getPuntaje()<<"pts"<< " \\n cantidad: "<<aux->getFicha()->getCantidad_de_fichas() <<"\" ] ;";
					}
					else {
						char letra = toupper(aux->getFicha()->getLetra());
						w << "a" << x << "[label = \" " << letra << " x " << aux->getFicha()->getPuntaje() <<"pts"<< " \\n cantidad: " << aux->getFicha()->getCantidad_de_fichas()<< "\" ] ;";
					}
			
				
					x++;
					if (aux->getSig() == NULL) {
					}
					else {
						w << "a" << (x - 1) << " -> " << "a" << x << "[arrowhead = empty color = red]; ";
					}
					aux = aux->getSig();
				}
				w << "}";
				w.close();
				char genera[] = "dot -Tjpg REPORTES\\cola.txt -o REPORTES\\cola.jpg";// usando el prueba par mientrasr 
				system(genera);
				char ejecuta[] = "REPORTES\\cola.jpg";
				system(ejecuta);
				cout << "----- PROCESO TERMINADO CON EXITO ------ " << endl;
				cin.get();
			}
			else {
				cout << "NO GENERA NADA PORQUE LA LISTA ESTA VACIA " << endl;
			}
	}

	void PuntajePorJugador(NodoSimple* inicio) { // -----------------------para
		system("cls");
		ofstream w;
		w.open("REPORTES\\puntajePorJugador.txt", ios::out);//si no existe lo crea  y si ya lo reemplaza
		if (w.fail()) {
			cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
			system("pause");
			exit(1);
		}
		if (inicio != NULL) {
			w << "digraph G {rankdir = LR;charset = latin1; style = filled; bgcolor = black;color = lightgrey;node[style = filled, color = orange, shape = parallelogram];";
			NodoSimple* aux = new NodoSimple();
			aux = inicio;
			w << "NULL1[label = \" " << "NULL" << "\" ] ;";
			int x = 1; // porque graph no acepta negativos 
			while (aux != NULL) {
				w << "a" << x << "[label = \" " << "PUNTAJE: " << aux->getRegistro()->getPuntaje() << "\" ] ;";
				x++;
				if (aux->getSig() == NULL) {
					w << "a" << (x - 1) << " -> " << "NULL1" << "[arrowhead = empty color = gold2]; ";
				}
				else {
					w << "a" << (x - 1) << " -> " << "a" << x << "[arrowhead = empty color = gold2]; ";
				}
				aux = aux->getSig();
			}
			w << "}";
			w.close();
			char genera[] = "dot -Tjpg REPORTES\\puntajePorJugador.txt -o REPORTES\\puntajePorJugador.jpg";// usando el prueba par mientrasr 
			system(genera);
			char ejecuta[] = "REPORTES\\puntajePorJugador.jpg";
			system(ejecuta);
			cout << "----- PROCESO TERMINADO CON EXITO ------ " << endl;
			cin.get();
		}
		else {
			cout << "NO GENERA NADA PORQUE LA LISTA ESTA VACIA " << endl;
		}

	}
	//----- GRADO CIRCULAR DOBLE 
	void DobleCircular(NodoDobleC* inicio, NodoDobleC* ultimo , int tamanio) { // -----------------------para
		system("cls");
		system("color 9");
		ofstream w;
		w.open("REPORTES\\reporteDobleEnlazadaC.txt", ios::out);//si no existe lo crea  y si ya lo reemplaza
		if (w.fail()) {
			cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;

			system("pause");
			exit(1);
		}
		if (inicio != NULL) {
			w << "digraph GraphDOBLE {style = filled;charset = latin1;bgcolor = black;color = lightgrey;node[style = filled, color = dodgerblue, shape = component];";
			NodoDobleC* aux = new NodoDobleC();
			aux = inicio;

			int x = 1; // porque graph no acepta negativos 
			do{
				w << "a" << x << "[label = \" " << aux->dato << "\" ] ;";
				x++;
				if (aux->sig != inicio) { // llevo al ultimo nodo 
					w << "a" << (x - 1) << " -> " << "a" << x << "[ arrowhead = \"empty\"   color = \"green\"]; ";
				}
				aux = aux->sig;
			}while (aux != inicio);
			x--;
			w << "a1" << " -> " << "a" << x << "[ arrowhead = \"empty\"   color = \"green\"]; ";
			w << "a" << x << " -> " << "a1" << "[ arrowhead = \"empty\"   color = \"green\"]; ";


			NodoDobleC* aux2 = new NodoDobleC();
			aux2 = ultimo;
			for (int i = 0; i < tamanio - 1; i++) // estando en el ultimo nodo recorro para atras 
			{
				w << "a" << x << " -> " << "a" << (x - 1) << "[arrowhead = \"empty\" color = \"green\"]; ";
				x--;
				aux2 = aux2->ant;
			}
		


			w << "}";
			w.close();
			char genera[] = "dot -Tjpg REPORTES\\reporteDobleEnlazadaC.txt -o REPORTES\\listaDobleC.jpg";// usando el prueba par mientrasr 
			system(genera);
			char ejecuta[] = "REPORTES\\listaDobleC.jpg";
			system(ejecuta);
			cout << "----- PROCESO TERMINADO CON EXITO ------ " << endl;
			cin.get();
		}
		else {
			cout << "NO GENERA NADA PORQUE LA LISTA ESTA VACIA " << endl;
		}
	}
	// graficando el arbol-------------------------------------------------------------------------
	void graficaArbol(string cadenaGraph , NodoSimple* cabezaPre , NodoSimple* cabezaIn , NodoSimple* cabezaPost) {
		system("color 9");
		ofstream w;
		w.open("REPORTES\\reporteArbol.txt", ios::out);//si no existe lo crea  y si ya lo reemplaza
		if (w.fail()) {
			cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;

			system("pause");
			exit(1);
		}
		if (cadenaGraph.compare("") !=0 ) {
			w << cadenaGraph;
			// preOrder
			w<<"subgraph cluster_0 { style = filled; charset = latin1;color = lightgrey;node[style = filled, color = gold   , shape = tripleoctagon]; label = \"PRE-ORDER\" ;  \n ";
			while (cabezaPre != NULL) {
				w << cabezaPre->getRegistro()->getNombre()<< cabezaPre->getRegistro()->getPuntaje() << "[label = \" " << cabezaPre->getRegistro()->getNombre() << "\" ] ; \n";
				if (cabezaPre->getSig() != NULL) {
					w << cabezaPre->getRegistro()->getNombre() << cabezaPre->getRegistro()->getPuntaje() << "->"<< cabezaPre->getSig()->getRegistro()->getNombre() << cabezaPre->getSig()->getRegistro()->getPuntaje() << "[arrowhead = \"" << "vee" << "\"] ; ";
				}
				cabezaPre = cabezaPre->getSig(); 
			}
			w << "}\n";
			// innorder
			w << "subgraph cluster_1 { style = filled; color = lightgrey;node[style = filled, color = lightskyblue2, shape = tripleoctagon]; label = \"IN-ORDER\" ;  \n ";
			while (cabezaIn != NULL) {
				w << cabezaIn->getRegistro()->getNombre() << cabezaIn->getRegistro()->getPuntaje() << "[label = \" " << cabezaIn->getRegistro()->getNombre() << "\" ] ; \n";
				if (cabezaIn->getSig() != NULL) {
					w << cabezaIn->getRegistro()->getNombre() << cabezaIn->getRegistro()->getPuntaje() << "->" << cabezaIn->getSig()->getRegistro()->getNombre() << cabezaIn->getSig()->getRegistro()->getPuntaje() << "[arrowhead = \"" <<"vee"<<"\"]; ";
				}
				cabezaIn = cabezaIn->getSig();
			}
			w << "}\n";
			// postOder
			w << "subgraph cluster_2 { style = filled; color = lightgrey;node[style = filled, color = orange2, shape = tripleoctagon]; label = \"POST-ORDER\" ;  \n ";
			while (cabezaPost != NULL) {
				w << cabezaPost->getRegistro()->getNombre() << cabezaPost->getRegistro()->getPuntaje() << "[label = \" " << cabezaPost->getRegistro()->getNombre() << "\" ] ; \n";
				if (cabezaPost->getSig() != NULL) {
					w << cabezaPost->getRegistro()->getNombre() << cabezaPost->getRegistro()->getPuntaje() << "->" << cabezaPost->getSig()->getRegistro()->getNombre() << cabezaPost->getSig()->getRegistro()->getPuntaje() << "[arrowhead = \"" << "vee" << "\"] ; ";
				}
				cabezaPost = cabezaPost->getSig();
			}
			w << "}\n";


				
				
			w << "}";
			w.close();
			char genera[] = "dot -Tjpg REPORTES\\reporteArbol.txt -o REPORTES\\reporteArbol.jpg";// usando el prueba par mientrasr 
			system(genera);
			char ejecuta[] = "REPORTES\\reporteArbol.jpg";
			system(ejecuta);
			cout << "----- PROCESO TERMINADO CON EXITO ------ " << endl;
			cin.get();
		}
		else {
			cout << "NO GENERA NADA PORQUE LA LISTA ESTA VACIA " << endl;
		}
	}



	//---------------------------------------- LISTA DOBLE DE FICHAS POR USUARIO 
	void Graph_LISTA_DOBLE(NodoD* inicio, NodoD* ultimo) {
		system("cls");
		ofstream w;
		w.open("REPORTES\\reporteDobleEnlazada.txt", ios::out);//si no existe lo crea  y si ya lo reemplaza
		if (w.fail()) {
			cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;

			system("pause");
			exit(1);
		}
		if (inicio != NULL) {
			w << "digraph GraphDOBLE {rankdir = LR; style = filled; charset = latin1; bgcolor = black;color = lightgrey;node[style = filled, color = dodgerblue, shape = component];";
			NodoD* aux = new NodoD();
			aux = inicio;
			int x = 1; // porque graph no acepta neg
			while (aux != NULL) {
				w << "a" << x << "[label = \" " << aux->getDato()->getLetra() << "\" ] ;";
				x++;
				if (aux->getSig() == NULL) {
					//w << "a" << (x - 1) << " -> " << "NULL2" << "[arrowhead = empty color = gold2]; ";
				}
				else {
					w << "a" << (x - 1) << " -> " << "a" << x << "[ arrowhead = \"empty\"   color = \"gold2\"]; ";
				}
				aux = aux->getSig();
			}
			x--;
			NodoD* aux2 = new NodoD();
			aux2 = ultimo;
			while (aux2 != NULL) {// recordar que ya los declare 
				if (aux2->getAnt() == NULL) {

				}
				else {
					w << "a" << x << " -> " << "a" << (x - 1) << "[arrowhead = \"empty\" color = \"gold2\"]; ";
					x--;
				}
				aux2 = aux2->getAnt();
			}
			w << "}";
			w.close();
			char genera[] = "dot -Tjpg REPORTES\\reporteDobleEnlazada.txt -o REPORTES\\listaDoble.jpg";// usando el prueba par mientrasr 
			system(genera);
			char ejecuta[] = "REPORTES\\listaDoble.jpg";
			system(ejecuta);
			cout << "----- PROCESO TERMINADO CON EXITO ------ " << endl;
			cin.get();
		}
		else {
			cout << "NO GENERA NADA PORQUE LA LISTA ESTA VACIA " << endl;
		}
		
	}













};