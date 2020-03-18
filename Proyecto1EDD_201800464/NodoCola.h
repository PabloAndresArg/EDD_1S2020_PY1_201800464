#pragma once
#include<iostream>
#include<string>
#include"Ficha.h"
using namespace std;
class NodoCola {
private:
	Ficha* ficha;
	NodoCola* sig;
public:
	
	NodoCola() { this->sig = NULL;  this->ficha = NULL; }
	NodoCola(Ficha* dato) { this->sig = NULL; this->ficha = dato; }
	inline NodoCola* getSig() {return this->sig ; }
	inline Ficha* getFicha() { return this->ficha; }
	inline void setSig(NodoCola* nuevo) { this->sig = nuevo; }
};
