#pragma once
class Ficha{
private: 
	int puntaje;
	char letra; 
public: 
	Ficha(int puntaje_, char letra_) { this->puntaje = puntaje_; this->letra = letra_;  }
	inline char getLetra() { return this->letra; }
	inline int getPuntaje() { return this->puntaje; }

};