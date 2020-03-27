#pragma once
#include<string>
#include"ListaSimpleOrdenada.h"
#include"ListaDoble.h"
using namespace std;
class Jugador
{
private:
	string nombre; 
	ListaSimpleOrdenada lista_puntajes; 
	ListaDoble lista_fichas;
	int contador;
	// un vector de fichas de 7 como maximo ? o es una lista que se puede expandir hasta n 
public:
	Jugador() { this->nombre = "ERROR ,  NO ENCONTRADO"; };
	Jugador(string nom) { this->nombre = nom; };
	inline string getNombre() { return this->nombre; }; 
	inline void setNombre(string nombre_) { this->nombre = nombre_; };
	inline ListaDoble&  getListaFichas() { return this->lista_fichas; } // ANDPERSON IMPORTANTE..!!!!!!!!!!!!!!!
	inline ListaSimpleOrdenada& getListaPuntajes() { return this->lista_puntajes; }
	inline int getContador() { return this->contador; }
	//void getGraphvizPorJugador(string); // cuando quiera puntaje por jugador , aun no implementado 
};

