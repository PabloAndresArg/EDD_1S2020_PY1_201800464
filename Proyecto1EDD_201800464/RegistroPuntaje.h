#pragma once
#pragma once
#include<string>
using namespace std;
class RegistroPuntaje
{
private: // tiene esos dos atributos para usar esta lista con modo propia de usuarios y modo general de mejor punteo 
	string nombre; 
	int puntaje; 

public:
	RegistroPuntaje(int puntaje_) { this->nombre = ""; this->puntaje = puntaje_; };
	RegistroPuntaje(string nombre_, int puntaje_) { this->nombre = nombre_; this->puntaje = puntaje_; };
	inline string getNombre() { return this->nombre; };
	inline int getPuntaje() { return this->puntaje; };
};
