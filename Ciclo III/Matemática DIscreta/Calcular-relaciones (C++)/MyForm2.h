#pragma once
#include <string>
#include "cConjuntoNumero.h"
#include "cConjuntoCaracter.h"

namespace TrabajoParcialMatemáticaDiscreta {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Resumen de MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
		cConjuntoNumero* conjunto_numero;
		bool charOnum;
		bool interruptor;
		Graphics^ g;
		cConjuntoCaracter* conjunto_caracter;
		Bitmap^ FondoCrema;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ lbl_DiagramaHasse;
	public:
		MyForm2(cConjuntoNumero* numero, cConjuntoCaracter* caracter, bool charnum)
		{
			InitializeComponent();
			charOnum = charnum;
			conjunto_caracter = caracter;
			conjunto_numero = numero;
			g = this->CreateGraphics();
			interruptor = true;
			FondoCrema = gcnew Bitmap("Fondo - Amarillo.jpg");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ bt_regresarHasse;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm2::typeid));
			this->bt_regresarHasse = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lbl_DiagramaHasse = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// bt_regresarHasse
			// 
			this->bt_regresarHasse->Location = System::Drawing::Point(1317, 28);
			this->bt_regresarHasse->Name = L"bt_regresarHasse";
			this->bt_regresarHasse->Size = System::Drawing::Size(195, 56);
			this->bt_regresarHasse->TabIndex = 0;
			this->bt_regresarHasse->Text = L"Regresar";
			this->bt_regresarHasse->UseVisualStyleBackColor = true;
			this->bt_regresarHasse->Click += gcnew System::EventHandler(this, &MyForm2::bt_regresarHasse_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm2::timer1_Tick);
			// 
			// lbl_DiagramaHasse
			// 
			this->lbl_DiagramaHasse->AutoSize = true;
			this->lbl_DiagramaHasse->BackColor = System::Drawing::Color::Transparent;
			this->lbl_DiagramaHasse->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 18, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_DiagramaHasse->Location = System::Drawing::Point(12, 9);
			this->lbl_DiagramaHasse->Name = L"lbl_DiagramaHasse";
			this->lbl_DiagramaHasse->Size = System::Drawing::Size(271, 38);
			this->lbl_DiagramaHasse->TabIndex = 12;
			this->lbl_DiagramaHasse->Text = L"Diagrama de Hasse";
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1629, 920);
			this->Controls->Add(this->lbl_DiagramaHasse);
			this->Controls->Add(this->bt_regresarHasse);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Diagrama de Hasse";
			this->Load += gcnew System::EventHandler(this, &MyForm2::MyForm2_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		template<typename T>
		void DibujarFila(vector<T> aux, int fila, vector<int>& puntosX, vector<int>& puntosY) {
			int x = 610;
			int x1 = 575;
			int y = 620 - fila * 120;

			for (short i = 0; i < aux.size(); i++) {
				String^ str;
				if (charOnum == true) {
					string std_str_caracter(1, aux[i]);
					str = gcnew String(std_str_caracter.c_str());
				}
				else {
					str = Convert::ToString(aux[i]);
				}

				if (aux.size() % 2 == 1) {
					if (i % 2 == 0) {
						x1 += i * 85;
						g->DrawEllipse(Pens::Black, x1, y, 35, 35);
						g->DrawString(str, this->Font, Brushes::Black, x1 + 7, y + 10);
						puntosX.push_back(x1 + 17);
						puntosY.push_back(y + 35);
					}
					else {
						x1 -= i * 85;
						g->DrawEllipse(Pens::Black, x1, y, 35, 35);
						g->DrawString(str, this->Font, Brushes::Black, x1 + 7, y + 10);
						puntosX.push_back(x1 + 17);
						puntosY.push_back(y + 35);
					}
				}
				else {

					if (i % 2 == 0) {
						x += i * 85;
						g->DrawEllipse(Pens::Black, x, y, 35, 35);
						g->DrawString(str, this->Font, Brushes::Black, x + 7, y + 10);
						puntosX.push_back(x + 17);
						puntosY.push_back(y + 35);
					}
					else {
						x -= i * 85;
						g->DrawEllipse(Pens::Black, x, y, 35, 35);
						g->DrawString(str, this->Font, Brushes::Black, x + 7, y + 10);
						puntosX.push_back(x + 17);
						puntosY.push_back(y + 35);
					}
				}
			}
		}


		int CalcularMaximo(vector<int> arreglo, int& pos) {
			if (arreglo.size() > 0) {
				int maximo = arreglo[0];
				for (short i = 0; i < arreglo.size(); i++) {
					if (maximo <= arreglo[i]) {
						maximo = arreglo[i];
						pos = i;
					}
				}
				return maximo;
			}
			return 1;
		}

		template<typename T>
		bool EsIgual(vector<T> arreglo, T comparar) {
			for (short i = 0; i < arreglo.size(); i++) {
				if (arreglo[i] == comparar) return true;
			}
			return false;
		}

		template<typename T>
		void DibujarLineas(vector<T> nivel, vector<T> NivelAnterior, vector<int> puntosX, vector<int> puntosY, vector<int> puntosAnteriorX, vector<int> puntosAnteriorY, int n) {
			if (n == 0) {
				for (short i = 0; i < nivel.size(); i++) {
					for (short j = 0; j < NivelAnterior.size(); j++) {
						if (conjunto_numero->getRelacion()[conjunto_numero->getIndice(NivelAnterior[j])][conjunto_numero->getIndice(nivel[i])] == 1) {
							g->DrawLine(Pens::Blue, puntosAnteriorX[j], puntosAnteriorY[j] - 35, puntosX[i], puntosY[i]);
						}
					}
				}
			}
			else {
				for (short i = 0; i < nivel.size(); i++) {
					for (short j = 0; j < NivelAnterior.size(); j++) {
						if (conjunto_caracter->getRelacion()[conjunto_caracter->getIndice(NivelAnterior[j])][conjunto_caracter->getIndice(nivel[i])] == 1) {
							g->DrawLine(Pens::Blue, puntosAnteriorX[j], puntosAnteriorY[j] - 35, puntosX[i], puntosY[i]);
						}
					}
				}
			}
		}

		void ReestablecerPuntosAnteriores(vector<int>& PuntosAnteriores) {
			vector<int> aux;
			for (short i = 0; i < PuntosAnteriores.size(); i++) {
				aux.push_back(PuntosAnteriores[i] - 35);
			}
			PuntosAnteriores = aux;
		}

		void ImprimirRestantes(bool* completados) {
			short columna = 50;
			String^ str;

			if (charOnum == false) {
				for (short i = 0; i < conjunto_numero->getCantidad(); i++) {
					if (completados[i] == 0) {
						str = Convert::ToString(conjunto_numero->getConjuntoNumero()[i]);

						g->DrawEllipse(Pens::Red, 0, columna, 35, 35);
						g->DrawString(str, this->Font, Brushes::Red, 7, columna + 10);
						columna += 40;
					}
				}
			}
			else {
				for (short i = 0; i < conjunto_caracter->getCantidad(); i++) {
					if (completados[i] == 0) {
						string std_str_caracter(1, conjunto_caracter->getConjuntoCaracter()[i]);
						str = gcnew String(std_str_caracter.c_str());

						g->DrawEllipse(Pens::Red, 0, columna, 35, 35);
						g->DrawString(str, this->Font, Brushes::Red, 7, columna + 10);
						columna += 40;
					}
				}
			}

		}


	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (charOnum == true) {
			if (interruptor == true) {
				interruptor = false;
				vector<int> puntosAnteriorX;
				vector<int> puntosAnteriorY;
				vector<int> puntosY;
				vector<int> puntosX;
				short tamaño = conjunto_caracter->getCantidad();

				bool* completado = new bool[tamaño];
				for (short i = 0; i < tamaño; i++) {
					completado[i] = 0;
				}
				vector<char> NivelAnterior;
				bool HayRelacionEnElMismoNivel = true;

				vector<char> ValoresEnElNivel;
				vector<char> ValoresQueTienenRelacionEnElMismoNivel;

				for (short i = 0; i < conjunto_caracter->getCantidad(); i++) {
					ValoresEnElNivel.push_back(conjunto_caracter->getConjuntoCaracter()[i]);
				}

				int cFila = 0;

				while (HayRelacionEnElMismoNivel == true) {
					HayRelacionEnElMismoNivel = false;

					if (ValoresQueTienenRelacionEnElMismoNivel.size() != 0) {
						ValoresEnElNivel.clear();
						for (short i = 0; i < ValoresQueTienenRelacionEnElMismoNivel.size(); i++) {
							if (EsIgual(ValoresEnElNivel, ValoresQueTienenRelacionEnElMismoNivel[i]) == false) ValoresEnElNivel.push_back(ValoresQueTienenRelacionEnElMismoNivel[i]);
						}
					}

					ValoresQueTienenRelacionEnElMismoNivel.clear();

					for (short i = 0; i < ValoresEnElNivel.size(); i++) {
						for (short j = 0; j < ValoresEnElNivel.size(); j++) {
							if (conjunto_caracter->getRelacion()[conjunto_caracter->getIndice(ValoresEnElNivel[i])][conjunto_caracter->getIndice(ValoresEnElNivel[j])] == 1 && j != i) {

								ValoresQueTienenRelacionEnElMismoNivel.push_back(ValoresEnElNivel[j]);
								HayRelacionEnElMismoNivel = true;
								ValoresEnElNivel.erase(ValoresEnElNivel.begin() + j);
								j--;
								if (j < i) i--;
								if (i >= ValoresEnElNivel.size() - 1) i--;
							}
						}
					}

					for (short i = 0; i < ValoresEnElNivel.size(); i++) {
						completado[conjunto_caracter->getIndice(ValoresEnElNivel[i])] = 1;
					}

					if (ValoresEnElNivel.size() != 0) {
						DibujarFila<char>(ValoresEnElNivel, cFila, puntosX, puntosY);
						conjunto_caracter->AgregarNivel(ValoresEnElNivel);
						if (cFila != 0) DibujarLineas<char>(ValoresEnElNivel, NivelAnterior, puntosX, puntosY, puntosAnteriorX, puntosAnteriorY, 1);

						NivelAnterior = ValoresEnElNivel;
						puntosAnteriorX = puntosX;
						puntosAnteriorY = puntosY;

						puntosX.clear();
						puntosY.clear();

						cFila++;
					}
				}
				ImprimirRestantes(completado);
			}
		}
		else {
			if (interruptor == true) {
				interruptor = false;
				vector<int> puntosAnteriorX;
				vector<int> puntosAnteriorY;
				vector<int> puntosY;
				vector<int> puntosX;
				short tamaño = conjunto_numero->getCantidad();

				bool* completado = new bool[tamaño];
				for (short i = 0; i < tamaño; i++) {
					completado[i] = 0;
				}
				vector<int> NivelAnterior;

				bool HayRelacionEnElMismoNivel = true;


				vector<int> ValoresEnElNivel;

				for (short i = 0; i < conjunto_numero->getCantidad(); i++) {
					ValoresEnElNivel.push_back(conjunto_numero->getConjuntoNumero()[i]);
				}

				vector<int> ValoresQueTienenRelacionEnElMismoNivel;
				int cFila = 0;

				while (HayRelacionEnElMismoNivel == true) {
					HayRelacionEnElMismoNivel = false;



					if (ValoresQueTienenRelacionEnElMismoNivel.size() != 0) {
						ValoresEnElNivel.clear();
						for (short i = 0; i < ValoresQueTienenRelacionEnElMismoNivel.size(); i++) {
							ValoresEnElNivel.push_back(ValoresQueTienenRelacionEnElMismoNivel[i]);
						}
					}

					ValoresQueTienenRelacionEnElMismoNivel.clear();

					for (short i = 0; i < ValoresEnElNivel.size(); i++) {
						for (short j = 0; j < ValoresEnElNivel.size(); j++) {
							if (conjunto_numero->getRelacion()[conjunto_numero->getIndice(ValoresEnElNivel[i])][conjunto_numero->getIndice(ValoresEnElNivel[j])] == 1 && j != i) {

								ValoresQueTienenRelacionEnElMismoNivel.push_back(ValoresEnElNivel[j]);
								HayRelacionEnElMismoNivel = true;
								ValoresEnElNivel.erase(ValoresEnElNivel.begin() + j);
								j--;
								if (j < i) i--;
								if (i >= ValoresEnElNivel.size() - 1) i--;
							}
						}
					}

					for (short i = 0; i < ValoresEnElNivel.size(); i++) {
						completado[conjunto_numero->getIndice(ValoresEnElNivel[i])] = 1;
					}

					if (ValoresEnElNivel.size() != 0) {
						DibujarFila<int>(ValoresEnElNivel, cFila, puntosX, puntosY);
						conjunto_numero->AgregarNivel(ValoresEnElNivel);
						if (cFila != 0) DibujarLineas<int>(ValoresEnElNivel, NivelAnterior, puntosX, puntosY, puntosAnteriorX, puntosAnteriorY, 0);

						NivelAnterior = ValoresEnElNivel;
						puntosAnteriorX = puntosX;
						puntosAnteriorY = puntosY;

						puntosX.clear();
						puntosY.clear();

						cFila++;
					}
				}
				ImprimirRestantes(completado);
			}
		}

	}
	private: System::Void bt_regresarHasse_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void MyForm2_Load(System::Object^ sender, System::EventArgs^ e) {
		this->BackgroundImage = FondoCrema;
	}
	};
}
