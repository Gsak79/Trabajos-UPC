#pragma once
#include "Bibliotecas.h"

class cLadron {
private:
	int x;
	int y;
	int dx;
	int dy;
	int ancho;
	int alto;
	int indicex;
	int indicey;
	bool colision;
	bool atrapado;
	direccion d;
public:
	cLadron(int _x, int _y) {
		x = _x;
		y = _y;
		indicex = 0;
		colision = false;
		atrapado = false;
	}
	~cLadron() {}

	int getX() { return x; }
	int getY() { return y; }

	void setColision(bool c) { colision = c; }
	void setAtrapado(bool a) { atrapado = a; }

	bool getColision() { return colision; }
	bool getAtrapado() { return atrapado; }

	int getdx() { return dx; }
	int getdy() { return dy; }

	void setY(int _y) { y = _y; }
	void setX(int _x) { x = _x; }

	void dibujar(BufferedGraphics^ buffer, Bitmap^ ladron, Bitmap^ atrapado) {
		ancho = ladron->Width / 3;
		alto = ladron->Height / 4;

		if (colision == true) {
			dx = 0;
			dy = 0;
			indicey = 2;
			indicex = 1;
		}

		Rectangle porcionVisible = Rectangle(ancho * indicex, alto * indicey, ancho, alto);
		Rectangle aumento = Rectangle(x, y, ancho * 0.8, alto * 0.8);

		if (colision == true) {
			dx = 0;
			dy = 0;
			buffer->Graphics->DrawImage(atrapado, aumento, porcionVisible, GraphicsUnit::Pixel);
		}
		else {
			buffer->Graphics->DrawImage(ladron, aumento, porcionVisible, GraphicsUnit::Pixel);
		}

		x += dx;
		y += dy;
	}

	void mover(BufferedGraphics^ buffer, Bitmap^ ladron, Bitmap^ atrapado, int jx, int jy) {
		if (indicex < 2) indicex++;
		else indicex = 0;

		if (jx > x) {
			d = derecha;
			dx = 8;
			indicey = 2;
		}
		else if (jx == x) {
			d = derecha;
			dx = 0;
		}
		else {
			d = izquierda;
			dx = -8;
			indicey = 1;
		}
		if (jy > y) {
			d = abajo;
			indicey = 0;
			dy = 8;
		}
		else if (jy == y) {
			dy = 0;
		}
		else {
			indicey = 3;
			d = arriba;
			dy = -8;
		}

		dibujar(buffer, ladron, atrapado);
	}

	void regresar(BufferedGraphics^ buffer, Bitmap^ ladron, Bitmap^ atrapado) {
		if (8 > x) {
			d = derecha;
			dx = 16;
			indicey = 2;
		}
		else if (8 == x) {
			d = derecha;
			dx = 0;
		}
		else {
			d = izquierda;
			dx = -16;
			indicey = 1;
		}
		if (8 > y) {
			d = abajo;
			indicey = 0;
			dy = 16;
		}
		else if (8 == y) {
			dy = 0;
		}
		else {
			indicey = 1;
			d = arriba;
			dy = -16;
		}
		if (dx != 0 && dy != 0) {
			dibujar(buffer, ladron, atrapado);
		}
	}

};

