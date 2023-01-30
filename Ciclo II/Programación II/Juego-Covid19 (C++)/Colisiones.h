#pragma once
#include "Bibliotecas.h"

bool colision_Jugador_Pared(direccion d, int x, int y, int nivel) {
	if (nivel % 4 == 1) {
		if (d == arriba) {
			if (mapa[y / 8 - 1][x / 8] == 1) return true;
			else return false;
		}
		if (d == abajo) {
			if (mapa[y / 8 + 1][x / 8] == 1) return true;
			else return false;
		}
		if (d == derecha) {
			if (mapa[y / 8][x / 8 + 1] == 1) return true;
			else return false;
		}
		if (d == izquierda) {
			if (mapa[y / 8][x / 8 - 1] == 1) return true;
			else return false;
		}
	}
	else if(nivel % 4 == 3) {
		if (d == arriba) {
			if (mapa2[y / 8 - 1][x / 8] == 1) return true;
			else return false;
		}
		if (d == abajo) {
			if (mapa2[y / 8 + 1][x / 8] == 1) return true;
			else return false;
		}
		if (d == derecha) {
			if (mapa2[y / 8][x / 8 + 1] == 1) return true;
			else return false;
		}
		if (d == izquierda) {
			if (mapa2[y / 8][x / 8 - 1] == 1) return true;
			else return false;
		}
	}
	else if (nivel % 4 == 2) {
		if (d == arriba) {
			if (mapa3[y / 8 - 1][x / 8] == 1) return true;
			else return false;
		}
		if (d == abajo) {
			if (mapa3[y / 8 + 1][x / 8] == 1) return true;
			else return false;
		}
		if (d == derecha) {
			if (mapa3[y / 8][x / 8 + 1] == 1) return true;
			else return false;
		}
		if (d == izquierda) {
			if (mapa3[y / 8][x / 8 - 1] == 1) return true;
			else return false;
		}
	}
	else if (nivel % 4 == 0) {
		if (d == arriba) {
			if (mapa4[y / 8 - 1][x / 8] == 1) return true;
			else return false;
		}
		if (d == abajo) {
			if (mapa4[y / 8 + 1][x / 8] == 1) return true;
			else return false;
		}
		if (d == derecha) {
			if (mapa4[y / 8][x / 8 + 1] == 1) return true;
			else return false;
		}
		if (d == izquierda) {
			if (mapa4[y / 8][x / 8 - 1] == 1) return true;
			else return false;
		}
	}
}

bool colision_BalaJugador_Pared(direccion d, int x, int y, int nivel) {
	if (nivel % 4 == 1) {
		switch (d) {
		case arriba:
			if (mapa[y / 8 - 1][x / 8 + 2] == 1) return true;
			else return false;
			break;

		case abajo:
			if (mapa[y / 8 + 5][x / 8 + 1] == 1) return true;
			else return false;
			break;

		case izquierda:
			if (mapa[y / 8][x / 8] == 1) return true;
			else return false;
			break;

		case derecha:
			if (mapa[y / 8][x / 8 + 7] == 1) return true;
			else return false;
			break;
		}
	}
	else if(nivel % 4 == 3){
		switch (d) {
		case arriba:
			if (mapa2[y / 8 - 1][x / 8 + 2] == 1) return true;
			else return false;
			break;

		case abajo:
			if (mapa2[y / 8 + 3][x / 8 + 1] == 1) return true;
			else return false;
			break;

		case izquierda:
			if (mapa2[y / 8][x / 8 - 1] == 1) return true;
			else return false;
			break;

		case derecha:
			if (mapa2[y / 8][x / 8 + 8] == 1) return true;
			else return false;
			break;
		}
	}
	else if (nivel % 4 == 2) {
		switch (d) {
		case arriba:
			if (mapa3[y / 8 - 1][x / 8 + 2] == 1) return true;
			else return false;
			break;

		case abajo:
			if (mapa3[y / 8 + 3][x / 8 + 1] == 1) return true;
			else return false;
			break;

		case izquierda:
			if (mapa3[y / 8][x / 8 - 1] == 1) return true;
			else return false;
			break;

		case derecha:
			if (mapa3[y / 8][x / 8 + 8] == 1) return true;
			else return false;
			break;
		}
	}
	else if (nivel % 4 == 0) {
		switch (d) {
		case arriba:
			if (mapa3[y / 8 - 1][x / 8 + 2] == 1) return true;
			else return false;
			break;

		case abajo:
			if (mapa3[y / 8 + 3][x / 8 + 1] == 1) return true;
			else return false;
			break;

		case izquierda:
			if (mapa3[y / 8][x / 8 - 1] == 1) return true;
			else return false;
			break;

		case derecha:
			if (mapa3[y / 8][x / 8 + 8] == 1) return true;
			else return false;
			break;
		}
	}
}

bool colision_BalaEnemigo_Pared(direccion d, int x, int y, int nivel) {
	if (nivel % 4 == 1) {
		if (y / 8 <= 0 || y / 8 >= 88 || x / 8 >= 120 || x / 8 <= 0) return true;
		switch (d) {
		case arriba:
			if (mapa[y / 8 - 2][x / 8 + 1] == 1) return true;
			else return false;
			break;
		case abajo:
			if (mapa[y / 8 + 1][x / 8 + 1] == 1) return true;
			else return false;
			break;

		case izquierda:
			if (mapa[y / 8][x / 8 - 1] == 1) return true;
			else return false;
			break;

		case derecha:
			if (mapa[y / 8][x / 8 + 4] == 1) return true;
			else return false;
			break;
		}
	}
	else if(nivel % 4 == 3){
		if (y / 8 <= 0 || y / 8 >= 88 || x / 8 >= 120 || x / 8 <= 0) return true;
		switch (d) {
		case arriba:
			if (mapa2[y / 8 - 2][x / 8 + 1] == 1) return true;
			else return false;
			break;
		case abajo:
			if (mapa2[y / 8 + 1][x / 8 + 1] == 1) return true;
			else return false;
			break;

		case izquierda:
			if (mapa2[y / 8][x / 8 - 1] == 1) return true;
			else return false;
			break;

		case derecha:
			if (mapa2[y / 8][x / 8 + 4] == 1) return true;
			else return false;
			break;
		}
	}
	else if (nivel % 4 == 2) {
		if (y / 8 <= 0 || y / 8 >= 88 || x / 8 >= 120 || x / 8 <= 0) return true;
		switch (d) {
		case arriba:
			if (mapa3[y / 8 - 2][x / 8 + 1] == 1) return true;
			else return false;
			break;
		case abajo:
			if (mapa3[y / 8 + 1][x / 8 + 1] == 1) return true;
			else return false;
			break;

		case izquierda:
			if (mapa3[y / 8][x / 8 - 1] == 1) return true;
			else return false;
			break;

		case derecha:
			if (mapa3[y / 8][x / 8 + 4] == 1) return true;
			else return false;
			break;
		}
	}
	else if (nivel % 4 == 0) {
		if (y / 8 <= 0 || y / 8 >= 88 || x / 8 >= 120 || x / 8 <= 0) return true;
		switch (d) {
		case arriba:
			if (mapa3[y / 8 - 2][x / 8 + 1] == 1) return true;
			else return false;
			break;
		case abajo:
			if (mapa3[y / 8 + 1][x / 8 + 1] == 1) return true;
			else return false;
			break;

		case izquierda:
			if (mapa3[y / 8][x / 8 - 1] == 1) return true;
			else return false;
			break;

		case derecha:
			if (mapa3[y / 8][x / 8 + 4] == 1) return true;
			else return false;
			break;
		}
	}
}

bool colision_Enemigo_Pared(direccion d, int x, int y, int nivel) {
	if (nivel % 4 == 1) {
		if (d == arriba) {
			if (mapa[y / 8 - 1][x / 8] == 1) return true;
			else return false;
		}
		if (d == abajo) {
			if (mapa[y / 8 + 1][x / 8] == 1) return true;
			else return false;
		}
		if (d == derecha) {
			if (mapa[y / 8][x / 8 + 1] == 1) return true;
			else return false;
		}
		if (d == izquierda) {
			if (mapa[y / 8][x / 8 - 1] == 1) return true;
			else return false;
		}
	}
	else if (nivel % 4 == 3) {
		if (d == arriba) {
			if (mapa2[y / 8 - 1][x / 8] == 1) return true;
			else return false;
		}
		if (d == abajo) {
			if (mapa2[y / 8 + 1][x / 8] == 1) return true;
			else return false;
		}
		if (d == derecha) {
			if (mapa2[y / 8][x / 8 + 1] == 1) return true;
			else return false;
		}
		if (d == izquierda) {
			if (mapa2[y / 8][x / 8 - 1] == 1) return true;
			else return false;
		}
	}
	else if (nivel % 4 == 2) {
		if (d == arriba) {
			if (mapa3[y / 8 - 1][x / 8] == 1) return true;
			else return false;
		}
		if (d == abajo) {
			if (mapa3[y / 8 + 1][x / 8] == 1) return true;
			else return false;
		}
		if (d == derecha) {
			if (mapa3[y / 8][x / 8 + 1] == 1) return true;
			else return false;
		}
		if (d == izquierda) {
			if (mapa3[y / 8][x / 8 - 1] == 1) return true;
			else return false;
		}
	}
	else if (nivel % 4 == 0) {
		if (d == arriba) {
			if (mapa3[y / 8 - 1][x / 8] == 1) return true;
			else return false;
		}
		if (d == abajo) {
			if (mapa3[y / 8 + 1][x / 8] == 1) return true;
			else return false;
		}
		if (d == derecha) {
			if (mapa3[y / 8][x / 8 + 1] == 1) return true;
			else return false;
		}
		if (d == izquierda) {
			if (mapa3[y / 8][x / 8 - 1] == 1) return true;
			else return false;
		}
	}
}

bool colision_Bala_Enemigo(int x, int y, int bx, int by, direccion D) {
	if (D == arriba || D == abajo) {
		if (x >= bx - 16 && x <= bx + 32 && y >= by && y <= by + 56) return true;
		else return false;
	}
	else {
		if (x >= bx - 8 && x <= bx + 56 && y >= by - 16 && y <= by + 24) return true;
		else return false;
	}
}

bool colision_Bala_Jugador(int x, int y, int bx, int by, direccion D) {
	if (D == arriba || D == abajo) {
		if (x >= bx - 8 && x <= bx + 32 && y >= by && y <= by + 32) return true;
		else return false;
	}
	else {
		if (x >= bx && x <= bx + 16 && y >= by - 24 && y <= by + 32 ) return true;
		else return false;
	}
}

bool colision_Jugador_Enemigo(int jx, int jy, int ex, int ey) {
	if (jx == ex && jy == ey) {
		return true;
	}
	else return false;
}

bool colision_Jugador_Ladron(int jx, int jy, int lx, int ly) {
	if (jx >= lx - 8 && jx <= lx + 8 && jy >= ly - 8 && jy <= lx + 8){
		return true;
	}
	else return false;
}