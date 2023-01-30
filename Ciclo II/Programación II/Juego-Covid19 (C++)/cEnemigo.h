#pragma once
#include "Bibliotecas.h"

class cEnemigo {
protected:
	int x;
	int y;
	int dx;
	int dy;
	int ancho;
	int alto;
	int indicex;
	int indicey;
	int tipo;
	direccion Direccion;
	bool colision;
	int nbala;
	cArregloBalaEnemigo* arregloBalaEnemigo;
public:
	cEnemigo(int _x, int _y, int _dy, int _dx, int _tipo) {
		x = _x;
		y = _y;
		dx = _dx;
		dy = _dy;
		ancho = 0;
		alto = 0;
		indicex = 0;
		indicey = 0;
		tipo = _tipo;
		direccion Direccion;
		colision = false;
		arregloBalaEnemigo = new cArregloBalaEnemigo;
	}
	~cEnemigo() {}

	int getEnemigoX() { return x; }
	int getEnemigoY() { return y; }
	int getTipo() { return tipo; }
	int getColision() { return colision;}

	virtual void dibujar(BufferedGraphics^ buffer, Bitmap^ normal, Bitmap^ saludable, Bitmap^ asintomatico, int nivel) abstract;

	void setColision(bool _colision) { colision = _colision; }

	void mover(BufferedGraphics^ buffer, Bitmap^ b, Bitmap^ saludable, Bitmap^ asintomatico, int nivel) {
		ancho = b->Width / 3;
		alto = b->Height / 4;

		if (indicex < 2) indicex++;
		else indicex = 0;

		if (dx > 0 && dy == 0) {
			Direccion = derecha;
			indicey = 2;
		}
		else if (dx < 0 && dy == 0) {
			Direccion = izquierda;
			indicey = 1;
		}
		else if (dx == 0 && dy < 0) {
			Direccion = arriba;
			indicey = 3;
		}
		else if (dx == 0 && dy > 0) {
			Direccion = abajo;
			indicey = 0;
		}

		dibujar(buffer, b, saludable, asintomatico, nivel);
	}

	void agregarBalaEnemigo() {
		cBalaEnemigo* BalaEnemigo = new cBalaEnemigo(x - 8, y, Direccion);
		arregloBalaEnemigo->registrarBalaEnemigo(BalaEnemigo);
	}

	bool eliminarEnemigo(vector<cBala*> aux, int c, int& nBala) {
		for (short i = 0; i < c; i++) {
			if (colision_Bala_Enemigo(x, y, aux[i]->getBalaX(), aux[i]->getBalaY(), aux[i]->getDireccionBala()) == true) {
				nBala = i;
				return true;
			}
		}
		return false;
	}


	void enemigoDisparo(BufferedGraphics^ buffer, Bitmap^ virus) {
		for (short i = 0; i < arregloBalaEnemigo->getCantidadBalaEnemigo(); i++) {
			arregloBalaEnemigo->getArregloBalaEnemigo()[i]->mover(buffer, virus);
			
		}
		
	}

	bool eliminarJugador(cJugador* jugador) {
		for (short i = 0; i < arregloBalaEnemigo->getCantidadBalaEnemigo(); i++) {
			if (colision_Bala_Jugador(jugador->getX(), jugador->getY(), arregloBalaEnemigo->getArregloBalaEnemigo()[i]->getBalaEnemigoX(), arregloBalaEnemigo->getArregloBalaEnemigo()[i]->getBalaEnemigoY(), Direccion) == true) {
				arregloBalaEnemigo->eliminarBalaEnemigo(i);
				return true;
			}
		}
		return false;
	}

	void eliminarBalaEnemigo(int nivel) {
		for (short i = 0; i < arregloBalaEnemigo->getCantidadBalaEnemigo(); i++) {
			if (colision_BalaEnemigo_Pared(arregloBalaEnemigo->getArregloBalaEnemigo()[i]->getBalaEnemigoDireccion(), arregloBalaEnemigo->getArregloBalaEnemigo()[i]->getBalaEnemigoX(), arregloBalaEnemigo->getArregloBalaEnemigo()[i]->getBalaEnemigoY(), nivel) == true) {
				arregloBalaEnemigo->eliminarBalaEnemigo(i);
			}
		}
	}
};