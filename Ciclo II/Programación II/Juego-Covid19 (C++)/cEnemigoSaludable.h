#pragma once
#include "Bibliotecas.h"

class cEnemigoSaludable : public cEnemigo {
public:
	cEnemigoSaludable(int _x, int _y, int _dx, int _dy, int _tipo) :
		cEnemigo(_x, _y, _dx, _dy, _tipo){}
	~cEnemigoSaludable(){}

	void dibujar(BufferedGraphics^ buffer, Bitmap^ b, Bitmap^ saludable, Bitmap^ asintomatico, int nivel) {

		if (colision_Enemigo_Pared(Direccion, x, y, nivel) == true) {
			dx *= -1;
		}
		if (colision_Enemigo_Pared(Direccion, x, y, nivel) == true) {
			dy *= -1;
		}

		if (colision == false) {

			Rectangle PorcionVisible = Rectangle(ancho * indicex, alto * indicey, ancho, alto);
			Rectangle aumento = Rectangle(x, y, ancho * 0.85, alto * 0.85);
			buffer->Graphics->DrawImage(b, aumento, PorcionVisible, GraphicsUnit::Pixel);
		}
		else {
			Rectangle PorcionVisible = Rectangle(ancho * indicex, alto * indicey, ancho, alto);
			Rectangle aumento = Rectangle(x, y, ancho * 0.85, alto * 0.85);
			buffer->Graphics->DrawImage(saludable, aumento, PorcionVisible, GraphicsUnit::Pixel);
		}

		x += dx;
		y += dy;
	}
};