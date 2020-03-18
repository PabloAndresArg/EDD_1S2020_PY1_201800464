#pragma once
#include<string>
#include"ListaSimpleOrdenada.h"
using namespace std;
class Jugador
{
private:
	string nombre; 
	ListaSimpleOrdenada lista_puntajes; 

public:
	Jugador() { this->nombre = "ERROR ,  NO ENCONTRADO"; };
	Jugador(string nom) { this->nombre = nom; };
	inline string getNombre() { return this->nombre; }; 
	inline void setNombre(string nombre_) { this->nombre = nombre_; };
	//void getGraphvizPorJugador(string); // cuando quiera puntaje por jugador , aun no implementado 
};

