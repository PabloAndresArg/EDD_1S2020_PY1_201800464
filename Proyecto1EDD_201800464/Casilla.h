#pragma once


class Casilla{
	public: 
		// tipo 2 doble tipo 3 triple
		int posX;
		int posY; 
		int tipo;
		Casilla(int x , int y , int t) {
			this->posX = x; 
			this->posY = y; 
			this->tipo = t;
		}
};