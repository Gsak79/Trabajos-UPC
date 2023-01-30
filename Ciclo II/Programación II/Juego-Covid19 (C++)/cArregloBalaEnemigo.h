#pragma once
#include "Bibliotecas.h"

class cArregloBalaEnemigo {
private:
	vector<cBalaEnemigo*> arreglo;
public:
	cArregloBalaEnemigo() {}
	~cArregloBalaEnemigo() {}

	vector<cBalaEnemigo*> getArregloBalaEnemigo() { return arreglo; }
	int getCantidadBalaEnemigo() { return arreglo.size(); }

	void registrarBalaEnemigo(cBalaEnemigo* nuevo) {
		arreglo.push_back(nuevo);
	}

	void eliminarBalaEnemigo(int pos) {
		arreglo.erase(arreglo.begin() + pos);
	}
};

