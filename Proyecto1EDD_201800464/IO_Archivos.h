#pragma once
#pragma once
#include<iostream>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<fstream>
#include"NodoSimple.h"
using namespace std;
class IO_Archivos {
private:

public:
	void PuntajePorJugador(NodoSimple* inicio) { // -----------------------para
		system("cls");
		system("color 9");
		ofstream w;
		w.open("REPORTES\\puntajePorJugador.txt", ios::out);//si no existe lo crea  y si ya lo reemplaza
		if (w.fail()) {
			cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
			system("pause");
			exit(1);
		}
		if (inicio != NULL) {
			w << "digraph G {rankdir = LR; style = filled; bgcolor = black;color = lightgrey;node[style = filled, color = orange, shape = parallelogram];";
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
};