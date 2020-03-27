#pragma once
#include<iostream>
#include"Casilla.h"
using namespace std; 
class nodoT {
public:
	nodoT* sig; 
	Casilla*casilla;

	nodoT() {
		this->sig = NULL;
		this->casilla = NULL;
	}
	nodoT(Casilla* ca) {
		this->sig = NULL;
		this->casilla = ca;
	}
};