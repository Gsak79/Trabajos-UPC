#pragma once
#include "Bibliotecas.h"

class cAmbulancia {
private:
	int x;
	int y;
	int dx;
	int dy;
	int ancho;
	int alto;
	int indicex;
	int indicey;
	direccion d;
public:
	cAmbulancia() {
		x = 0;
		y = 520;
		indicex = 0;
		indicey = 0;
		direccion d = derecha;
	}
	~cAmbulancia() {}

	int getAmbulanciaX() { return x; }
	int getAmbulanciaY() { return y; }

	void setAmbulanciaX(int _x) { x = _x; }
	void setAmbulanciaY(int  _y) { y = _y; }

	void dibujar(BufferedGraphics^ buffer, Bitmap^ ambulanciaV, Bitmap^ ambulanciaH) {
		if (d == derecha || d == izquierda) {
			ancho = ambulanciaH->Width;
			alto = ambulanciaH->Height / 2;

			Rectangle porcionVisible = Rectangle(ancho * indicex, alto * indicey, ancho, alto);
			Rectangle aumento = Rectangle(x, y, ancho * 2.5, alto * 2.5);

			buffer->Graphics->DrawImage(ambulanciaH, aumento, porcionVisible, GraphicsUnit::Pixel);
		}
		else {
			ancho = ambulanciaH->Width;
			alto = ambulanciaH->Height / 2;

			Rectangle porcionVisible = Rectangle(ancho * indicex, alto * indicey, ancho, alto);
			Rectangle aumento = Rectangle(x, y, ancho * 2.5, alto * 2.5);

			buffer->Graphics->DrawImage(ambulanciaV, aumento, porcionVisible, GraphicsUnit::Pixel);
		}

		x += dx;
		y += dy;
	}

	void mover(cEnemigo* enemigo, BufferedGraphics^ buffer, Bitmap^ ambulanciaV, Bitmap^ ambulanciaH) {

			if (enemigo->getEnemigoX() > x) {
				d = derecha;
				dx = 8;
				indicey = 1;
			}
			else if (enemigo->getEnemigoX() == x) {
				d = derecha;
				dx = 0;
			}
			else {
				d = izquierda;
				dx = -8;
				indicey = 0;
			}
			if (enemigo->getEnemigoY() > y) {
				d = abajo;
				indicey = 0;
				dy = 8;
			}
			else if (enemigo->getEnemigoY() == y) {
				dy = 0;
			}
			else {
				indicey = 0;
				d = arriba;
				dy = -8;
			}
		

		dibujar(buffer, ambulanciaV, ambulanciaH);
	}

	void moverHelipuerto(BufferedGraphics^ buffer, Bitmap^ ambulanciaV, Bitmap^ ambulanciaH, int nivel) {
		if (nivel % 2 != 0) {
			if (0 > x) {
				d = derecha;
				dx = 8;
				indicey = 1;
			}
			else if (0 == x) {
				d = derecha;
				dx = 0;
			}
			else {
				d = izquierda;
				dx = -8;
				indicey = 0;
			}
			if (520 > y) {
				d = abajo;
				indicey = 0;
				dy = 8;
			}
			else if (520 == y) {
				dy = 0;
			}
			else {
				indicey = 0;
				d = arriba;
				dy = -8;
			}
			if (dx == 0 && dy == 0) {
				indicey = 1;
			}
		}
		else {
			if (128 > x) {
				d = derecha;
				dx = 8;
				indicey = 1;
			}
			else if (128 == x) {
				d = derecha;
				dx = 0;
			}
			else {
				d = izquierda;
				dx = -8;
				indicey = 0;
			}
			if (176 > y) {
				d = abajo;
				indicey = 0;
				dy = 8;
			}
			else if (176 == y) {
				dy = 0;
			}
			else {
				indicey = 0;
				d = arriba;
				dy = -8;
			}
			if (dx == 0 && dy == 0) {
				indicey = 1;
			}
		}

		dibujar(buffer, ambulanciaV, ambulanciaH);
	}




};