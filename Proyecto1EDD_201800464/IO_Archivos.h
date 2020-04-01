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
#include"nMatrix.h"

using namespace std;
class IO_Archivos {
private:

public:
	// IMPRIMIR COLA..!!!!!!!!!
	void GraficaCola(NodoCola* inicio) {
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
						w << "a" << x << "[label = \" " << "Ñ" << " x " << aux->getFicha()->getPuntaje()<<"pts" <<"\" ] ;";
					}
					else {
						char letra = toupper(aux->getFicha()->getLetra());
						w << "a" << x << "[label = \" " << letra << " x " << aux->getFicha()->getPuntaje() <<"pts"<< "\" ] ;";
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

	void PuntajePorJugador(NodoSimple* inicio , string nombreJugador) { // -----------------------para
		system("cls");
		ofstream w;
		w.open("REPORTES\\puntajePorJugador.txt", ios::out);//si no existe lo crea  y si ya lo reemplaza
		if (w.fail()) {
			cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
			system("pause");
			exit(1);
		}
		if (inicio != NULL) {
			w << "digraph G {";
			w << "fontcolor = white; fontsize = \"20\" ; label = \""<<"LISTA PUNTAJES DE: "<< nombreJugador <<"\";";
			w<<"rankdir = LR;charset = latin1; style = filled; bgcolor = black;color = lightgrey;node[style = filled, color = orange, shape = parallelogram];";
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
		system("pause");
		system("cls");
	}
	// graficando el arbol-------------------------------------------------------------------------
	void graficaArbol(string cadenaGraph , NodoSimple* cabezaPre , NodoSimple* cabezaIn , NodoSimple* cabezaPost) {
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
	void Graph_LISTA_DOBLE(NodoD* inicio, NodoD* ultimo , string nombre) {
	
		system("cls");
		if (inicio != NULL) {
		ofstream w;
		w.open("REPORTES\\reporteDobleEnlazada.txt", ios::out);//si no existe lo crea  y si ya lo reemplaza
		if (w.fail()) {
			cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;

			system("pause");
			exit(1);
		}
		
		w << "digraph GraphDOBLE {rankdir = LR;";
		w << " fontcolor = white; fontsize = \"30\";";
		w << "label = \"Lista fichas del usuario:  "+ nombre +"\";";
		w<<"style = filled; charset = latin1; bgcolor = black; color = lightgrey; node[fillcolor = black , fontcolor = white , color = chartreuse1 ,style = filled, shape = component]; ";
			NodoD* aux = new NodoD();
			aux = inicio;
			int x = 1; // porque graph no acepta neg
			while (aux != NULL) {
				// nombre 
				if ((int)aux->getDato()->getLetra() == -92) {
					w << "a" << x << "[label = \" " << "Ñ"<< "\" ] ;";
				}
				else {
					char letra = toupper(aux->getDato()->getLetra());
					w << "a" << x << "[label = \" " << letra << "\" ] ;";
				}

				
				
				
				
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




	void grafica_MATRIX(nMatrix* root) {
		if (root->getDer()== NULL) {
			cout << "MATRIZ VACIA" << endl;
		}
		else {
		ofstream w;
		w.open("REPORTES\\matriz.dot", ios::out);
		if (w.fail())
		{
			cout << "NO SE ABRE :(" << endl;
			system("pause");
			exit(1);
		}
		w << "digraph G {bgcolor = black; \nnode[pin = true , shape = box, fontcolor = black  , fillcolor = gray  , width=0.7 ,style = filled] ;\ncharset = latin1;\n style = filled ;\nnodesep = 1.0;\n";
		nMatrix* aux = root;
		nMatrix* aux2 = NULL;
		while (aux != NULL) {
			if (aux->getDer() != NULL) {
				w << "VAL_" << &*aux << "->" << "VAL_" << &*aux->getDer() << " [ dir=both ,color = white]; " << "\n";
			}
			if (aux->getIzq() != NULL) {
				//w << "VAL_" << &*aux << "->" << "VAL_" << &*aux->getIzq() << " [arrowhead = empty, color = white]; " << "\n";
			}
			if (aux->getDown() != NULL) {
				w << "VAL_" << &*aux << "->" << "VAL_" << &*aux->getDown() << " [  dir=both,  color = white]; " << "\n";
			}
			if (aux->getUp() != NULL) {
				//w << "VAL_" << &*aux << "->" << "VAL_" << &*aux->getUp() << " [arrowhead = empty, color = white]; " << "\n";
			}
			// nomnbre-----------------------------------------------------------
			if (aux != root && aux->getPos_x() == -1) {
				w << "VAL_" << &*aux << "[label=\"" << aux->getLetra() << to_string(aux->getPos_y()) << "\" , group = " << to_string(aux->getPos_x()) << ",pos = \"" << to_string(aux->getPos_x()) << "," << to_string((-1) * (aux->getPos_y())) << "\" ];\n";
			}
			else {
				w << "VAL_" << &*aux << "[label = \"ROOT\", group = " << to_string(aux->getPos_x()) << ",pos = \"" << to_string(aux->getPos_x()) << "," << to_string((-1) * (aux->getPos_y())) << "\" ];\n";
			}
			if (aux->getDer() != NULL)
			{
				aux2 = aux->getDer();
				while (aux2 != NULL)
				{
					if (aux2->getDer() != NULL) {
						w << "VAL_" << &*aux2 << "->" << "VAL_" << &*aux2->getDer() << " [ dir=both, color = white]; " << "\n";
					}
					if (aux2->getIzq() != NULL) {
					//	w << "VAL_" << &*aux2 << "->" << "VAL_" << &*aux2->getIzq() << " [arrowhead = empty, color = white]; " << "\n";
					}
					if (aux2->getDown() != NULL) {
						w << "VAL_" << &*aux2 << "->" << "VAL_" << &*aux2->getDown() << " [ dir=both, color = white]; " << "\n";
					}
					if (aux2->getUp() != NULL) {
					//	w << "VAL_" << &*aux2 << "->" << "VAL_" << &*aux2->getUp() << " [arrowhead = empty, color = white]; " << "\n";
					}
					//-------------------------------------------- NOMBRES
					if (aux2->getPos_y() == -1) {// si mi pos en x es negativa en y si voy a tener 
						w << "VAL_" << &*aux2 << "[label=\"" << aux2->getLetra() << to_string(aux2->getPos_x()) << "\", group = " << to_string(aux2->getPos_x()) << ",pos = \"" << to_string(aux2->getPos_x()) << "," << to_string((-1) * (aux2->getPos_y())) << "\" ];\n";
					}
					else {
						if ((int)aux2->getLetra() == -92) {
							w << "VAL_" << &*aux2 << "[ label = \"" <<"Ñ"<< "\" , fillcolor = chartreuse1, group = " << to_string(aux2->getPos_x()) << ",pos = \"" << to_string(aux2->getPos_x()) << "," << to_string((-1) * (aux2->getPos_y())) << "\" ];\n";
						}
						else if (aux2->getLetra() == '3') {// triples 
							w << "VAL_" << &*aux2 << "[ label = \"" << " x3 " << "\"  ,fillcolor = gold1, group = " << to_string(aux2->getPos_x()) << ",pos = \"" << to_string(aux2->getPos_x()) << "," << to_string((-1) * (aux2->getPos_y())) << "\" ];\n";
						}
						else if (aux2->getLetra() == '2') {// dobles
							w << "VAL_" << &*aux2 << "[ label = \"" << " x2 " << "\" ,fillcolor = dodgerblue1, group = " << to_string(aux2->getPos_x()) << ",pos = \"" << to_string(aux2->getPos_x()) << "," << to_string((-1) * (aux2->getPos_y())) << "\" ];\n";
						}
						else {
							char letra = toupper(aux2->getLetra());
							w << "VAL_" << &*aux2 << "[ label = \"" << letra << "\" ,dir=both ,fillcolor = chartreuse1, group = " << to_string(aux2->getPos_x()) << ",pos = \"" << to_string(aux2->getPos_x()) << "," << to_string((-1) * (aux2->getPos_y())) << "\" ];\n";
						}

						
					}
					aux2 = aux2->getDer();
				}
			}
			aux = aux->getDown();
		}


		// rank
		aux = root;
		aux2 = NULL;
		while (aux != NULL) {
			w << "{rank = same; ";
			w << "VAL_" << &*aux << " ";
			if (aux->getDer() != NULL)
			{
				aux2 = aux->getDer();
				while (aux2 != NULL)
				{
					w << "VAL_" << &*aux2 << " ";
					aux2 = aux2->getDer();
				}
			}
			w << "};\n\n";
			aux = aux->getDown();
		}

		w << "}\n";
		w.close();
		char eje[] = "dot -Tjpg REPORTES\\matriz.dot -o REPORTES\\matriz.jpg";
		system(eje);
		char abre[] = "REPORTES\\matriz.jpg";
		system(abre);
	  }
	 }
	 







	void graph_winner(string nombre) {

		system("cls");

		ofstream w;
		w.open("REPORTES\\winner.txt", ios::out);//si no existe lo crea  y si ya lo reemplaza
		if (w.fail()) {
			cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;

			system("pause");
			exit(1);


			w << "digraph winner{";
			w << " fontcolor = white; fontsize = \"30\";";
			w << "label = \"Lista fichas del usuario:  " + nombre + "\";";
			w << "style = filled; charset = latin1; bgcolor = black; color = lightgrey; node[fillcolor = black , fontcolor = white , color = chartreuse1 ,style = filled,penwidth = 0.8 , color = gold1 , shape = signature]; ";
			w << " fontcolor = white;";
			w << "fontsize = \"30\";";
			w <<"label = \"JUGADOR VICTORIOSO \";";
			w<<"a1[label = \"" <<nombre<<"\"]";
			w << "}";
			w.close();
			char genera[] = "dot -Tjpg REPORTES\\winner.txt -o REPORTES\\winner.jpg";// usando el prueba par mientrasr 
			system(genera);
			char ejecuta[] = "REPORTES\\winner.jpg";
			system(ejecuta);
			cin.get();
		}

	}
















};