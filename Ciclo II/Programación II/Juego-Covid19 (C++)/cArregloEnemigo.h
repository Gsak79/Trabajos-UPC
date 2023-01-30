#pragma once
#include "Bibliotecas.h"


class cArregloEnemigo {
private:
	vector<cEnemigo*> arreglo;
public:
	cArregloEnemigo(){}
	~cArregloEnemigo(){}

	vector<cEnemigo*> getArregloEnemigo() { return arreglo; }
	int getCantidadEnemigo() { return arreglo.size(); }

	void registrarEnemigo(cEnemigo* nuevo) {
		arreglo.push_back(nuevo);
	}

	void eliminarEnemigo(int pos) {
		arreglo.erase(arreglo.begin() + pos);
	}
};