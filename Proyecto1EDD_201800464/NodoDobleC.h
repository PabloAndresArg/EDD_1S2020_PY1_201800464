#pragma once
#include<iostream>
#include<string>
using namespace std; 
class NodoDobleC {
public:
	string dato;
	NodoDobleC* ant;
	NodoDobleC* sig;
	NodoDobleC() { this->ant = NULL; this->sig = NULL; }
};