#pragma once
#include<iostream>
#include<string>
using namespace std;
class NodoCola {
public:
	string dato;
	NodoCola* sig;
	NodoCola() { this->sig = NULL; }
};
