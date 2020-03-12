#pragma once
#include<string>
using namespace std;
class Jugador
{
private:
	string nombre; 
	// lista de puntajrs 

public:
	Jugador(string nom) { this->nombre = nom; };
	inline string getNombre() { return this->nombre; }; 
	//void getGraphvizPorJugador(string);
};

