#pragma once
#include <iostream>
#include <conio.h>
#include "auxiliar.h"
using namespace std;
using namespace System;

typedef struct nave {
	int x, y, vidas = 4, puntuacion = 0, nivel = 1;
public:
	nave(int _x, int _y) {
		x = _x;
		y = _y;

	}
	void AnimarNave(char direccion) {
		BorrarNave();
		MoverNave(direccion);
		DibujarNave();
	}
	void BorrarNave() {
		Console::SetCursorPosition(x, y); cout << "  ";
		Console::SetCursorPosition(x, y + 1); cout << "   ";
		Console::SetCursorPosition(x, y + 2); cout << "    ";
	}
	void MoverNave(char direccion) {
		switch (direccion) {
		case IZQUIERDA: if (x > 2) x--; break;
		case DERECHA: if (x < 54) x++; break;
		}
	}
	void DibujarNave() {
		colorearCaracter(Azul);
		Console::SetCursorPosition(x, y); cout << " A";
		Console::SetCursorPosition(x, y + 1); cout << "/+\\";
		Console::SetCursorPosition(x, y + 2); cout << "%%%";
		colorearCaracter(Blanco);
	}
};
typedef struct mariposa {
	int x = 4 + rand() % (53 - 4);
	int y = 7 + rand() % (20 - 7);
	int dx = 1, dy = 1;
public:

	void AnimarMariposa() {
		BorrarMariposa();
		MoverMariposa();
		DibujarMariposa();

	}
	void BorrarMariposa() {
		Console::SetCursorPosition(x, y); cout << "   ";
	}
	void MoverMariposa() {
		if (x < 3) dx *= -1;
		if (x > 53) dx *= -1;
		if (y < 6) dy *= -1;
		if (y > 31) dy *= -1;

		x += dx;
		y += dy;
	}
	void DibujarMariposa() {
		colorearCaracter(Rojo);
		Console::SetCursorPosition(x, y); cout << ">|<";
		colorearCaracter(Blanco);
	}
	bool ChoqueMariposa(int X, int Y) {
		if (x == X + 1 && y == Y || x + 1 == X + 1 && y == Y || x + 2 == X + 1 && y == Y) {
			return true;
		}
		return false;
	}
};
typedef struct avispa {
	int x = 7 + rand() % (50 - 7);
	int y = 7 + rand() % (20 - 7);
	int dx = 1, dy = 1;
public:

	void AnimarAvispa() {
		BorrarAvispa();
		MoverAvispa();
		DibujarAvispa();

	}
	void BorrarAvispa() {
		Console::SetCursorPosition(x, y); cout << "   ";
	}
	void MoverAvispa() {
		if (x < 6) dx *= -1;
		if (x > 50) dx *= -1;
		if (y < 6) dy *= -1;
		if (y > 31) dy *= -1;

		if (y == 30 || y == 7) x += dx * 2;
		y += dy;
	}

	void DibujarAvispa() {
		colorearCaracter(Amarillo);
		Console::SetCursorPosition(x, y); cout << "-#-";
		colorearCaracter(Blanco);
	}
	bool ChoqueAvispa(int X, int Y) {
		if (x == X + 1 && y == Y || x + 1 == X + 1 && y == Y || x + 2 == X + 1 && y == Y) {
			return true;
		}
		return false;
	}
};
typedef struct comandante {
	int x = x = 4 + rand() % (53 - 4);
	int y = 7 + rand() % (20 - 7);
	int dx = 1, dy = 1;
	short vidas = 2;
public:

	void AnimarComandante() {
		BorrarComandante();
		MoverComandante();
		DibujarComandante();
	}
	void BorrarComandante() {
		Console::SetCursorPosition(x, y); cout << "   ";
	}
	void MoverComandante() {
		if (x == 3 || x == 28) dx *= -1;
		else if (x == 28 || x == 53) dx *= -1;
		if (y < 6) dy *= -1;
		if (y > 31) dy *= -1;

		x += dx;
		y += dy;
	}
	void DibujarComandante() {
		if (vidas == 2) {
			colorearCaracter(Verde);
			Console::SetCursorPosition(x, y); cout << "/$\\";
			colorearCaracter(Blanco);
		}
		else if (vidas == 1) {
			colorearCaracter(Morado);
			Console::SetCursorPosition(x, y); cout << "/$\\";
			colorearCaracter(Blanco);
		}
	}
	bool ChoqueComandante(int X, int Y) {
		if (x == X + 1 && y == Y || x + 1 == X + 1 && y == Y || x + 2 == X + 1 && y == Y) {
			return true;
		}
		return false;
	}
};
typedef struct bala {
	int x, y;
	bool choque = false;
	bool tope = false;
public:
	bala(int _x, int _y) {
		x = _x;
		y = _y;
	}
	int X() { return x; }
	int Y() { return y; }
	void ChoqueBala() { choque = true; }
	bool TopeBala() {
		if (tope) {
			return true;
		}
		return false;
	}
	void AnimarBala() {
		if (y != 3 && choque == false) {
			BorrarBala();
			MoverBala();
			DibujarBala();
		}
		else {
			tope = true;
			choque = true;
			Console::SetCursorPosition(x, y); cout << " ";
			x = NULL;
			y = NULL;
		}
	}

	void BorrarBala() {
		Console::SetCursorPosition(x, y); cout << " ";
	}
	void MoverBala() {
		if (y > 3 && y != 37) y--;
	}
	void DibujarBala() {
		Console::SetCursorPosition(x, y); cout << "|";
	}
};