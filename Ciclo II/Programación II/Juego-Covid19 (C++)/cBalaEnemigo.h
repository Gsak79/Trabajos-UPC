#pragma once
#include "Bibliotecas.h"

class cBalaEnemigo {
private:
	int x;
	int y;
	int dx;
	int dy;
	int alto;
	int ancho;
	int indicex;
	int indicey;
	direccion Direccion;
public:
	cBalaEnemigo(int _x, int _y, direccion D) {
		x = _x;
		y = _y;
		dx = 0;
		dy = 0;
		alto = 0;
		ancho = 0;
		indicex = 0;
		indicey = 0;
		Direccion = D;
	}
	~cBalaEnemigo() {}

	int getBalaEnemigoX() { return x; }
	int getBalaEnemigoY() { return y; }
	direccion getBalaEnemigoDireccion() { return Direccion; }

	void dibujar(BufferedGraphics^ buffer, Bitmap^ virus) {
		Rectangle PorcionVisible = Rectangle(ancho * indicex, 0, ancho, alto);
		Rectangle aumento = Rectangle(x, y, ancho * 0.25, alto * 0.25);

		buffer->Graphics->DrawImage(virus, aumento, PorcionVisible, GraphicsUnit::Pixel);

		x += dx;
		y += dy;
	}

	void mover(BufferedGraphics^ buffer, Bitmap^ virus) {

		if (indicex < 3) {
			indicex++;
		}
		else indicex = 0;

		if (Direccion == izquierda) {
			dy = 0;
			dx = -16;
		}
		if (Direccion == derecha) {
			;
			dx = 16;
			dy = 0;
		}
		if (Direccion == arriba) {
			dx = 0;
			dy = -16;
		}
		if (Direccion == abajo) {
			dx = 0;
			dy = 16;
		}

		ancho = virus->Width / 4;
		alto = virus->Height;

		dibujar(buffer, virus);
	}

};