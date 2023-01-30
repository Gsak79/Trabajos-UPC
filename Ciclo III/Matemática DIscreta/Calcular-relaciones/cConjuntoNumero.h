#pragma once
#include <vector>
using namespace std;

class cConjuntoNumero {
private:
	vector<int> ConjuntoNumero;
	short** relacion;
	vector<vector<int>> niveles;
	short cantidad;
public:
	cConjuntoNumero() {
		relacion = nullptr;
	}
	~cConjuntoNumero() {}

	void setCantidad(short cant) {
		cantidad = cant;

		if (relacion != nullptr) {
			delete relacion;
			relacion = nullptr;
		}

		relacion = new short* [cant];
		for (short i = 0; i < cant; i++) {
			relacion[i] = new short[cant];
		}
		for (short i = 0; i < cant; i++) {
			for (short j = 0; j < cant; j++) {
				relacion[i][j] = 0;
			}
		}
	}

	bool IngresarElemento(int nuevo) {
		for (short i = 0; i < ConjuntoNumero.size(); i++) {
			if (ConjuntoNumero[i] == nuevo) {
				return true;
			}
		}
		ConjuntoNumero.push_back(nuevo);
		return false;
	}

	void EliminarElemento(int pos) {
		ConjuntoNumero.erase(ConjuntoNumero.begin() + pos);
	}

	short getCantidad() {
		return cantidad;
	}

	short** getRelacion() {
		return relacion;
	}

	vector<int> getConjuntoNumero() {
		return ConjuntoNumero;
	}

	void AgregarRelacion(int pos) {
		int contador = 0;
		for (short i = 0; i < cantidad; i++) {
			for (short j = 0; j < cantidad; j++) {
				if (contador == pos && relacion[i][j] == 0) {
					relacion[i][j] = 1;
					contador++;
				}
				else if (relacion[i][j] == 0) contador++;
			}
		}
	}

	void setRelacion(short i, short j, short numero) {
		if (numero == 1) relacion[i][j] = 1;
		else if (numero == 0) relacion[i][j] = 0;
	}

	int getIndice(int valor) {
		for (short i = 0; i < cantidad; i++) {
			if (ConjuntoNumero[i] == valor) {
				return i;
			}
		}
		return -1;
	}

	void borrarRelacion(int pos) {
		int contador = 0;
		for (short i = 0; i < cantidad; i++) {
			for (short j = 0; j < cantidad; j++) {
				if (contador == pos && relacion[i][j] == 1) {
					relacion[i][j] = 0;
					contador++;
				}
				else if (relacion[i][j] == 1) contador++;
			}
		}
	}


	void borrarTodoRelacion() {
		for (short i = 0; i < cantidad; i++) {
			for (short j = 0; j < cantidad; j++) {
				relacion[i][j] = 0;
			}
		}
	}

	bool Reflexivo() {
		for (short i = 0; i < cantidad; i++) {
			if (relacion[i][i] != 1) return false;
		}
		return true;
	}

	bool Antisimetrico() {
		for (short i = 0; i < cantidad; i++) {
			for (short j = 0; j < cantidad; j++) {
				if (relacion[i][j] == 1 && relacion[j][i] == 1 && i != j) return false;
			}
		}
		return true;
	}

	bool Transitivo() {
		for (short b = 0; b < cantidad; b++) {
			for (short i = 0; i < cantidad; i++) {
				for (short j = 0; j < cantidad; j++) {
					if (relacion[i][b] == 1 && relacion[b][j] == 1) {
						if (relacion[i][j] != 1)return false;
					}
				}
			}
		}
		return true;
	}

	void AgregarNivel(vector<int> nivel) {
		niveles.push_back(nivel);
	}

	vector<int> CalcularMinimales(short i, short j) {
		vector<int> minimales;
		int nivel = 0;
		int niveli = 0;
		int nivelj = 0;
		for (short k = 0; k < niveles.size(); k++) {
			for (short l = 0; l < niveles[k].size(); l++) {
				if (niveles[k][l] == ConjuntoNumero[i]) niveli = k - 1;
				else if (niveles[k][l] == ConjuntoNumero[j]) nivelj = k - 1;
			}
		}
		if (niveli >= nivelj) nivel = niveli;
		else nivel = nivelj;

		for (short l = nivel; l >= 0; l--) {
			for (short k = 0; k < niveles[l].size(); k++) {
				if (relacion[getIndice(niveles[l][k])][i] == 1 && relacion[getIndice(niveles[l][k])][j] == 1) {
					minimales.push_back(niveles[l][k]);
				}
			}
			if (minimales.size() != 0) break;
		}
		return minimales;
	}

	vector<int> CalcularMaximales(short i, short j) {
		vector<int> maximales;
		int nivel = 0;
		int niveli = 0;
		int nivelj = 0;
		for (short k = 0; k < niveles.size(); k++) {
			for (short l = 0; l < niveles[k].size(); l++) {
				if (niveles[k][l] == ConjuntoNumero[i]) niveli = k + 1;
				else if (niveles[k][l] == ConjuntoNumero[j]) nivelj = k + 1;
			}
		}

		if (niveli >= nivelj) nivel = niveli;
		else nivel = nivelj;

		for (short l = nivel; l < niveles.size(); l++) {
			for (short k = 0; k < niveles[l].size(); k++) {
				if (relacion[i][getIndice(niveles[l][k])] == 1 && relacion[j][getIndice(niveles[l][k])] == 1) {
					maximales.push_back(niveles[l][k]);
				}
			}
			if (maximales.size() != 0) break;
		}
		return maximales;
	}

	bool TieneInfimo() {
		vector<int> minimales;
		if (niveles[0].size() > 1) return false;

		for (short i = 0; i < cantidad; i++) {
			for (short j = 0; j < cantidad; j++) {
				if (relacion[i][j] == 0 && relacion[j][i] == 0) {
					minimales = CalcularMinimales(i, j);
					if (minimales.size() > 1 || minimales.size() == 0) return false;
				}
			}
		}
		return true;
	}

	bool TieneSupremo() {
		vector<int> maximales;
		if (niveles[niveles.size() - 1].size() > 1) return false;

		for (short i = 0; i < cantidad; i++) {
			for (short j = 0; j < cantidad; j++) {
				if (relacion[i][j] == 0 && relacion[j][i] == 0) {
					maximales = CalcularMaximales(i, j);
					if (maximales.size() > 1 || maximales.size() == 0) return false;
				}
			}
		}
		return true;
	}

	vector<int> HallarComplementos(int vertice) {

		vector<int> maximales;
		vector<int> minimales;

		vector<int> complementos;

		if (niveles[0][0] == ConjuntoNumero[vertice]) {
			complementos.push_back(niveles[niveles.size() - 1][0]);
			return complementos;
		}
		else if (niveles[niveles.size() - 1][0] == ConjuntoNumero[vertice]) {
			complementos.push_back(niveles[0][0]);
			return complementos;
		}

		for (short i = 0; i < cantidad; i++) {
			if (relacion[vertice][i] == 0 && relacion[i][vertice] == 0) {
				maximales = CalcularMaximales(vertice, i);
				minimales = CalcularMinimales(vertice, i);
				if (maximales.size() == 1 && minimales.size() == 1) {
					if (maximales[0] == niveles[niveles.size() - 1][0] && minimales[0] == niveles[0][0]) {
						complementos.push_back(ConjuntoNumero[i]);
					}
				}
			}
		}
		return complementos;
	}

};