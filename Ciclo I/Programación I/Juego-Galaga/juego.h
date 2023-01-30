#pragma once
#include "auxiliar.h"
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "estructuras.h"

int jugar() {
	Console::CursorVisible = false;
	srand(time(NULL));
	system("mode con: cols=60 lines=37");
	bool game_over = false, ganado = false;
	char direccion;
	char tecla = NULL;
	short tanda = 1, tiempo = 90, t = 0;
	DibujarMarco();
	nave n = nave(28, 32);
	bool creacion = true;
	short nMariposa, nAvispa, nComandante, T2 = 2, T3 = 3, T5 = 5;
	int puntaje;
	int cMariposa, cAvispa, cComandante;
	mariposa* m = NULL;
	avispa* a = NULL;
	comandante* c = NULL;
	while (tecla != ENTER) {
		do {
			Console::SetCursorPosition(12, 17); cout << "Presione ENTER para comenzar a jugar";
			Console::SetCursorPosition(9, 19); cout << "Presione ESPACIO para leer las instrucciones";
			ImprimirLogo();
			tecla = _getch();
		} while (tecla != ENTER && tecla != ESPACIO);

		if (tecla == ESPACIO) {
			LimpiarPantalla();
			ImprimirInstrucciones();
			system("pause>0");
		}
		Console::SetCursorPosition(9, 34); cout << "                                          ";
		LimpiarPantalla();
	}
	LimpiarPantalla();
	n.DibujarNave();
	bala* balita = NULL;
	while (!game_over) {
		Console::SetCursorPosition(1, 1); cout << "Vidas: " << n.vidas;
		Console::SetCursorPosition(15, 1); cout << "Puntuacion: " << n.puntuacion;
		Console::SetCursorPosition(47, 1); cout << "Tiempo: " << tiempo;
		if (t < 40) {
			t++;
		}
		else if (tiempo != 0) {
			t = 0;
			tiempo--;
		}
		Console::SetCursorPosition(34, 1); cout << "Nivel: " << n.nivel;
		if (tiempo == 9) {
			Console::SetCursorPosition(56, 1); cout << " ";
		}

		if (creacion) {
			if (tanda == 1) {
				nMariposa = T2;
				nAvispa = T2;
				cMariposa = nMariposa;
				cAvispa = nAvispa;
				m = new mariposa[nMariposa];
				a = new avispa[nAvispa];
			}
			if (tanda == 2) {
				nMariposa = T2;
				nComandante = 3;
				cMariposa = nMariposa;
				cComandante = nComandante;
				m = new mariposa[nMariposa];
				c = new comandante[nComandante];
			}
			if (tanda == 3) {
				nMariposa = T3;
				cMariposa = nMariposa;
				m = new mariposa[nMariposa];
			}
			if (tanda == 4) {
				nAvispa = T5;
				cAvispa = nAvispa;
				a = new avispa[nAvispa];
			}
			creacion = false;
		}
		if (tanda == 1) {
			for (short i = 0; i < nMariposa; i++) {
				m[i].AnimarMariposa();
				if (m[i].ChoqueMariposa(n.x, n.y) == true) {
					n.vidas--;
				}
			}
			for (short i = 0; i < nAvispa; i++) {
				a[i].AnimarAvispa();
				if (a[i].ChoqueAvispa(n.x, n.y) == true) {
					n.vidas--;
				}
			}
		}
		if (tanda == 2) {
			for (short i = 0; i < nMariposa; i++) {
				m[i].AnimarMariposa();
				if (m[i].ChoqueMariposa(n.x, n.y) == true) {
					n.vidas--;
				}
			}
			for (short i = 0; i < nComandante; i++) {
				c[i].AnimarComandante();
				if (c[i].ChoqueComandante(n.x, n.y) == true) {
					n.vidas--;
				}
			}
		}
		if (tanda == 3) {
			for (short i = 0; i < nMariposa; i++) {
				m[i].AnimarMariposa();
				if (m[i].ChoqueMariposa(n.x, n.y) == true) {
					n.vidas--;
				}
			}
		}
		if (tanda == 4) {
			for (short i = 0; i < nAvispa; i++) {
				a[i].AnimarAvispa();
				if (a[i].ChoqueAvispa(n.x, n.y) == true) {
					n.vidas--;
				}
			}
		}
		if (kbhit()) {
			direccion = _getch();
			if (direccion == ESPACIO) {
				if (balita == NULL) {
					balita = new bala(n.x + 1, n.y - 1);
				}
				else if (balita->TopeBala()) {
					delete balita;
					balita = new bala(n.x + 1, n.y - 1);
				}
			}
			else {
				n.AnimarNave(direccion);
			}
		}
		if (balita != NULL) {
			balita->AnimarBala();
			if (tanda == 1 || tanda == 2 || tanda == 3) {
				for (short i = 0; i < nMariposa; i++) {
					if (balita->X() == m[i].x && balita->Y() + 1 == m[i].y || balita->X() == m[i].x && balita->Y() == m[i].y ||
						balita->X() == m[i].x + 1 && balita->Y() + 1 == m[i].y || balita->X() == m[i].x + 1 && balita->Y() == m[i].y ||
						balita->X() == m[i].x + 2 && balita->Y() + 1 == m[i].y || balita->X() == m[i].x + 2 && balita->Y() == m[i].y) {
						Console::SetCursorPosition(m[i].x, m[i].y); cout << "   ";
						balita->ChoqueBala();
						for (short t = i; t < cMariposa; t++) {
							m[t] = m[t + 1];
						}
						nMariposa--;
						n.puntuacion += 160;
					}
				}
			}
			if (tanda == 1 || tanda == 4) {
				for (short i = 0; i < nAvispa; i++) {
					if (balita->X() == a[i].x && balita->Y() + 1 == a[i].y || balita->X() == a[i].x && balita->Y() == a[i].y ||
						balita->X() == a[i].x + 1 && balita->Y() + 1 == a[i].y || balita->X() == a[i].x + 1 && balita->Y() == a[i].y ||
						balita->X() == a[i].x + 2 && balita->Y() + 1 == a[i].y || balita->X() == a[i].x + 2 && balita->Y() == a[i].y) {
						Console::SetCursorPosition(a[i].x, a[i].y); cout << "   ";
						balita->ChoqueBala();
						for (short t = i; t < cAvispa; t++) {
							a[t] = a[t + 1];
						}
						nAvispa--;
						n.puntuacion += 100;
					}

				}
			}
			if (tanda == 2) {
				for (short i = 0; i < nComandante; i++) {
					if (balita->X() == c[i].x && balita->Y() + 1 == c[i].y || balita->X() == c[i].x && balita->Y() == c[i].y ||
						balita->X() == c[i].x + 1 && balita->Y() + 1 == c[i].y || balita->X() == c[i].x + 1 && balita->Y() == c[i].y ||
						balita->X() == c[i].x + 2 && balita->Y() + 1 == c[i].y || balita->X() == c[i].x + 2 && balita->Y() == c[i].y) {
						c[i].vidas--;
						balita->ChoqueBala();

						if (c[i].vidas == 0) {
							Console::SetCursorPosition(c[i].x, c[i].y); cout << "   ";
							balita->ChoqueBala();
							if (n.nivel == 4) {
								for (short t = i; t < 5; t++) {
									c[t] = c[t + 1];
								}
							}
							else {
								for (short t = i; t < cComandante; t++) {
									c[t] = c[t + 1];
								}
							}
							nComandante--;
							n.puntuacion += 400;
						}
					}
				}
			}
		}

		if (nMariposa == 0 && nAvispa == 0 && tanda == 1) {
			tanda++;
			creacion = true;
			delete m, a;
		}
		else if (nMariposa == 0 && nComandante == 0 && tanda == 2) {
			tanda++;
			creacion = true;
			delete m, c;
		}
		else if (nMariposa == 0 && tanda == 3) {
			tanda++;
			creacion = true;
			delete m;
		}
		else if (nAvispa == 0 && tanda == 4) {
			tanda++;
			creacion = true;
			delete a;
		}

		if (n.puntuacion >= puntaje + 2500 && n.nivel == 1 && tiempo == 0 || (tanda == 5 && n.nivel == 1)) {
			n.nivel++;
			tanda = 1;
			LimpiarPantalla();
			puntaje = n.puntuacion;
			creacion = true;
			if (tanda == 4) delete a;
			T2++;
			T3++;
			T5++;
			tiempo = 90;
			t = 0;
			_sleep(250);
		}
		else if (n.puntuacion < puntaje + 2500 && tiempo == 0 && n.nivel == 1) {
			tanda = 1;
			creacion = true;
			puntaje = n.puntuacion;
			if (tanda == 1) delete m, a;
			if (tanda == 2) delete m, c;
			if (tanda == 3) delete m;
			if (tanda == 4) delete a;
			n.vidas--;
			LimpiarPantalla();
			tiempo = 90;
			t = 0;
			_sleep(250);
		}
		if (n.puntuacion >= puntaje + 2500 && n.nivel == 2 && tiempo == 0 || (tanda == 5 && n.nivel == 2)) {
			n.nivel++;
			puntaje = n.puntuacion;
			tanda = 1;
			creacion = true;
			LimpiarPantalla();
			if (tanda == 3) delete m;
			if (tanda == 4) delete a;
			_sleep(250);
			tiempo = 90;
			t = 0;
			T2++;
			T3++;
			T5++;
		}
		else if (n.puntuacion < puntaje + 2500 && n.nivel == 2 && tiempo == 0) {
			tanda = 1;
			creacion = true;
			puntaje = n.puntuacion;
			delete m;
			if (tanda == 1) delete m, a;
			if (tanda == 2) delete m, c;
			if (tanda == 3) delete m;
			LimpiarPantalla();
			n.vidas--;
			tiempo = 90;
			t = 0;
			_sleep(250);
		}
		if (n.puntuacion >= puntaje + 2500 && n.nivel == 3 && tiempo == 0 || (tanda == 5 && n.nivel == 3)) {
			n.nivel++;
			tanda = 1;
			creacion = true;
			puntaje = n.puntuacion;
			LimpiarPantalla();
			if (tanda == 2) delete m, c;
			if (tanda == 3) delete m;
			if (tanda == 4) delete a;
			tiempo = 90;
			t = 0;
			_sleep(250);
			T2++;
			T3++;
			T5++;
		}
		else if (n.puntuacion < puntaje + 2500 && n.nivel == 3 && tiempo == 0) {
			tanda = 1;
			creacion = true;
			puntaje = n.puntuacion;
			delete m;
			if (tanda == 1) delete m, a;
			if (tanda == 2) delete m, c;
			if (tanda == 3) delete m;
			LimpiarPantalla();
			n.vidas--;
			tiempo = 90;
			t = 0;
			_sleep(250);
		}
		if (n.puntuacion >= puntaje + 2500 && n.nivel == 4 && tiempo == 0 || (tanda == 5 && n.nivel == 4)) {
			_sleep(250);
			ganado = true;
			game_over = true;
		}
		else if (n.puntuacion < puntaje + 2500 && n.nivel == 4 && tiempo == 0) {
			tanda = 1;
			creacion = true;
			puntaje = n.puntuacion;
			delete m;
			if (tanda == 1) delete m, a;
			if (tanda == 2) delete m, c;
			if (tanda == 3) delete m;
			LimpiarPantalla();
			n.vidas--;
			tiempo = 90;
			t = 0;
			_sleep(250);
		}
		_sleep(25);
		colorearCaracter(Azul);
		Console::SetCursorPosition(n.x + 1, n.y); cout << "A";
		colorearCaracter(Blanco);
		Console::SetCursorPosition(0, 0); cout << " ";
		if (n.vidas == 0 || game_over) {
			game_over = true;
			delete balita;
		}
	}
	return ganado;
}