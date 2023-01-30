#pragma once
#include "Bibliotecas.h"


class cArregloBala {
private: 
	vector<cBala*> arreglo;
	int cantidad;
public:
	cArregloBala(){}
	~cArregloBala(){}
	
	vector<cBala*> getArreglo() { return arreglo; }

	int getCantidad() { return arreglo.size(); }

	void registrarBala(cBala* nuevo) {
		arreglo.push_back(nuevo);
	}

	void eliminarBala(int pos) {
		arreglo.erase(arreglo.begin() + pos);
	}
};