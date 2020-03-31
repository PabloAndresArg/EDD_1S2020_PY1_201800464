#pragma once
#include<iostream>
#include<string>

using namespace std;
class nMatrix {
private:
	int pos_x;
	int pos_y;
	nMatrix* izq, *der, *down,*up; 
	char letra;
	bool iSnueva;
public:
	nMatrix() {
		this->up = NULL; this->down = NULL;
		this->izq = NULL; this->der = NULL;	
		this->pos_x = 0;
		this->pos_y = 0;
		this->letra = ' ';
		this->iSnueva = false;
	};

	inline nMatrix( int x_, int y_, char letra_) {// x y
		this->up = NULL; this->down = NULL;
		this->izq = NULL; this->der = NULL;
		this->pos_x = x_;
		this->pos_y = y_;
		this->letra = letra_;
		this->iSnueva = false;
	}; 
	inline void setIs_nueva(bool s) {
		this->iSnueva = s;
	}

	inline nMatrix* getIzq() {
		return this->izq;
	}
	inline nMatrix* getDer() {
		return this->der;
	}

	inline nMatrix* getUp() {
		return this->up;
	}
	inline nMatrix* getDown() {
		return this->down;
	}

	inline void setIzq(nMatrix* izq_) {
		this->izq = izq_;
	}

	inline void setDerecha(nMatrix* der_) {
		this->der = der_;
	}

	inline void setArriba(nMatrix* up_) {
		this->up = up_;
	}

	inline void setAbajo(nMatrix* down_) {
		this->down = down_;
	}

	inline bool getIs_nueva() {
		return this->iSnueva;
	}


	inline void setLetra(char letra_) {
		this->letra = letra_;
	}

	inline int getPos_x() {
		return this->pos_x;
	}

	inline int getPos_y() {
		return this->pos_y;
	}

	inline void setPos_x(int x_) {
		this->pos_x = x_;
	}

	inline void setPos_y(int y_) {
		this->pos_y = y_;
	}

	inline char getLetra() {
		return this->letra;
	}


	
};