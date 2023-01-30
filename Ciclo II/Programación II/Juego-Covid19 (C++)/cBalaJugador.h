#pragma once
#include "Bibliotecas.h"

class cBala {
private:
	int x;
	int y;
	int dx;
	int dy;
	direccion Direccion;
	int alto;
	int ancho;
	int indicex;
	int indicey;
	int a2;
	int aumentox;
	int aumentoy;
public:
	cBala(int _x, int _y, int ix, direccion D) {
		x = _x - 16;
		y = _y;
		Direccion = D;
		dx = 0;
		dy = 0;
		alto = 0;
		ancho = 0;
		indicex = ix;
		indicey = 0;
		a2 = 0;
		aumentox = 0;
		aumentoy = 0;
	}
	~cBala() {}

	int getBalaX() { return x; }
	int getBalaY() { return y; }
	direccion getDireccionBala() { return Direccion; }

	void dibujar(BufferedGraphics^ buffer, Bitmap^ bH, Bitmap^ bV) {
		Rectangle PorcionVisible = Rectangle(ancho * indicex, alto * indicey, ancho, alto);
		Rectangle aumento = Rectangle(x, y, ancho * 0.9, alto * 0.9);

		if (Direccion == arriba || Direccion == abajo) {
			buffer->Graphics->DrawImage(bV, aumento, PorcionVisible, GraphicsUnit::Pixel);
		}
		else {
			buffer->Graphics->DrawImage(bH, aumento, PorcionVisible, GraphicsUnit::Pixel);
		}

		x += dx;
		y += dy;
	}

	void mover(BufferedGraphics^ buffer, Bitmap^ bH, Bitmap^ bV) {
		if (Direccion == arriba) {
			indicey = 0;
			dx = 0;
			dy = -12;
		}
		else if (Direccion == abajo) {
			indicey = 1;
			dx = 0;
			dy = 12;
		}
		else if (Direccion == izquierda) {
			indicey = 1;
			dx = -12;
			dy = 0;
		}
		else if (Direccion == derecha) {
			indicey = 0;
			dx = 12;
			dy = 0;
		}

		if (Direccion == arriba || Direccion == abajo) {
			ancho = bV->Width / 4;
			alto = bV->Height / 2;
		}
		else {
			ancho = bH->Width / 4;
			alto = bH->Height / 2;
		}

		dibujar(buffer, bH, bV);
	}

};