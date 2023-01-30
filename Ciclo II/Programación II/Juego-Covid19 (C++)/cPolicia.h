#pragma once
#pragma once
#include "Bibliotecas.h"

class cPolicia{
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
	cPolicia() {
		x = 832;
		y = 160;
		indicex = 0;
		indicey = 0;
		direccion d = derecha;
	}
	~cPolicia() {}

	int getPoliciaX() { return x; }
	int getPoliciaY() { return y; }

	void setPoliciaX(int _x) { x = _x; }
	void setPoliciaY(int _y) { y = _y; }

	void dibujar(BufferedGraphics^ buffer, Bitmap^ policiaV, Bitmap^ policiaH) {
		if (d == derecha || d == izquierda) {
			ancho = policiaH->Width;
			alto = policiaH->Height / 2;

			Rectangle porcionVisible = Rectangle(ancho * indicex, alto * indicey, ancho, alto);
			Rectangle aumento = Rectangle(x, y, ancho * 2.5, alto * 2.5);

			buffer->Graphics->DrawImage(policiaH, aumento, porcionVisible, GraphicsUnit::Pixel);
		}
		else {
			ancho = policiaH->Width;
			alto = policiaH->Height / 2;

			Rectangle porcionVisible = Rectangle(ancho * indicex, alto * indicey, ancho, alto);
			Rectangle aumento = Rectangle(x, y, ancho * 2.5, alto * 2.5);

			buffer->Graphics->DrawImage(policiaV, aumento, porcionVisible, GraphicsUnit::Pixel);
		}

		x += dx;
		y += dy;
	}

	void mover(cEnemigo* enemigo, BufferedGraphics^ buffer, Bitmap^ policiaV, Bitmap^ policiaH, cLadron* ladron) {
		if (ladron->getColision() == true && ladron->getAtrapado() == false) {
			if (ladron->getX() > x) {
				d = derecha;
				dx = 8;
				indicey = 1;
			}
			else if (ladron->getX() == x) {
				d = derecha;
				dx = 0;
			}
			else {
				d = izquierda;
				dx = -8;
				indicey = 0;
			}
			if (ladron->getY() > y) {
				d = abajo;
				indicey = 0;
				dy = 8;
			}
			else if (ladron->getY() == y) {
				dy = 0;
			}
			else {
				indicey = 0;
				d = arriba;
				dy = -8;
			}
		}
		else {
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
		}


		dibujar(buffer, policiaV, policiaH);
	}

	void moverHelipuerto(BufferedGraphics^ buffer, Bitmap^ policiaV, Bitmap^ policiaH, int nivel) {
		if (nivel % 2 != 0) {
			if (832 > x) {
				d = derecha;
				dx = 8;
				indicey = 1;
			}
			else if (832 == x) {
				d = derecha;
				dx = 0;
			}
			else {
				d = izquierda;
				dx = -8;
				indicey = 0;
			}
			if (160 > y) {
				d = abajo;
				indicey = 0;
				dy = 8;
			}
			else if (160 == y) {
				dy = 0;
			}
			else {
				indicey = 0;
				d = arriba;
				dy = -8;
			}
			if (dx == 0 && dy == 0) {
				indicey = 0;
			}
		}
		else {
			if (160 > x) {
				d = derecha;
				dx = 8;
				indicey = 1;
			}
			else if (160 == x) {
				d = derecha;
				dx = 0;
			}
			else {
				d = izquierda;
				dx = -8;
				indicey = 0;
			}
			if (584 > y) {
				d = abajo;
				indicey = 0;
				dy = 8;
			}
			else if (584 == y) {
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

		dibujar(buffer, policiaV, policiaH);
	}
};