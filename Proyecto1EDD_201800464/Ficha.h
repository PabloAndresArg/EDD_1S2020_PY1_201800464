#pragma once
class Ficha{
private: 
	int puntaje;
	char letra; 
	int cantidad_de_fichas; 
public: 
	Ficha(int puntaje_, char letra_, int c) { this->puntaje = puntaje_; this->letra = letra_; this->cantidad_de_fichas = c;  }
	inline char getLetra() { return this->letra; }
	inline int getPuntaje() { return this->puntaje; }
	inline int getCantidad_de_fichas() { return this->cantidad_de_fichas; }
	inline void setCantidad_de_fichas(int nueva_cantidad) { this->cantidad_de_fichas = nueva_cantidad; }

};