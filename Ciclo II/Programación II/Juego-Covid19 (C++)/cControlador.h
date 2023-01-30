#pragma once
#include "Bibliotecas.h"

using namespace System::Drawing;
using namespace std;

class cControlador {
private:
	cJugador* jugador;
	cArregloEnemigo* arrEnemigo;
	cAmbulancia* ambulancia;
	cPolicia* policia;
	cArregloBala* arrBalaJugador;
	cLadron* ladron;
	int nivel;
	bool jugando;
	bool generarEnemigo;
	int nene;
	int cantEnemigo;
	bool dificultad;
	bool contador;
	int inicio;
	int eliminados;
	bool uplevel;
	bool crearLadron;
	bool ladrondesaparecer;
	bool crear;
	char* distrito;
public:
	cControlador() {
		ambulancia = new cAmbulancia();
		policia = new cPolicia();
		jugador = new cJugador(456, 232);
		arrEnemigo = new cArregloEnemigo;
		arrBalaJugador = new cArregloBala;
		ladron = new cLadron(56, 56);
		nivel = 1;
		jugando = false;
		generarEnemigo = true;
		cantEnemigo = 0;
		nene = 0;
		contador = true;
		uplevel = false;
		ladrondesaparecer = false;
		crearLadron = true;
		distrito = "Comas";
		eliminados = 0;
		inicio = 11;
	}
	~cControlador() {}

	int Aleatorio(int ini, int fin) {
		return rand() % (fin + 1 - ini) + ini;
	}

	void setVidas(int vidas) {jugador->setVidas(vidas);}
	void setDificultad(bool d) { dificultad = d; }
	void setNivel(short n) { nivel = n; }
	void setPuntuacion(short p) { jugador->setPuntuacion(p); }

	int getEnemigos(int t) {
		if (cantEnemigo != 0 && jugando == true) {
			if (cantEnemigo % 2 == 0) {
				return cantEnemigo / 2 + 1 - eliminados;
			}
			else {
				return cantEnemigo / 2 + 2 - eliminados;
			}
		}
		else {
			if (t % 2 == 0) {
				return t / 2 + 1- eliminados;
			}
			else {
				return t / 2 + 2 - eliminados;
			}
		}
	}

	void subirNivel() {
		if (arrEnemigo->getCantidadEnemigo() <= cantEnemigo / 2 && jugando == true || uplevel == true) {
			uplevel = false;
			crearLadron = true;
			inicio = 11;
			ladron->setX(8);
			ladron->setY(8);
			ladrondesaparecer = false;
			ladron->setAtrapado(false);
			ladron->setColision(false);
			while(arrEnemigo->getCantidadEnemigo() != 0){
				arrEnemigo->eliminarEnemigo(0);
			}
			jugando = false;
			nivel++;
			generarEnemigo = true;
			if (nivel % 4 == 1) {
				jugador->setJugadorX(456);
				jugador->setJugadorY(232);
				ambulancia->setAmbulanciaX(0);
				ambulancia->setAmbulanciaY(520);
				policia->setPoliciaX(832);
				policia->setPoliciaY(160);
				distrito = "Comas";
			}
			else if(nivel % 4 == 3){
				jugador->setJugadorX(504);
				jugador->setJugadorY(232);
				ambulancia->setAmbulanciaX(128);
				ambulancia->setAmbulanciaY(176);
				policia->setPoliciaX(160);
				policia->setPoliciaY(584);
				distrito = "S.J.L";
			}
			else if (nivel % 4 == 2) {
				jugador->setJugadorX(456);
				jugador->setJugadorY(232);
				distrito = "San Isidro";
			}
			else if (nivel % 4 == 0) {
				jugador->setJugadorX(456);
				jugador->setJugadorY(200);
				distrito = "Jesús María";
			}
			contador = true;
			eliminados = 0;
		}
	}

	bool getJugando() { return jugando; }
	bool getGenerarEnemigo() { return generarEnemigo; }


	void dibujarMapa(BufferedGraphics^ buffer, Bitmap^ bmpMapa1, Bitmap^ bmpMapa2, Bitmap^ bmpMapa3, Bitmap^ bmpMapa4) {
		if (nivel % 4 == 1) buffer->Graphics->DrawImage(bmpMapa1, 0, 0, 960, 688);
		else if (nivel % 4 == 3) buffer->Graphics->DrawImage(bmpMapa2, 0, 0, 960, 688);
		else if (nivel % 4 == 2) buffer->Graphics->DrawImage(bmpMapa3, 0, 0, 960, 688);
		else if (nivel % 4 == 0) buffer->Graphics->DrawImage(bmpMapa4, 0, 0, 960, 688);
	}

	void dibujarBanner(BufferedGraphics^ buffer, Bitmap^ bmpBanner) {
		buffer->Graphics->DrawImage(bmpBanner, 0, 0, 960, 40);
	}

	bool getDificultad() { return dificultad; }
	int getPuntuacion() { return jugador->getPuntuacion(); }
	int getVidas() { return jugador->getVidas(); }
	int getNivel() { return nivel; }
	int getCantEnemigos() { return cantEnemigo; }
	char* getDistrito() { return distrito; }

	void Movjugador(BufferedGraphics^ buffer, Bitmap^ bmpJugador, Bitmap^ bmpBalaJugadorHorizontal, Bitmap^ bmpBalaJugadorVertical, Bitmap^ enfermo1, Bitmap^ enfermo2, Bitmap^ enfermo3) {
		jugador->mover(buffer, bmpJugador, nivel, enfermo1, enfermo2, enfermo3);
		jugador->disparoJugador(buffer, bmpBalaJugadorHorizontal, bmpBalaJugadorVertical, arrBalaJugador);
		jugador->EliminarBala(arrBalaJugador, nivel);
	}

	void direccionJugador(direccion D) {
		jugador->setDireccion(D);
	}

	void AgregarBala(int o) {
		if (o == 0) {
			jugador->agregarBalaJugador(arrBalaJugador);
		}
		else {
			for (short i = 0; i < arrEnemigo->getCantidadEnemigo(); i++) {
				arrEnemigo->getArregloEnemigo()[i]->agregarBalaEnemigo();
			}
		}
	}

	void AgregarEnemigos(short t) {
		cEnemigo* enemigos = NULL;
		int x;
		int y;
		int a;
		int ad;
		int dx;
		int dy;
		int tipo;
		if (nivel % 4 == 1) {
			do {
				dx = 0;
				dy = 0;
				x = Aleatorio(8, 950);
				y = Aleatorio(8, 650);

			} while (mapa[y / 8][x / 8] == 1 || mapa[y / 8 + 1][x / 8] == 1 || mapa[y / 8 - 1][x / 8] == 1 || mapa[y / 8][x / 8 - 1] == 1 || mapa[y / 8][x / 8 + 1] == 1 || mapa[y / 8 + 2][x / 8] == 1 || mapa[y / 8 - 2][x / 8] == 1 || mapa[y / 8][x / 8 - 2] == 1 || mapa[y / 8][x / 8 + 2] == 1 || x % 8 != 0 || y % 8 != 0);
		}
		else {
			do {
				dx = 0;
				dy = 0;
				x = Aleatorio(8, 950);
				y = Aleatorio(8, 650);

			} while (mapa2[y / 8][x / 8] == 1 || mapa2[y / 8 + 1][x / 8] == 1 || mapa2[y / 8 - 1][x / 8] == 1 || mapa2[y / 8][x / 8 - 1] == 1 || mapa2[y / 8][x / 8 + 1] == 1 || mapa2[y / 8 + 2][x / 8] == 1 || mapa2[y / 8 - 2][x / 8] == 1 || mapa2[y / 8][x / 8 - 2] == 1 || mapa2[y / 8][x / 8 + 2] == 1 || x % 8 != 0 || y % 8 != 0);
		}
		a = Aleatorio(0, 1);
		ad = Aleatorio(0, 1);

		if (a == 0) {
			if (ad == 1) dx = 8;
			else dx = -8;
		}
		else {
			if (ad == 1) dy = 8;
			else dy = -8;
		}

		tipo = Aleatorio(0, 1);
		if (tipo == 0) {
			enemigos = new cEnemigoSaludable(x, y, dy, dx, tipo);
		}
		else {
			enemigos = new cEnemigoAsintomatico(x, y, dy, dx, tipo);
		}

		arrEnemigo->registrarEnemigo(enemigos);
		nene++;

		if (generarEnemigo == true) {
			generarEnemigo = false;
			cantEnemigo = t;
		}

		if (nene == cantEnemigo) {
			jugando = true;
			nene = 0;
		}
	}

	void MovVehiculo(BufferedGraphics^ buffer, Bitmap^ bmpPoliciaV, Bitmap^ bmpPoliciaH, Bitmap^ bmpAmbulanciaV, Bitmap^ bmpAmbulanciaH) {
		if (jugando == true) {
			bool enemigoS = true;
			for (short i = 0; i < arrEnemigo->getCantidadEnemigo(); i++) {
				if (arrEnemigo->getArregloEnemigo()[i]->getColision() == true && arrEnemigo->getArregloEnemigo()[i]->getTipo() == 0 || ladron->getColision() == true && ladron->getAtrapado() == false) {
					enemigoS = false;
					policia->mover(arrEnemigo->getArregloEnemigo()[i], buffer, bmpPoliciaV, bmpPoliciaH, ladron);
					if (arrEnemigo->getArregloEnemigo()[i]->getEnemigoX() == policia->getPoliciaX() && arrEnemigo->getArregloEnemigo()[i]->getEnemigoY() == policia->getPoliciaY()) {
						arrEnemigo->eliminarEnemigo(i);
						jugador->subirPuntos();
						eliminados++;
					}
					if (policia->getPoliciaX() == ladron->getX() && policia->getPoliciaY() == ladron->getY()) {
						ladron->setAtrapado(true);
						jugador->subirPuntos();
						ladrondesaparecer = true;
					}
					break;
				}
				else if (i == arrEnemigo->getCantidadEnemigo() - 1 && enemigoS == true) {
					policia->moverHelipuerto(buffer, bmpPoliciaV, bmpPoliciaH, nivel);
				}

			}

			bool enemigoA = true;
			for (short i = 0; i < arrEnemigo->getCantidadEnemigo(); i++) {
				if (arrEnemigo->getArregloEnemigo()[i]->getColision() == true && arrEnemigo->getArregloEnemigo()[i]->getTipo() == 1) {
					enemigoA = false;
					ambulancia->mover(arrEnemigo->getArregloEnemigo()[i], buffer, bmpAmbulanciaV, bmpAmbulanciaH);
					if (arrEnemigo->getArregloEnemigo()[i]->getEnemigoX() == ambulancia->getAmbulanciaX() && arrEnemigo->getArregloEnemigo()[i]->getEnemigoY() == ambulancia->getAmbulanciaY()) {
						arrEnemigo->eliminarEnemigo(i);
						jugador->subirPuntos();
						eliminados++;
					}
					break;
				}
				else if (i == arrEnemigo->getCantidadEnemigo() - 1 && enemigoA == true) {
					ambulancia->moverHelipuerto(buffer, bmpAmbulanciaV, bmpAmbulanciaH, nivel);
				}
			}
		}
	}

	void Movenemigo(BufferedGraphics^ buffer, Bitmap^ bmpEnemigo, Bitmap^ covid, Bitmap^ bmpEnemigoSaludable, Bitmap^ bmpEnemigoAsintomatico) {
		for (short i = 0; i < arrEnemigo->getCantidadEnemigo(); i++) {
			arrEnemigo->getArregloEnemigo()[i]->mover(buffer, bmpEnemigo, bmpEnemigoSaludable, bmpEnemigoAsintomatico, nivel);
			arrEnemigo->getArregloEnemigo()[i]->enemigoDisparo(buffer, covid);
			if (arrEnemigo->getArregloEnemigo()[i]->eliminarJugador(jugador) == true || colision_Jugador_Enemigo(jugador->getX(), jugador->getY(), arrEnemigo->getArregloEnemigo()[i]->getEnemigoX(), arrEnemigo->getArregloEnemigo()[i]->getEnemigoY()) == true) {
				jugador->bajarVida();
			}
			arrEnemigo->getArregloEnemigo()[i]->eliminarBalaEnemigo(nivel);
			int nbala = 0;

			if (arrEnemigo->getArregloEnemigo()[i]->eliminarEnemigo(arrBalaJugador->getArreglo(), arrBalaJugador->getCantidad(), nbala) == true) {
				arrEnemigo->getArregloEnemigo()[i]->setColision(true);
				arrBalaJugador->eliminarBala(nbala);
			}
		}
	}

	int tiempo(int t) {
		if (nivel % 4 != 2 && nivel % 4 != 0) {
			if (contador == true && nivel == 1) {
				inicio = t * 4;
				contador = false;
			}
			else if (nivel > 1 && contador == true) {
				contador = false;
				inicio = (t - 2) * 4 + 2;
			}

			if (inicio != 0) {
				inicio--;
			}
		}
		else {
			if (contador == true) {
				inicio = t;
				contador = false;
			}
			if (inicio != 0) {
				inicio--;
			}
			else if (inicio == 0) {
				uplevel = true;
			}
			
		}

		return inicio;
	}

	void MovLadron(BufferedGraphics^ buffer, Bitmap^ lad, Bitmap^ atrapado) {
		if (crearLadron == true) {
			crear = 1;
			crearLadron = false;
		}
		if ((nivel % 4 == 1 || nivel % 4 == 3) && crear == true && inicio < 10) {
			if (ladrondesaparecer == false) {
				ladron->mover(buffer, lad, atrapado, jugador->getX(), jugador->getY());
				for (short i = 0; i < arrBalaJugador->getCantidad(); i++) {
					if (colision_Bala_Enemigo(ladron->getX(), ladron->getY(), arrBalaJugador->getArreglo()[i]->getBalaX(), arrBalaJugador->getArreglo()[i]->getBalaY(), arrBalaJugador->getArreglo()[i]->getDireccionBala()) == true) {
						ladron->setColision(true);
					}
				}
				if (colision_Jugador_Ladron(jugador->getX(), jugador->getY(), ladron->getX(), ladron->getY()) == true || ladron->getdx() == 0 && ladron->getdy() == 0 && ladron->getColision() == false) {
					jugador->bajarVida();
					ladrondesaparecer = true;
				}
			}
			else if (ladron->getAtrapado() == true) {
				
			}
			else {
				ladron->regresar(buffer, lad, atrapado);
			}
		}
	}
};

