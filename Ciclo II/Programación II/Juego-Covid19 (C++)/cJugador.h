#pragma once
#include "Bibliotecas.h"

class cJugador {
private:
	int x;
	int y;
	int dx;
	int dy;
	int ancho;
	int alto;
	int indicex;
	int indicey;
	int puntos;
	int vidas;
	int maxVidas;
	direccion Direccion;
	direccion ultima;
public:
	cJugador(int _x, int _y) {
		x = _x;
		y = _y;
		dx = 0;
		dy = 0;
		ancho = 0;
		alto = 0;
		indicex = 0;
		indicey = 0;
		Direccion = ninguna;
		ultima = abajo;
		puntos = 0;
		maxVidas = 0;
		vidas = 0;
		
	}
	~cJugador() {}

	int getPuntuacion() { return puntos; }
	int getVidas() { return vidas; }
	int getX() { return x; }
	int getY() { return y; }

	void subirPuntos() { puntos += 10; }
	void bajarVida() { vidas--; }

	void setDireccion(direccion d) { Direccion = d; }
	void setPuntuacion(short p) { puntos = p; }
	void setJugadorX(int _x) { x = _x; }
	void setJugadorY(int _y) { y = _y; }
	void setVidas(int _v) { 
		maxVidas = _v;
		vidas = _v;
	}

	void dibujar(BufferedGraphics^ buffer, Bitmap^ sano, Bitmap^ enfermo1, Bitmap^ enfermo2, Bitmap^ enfermo3) {
		
		Rectangle PorcionVisible = Rectangle(ancho * indicex, alto * indicey, ancho, alto);
		Rectangle aumento = Rectangle(x, y, ancho * 0.85, alto * 0.85);
		if (vidas == maxVidas) {
			buffer->Graphics->DrawImage(sano, aumento, PorcionVisible, GraphicsUnit::Pixel);
		}
		else if (vidas > (maxVidas * 2) / 3) {
			buffer->Graphics->DrawImage(enfermo1, aumento, PorcionVisible, GraphicsUnit::Pixel);
		}
		else if (vidas > maxVidas / 3) {
			buffer->Graphics->DrawImage(enfermo2, aumento, PorcionVisible, GraphicsUnit::Pixel);
		}
		else {
			buffer->Graphics->DrawImage(enfermo3, aumento, PorcionVisible, GraphicsUnit::Pixel);
		}

		x += dx;
		y += dy;
	}

	void mover(BufferedGraphics^ buffer, Bitmap^ sano, int nivel, Bitmap^ enfermo1, Bitmap^ enfermo2, Bitmap^ enfermo3) {
		ancho = sano->Width / 3;
		alto = sano->Height / 4;

		if (indicex < 2) indicex++;
		else indicex = 0;

		switch (Direccion) {
		case arriba: indicey = 3;

			if (colision_Jugador_Pared(Direccion, x, y, nivel) == true) {
				dx = 0;
				dy = 0;
			}
			else {
				dx = 0;
				dy = -8;
			}

			ultima = arriba;
			break;
			break;
		case abajo: indicey = 0;

			if (colision_Jugador_Pared(Direccion, x, y, nivel) == true) {
				dx = 0;
				dy = 0;
			}
			else {
				dx = 0;
				dy = 8;
			}

			ultima = abajo;
			break;
		case izquierda: indicey = 1;

			if (colision_Jugador_Pared(Direccion, x, y, nivel) == true) {
				dx = 0;
				dy = 0;
			}
			else {
				dx = -8;
				dy = 0;
			}

			ultima = izquierda;
			break;
		case derecha: indicey = 2;

			if (colision_Jugador_Pared(Direccion, x, y, nivel) == true) {
				dx = 0;
				dy = 0;
			}
			else {
				dx = 8;
				dy = 0;
			}

			ultima = derecha;
			break;
		case ninguna:
			dx = 0;
			dy = 0;
			if (ultima == arriba) {
				indicex = 1;
				indicey = 3;
			}
			else if (ultima == abajo) {
				indicex = 1;
				indicey = 0;
			}
			else if (ultima == izquierda) {
				indicex = 1;
				indicey = 1;
			}
			else if (ultima == derecha) {
				indicex = 1;
				indicey = 2;
			}
			break;
		}
		dibujar(buffer, sano, enfermo1, enfermo2, enfermo3);

	}

	void disparoJugador(BufferedGraphics^ buffer, Bitmap^ bH, Bitmap^ bV, cArregloBala* arrBalaJugador) {
		for (short i = 0; i < arrBalaJugador->getCantidad(); i++) {
			arrBalaJugador->getArreglo()[i]->mover(buffer, bH, bV);
		}
	}

	void EliminarBala(cArregloBala* arrBalaJugador, int nivel) {
		for (short i = 0; i < arrBalaJugador->getCantidad(); i++) {
			if (colision_BalaJugador_Pared(arrBalaJugador->getArreglo()[i]->getDireccionBala(), arrBalaJugador->getArreglo()[i]->getBalaX(), arrBalaJugador->getArreglo()[i]->getBalaY(), nivel) == true) {
				arrBalaJugador->eliminarBala(i);
			}
		}
	}

	void agregarBalaJugador(cArregloBala* arrBalaJugador) {
		short i = rand() % (4 - 0) + 0;
		cBala* BalaJugador = new cBala(x, y, i, ultima);
		arrBalaJugador->registrarBala(BalaJugador);
	}


};
