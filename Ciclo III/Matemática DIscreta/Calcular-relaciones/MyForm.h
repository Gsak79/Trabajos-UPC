#pragma once
#include <string>
#include "stdafx.h"
#include "MyForm2.h"
#include <functional>
#include "cConjuntoCaracter.h"
#include "cConjuntoNumero.h"
#include <msclr\marshal_cppstd.h>
using namespace std;


namespace TrabajoParcialMatemáticaDiscreta {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		cConjuntoCaracter* conjunto_caracter;
		cConjuntoNumero* conjunto_numero;
		bool dibujar;
		bool charOnum;
		Bitmap^ FondoAzul;
		Bitmap^ FondoBlanco;
	private: System::Windows::Forms::Timer^ tm_BorrarElemento;
	private: System::Windows::Forms::Panel^ pa_relacion;
	private: System::Windows::Forms::ListBox^ lb_productoCartesiano;
	private: System::Windows::Forms::Button^ bt_AgregarRelacion;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ListBox^ lb_relacion;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ bt_condicion;
	private: System::Windows::Forms::Panel^ pa_EstablecerRelacion;
	private: System::Windows::Forms::TextBox^ tb_resultado;
	private: System::Windows::Forms::ComboBox^ cb_operador2;
	private: System::Windows::Forms::ComboBox^ cb_valor2;
	private: System::Windows::Forms::ComboBox^ cb_operador1;
	private: System::Windows::Forms::ComboBox^ cb_valor1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ bt_establecercondicion;
	private: System::Windows::Forms::Timer^ tm_condicion;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ bt_BorrarTodoRelacion;
	private: System::Windows::Forms::Button^ bt_BorrarRelacion;
	private: System::Windows::Forms::Button^ bt_DeterminarOrdenParcial;
	private: System::Windows::Forms::Button^ bt_RegresarConjuntos;
	private: System::Windows::Forms::Panel^ pa_OrdenParcial;
	private: System::Windows::Forms::Label^ lbl_transitiva;
	private: System::Windows::Forms::Label^ lbl_antisimetrica;
	private: System::Windows::Forms::Label^ lbl_reflexiva;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ lbl_ordenParcial;
	private: System::Windows::Forms::Button^ bt_RegresarRelacion;
	private: System::Windows::Forms::Button^ bt_dibujarHasse;
	private: System::Windows::Forms::Button^ bt_regresarRela;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Panel^ pa_EstablecerRelacionCaracter;
	private: System::Windows::Forms::Button^ bt_EstablecerCaracter;
	private: System::Windows::Forms::ComboBox^ cb_caracterOperador;
	private: System::Windows::Forms::ComboBox^ cb_caracter2;
	private: System::Windows::Forms::ComboBox^ cb_caracter1;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Button^ bt_DeterminarReticula;
	private: System::Windows::Forms::Panel^ pa_reticula;
	private: System::Windows::Forms::Label^ lbl_infimo;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Button^ bt_RelacionAleatoria;
	private: System::Windows::Forms::Label^ lbl_supremo;
	private: System::Windows::Forms::Panel^ pa_Inicio;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ tb_NumeroElementos;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Button^ bt_generar;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::RadioButton^ rb_Caracteres;
	private: System::Windows::Forms::RadioButton^ rb_Numero;
	private: System::Windows::Forms::Button^ bt_regresarReticula;
	private: System::Windows::Forms::Button^ bt_HallarComplementos;
	private: System::Windows::Forms::Panel^ pa_Complementos;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::ListBox^ lb_complementos;
	private: System::Windows::Forms::Button^ bt_regresarComplementos;
	private: System::Windows::Forms::Label^ lbl_reticula;
	private: System::Windows::Forms::Button^ bt_RegresarCaracterRelacion;

	private: System::Windows::Forms::Button^ bt_regresarInicio;
	public:
		MyForm(void)
		{
			InitializeComponent();
			conjunto_caracter = new cConjuntoCaracter;
			conjunto_numero = new cConjuntoNumero;
			dibujar = false;
			FondoAzul = gcnew Bitmap("Fondo - Azul claro.jpg");
			FondoBlanco = gcnew Bitmap("Fondo - Blanco.jpg");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pa_ConjuntoA;
	private: System::Windows::Forms::ListBox^ lb_elementosA;
	private: System::Windows::Forms::Button^ bt_DefinirRelacion;
	private: System::Windows::Forms::Button^ bt_GenerarAleatorioRestantes;
	private: System::Windows::Forms::Button^ bt_IngresarElemento;
	private: System::Windows::Forms::Label^ label1;


	private: System::Windows::Forms::Button^ bt_BorrarTodo;
	private: System::Windows::Forms::Button^ bt_Borrar;
	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::Button^ GenerarAleatorioTodos;
	private: System::Windows::Forms::TextBox^ tb_NuevoElemento;
	private: System::Windows::Forms::Label^ lbl_ElementosRestantes;
	private: System::Windows::Forms::Timer^ tm_ElementosRestantes;
	private: System::ComponentModel::IContainer^ components;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pa_ConjuntoA = (gcnew System::Windows::Forms::Panel());
			this->bt_regresarInicio = (gcnew System::Windows::Forms::Button());
			this->bt_BorrarTodo = (gcnew System::Windows::Forms::Button());
			this->bt_Borrar = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->GenerarAleatorioTodos = (gcnew System::Windows::Forms::Button());
			this->tb_NuevoElemento = (gcnew System::Windows::Forms::TextBox());
			this->lbl_ElementosRestantes = (gcnew System::Windows::Forms::Label());
			this->bt_DefinirRelacion = (gcnew System::Windows::Forms::Button());
			this->bt_GenerarAleatorioRestantes = (gcnew System::Windows::Forms::Button());
			this->bt_IngresarElemento = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lb_elementosA = (gcnew System::Windows::Forms::ListBox());
			this->lb_productoCartesiano = (gcnew System::Windows::Forms::ListBox());
			this->tm_ElementosRestantes = (gcnew System::Windows::Forms::Timer(this->components));
			this->tm_BorrarElemento = (gcnew System::Windows::Forms::Timer(this->components));
			this->pa_relacion = (gcnew System::Windows::Forms::Panel());
			this->bt_RelacionAleatoria = (gcnew System::Windows::Forms::Button());
			this->bt_DeterminarOrdenParcial = (gcnew System::Windows::Forms::Button());
			this->bt_RegresarConjuntos = (gcnew System::Windows::Forms::Button());
			this->bt_BorrarTodoRelacion = (gcnew System::Windows::Forms::Button());
			this->bt_BorrarRelacion = (gcnew System::Windows::Forms::Button());
			this->bt_condicion = (gcnew System::Windows::Forms::Button());
			this->bt_AgregarRelacion = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->lb_relacion = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pa_EstablecerRelacion = (gcnew System::Windows::Forms::Panel());
			this->bt_regresarRela = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->bt_establecercondicion = (gcnew System::Windows::Forms::Button());
			this->tb_resultado = (gcnew System::Windows::Forms::TextBox());
			this->cb_operador2 = (gcnew System::Windows::Forms::ComboBox());
			this->cb_valor2 = (gcnew System::Windows::Forms::ComboBox());
			this->cb_operador1 = (gcnew System::Windows::Forms::ComboBox());
			this->cb_valor1 = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tm_condicion = (gcnew System::Windows::Forms::Timer(this->components));
			this->pa_OrdenParcial = (gcnew System::Windows::Forms::Panel());
			this->bt_DeterminarReticula = (gcnew System::Windows::Forms::Button());
			this->bt_RegresarRelacion = (gcnew System::Windows::Forms::Button());
			this->bt_dibujarHasse = (gcnew System::Windows::Forms::Button());
			this->lbl_ordenParcial = (gcnew System::Windows::Forms::Label());
			this->lbl_transitiva = (gcnew System::Windows::Forms::Label());
			this->lbl_antisimetrica = (gcnew System::Windows::Forms::Label());
			this->lbl_reflexiva = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->pa_EstablecerRelacionCaracter = (gcnew System::Windows::Forms::Panel());
			this->bt_EstablecerCaracter = (gcnew System::Windows::Forms::Button());
			this->cb_caracterOperador = (gcnew System::Windows::Forms::ComboBox());
			this->cb_caracter2 = (gcnew System::Windows::Forms::ComboBox());
			this->cb_caracter1 = (gcnew System::Windows::Forms::ComboBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->pa_reticula = (gcnew System::Windows::Forms::Panel());
			this->lbl_reticula = (gcnew System::Windows::Forms::Label());
			this->bt_regresarReticula = (gcnew System::Windows::Forms::Button());
			this->bt_HallarComplementos = (gcnew System::Windows::Forms::Button());
			this->lbl_supremo = (gcnew System::Windows::Forms::Label());
			this->lbl_infimo = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->pa_Complementos = (gcnew System::Windows::Forms::Panel());
			this->bt_regresarComplementos = (gcnew System::Windows::Forms::Button());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->lb_complementos = (gcnew System::Windows::Forms::ListBox());
			this->pa_Inicio = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->rb_Caracteres = (gcnew System::Windows::Forms::RadioButton());
			this->rb_Numero = (gcnew System::Windows::Forms::RadioButton());
			this->bt_generar = (gcnew System::Windows::Forms::Button());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->tb_NumeroElementos = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->bt_RegresarCaracterRelacion = (gcnew System::Windows::Forms::Button());
			this->pa_ConjuntoA->SuspendLayout();
			this->pa_relacion->SuspendLayout();
			this->pa_EstablecerRelacion->SuspendLayout();
			this->pa_OrdenParcial->SuspendLayout();
			this->pa_EstablecerRelacionCaracter->SuspendLayout();
			this->pa_reticula->SuspendLayout();
			this->pa_Complementos->SuspendLayout();
			this->pa_Inicio->SuspendLayout();
			this->SuspendLayout();
			// 
			// pa_ConjuntoA
			// 
			this->pa_ConjuntoA->Controls->Add(this->bt_regresarInicio);
			this->pa_ConjuntoA->Controls->Add(this->bt_BorrarTodo);
			this->pa_ConjuntoA->Controls->Add(this->bt_Borrar);
			this->pa_ConjuntoA->Controls->Add(this->label4);
			this->pa_ConjuntoA->Controls->Add(this->GenerarAleatorioTodos);
			this->pa_ConjuntoA->Controls->Add(this->tb_NuevoElemento);
			this->pa_ConjuntoA->Controls->Add(this->lbl_ElementosRestantes);
			this->pa_ConjuntoA->Controls->Add(this->bt_DefinirRelacion);
			this->pa_ConjuntoA->Controls->Add(this->bt_GenerarAleatorioRestantes);
			this->pa_ConjuntoA->Controls->Add(this->bt_IngresarElemento);
			this->pa_ConjuntoA->Controls->Add(this->label1);
			this->pa_ConjuntoA->Controls->Add(this->lb_elementosA);
			this->pa_ConjuntoA->Location = System::Drawing::Point(0, 0);
			this->pa_ConjuntoA->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pa_ConjuntoA->Name = L"pa_ConjuntoA";
			this->pa_ConjuntoA->Size = System::Drawing::Size(915, 562);
			this->pa_ConjuntoA->TabIndex = 0;
			this->pa_ConjuntoA->Visible = false;
			// 
			// bt_regresarInicio
			// 
			this->bt_regresarInicio->Location = System::Drawing::Point(748, 14);
			this->bt_regresarInicio->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bt_regresarInicio->Name = L"bt_regresarInicio";
			this->bt_regresarInicio->Size = System::Drawing::Size(154, 43);
			this->bt_regresarInicio->TabIndex = 14;
			this->bt_regresarInicio->Text = L"Regresar";
			this->bt_regresarInicio->UseVisualStyleBackColor = true;
			this->bt_regresarInicio->Click += gcnew System::EventHandler(this, &MyForm::bt_regresarInicio_Click);
			// 
			// bt_BorrarTodo
			// 
			this->bt_BorrarTodo->Location = System::Drawing::Point(768, 351);
			this->bt_BorrarTodo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bt_BorrarTodo->Name = L"bt_BorrarTodo";
			this->bt_BorrarTodo->Size = System::Drawing::Size(115, 43);
			this->bt_BorrarTodo->TabIndex = 13;
			this->bt_BorrarTodo->Text = L"Borrar todo";
			this->bt_BorrarTodo->UseVisualStyleBackColor = true;
			this->bt_BorrarTodo->Click += gcnew System::EventHandler(this, &MyForm::bt_BorrarTodo_Click);
			// 
			// bt_Borrar
			// 
			this->bt_Borrar->Location = System::Drawing::Point(630, 351);
			this->bt_Borrar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bt_Borrar->Name = L"bt_Borrar";
			this->bt_Borrar->Size = System::Drawing::Size(115, 43);
			this->bt_Borrar->TabIndex = 12;
			this->bt_Borrar->Text = L"Borrar";
			this->bt_Borrar->UseVisualStyleBackColor = true;
			this->bt_Borrar->Click += gcnew System::EventHandler(this, &MyForm::bt_Borrar_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Location = System::Drawing::Point(627, 87);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(146, 17);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Ingresar un elemento:";
			// 
			// GenerarAleatorioTodos
			// 
			this->GenerarAleatorioTodos->Location = System::Drawing::Point(630, 267);
			this->GenerarAleatorioTodos->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->GenerarAleatorioTodos->Name = L"GenerarAleatorioTodos";
			this->GenerarAleatorioTodos->Size = System::Drawing::Size(253, 43);
			this->GenerarAleatorioTodos->TabIndex = 9;
			this->GenerarAleatorioTodos->Text = L"Generar automáticamente todos los elementos";
			this->GenerarAleatorioTodos->UseVisualStyleBackColor = true;
			this->GenerarAleatorioTodos->Click += gcnew System::EventHandler(this, &MyForm::GenerarAleatorioTodos_Click);
			// 
			// tb_NuevoElemento
			// 
			this->tb_NuevoElemento->Location = System::Drawing::Point(630, 116);
			this->tb_NuevoElemento->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tb_NuevoElemento->Name = L"tb_NuevoElemento";
			this->tb_NuevoElemento->Size = System::Drawing::Size(253, 22);
			this->tb_NuevoElemento->TabIndex = 8;
			// 
			// lbl_ElementosRestantes
			// 
			this->lbl_ElementosRestantes->AutoSize = true;
			this->lbl_ElementosRestantes->BackColor = System::Drawing::Color::Transparent;
			this->lbl_ElementosRestantes->Location = System::Drawing::Point(29, 455);
			this->lbl_ElementosRestantes->Name = L"lbl_ElementosRestantes";
			this->lbl_ElementosRestantes->Size = System::Drawing::Size(161, 17);
			this->lbl_ElementosRestantes->TabIndex = 7;
			this->lbl_ElementosRestantes->Text = L"Elementos restantes: 20";
			// 
			// bt_DefinirRelacion
			// 
			this->bt_DefinirRelacion->Enabled = false;
			this->bt_DefinirRelacion->Location = System::Drawing::Point(124, 494);
			this->bt_DefinirRelacion->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bt_DefinirRelacion->Name = L"bt_DefinirRelacion";
			this->bt_DefinirRelacion->Size = System::Drawing::Size(389, 43);
			this->bt_DefinirRelacion->TabIndex = 4;
			this->bt_DefinirRelacion->Text = L"Definir una relación";
			this->bt_DefinirRelacion->UseVisualStyleBackColor = true;
			this->bt_DefinirRelacion->Click += gcnew System::EventHandler(this, &MyForm::bt_DefinirRelacion_Click);
			// 
			// bt_GenerarAleatorioRestantes
			// 
			this->bt_GenerarAleatorioRestantes->Location = System::Drawing::Point(630, 219);
			this->bt_GenerarAleatorioRestantes->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bt_GenerarAleatorioRestantes->Name = L"bt_GenerarAleatorioRestantes";
			this->bt_GenerarAleatorioRestantes->Size = System::Drawing::Size(253, 43);
			this->bt_GenerarAleatorioRestantes->TabIndex = 3;
			this->bt_GenerarAleatorioRestantes->Text = L"Generar automáticamente los elementos restantes";
			this->bt_GenerarAleatorioRestantes->UseVisualStyleBackColor = true;
			this->bt_GenerarAleatorioRestantes->Click += gcnew System::EventHandler(this, &MyForm::bt_GenerarAleatorioRestantes_Click);
			// 
			// bt_IngresarElemento
			// 
			this->bt_IngresarElemento->Location = System::Drawing::Point(630, 143);
			this->bt_IngresarElemento->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bt_IngresarElemento->Name = L"bt_IngresarElemento";
			this->bt_IngresarElemento->Size = System::Drawing::Size(253, 43);
			this->bt_IngresarElemento->TabIndex = 2;
			this->bt_IngresarElemento->Text = L"Ingresar elemento";
			this->bt_IngresarElemento->UseVisualStyleBackColor = true;
			this->bt_IngresarElemento->Click += gcnew System::EventHandler(this, &MyForm::bt_IngresarElemento_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"UD Digi Kyokasho NP-B", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label1->Location = System::Drawing::Point(29, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(279, 24);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Elementos del conjunto A:";
			// 
			// lb_elementosA
			// 
			this->lb_elementosA->ItemHeight = 16;
			this->lb_elementosA->Location = System::Drawing::Point(29, 44);
			this->lb_elementosA->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->lb_elementosA->Name = L"lb_elementosA";
			this->lb_elementosA->Size = System::Drawing::Size(561, 404);
			this->lb_elementosA->TabIndex = 0;
			// 
			// lb_productoCartesiano
			// 
			this->lb_productoCartesiano->FormattingEnabled = true;
			this->lb_productoCartesiano->ItemHeight = 16;
			this->lb_productoCartesiano->Location = System::Drawing::Point(13, 55);
			this->lb_productoCartesiano->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->lb_productoCartesiano->Name = L"lb_productoCartesiano";
			this->lb_productoCartesiano->Size = System::Drawing::Size(333, 436);
			this->lb_productoCartesiano->TabIndex = 0;
			// 
			// tm_ElementosRestantes
			// 
			this->tm_ElementosRestantes->Enabled = true;
			this->tm_ElementosRestantes->Tick += gcnew System::EventHandler(this, &MyForm::tm_ElementosRestantes_Tick);
			// 
			// tm_BorrarElemento
			// 
			this->tm_BorrarElemento->Enabled = true;
			this->tm_BorrarElemento->Tick += gcnew System::EventHandler(this, &MyForm::tm_BorrarElemento_Tick);
			// 
			// pa_relacion
			// 
			this->pa_relacion->Controls->Add(this->bt_RelacionAleatoria);
			this->pa_relacion->Controls->Add(this->bt_DeterminarOrdenParcial);
			this->pa_relacion->Controls->Add(this->bt_RegresarConjuntos);
			this->pa_relacion->Controls->Add(this->bt_BorrarTodoRelacion);
			this->pa_relacion->Controls->Add(this->bt_BorrarRelacion);
			this->pa_relacion->Controls->Add(this->bt_condicion);
			this->pa_relacion->Controls->Add(this->bt_AgregarRelacion);
			this->pa_relacion->Controls->Add(this->label5);
			this->pa_relacion->Controls->Add(this->lb_relacion);
			this->pa_relacion->Controls->Add(this->lb_productoCartesiano);
			this->pa_relacion->Controls->Add(this->label2);
			this->pa_relacion->Location = System::Drawing::Point(0, 0);
			this->pa_relacion->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pa_relacion->Name = L"pa_relacion";
			this->pa_relacion->Size = System::Drawing::Size(915, 562);
			this->pa_relacion->TabIndex = 14;
			this->pa_relacion->Visible = false;
			// 
			// bt_RelacionAleatoria
			// 
			this->bt_RelacionAleatoria->Location = System::Drawing::Point(369, 287);
			this->bt_RelacionAleatoria->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bt_RelacionAleatoria->Name = L"bt_RelacionAleatoria";
			this->bt_RelacionAleatoria->Size = System::Drawing::Size(176, 43);
			this->bt_RelacionAleatoria->TabIndex = 11;
			this->bt_RelacionAleatoria->Text = L"Generar aleatoriamente";
			this->bt_RelacionAleatoria->UseVisualStyleBackColor = true;
			this->bt_RelacionAleatoria->Click += gcnew System::EventHandler(this, &MyForm::bt_RelacionAleatoria_Click);
			// 
			// bt_DeterminarOrdenParcial
			// 
			this->bt_DeterminarOrdenParcial->Location = System::Drawing::Point(630, 507);
			this->bt_DeterminarOrdenParcial->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bt_DeterminarOrdenParcial->Name = L"bt_DeterminarOrdenParcial";
			this->bt_DeterminarOrdenParcial->Size = System::Drawing::Size(272, 43);
			this->bt_DeterminarOrdenParcial->TabIndex = 10;
			this->bt_DeterminarOrdenParcial->Text = L"Determinar relación de orden parcial";
			this->bt_DeterminarOrdenParcial->UseVisualStyleBackColor = true;
			this->bt_DeterminarOrdenParcial->Click += gcnew System::EventHandler(this, &MyForm::bt_DeterminarOrdenParcial_Click);
			// 
			// bt_RegresarConjuntos
			// 
			this->bt_RegresarConjuntos->Location = System::Drawing::Point(13, 507);
			this->bt_RegresarConjuntos->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bt_RegresarConjuntos->Name = L"bt_RegresarConjuntos";
			this->bt_RegresarConjuntos->Size = System::Drawing::Size(176, 43);
			this->bt_RegresarConjuntos->TabIndex = 9;
			this->bt_RegresarConjuntos->Text = L"Regresar";
			this->bt_RegresarConjuntos->UseVisualStyleBackColor = true;
			this->bt_RegresarConjuntos->Click += gcnew System::EventHandler(this, &MyForm::bt_RegresarConjuntos_Click);
			// 
			// bt_BorrarTodoRelacion
			// 
			this->bt_BorrarTodoRelacion->Location = System::Drawing::Point(369, 444);
			this->bt_BorrarTodoRelacion->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bt_BorrarTodoRelacion->Name = L"bt_BorrarTodoRelacion";
			this->bt_BorrarTodoRelacion->Size = System::Drawing::Size(176, 43);
			this->bt_BorrarTodoRelacion->TabIndex = 8;
			this->bt_BorrarTodoRelacion->Text = L"Borrar todo";
			this->bt_BorrarTodoRelacion->UseVisualStyleBackColor = true;
			this->bt_BorrarTodoRelacion->Click += gcnew System::EventHandler(this, &MyForm::bt_BorrarTodoRelacion_Click);
			// 
			// bt_BorrarRelacion
			// 
			this->bt_BorrarRelacion->Location = System::Drawing::Point(369, 386);
			this->bt_BorrarRelacion->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bt_BorrarRelacion->Name = L"bt_BorrarRelacion";
			this->bt_BorrarRelacion->Size = System::Drawing::Size(176, 43);
			this->bt_BorrarRelacion->TabIndex = 7;
			this->bt_BorrarRelacion->Text = L"Borrar";
			this->bt_BorrarRelacion->UseVisualStyleBackColor = true;
			this->bt_BorrarRelacion->Click += gcnew System::EventHandler(this, &MyForm::bt_BorrarRelacion_Click);
			// 
			// bt_condicion
			// 
			this->bt_condicion->Location = System::Drawing::Point(369, 232);
			this->bt_condicion->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bt_condicion->Name = L"bt_condicion";
			this->bt_condicion->Size = System::Drawing::Size(176, 43);
			this->bt_condicion->TabIndex = 6;
			this->bt_condicion->Text = L"Establecer una condición";
			this->bt_condicion->UseVisualStyleBackColor = true;
			this->bt_condicion->Click += gcnew System::EventHandler(this, &MyForm::bt_condicion_Click);
			// 
			// bt_AgregarRelacion
			// 
			this->bt_AgregarRelacion->Enabled = false;
			this->bt_AgregarRelacion->Location = System::Drawing::Point(369, 108);
			this->bt_AgregarRelacion->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bt_AgregarRelacion->Name = L"bt_AgregarRelacion";
			this->bt_AgregarRelacion->Size = System::Drawing::Size(176, 44);
			this->bt_AgregarRelacion->TabIndex = 5;
			this->bt_AgregarRelacion->Text = L"Agregar a la relación";
			this->bt_AgregarRelacion->UseVisualStyleBackColor = true;
			this->bt_AgregarRelacion->Click += gcnew System::EventHandler(this, &MyForm::bt_AgregarRelacion_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"UD Digi Kyokasho NP-B", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label5->Location = System::Drawing::Point(565, 21);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(107, 20);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Relación R:";
			// 
			// lb_relacion
			// 
			this->lb_relacion->FormattingEnabled = true;
			this->lb_relacion->ItemHeight = 16;
			this->lb_relacion->Location = System::Drawing::Point(569, 55);
			this->lb_relacion->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->lb_relacion->Name = L"lb_relacion";
			this->lb_relacion->Size = System::Drawing::Size(333, 436);
			this->lb_relacion->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"UD Digi Kyokasho NP-B", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label2->Location = System::Drawing::Point(3, 21);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(367, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Elementos del producto cartesiano A x A:";
			// 
			// pa_EstablecerRelacion
			// 
			this->pa_EstablecerRelacion->Controls->Add(this->bt_regresarRela);
			this->pa_EstablecerRelacion->Controls->Add(this->label7);
			this->pa_EstablecerRelacion->Controls->Add(this->bt_establecercondicion);
			this->pa_EstablecerRelacion->Controls->Add(this->tb_resultado);
			this->pa_EstablecerRelacion->Controls->Add(this->cb_operador2);
			this->pa_EstablecerRelacion->Controls->Add(this->cb_valor2);
			this->pa_EstablecerRelacion->Controls->Add(this->cb_operador1);
			this->pa_EstablecerRelacion->Controls->Add(this->cb_valor1);
			this->pa_EstablecerRelacion->Controls->Add(this->label6);
			this->pa_EstablecerRelacion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->pa_EstablecerRelacion->Location = System::Drawing::Point(0, 0);
			this->pa_EstablecerRelacion->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pa_EstablecerRelacion->Name = L"pa_EstablecerRelacion";
			this->pa_EstablecerRelacion->Size = System::Drawing::Size(913, 558);
			this->pa_EstablecerRelacion->TabIndex = 8;
			this->pa_EstablecerRelacion->Visible = false;
			// 
			// bt_regresarRela
			// 
			this->bt_regresarRela->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bt_regresarRela->Location = System::Drawing::Point(28, 474);
			this->bt_regresarRela->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bt_regresarRela->Name = L"bt_regresarRela";
			this->bt_regresarRela->Size = System::Drawing::Size(176, 43);
			this->bt_regresarRela->TabIndex = 10;
			this->bt_regresarRela->Text = L"Regresar";
			this->bt_regresarRela->UseVisualStyleBackColor = true;
			this->bt_regresarRela->Click += gcnew System::EventHandler(this, &MyForm::bt_regresarRela_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Location = System::Drawing::Point(363, 137);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(200, 25);
			this->label7->TabIndex = 7;
			this->label7->Text = L"R = { (a, b) ∈ A x A /...";
			// 
			// bt_establecercondicion
			// 
			this->bt_establecercondicion->Enabled = false;
			this->bt_establecercondicion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->bt_establecercondicion->Location = System::Drawing::Point(341, 249);
			this->bt_establecercondicion->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bt_establecercondicion->Name = L"bt_establecercondicion";
			this->bt_establecercondicion->Size = System::Drawing::Size(221, 47);
			this->bt_establecercondicion->TabIndex = 6;
			this->bt_establecercondicion->Text = L"Establecer condición";
			this->bt_establecercondicion->UseVisualStyleBackColor = true;
			this->bt_establecercondicion->Click += gcnew System::EventHandler(this, &MyForm::bt_establecercondicion_Click);
			// 
			// tb_resultado
			// 
			this->tb_resultado->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tb_resultado->Location = System::Drawing::Point(609, 190);
			this->tb_resultado->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tb_resultado->Name = L"tb_resultado";
			this->tb_resultado->Size = System::Drawing::Size(89, 23);
			this->tb_resultado->TabIndex = 5;
			// 
			// cb_operador2
			// 
			this->cb_operador2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cb_operador2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cb_operador2->FormattingEnabled = true;
			this->cb_operador2->Location = System::Drawing::Point(452, 187);
			this->cb_operador2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->cb_operador2->Name = L"cb_operador2";
			this->cb_operador2->Size = System::Drawing::Size(137, 25);
			this->cb_operador2->TabIndex = 4;
			// 
			// cb_valor2
			// 
			this->cb_valor2->BackColor = System::Drawing::SystemColors::Window;
			this->cb_valor2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cb_valor2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cb_valor2->FormattingEnabled = true;
			this->cb_valor2->Location = System::Drawing::Point(379, 187);
			this->cb_valor2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->cb_valor2->Name = L"cb_valor2";
			this->cb_valor2->Size = System::Drawing::Size(51, 25);
			this->cb_valor2->TabIndex = 3;
			this->cb_valor2->Tag = L"a, b";
			// 
			// cb_operador1
			// 
			this->cb_operador1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cb_operador1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cb_operador1->FormattingEnabled = true;
			this->cb_operador1->Location = System::Drawing::Point(315, 187);
			this->cb_operador1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->cb_operador1->Name = L"cb_operador1";
			this->cb_operador1->Size = System::Drawing::Size(44, 25);
			this->cb_operador1->TabIndex = 2;
			// 
			// cb_valor1
			// 
			this->cb_valor1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cb_valor1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cb_valor1->FormattingEnabled = true;
			this->cb_valor1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->cb_valor1->Location = System::Drawing::Point(237, 187);
			this->cb_valor1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->cb_valor1->Name = L"cb_valor1";
			this->cb_valor1->Size = System::Drawing::Size(57, 25);
			this->cb_valor1->TabIndex = 1;
			this->cb_valor1->Tag = L"a, b";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(189, 21);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(540, 61);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Establecer una condición";
			// 
			// tm_condicion
			// 
			this->tm_condicion->Enabled = true;
			this->tm_condicion->Tick += gcnew System::EventHandler(this, &MyForm::tm_condicion_Tick);
			// 
			// pa_OrdenParcial
			// 
			this->pa_OrdenParcial->Controls->Add(this->bt_DeterminarReticula);
			this->pa_OrdenParcial->Controls->Add(this->bt_RegresarRelacion);
			this->pa_OrdenParcial->Controls->Add(this->bt_dibujarHasse);
			this->pa_OrdenParcial->Controls->Add(this->lbl_ordenParcial);
			this->pa_OrdenParcial->Controls->Add(this->lbl_transitiva);
			this->pa_OrdenParcial->Controls->Add(this->lbl_antisimetrica);
			this->pa_OrdenParcial->Controls->Add(this->lbl_reflexiva);
			this->pa_OrdenParcial->Controls->Add(this->label8);
			this->pa_OrdenParcial->Location = System::Drawing::Point(0, 0);
			this->pa_OrdenParcial->Name = L"pa_OrdenParcial";
			this->pa_OrdenParcial->Size = System::Drawing::Size(915, 562);
			this->pa_OrdenParcial->TabIndex = 11;
			this->pa_OrdenParcial->Visible = false;
			// 
			// bt_DeterminarReticula
			// 
			this->bt_DeterminarReticula->Location = System::Drawing::Point(486, 418);
			this->bt_DeterminarReticula->Name = L"bt_DeterminarReticula";
			this->bt_DeterminarReticula->Size = System::Drawing::Size(231, 53);
			this->bt_DeterminarReticula->TabIndex = 9;
			this->bt_DeterminarReticula->Text = L"Determinar retícula";
			this->bt_DeterminarReticula->UseVisualStyleBackColor = true;
			this->bt_DeterminarReticula->Click += gcnew System::EventHandler(this, &MyForm::bt_DeterminarReticula_Click);
			// 
			// bt_RegresarRelacion
			// 
			this->bt_RegresarRelacion->Location = System::Drawing::Point(13, 507);
			this->bt_RegresarRelacion->Name = L"bt_RegresarRelacion";
			this->bt_RegresarRelacion->Size = System::Drawing::Size(201, 41);
			this->bt_RegresarRelacion->TabIndex = 8;
			this->bt_RegresarRelacion->Text = L"Regresar";
			this->bt_RegresarRelacion->UseVisualStyleBackColor = true;
			this->bt_RegresarRelacion->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// bt_dibujarHasse
			// 
			this->bt_dibujarHasse->Location = System::Drawing::Point(175, 418);
			this->bt_dibujarHasse->Name = L"bt_dibujarHasse";
			this->bt_dibujarHasse->Size = System::Drawing::Size(231, 53);
			this->bt_dibujarHasse->TabIndex = 7;
			this->bt_dibujarHasse->Text = L"Dibujar diagrama de Hasse";
			this->bt_dibujarHasse->UseVisualStyleBackColor = true;
			this->bt_dibujarHasse->Click += gcnew System::EventHandler(this, &MyForm::bt_dibujarHasse_Click);
			// 
			// lbl_ordenParcial
			// 
			this->lbl_ordenParcial->AutoSize = true;
			this->lbl_ordenParcial->BackColor = System::Drawing::Color::Transparent;
			this->lbl_ordenParcial->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_ordenParcial->Location = System::Drawing::Point(282, 354);
			this->lbl_ordenParcial->Name = L"lbl_ordenParcial";
			this->lbl_ordenParcial->Size = System::Drawing::Size(331, 30);
			this->lbl_ordenParcial->TabIndex = 6;
			this->lbl_ordenParcial->Text = L"La relación es de orden parcial";
			// 
			// lbl_transitiva
			// 
			this->lbl_transitiva->AutoSize = true;
			this->lbl_transitiva->BackColor = System::Drawing::Color::Transparent;
			this->lbl_transitiva->Font = (gcnew System::Drawing::Font(L"UD Digi Kyokasho NP-B", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->lbl_transitiva->Location = System::Drawing::Point(196, 277);
			this->lbl_transitiva->Name = L"lbl_transitiva";
			this->lbl_transitiva->Size = System::Drawing::Size(197, 20);
			this->lbl_transitiva->TabIndex = 5;
			this->lbl_transitiva->Text = L"Propiedad transitiva:";
			// 
			// lbl_antisimetrica
			// 
			this->lbl_antisimetrica->AutoSize = true;
			this->lbl_antisimetrica->BackColor = System::Drawing::Color::Transparent;
			this->lbl_antisimetrica->Font = (gcnew System::Drawing::Font(L"UD Digi Kyokasho NP-B", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->lbl_antisimetrica->Location = System::Drawing::Point(196, 214);
			this->lbl_antisimetrica->Name = L"lbl_antisimetrica";
			this->lbl_antisimetrica->Size = System::Drawing::Size(228, 20);
			this->lbl_antisimetrica->TabIndex = 4;
			this->lbl_antisimetrica->Text = L"Propiedad antisimétrica:";
			// 
			// lbl_reflexiva
			// 
			this->lbl_reflexiva->AutoSize = true;
			this->lbl_reflexiva->BackColor = System::Drawing::Color::Transparent;
			this->lbl_reflexiva->Font = (gcnew System::Drawing::Font(L"UD Digi Kyokasho NP-B", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->lbl_reflexiva->Location = System::Drawing::Point(196, 151);
			this->lbl_reflexiva->Name = L"lbl_reflexiva";
			this->lbl_reflexiva->Size = System::Drawing::Size(187, 20);
			this->lbl_reflexiva->TabIndex = 3;
			this->lbl_reflexiva->Text = L"Propiedad reflexiva:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(146, 33);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(599, 61);
			this->label8->TabIndex = 1;
			this->label8->Text = L"¿Relación de orden parcial\?";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Location = System::Drawing::Point(405, 122);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(146, 17);
			this->label9->TabIndex = 8;
			this->label9->Text = L"R = { (a, b) ∈ A x A /...";
			// 
			// pa_EstablecerRelacionCaracter
			// 
			this->pa_EstablecerRelacionCaracter->Controls->Add(this->bt_RegresarCaracterRelacion);
			this->pa_EstablecerRelacionCaracter->Controls->Add(this->bt_EstablecerCaracter);
			this->pa_EstablecerRelacionCaracter->Controls->Add(this->cb_caracterOperador);
			this->pa_EstablecerRelacionCaracter->Controls->Add(this->cb_caracter2);
			this->pa_EstablecerRelacionCaracter->Controls->Add(this->cb_caracter1);
			this->pa_EstablecerRelacionCaracter->Controls->Add(this->label10);
			this->pa_EstablecerRelacionCaracter->Controls->Add(this->label9);
			this->pa_EstablecerRelacionCaracter->Location = System::Drawing::Point(0, 0);
			this->pa_EstablecerRelacionCaracter->Name = L"pa_EstablecerRelacionCaracter";
			this->pa_EstablecerRelacionCaracter->Size = System::Drawing::Size(912, 562);
			this->pa_EstablecerRelacionCaracter->TabIndex = 11;
			this->pa_EstablecerRelacionCaracter->Visible = false;
			// 
			// bt_EstablecerCaracter
			// 
			this->bt_EstablecerCaracter->Enabled = false;
			this->bt_EstablecerCaracter->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->bt_EstablecerCaracter->Location = System::Drawing::Point(366, 236);
			this->bt_EstablecerCaracter->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bt_EstablecerCaracter->Name = L"bt_EstablecerCaracter";
			this->bt_EstablecerCaracter->Size = System::Drawing::Size(221, 47);
			this->bt_EstablecerCaracter->TabIndex = 13;
			this->bt_EstablecerCaracter->Text = L"Establecer condición";
			this->bt_EstablecerCaracter->UseVisualStyleBackColor = true;
			this->bt_EstablecerCaracter->Click += gcnew System::EventHandler(this, &MyForm::bt_EstablecerCaracter_Click);
			// 
			// cb_caracterOperador
			// 
			this->cb_caracterOperador->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cb_caracterOperador->FormattingEnabled = true;
			this->cb_caracterOperador->Location = System::Drawing::Point(449, 163);
			this->cb_caracterOperador->Name = L"cb_caracterOperador";
			this->cb_caracterOperador->Size = System::Drawing::Size(54, 24);
			this->cb_caracterOperador->TabIndex = 12;
			// 
			// cb_caracter2
			// 
			this->cb_caracter2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cb_caracter2->FormattingEnabled = true;
			this->cb_caracter2->Location = System::Drawing::Point(536, 163);
			this->cb_caracter2->Name = L"cb_caracter2";
			this->cb_caracter2->Size = System::Drawing::Size(50, 24);
			this->cb_caracter2->TabIndex = 11;
			// 
			// cb_caracter1
			// 
			this->cb_caracter1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cb_caracter1->FormattingEnabled = true;
			this->cb_caracter1->Location = System::Drawing::Point(365, 163);
			this->cb_caracter1->Name = L"cb_caracter1";
			this->cb_caracter1->Size = System::Drawing::Size(54, 24);
			this->cb_caracter1->TabIndex = 10;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(202, 23);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(540, 61);
			this->label10->TabIndex = 9;
			this->label10->Text = L"Establecer una condición";
			// 
			// pa_reticula
			// 
			this->pa_reticula->Controls->Add(this->lbl_reticula);
			this->pa_reticula->Controls->Add(this->bt_regresarReticula);
			this->pa_reticula->Controls->Add(this->bt_HallarComplementos);
			this->pa_reticula->Controls->Add(this->lbl_supremo);
			this->pa_reticula->Controls->Add(this->lbl_infimo);
			this->pa_reticula->Controls->Add(this->label11);
			this->pa_reticula->Location = System::Drawing::Point(0, 0);
			this->pa_reticula->Name = L"pa_reticula";
			this->pa_reticula->Size = System::Drawing::Size(915, 562);
			this->pa_reticula->TabIndex = 10;
			this->pa_reticula->Visible = false;
			// 
			// lbl_reticula
			// 
			this->lbl_reticula->AutoSize = true;
			this->lbl_reticula->BackColor = System::Drawing::Color::Transparent;
			this->lbl_reticula->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_reticula->Location = System::Drawing::Point(394, 332);
			this->lbl_reticula->Name = L"lbl_reticula";
			this->lbl_reticula->Size = System::Drawing::Size(192, 36);
			this->lbl_reticula->TabIndex = 8;
			this->lbl_reticula->Text = L"Es una retícula";
			// 
			// bt_regresarReticula
			// 
			this->bt_regresarReticula->Location = System::Drawing::Point(184, 411);
			this->bt_regresarReticula->Name = L"bt_regresarReticula";
			this->bt_regresarReticula->Size = System::Drawing::Size(250, 58);
			this->bt_regresarReticula->TabIndex = 7;
			this->bt_regresarReticula->Text = L"Regresar";
			this->bt_regresarReticula->UseVisualStyleBackColor = true;
			this->bt_regresarReticula->Click += gcnew System::EventHandler(this, &MyForm::bt_regresarReticula_Click);
			// 
			// bt_HallarComplementos
			// 
			this->bt_HallarComplementos->Location = System::Drawing::Point(523, 415);
			this->bt_HallarComplementos->Name = L"bt_HallarComplementos";
			this->bt_HallarComplementos->Size = System::Drawing::Size(250, 58);
			this->bt_HallarComplementos->TabIndex = 6;
			this->bt_HallarComplementos->Text = L"Hallar el complemento de los vértices";
			this->bt_HallarComplementos->UseVisualStyleBackColor = true;
			this->bt_HallarComplementos->Click += gcnew System::EventHandler(this, &MyForm::bt_HallarComplementos_Click);
			// 
			// lbl_supremo
			// 
			this->lbl_supremo->AutoSize = true;
			this->lbl_supremo->BackColor = System::Drawing::Color::Transparent;
			this->lbl_supremo->Font = (gcnew System::Drawing::Font(L"UD Digi Kyokasho NP-B", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->lbl_supremo->Location = System::Drawing::Point(119, 245);
			this->lbl_supremo->Name = L"lbl_supremo";
			this->lbl_supremo->Size = System::Drawing::Size(585, 28);
			this->lbl_supremo->TabIndex = 5;
			this->lbl_supremo->Text = L"Para cada {a,b} pertenece a A, tiene supremo: ";
			// 
			// lbl_infimo
			// 
			this->lbl_infimo->AutoSize = true;
			this->lbl_infimo->BackColor = System::Drawing::Color::Transparent;
			this->lbl_infimo->Font = (gcnew System::Drawing::Font(L"UD Digi Kyokasho NP-B", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->lbl_infimo->Location = System::Drawing::Point(119, 190);
			this->lbl_infimo->Name = L"lbl_infimo";
			this->lbl_infimo->Size = System::Drawing::Size(559, 28);
			this->lbl_infimo->TabIndex = 4;
			this->lbl_infimo->Text = L"Para cada {a,b} pertenece a A, tiene ínfimo: ";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::Color::Transparent;
			this->label11->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(343, 55);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(244, 61);
			this->label11->TabIndex = 2;
			this->label11->Text = L"¿Retícula\?";
			// 
			// pa_Complementos
			// 
			this->pa_Complementos->Controls->Add(this->bt_regresarComplementos);
			this->pa_Complementos->Controls->Add(this->label14);
			this->pa_Complementos->Controls->Add(this->lb_complementos);
			this->pa_Complementos->Location = System::Drawing::Point(0, 0);
			this->pa_Complementos->Name = L"pa_Complementos";
			this->pa_Complementos->Size = System::Drawing::Size(915, 562);
			this->pa_Complementos->TabIndex = 8;
			this->pa_Complementos->Visible = false;
			// 
			// bt_regresarComplementos
			// 
			this->bt_regresarComplementos->Location = System::Drawing::Point(49, 477);
			this->bt_regresarComplementos->Name = L"bt_regresarComplementos";
			this->bt_regresarComplementos->Size = System::Drawing::Size(264, 46);
			this->bt_regresarComplementos->TabIndex = 2;
			this->bt_regresarComplementos->Text = L"Regresar";
			this->bt_regresarComplementos->UseVisualStyleBackColor = true;
			this->bt_regresarComplementos->Click += gcnew System::EventHandler(this, &MyForm::bt_regresarComplementos_Click);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->BackColor = System::Drawing::Color::Transparent;
			this->label14->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(260, 21);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(399, 37);
			this->label14->TabIndex = 1;
			this->label14->Text = L"Complementos de vértices";
			// 
			// lb_complementos
			// 
			this->lb_complementos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lb_complementos->FormattingEnabled = true;
			this->lb_complementos->ItemHeight = 25;
			this->lb_complementos->Location = System::Drawing::Point(49, 83);
			this->lb_complementos->Name = L"lb_complementos";
			this->lb_complementos->Size = System::Drawing::Size(820, 354);
			this->lb_complementos->TabIndex = 0;
			// 
			// pa_Inicio
			// 
			this->pa_Inicio->Controls->Add(this->label3);
			this->pa_Inicio->Controls->Add(this->rb_Caracteres);
			this->pa_Inicio->Controls->Add(this->rb_Numero);
			this->pa_Inicio->Controls->Add(this->bt_generar);
			this->pa_Inicio->Controls->Add(this->label13);
			this->pa_Inicio->Controls->Add(this->tb_NumeroElementos);
			this->pa_Inicio->Controls->Add(this->label12);
			this->pa_Inicio->Location = System::Drawing::Point(0, 0);
			this->pa_Inicio->Name = L"pa_Inicio";
			this->pa_Inicio->Size = System::Drawing::Size(915, 562);
			this->pa_Inicio->TabIndex = 10;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(145, 352);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(163, 25);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Tipo de conjunto:";
			// 
			// rb_Caracteres
			// 
			this->rb_Caracteres->AutoSize = true;
			this->rb_Caracteres->BackColor = System::Drawing::Color::Transparent;
			this->rb_Caracteres->Location = System::Drawing::Point(492, 354);
			this->rb_Caracteres->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->rb_Caracteres->Name = L"rb_Caracteres";
			this->rb_Caracteres->Size = System::Drawing::Size(98, 21);
			this->rb_Caracteres->TabIndex = 12;
			this->rb_Caracteres->TabStop = true;
			this->rb_Caracteres->Text = L"Caracteres";
			this->rb_Caracteres->UseVisualStyleBackColor = false;
			// 
			// rb_Numero
			// 
			this->rb_Numero->AutoSize = true;
			this->rb_Numero->BackColor = System::Drawing::Color::Transparent;
			this->rb_Numero->Location = System::Drawing::Point(348, 354);
			this->rb_Numero->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->rb_Numero->Name = L"rb_Numero";
			this->rb_Numero->Size = System::Drawing::Size(86, 21);
			this->rb_Numero->TabIndex = 11;
			this->rb_Numero->TabStop = true;
			this->rb_Numero->Text = L"Números";
			this->rb_Numero->UseVisualStyleBackColor = false;
			// 
			// bt_generar
			// 
			this->bt_generar->Location = System::Drawing::Point(294, 432);
			this->bt_generar->Name = L"bt_generar";
			this->bt_generar->Size = System::Drawing::Size(319, 59);
			this->bt_generar->TabIndex = 3;
			this->bt_generar->Text = L"Generar conjunto A";
			this->bt_generar->UseVisualStyleBackColor = true;
			this->bt_generar->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->BackColor = System::Drawing::Color::Transparent;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(138, 277);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(425, 25);
			this->label13->TabIndex = 2;
			this->label13->Text = L"Ingrese el numero de elementos del conjunto A:";
			// 
			// tb_NumeroElementos
			// 
			this->tb_NumeroElementos->Location = System::Drawing::Point(614, 277);
			this->tb_NumeroElementos->Name = L"tb_NumeroElementos";
			this->tb_NumeroElementos->Size = System::Drawing::Size(58, 22);
			this->tb_NumeroElementos->TabIndex = 1;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BackColor = System::Drawing::Color::Transparent;
			this->label12->Font = (gcnew System::Drawing::Font(L"Oswald", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(146, 113);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(597, 63);
			this->label12->TabIndex = 0;
			this->label12->Text = L"Relaciones y Diagrama de Hasse";
			this->label12->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// bt_RegresarCaracterRelacion
			// 
			this->bt_RegresarCaracterRelacion->Enabled = false;
			this->bt_RegresarCaracterRelacion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->bt_RegresarCaracterRelacion->Location = System::Drawing::Point(33, 477);
			this->bt_RegresarCaracterRelacion->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bt_RegresarCaracterRelacion->Name = L"bt_RegresarCaracterRelacion";
			this->bt_RegresarCaracterRelacion->Size = System::Drawing::Size(181, 47);
			this->bt_RegresarCaracterRelacion->TabIndex = 14;
			this->bt_RegresarCaracterRelacion->Text = L"Regresar";
			this->bt_RegresarCaracterRelacion->UseVisualStyleBackColor = true;
			this->bt_RegresarCaracterRelacion->Click += gcnew System::EventHandler(this, &MyForm::bt_RegresarCaracterRelacion_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(915, 561);
			this->Controls->Add(this->pa_EstablecerRelacionCaracter);
			this->Controls->Add(this->pa_reticula);
			this->Controls->Add(this->pa_Complementos);
			this->Controls->Add(this->pa_OrdenParcial);
			this->Controls->Add(this->pa_EstablecerRelacion);
			this->Controls->Add(this->pa_relacion);
			this->Controls->Add(this->pa_ConjuntoA);
			this->Controls->Add(this->pa_Inicio);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Relaciones y Diagrama de Hasse";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->pa_ConjuntoA->ResumeLayout(false);
			this->pa_ConjuntoA->PerformLayout();
			this->pa_relacion->ResumeLayout(false);
			this->pa_relacion->PerformLayout();
			this->pa_EstablecerRelacion->ResumeLayout(false);
			this->pa_EstablecerRelacion->PerformLayout();
			this->pa_OrdenParcial->ResumeLayout(false);
			this->pa_OrdenParcial->PerformLayout();
			this->pa_EstablecerRelacionCaracter->ResumeLayout(false);
			this->pa_EstablecerRelacionCaracter->PerformLayout();
			this->pa_reticula->ResumeLayout(false);
			this->pa_reticula->PerformLayout();
			this->pa_Complementos->ResumeLayout(false);
			this->pa_Complementos->PerformLayout();
			this->pa_Inicio->ResumeLayout(false);
			this->pa_Inicio->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

		void ListarElementos() {
			lb_elementosA->Items->Clear();
			if (charOnum == true) {
				for (short i = 0; i < conjunto_caracter->getConjuntoCaracter().size(); i++) {
					string std_str_caracter(1, conjunto_caracter->getConjuntoCaracter()[i]);
					String^ sys_str_caracter = gcnew String(std_str_caracter.c_str());
					lb_elementosA->Items->Add(sys_str_caracter);
				}
			}
			if (charOnum == false) {
				for (short i = 0; i < conjunto_numero->getConjuntoNumero().size(); i++) {
					lb_elementosA->Items->Add(conjunto_numero->getConjuntoNumero()[i]);
				}
			}
		}

		char CaracterAleatorio() {
			char carac;
			do {
				carac = rand() % (126 + 1 - 33) + 33;
			} while (carac == 44 || (carac >= 48 && carac <= 57) || (carac >= 60 && carac <= 62) || (carac >= 39 && carac <= 42) || carac == 93 || carac == 91 || carac == 123 || carac == 125 || carac == 34 || carac == 96 || carac == 44 || carac == 46 || carac == 58 || carac == 59 || carac == 94);
			return carac;
		}

		int NumeroAleatorio() {
			return rand() % (999 + 1 - 1) + 1;
		}

		bool EsNumero(char numero[3], int cantidad) {
			for (short i = 0; i < cantidad; i++) {
				if (!isdigit(numero[i])) return false;
			}
			return true;
		}

		void BorrarTodo() {
			if (charOnum == true) {
				short cantidad = conjunto_caracter->getConjuntoCaracter().size();
				for (short i = 0; i < cantidad; i++) {
					conjunto_caracter->EliminarElemento(conjunto_caracter->getConjuntoCaracter().size() - 1);
				}
			}
			if (charOnum == false) {
				short cantidad = conjunto_numero->getConjuntoNumero().size();
				for (short i = 0; i < cantidad; i++) {
					conjunto_numero->EliminarElemento(conjunto_numero->getConjuntoNumero().size() - 1);
				}
			}
			lb_elementosA->Items->Clear();
		}

	private: System::Void bt_BorrarTodo_Click(System::Object^ sender, System::EventArgs^ e) {
		BorrarTodo();
	}
	private: System::Void tm_ElementosRestantes_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (charOnum == true) {

			short restante = conjunto_caracter->getCantidad() - conjunto_caracter->getConjuntoCaracter().size();

			lbl_ElementosRestantes->Text = "Elementos restantes: " + restante;

			if (restante == 0) bt_DefinirRelacion->Enabled = true;
			else bt_DefinirRelacion->Enabled = false;
		}
		else if (charOnum == false) {
			short restante = conjunto_numero->getCantidad() - conjunto_numero->getConjuntoNumero().size();

			lbl_ElementosRestantes->Text = "Elementos restantes: " + restante;

			if (restante == 0) bt_DefinirRelacion->Enabled = true;
			else bt_DefinirRelacion->Enabled = false;
		}
		if (conjunto_caracter->getConjuntoCaracter().size() == conjunto_caracter->getCantidad() || conjunto_numero->getConjuntoNumero().size() == conjunto_numero->getCantidad()) bt_IngresarElemento->Enabled = false;
		else bt_IngresarElemento->Enabled = true;

		if (lb_productoCartesiano->SelectedIndex != -1) bt_AgregarRelacion->Enabled = true;
		else bt_AgregarRelacion->Enabled = false;
	}

	private: System::Void bt_GenerarAleatorioRestantes_Click(System::Object^ sender, System::EventArgs^ e) {
		if (charOnum == true) {
			for (short i = conjunto_caracter->getConjuntoCaracter().size(); i < conjunto_caracter->getCantidad(); i++) {
				bool repetir;
				do {
					repetir = conjunto_caracter->IngresarElemento(CaracterAleatorio());
				} while (repetir == true);
			}
			ListarElementos();
		}
		else if (charOnum == false) {
			for (short i = conjunto_numero->getConjuntoNumero().size(); i < conjunto_numero->getCantidad(); i++) {
				bool repetir;
				do {
					repetir = conjunto_numero->IngresarElemento(NumeroAleatorio());
				} while (repetir == true);
			}
			ListarElementos();
		}
	}
	private: System::Void GenerarAleatorioTodos_Click(System::Object^ sender, System::EventArgs^ e) {
		if (charOnum == true) {
			short cantidad = conjunto_caracter->getConjuntoCaracter().size();
			for (short i = 0; i < cantidad; i++) {
				conjunto_caracter->EliminarElemento(conjunto_caracter->getConjuntoCaracter().size() - 1);
			}

			for (short i = conjunto_caracter->getConjuntoCaracter().size(); i < conjunto_caracter->getCantidad(); i++) {
				bool repetir;
				do {
					repetir = conjunto_caracter->IngresarElemento(CaracterAleatorio());
				} while (repetir == true);
			}
			ListarElementos();
		}
		else if (charOnum == false) {
			short cantidad = conjunto_numero->getConjuntoNumero().size();
			for (short i = 0; i < cantidad; i++) {
				conjunto_numero->EliminarElemento(conjunto_numero->getConjuntoNumero().size() - 1);
			}

			for (short i = conjunto_numero->getConjuntoNumero().size(); i < conjunto_numero->getCantidad(); i++) {
				bool repetir;
				do {
					repetir = conjunto_numero->IngresarElemento(NumeroAleatorio());
				} while (repetir == true);
			}
			ListarElementos();
		}
	}
	private: System::Void tm_BorrarElemento_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (conjunto_caracter->getConjuntoCaracter().size() == 0 && conjunto_numero->getConjuntoNumero().size() == 0) {
			bt_BorrarTodo->Enabled = false;
			bt_Borrar->Enabled = false;
		}
		else {
			if (lb_elementosA->SelectedIndex != -1) {
				bt_Borrar->Enabled = true;
			}
			else {
				bt_Borrar->Enabled = false;
			}
			bt_BorrarTodo->Enabled = true;
		}
		if (lb_relacion->SelectedIndex == -1) bt_BorrarRelacion->Enabled = false;
		else bt_BorrarRelacion->Enabled = true;
		if (lb_relacion->Items->Count > 0) {
			bt_BorrarTodoRelacion->Enabled = true;
			bt_DeterminarOrdenParcial->Enabled = true;
		}
		else {
			bt_BorrarTodoRelacion->Enabled = false;
			bt_DeterminarOrdenParcial->Enabled = false;
		}
	}
	private: System::Void bt_Borrar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (charOnum == true) {
			conjunto_caracter->EliminarElemento(lb_elementosA->SelectedIndex);
		}
		else if (charOnum == false) {
			conjunto_numero->EliminarElemento(lb_elementosA->SelectedIndex);
		}
		ListarElementos();
	}
	private: System::Void bt_IngresarElemento_Click(System::Object^ sender, System::EventArgs^ e) {
		if (tb_NuevoElemento->Text->Length == 0) {
			MessageBox::Show("No ha ingresado ningún elemento. Ingrese algún elemento para añadir al conjunto");
			tb_NuevoElemento->Focus();
			return;
		}
		if (charOnum == true) {
			if (tb_NuevoElemento->Text->Length > 1) {
				MessageBox::Show("Solo se puede ingresar elementos de un solo caracter");
				tb_NuevoElemento->Text = "";
				tb_NuevoElemento->Focus();
				return;
			}

			char caracter = Convert::ToChar(tb_NuevoElemento->Text);

			if (isdigit(caracter)) {
				MessageBox::Show("El elemento ingresado no es un caracter");
				tb_NuevoElemento->Focus();
				tb_NuevoElemento->Text = "";
				return;
			}
			if (caracter == 44 || (caracter >= 48 && caracter <= 57) || (caracter >= 60 && caracter <= 62) || (caracter >= 39 && caracter <= 42) || caracter == 93 || caracter == 91 || caracter == 123 || caracter == 125 || caracter == 34 || caracter == 96 || caracter == 44 || caracter == 46 || caracter == 58 || caracter == 59 || caracter == 94) {
				MessageBox::Show("El caracter ingresado no está permitido");
				tb_NuevoElemento->Text = "";
				tb_NuevoElemento->Focus();
				return;
			}

			bool repetir = conjunto_caracter->IngresarElemento(caracter);
			if (repetir == true) MessageBox::Show("El elemento ingresado ya se encuentra en el conjunto A");
			tb_NuevoElemento->Text = "";
			tb_NuevoElemento->Focus();
			ListarElementos();

		}
		else if (charOnum == false) {
			if (tb_NuevoElemento->Text->Length > 3) {
				MessageBox::Show("Solo se permite números entre 1 al 999");
				tb_NuevoElemento->Text = "";
				tb_NuevoElemento->Focus();
				return;
			}

			char char_numero[3];
			sprintf(char_numero, "%s", tb_NuevoElemento->Text);

			short cantidad = tb_NuevoElemento->Text->Length;

			if (EsNumero(char_numero, cantidad) == false) {
				MessageBox::Show("El elemento ingresado no es un número");
				tb_NuevoElemento->Focus();
				tb_NuevoElemento->Text = "";
				return;
			}

			int numero = Convert::ToInt32(tb_NuevoElemento->Text);
			if (numero < 1) {
				MessageBox::Show("Solo se permite números entre 1 al 999");
				tb_NuevoElemento->Text = "";
				tb_NuevoElemento->Focus();
				return;
			}

			bool repetir = conjunto_numero->IngresarElemento(numero);
			if (repetir == true) MessageBox::Show("El elemento ingresado ya se encuentra en el conjunto A");
			tb_NuevoElemento->Text = "";
			tb_NuevoElemento->Focus();
			ListarElementos();
		}
	}
	private: System::Void bt_DefinirRelacion_Click(System::Object^ sender, System::EventArgs^ e) {
		pa_ConjuntoA->Visible = false;
		pa_relacion->Visible = true;
		ListarRelacion();
	}
		   void ListarRelacion() {
			   lb_relacion->Items->Clear();
			   lb_productoCartesiano->Items->Clear();
			   if (charOnum == true) {
				   for (short i = 0; i < conjunto_caracter->getCantidad(); i++) {
					   for (short j = 0; j < conjunto_caracter->getCantidad(); j++) {
						   char a = conjunto_caracter->getConjuntoCaracter()[i];
						   char b = conjunto_caracter->getConjuntoCaracter()[j];

						   string std_str_caracter_a(1, a);
						   String^ sys_str_caracter_a = gcnew String(std_str_caracter_a.c_str());
						   string std_str_caracter_b(1, b);
						   String^ sys_str_caracter_b = gcnew String(std_str_caracter_b.c_str());

						   if (conjunto_caracter->getRelacion()[i][j] == 1) lb_relacion->Items->Add("(" + sys_str_caracter_a + "; " + sys_str_caracter_b + ")");
						   else lb_productoCartesiano->Items->Add("(" + sys_str_caracter_a + "; " + sys_str_caracter_b + ")");
					   }
				   }
			   }
			   else {
				   for (short i = 0; i < conjunto_numero->getCantidad(); i++) {
					   for (short j = 0; j < conjunto_numero->getCantidad(); j++) {
						   if (conjunto_numero->getRelacion()[i][j] == 1) lb_relacion->Items->Add("(" + conjunto_numero->getConjuntoNumero()[i] + "; " + conjunto_numero->getConjuntoNumero()[j] + ")");
						   else lb_productoCartesiano->Items->Add("(" + conjunto_numero->getConjuntoNumero()[i] + "; " + conjunto_numero->getConjuntoNumero()[j] + ")");
					   }
				   }
			   }
		   }
	private: System::Void bt_AgregarRelacion_Click(System::Object^ sender, System::EventArgs^ e) {
		int pos = lb_productoCartesiano->SelectedIndex;
		if (charOnum == true) conjunto_caracter->AgregarRelacion(pos);
		else conjunto_numero->AgregarRelacion(pos);

		ListarRelacion();
	}
	private: System::Void bt_condicion_Click(System::Object^ sender, System::EventArgs^ e) {
		pa_relacion->Visible = false;
		if (charOnum == false) {
			cb_operador1->Items->Clear();
			cb_operador2->Items->Clear();
			cb_valor1->Items->Clear();
			cb_valor2->Items->Clear();
			pa_EstablecerRelacion->Visible = true;
			cb_valor1->Items->Add("a");
			cb_valor1->Items->Add("b");
			cb_valor2->Items->Add("a");
			cb_valor2->Items->Add("b");
			cb_operador1->Items->Add("+");
			cb_operador1->Items->Add("-");
			cb_operador1->Items->Add("x");
			cb_operador1->Items->Add("÷");
			cb_operador1->Items->Add("|");
			cb_operador1->Items->Add(">");
			cb_operador1->Items->Add(">=");
			cb_operador1->Items->Add("<");
			cb_operador1->Items->Add("<=");
			cb_operador2->Items->Add("=");
			cb_operador1->Items->Add("=");
			cb_operador2->Items->Add("es par");
			cb_operador2->Items->Add("es impar");
			cb_operador2->Items->Add("es múltiplo de");
			tb_resultado->Text = "";
		}
		else {
			pa_EstablecerRelacionCaracter->Visible = true;
			cb_caracter1->Items->Clear();
			cb_caracter2->Items->Clear();
			cb_caracterOperador->Items->Clear();
			cb_caracter1->Items->Add("a");
			cb_caracter1->Items->Add("b");
			cb_caracter2->Items->Add("a");
			cb_caracter2->Items->Add("b");
			cb_caracterOperador->Items->Add("=");
			cb_caracterOperador->Items->Add("!=");
		}
	}
		   short CalcularOperador(String^ valor, short i, short j) {
			   if (valor == "a") return i;
			   else return j;
		   }
	private: System::Void bt_establecercondicion_Click(System::Object^ sender, System::EventArgs^ e) {
		int resultado;
		if (cb_operador1->Text != "|" && cb_operador2->Text != "es par" && cb_operador2->Text != "es impar" && cb_operador1->Text != "<" && cb_operador1->Text != "<=" && cb_operador1->Text != ">" && cb_operador1->Text != ">=" && cb_operador1->Text != "=") {
			char char_resultado[50];
			sprintf(char_resultado, "%s", tb_resultado->Text);
			if (EsNumero(char_resultado, tb_resultado->Text->Length) == false) {
				MessageBox::Show("La condición es incorrecta o no esta disponible");
				tb_resultado->Focus();
				tb_resultado->Clear();
				return;
			}
			resultado = Convert::ToInt32(tb_resultado->Text);
		}

		for (short i = 0; i < conjunto_numero->getCantidad(); i++) {
			for (short j = 0; j < conjunto_numero->getCantidad(); j++) {
				if (cb_operador1->Text == "+") {
					if (cb_operador2->Text == "=") {
						if (conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor1->Text, i, j)] + conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor2->Text, i, j)] == resultado) conjunto_numero->setRelacion(i, j, 1);
					}
					else if (cb_operador2->Text == "es par") {
						if ((conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor1->Text, i, j)] + conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor2->Text, i, j)]) % 2 == 0) conjunto_numero->setRelacion(i, j, 1);
					}
					else if (cb_operador2->Text == "es impar") {
						if ((conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor1->Text, i, j)] + conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor2->Text, i, j)]) % 2 == 1) conjunto_numero->setRelacion(i, j, 1);
					}
					else {
						if ((conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor1->Text, i, j)] + conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor2->Text, i, j)]) % resultado == 0) conjunto_numero->setRelacion(i, j, 1);
					}
				}
				if (cb_operador1->Text == "-") {
					if (cb_operador2->Text == "=") {
						if (conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor1->Text, i, j)] - conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor2->Text, i, j)] == resultado) conjunto_numero->setRelacion(i, j, 1);
					}
					else if (cb_operador2->Text == "es par") {
						if ((conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor1->Text, i, j)] - conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor2->Text, i, j)]) % 2 == 0) conjunto_numero->setRelacion(i, j, 1);
					}
					else if (cb_operador2->Text == "es impar") {
						if ((conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor1->Text, i, j)] - conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor2->Text, i, j)]) % 2 == 1) conjunto_numero->setRelacion(i, j, 1);
					}
					else {
						if ((conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor1->Text, i, j)] - conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor2->Text, i, j)]) % resultado == 0) conjunto_numero->setRelacion(i, j, 1);
					}
				}
				if (cb_operador1->Text == "x") {
					if (cb_operador2->Text == "=") {
						if (conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor1->Text, i, j)] * conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor2->Text, i, j)] == resultado) conjunto_numero->setRelacion(i, j, 1);
					}
					else if (cb_operador2->Text == "es par") {
						if ((conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor1->Text, i, j)] * conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor2->Text, i, j)]) % 2 == 0) conjunto_numero->setRelacion(i, j, 1);
					}
					else if (cb_operador2->Text == "es impar") {
						if ((conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor1->Text, i, j)] * conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor2->Text, i, j)]) % 2 == 1) conjunto_numero->setRelacion(i, j, 1);
					}
					else {
						if ((conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor1->Text, i, j)] * conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor2->Text, i, j)]) % resultado == 0) conjunto_numero->setRelacion(i, j, 1);
					}
				}
				if (cb_operador1->Text == "÷") {
					if (cb_operador2->Text == "=") {
						if (conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor1->Text, i, j)] / conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor2->Text, i, j)] == resultado) conjunto_numero->setRelacion(i, j, 1);
					}
					else if (cb_operador2->Text == "es par") {
						if ((conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor1->Text, i, j)] / conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor2->Text, i, j)]) % 2 == 0) conjunto_numero->setRelacion(i, j, 1);
					}
					else if (cb_operador2->Text == "es impar") {
						if ((conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor1->Text, i, j)] / conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor2->Text, i, j)]) % 2 == 1) conjunto_numero->setRelacion(i, j, 1);
					}
					else {
						if ((conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor1->Text, i, j)] / conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor2->Text, i, j)]) % resultado == 0) conjunto_numero->setRelacion(i, j, 1);
					}
				}
				if (cb_operador1->Text == "|") {
					if (conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor2->Text, i, j)] % conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor1->Text, i, j)] == 0) conjunto_numero->setRelacion(i, j, 1);
				}
				if (cb_operador1->Text == ">") {
					if (conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor1->Text, i, j)] > conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor2->Text, i, j)]) conjunto_numero->setRelacion(i, j, 1);
				}
				if (cb_operador1->Text == ">=") {
					if (conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor1->Text, i, j)] >= conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor2->Text, i, j)]) conjunto_numero->setRelacion(i, j, 1);
				}
				if (cb_operador1->Text == "<") {
					if (conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor1->Text, i, j)] < conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor2->Text, i, j)]) conjunto_numero->setRelacion(i, j, 1);
				}
				if (cb_operador1->Text == "<=") {
					if (conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor1->Text, i, j)] <= conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor2->Text, i, j)]) conjunto_numero->setRelacion(i, j, 1);
				}
				if (cb_operador1->Text == "=") {
					if (conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor1->Text, i, j)] == conjunto_numero->getConjuntoNumero()[CalcularOperador(cb_valor2->Text, i, j)]) conjunto_numero->setRelacion(i, j, 1);
				}
			}
		}
		ListarRelacion();
		pa_EstablecerRelacion->Visible = false;
		pa_relacion->Visible = true;
	}
	private: System::Void tm_condicion_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (charOnum == false) {
			if (cb_operador1->Text == "|" || cb_operador1->Text == "<" || cb_operador1->Text == "<=" || cb_operador1->Text == ">" || cb_operador1->Text == ">=" || cb_operador1->Text == "=") {
				cb_operador2->Enabled = false;
				cb_operador2->SelectedIndex = -1;
				tb_resultado->Enabled = false;
				tb_resultado->Text = "";
			}
			else {
				cb_operador2->Enabled = true;
				tb_resultado->Enabled = true;
			}

			if (cb_operador2->Text == "es par" || cb_operador2->Text == "es impar" || cb_operador1->Text == "|" || cb_operador1->Text == "<" || cb_operador1->Text == "<=" || cb_operador1->Text == ">" || cb_operador1->Text == ">=" || cb_operador1->Text == "=") tb_resultado->Enabled = false;
			else tb_resultado->Enabled = true;

			if ((cb_operador1->Text == "" || cb_valor1->Text == "" || cb_valor2->Text == "") || (cb_operador2->Text == "" && cb_operador1->Text != "|" && cb_operador1->Text != "<" && cb_operador1->Text != "<=" && cb_operador1->Text != ">" && cb_operador1->Text != ">=" && cb_operador1->Text != "=") || (tb_resultado->Text == "" && cb_operador1->Text != "|" && cb_operador2->Text != "es par" && cb_operador2->Text != "es impar" && cb_operador1->Text != "<" && cb_operador1->Text != "<=" && cb_operador1->Text != ">" && cb_operador1->Text != ">=" && cb_operador1->Text != "=")) bt_establecercondicion->Enabled = false;
			else bt_establecercondicion->Enabled = true;
		}
		else {
			if (cb_caracter1->Text == "" || cb_caracter2->Text == "" || cb_caracterOperador->Text == "") bt_EstablecerCaracter->Enabled = false;
			else bt_EstablecerCaracter->Enabled = true;
		}
	}
	private: System::Void bt_BorrarRelacion_Click(System::Object^ sender, System::EventArgs^ e) {
		if (charOnum == true) conjunto_caracter->borrarRelacion(lb_relacion->SelectedIndex);
		else conjunto_numero->borrarRelacion(lb_relacion->SelectedIndex);
		ListarRelacion();
	}
	private: System::Void bt_BorrarTodoRelacion_Click(System::Object^ sender, System::EventArgs^ e) {
		if (charOnum == true) conjunto_caracter->borrarTodoRelacion();
		else conjunto_numero->borrarTodoRelacion();
		ListarRelacion();
	}
	private: System::Void bt_RegresarConjuntos_Click(System::Object^ sender, System::EventArgs^ e) {
		pa_relacion->Visible = false;
		pa_ConjuntoA->Visible = true;
		if (charOnum == true) conjunto_caracter->borrarTodoRelacion();
		else conjunto_numero->borrarTodoRelacion();

	}
	private: System::Void bt_DeterminarOrdenParcial_Click(System::Object^ sender, System::EventArgs^ e) {
		pa_relacion->Visible = false;
		pa_OrdenParcial->Visible = true;

		if (charOnum == false) {
			if (conjunto_numero->Reflexivo() == true) lbl_reflexiva->Text = "Propiedad reflexiva: Sí cumple";
			else lbl_reflexiva->Text = "Propiedad reflexiva: No cumple";

			if (conjunto_numero->Antisimetrico() == true) lbl_antisimetrica->Text = "Propiedad antisimétrica: Sí cumple";
			else lbl_antisimetrica->Text = "Propiedad antisimétrica: No cumple";

			if (conjunto_numero->Transitivo() == true) lbl_transitiva->Text = "Propiedad transitiva: Sí cumple";
			else lbl_transitiva->Text = "Propiedad transitiva: No cumple";

			if (conjunto_numero->Reflexivo() == true && conjunto_numero->Antisimetrico() == true && conjunto_numero->Transitivo() == true) {
				lbl_ordenParcial->Text = "La relación es de orden parcial";
				bt_dibujarHasse->Enabled = true;
			}
			else {
				lbl_ordenParcial->Text = "La relación no es de orden parcial";
				bt_dibujarHasse->Enabled = false;
			}
		}
		else {
			if (conjunto_caracter->Reflexivo() == true) lbl_reflexiva->Text = "Propiedad reflexiva: Sí cumple";
			else lbl_reflexiva->Text = "Propiedad reflexiva: No cumple";

			if (conjunto_caracter->Antisimetrico() == true) lbl_antisimetrica->Text = "Propiedad antisimétrica: Sí cumple";
			else lbl_antisimetrica->Text = "Propiedad antisimétrica: No cumple";

			if (conjunto_caracter->Transitivo() == true) lbl_transitiva->Text = "Propiedad transitiva: Sí cumple";
			else lbl_transitiva->Text = "Propiedad transitiva: No cumple";

			if (conjunto_caracter->Reflexivo() == true && conjunto_caracter->Antisimetrico() == true && conjunto_caracter->Transitivo() == true) {
				lbl_ordenParcial->Text = "La relación es de orden parcial";
				bt_dibujarHasse->Enabled = true;
			}
			else {
				lbl_ordenParcial->Text = "La relación no es de orden parcial";
				bt_dibujarHasse->Enabled = false;
			}
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		pa_OrdenParcial->Visible = false;
		pa_relacion->Visible = true;
		dibujar = false;
	}



	private: System::Void bt_dibujarHasse_Click(System::Object^ sender, System::EventArgs^ e) {
		dibujar = true;
		MyForm2^ Hasse;
		if (charOnum == false) Hasse = gcnew MyForm2(conjunto_numero, nullptr, false);
		else Hasse = gcnew MyForm2(nullptr, conjunto_caracter, true);
		Hasse->ShowDialog();
	}
	private: System::Void bt_regresarRela_Click(System::Object^ sender, System::EventArgs^ e) {
		pa_EstablecerRelacion->Visible = false;
		pa_relacion->Visible = true;
	}
	private: System::Void bt_EstablecerCaracter_Click(System::Object^ sender, System::EventArgs^ e) {
		for (short i = 0; i < conjunto_caracter->getCantidad(); i++) {
			for (short j = 0; j < conjunto_caracter->getCantidad(); j++) {
				if (cb_caracterOperador->Text == "=") {
					if (conjunto_caracter->getConjuntoCaracter()[i] == conjunto_caracter->getConjuntoCaracter()[j])	conjunto_caracter->setRelacion(i, j, 1);
				}
				else if (cb_caracterOperador->Text == "!=") {
					if (conjunto_caracter->getConjuntoCaracter()[i] != conjunto_caracter->getConjuntoCaracter()[j])	conjunto_caracter->setRelacion(i, j, 1);
				}
			}
		}
		ListarRelacion();
		pa_EstablecerRelacionCaracter->Visible = false;
		pa_relacion->Visible = true;
	}
	private: System::Void bt_DeterminarReticula_Click(System::Object^ sender, System::EventArgs^ e) {
		if (dibujar == false) {
			MessageBox::Show("Primero debe dibujar el diagrama de Hasse");
			return;
		}
		pa_OrdenParcial->Visible = false;
		pa_reticula->Visible = true;
		bool infimo;
		bool supremo;

		if (charOnum == false) {
			infimo = conjunto_numero->TieneInfimo();
			supremo = conjunto_numero->TieneSupremo();
		}
		else {
			infimo = conjunto_caracter->TieneInfimo();
			supremo = conjunto_caracter->TieneSupremo();
		}

		if (infimo == true) lbl_infimo->Text = "Para cada {a,b} pertenece a A, tiene ínfimo: Sí";
		else lbl_infimo->Text = "Para cada {a,b} pertenece A, tiene ínfimo: No";

		if (supremo == true) lbl_supremo->Text = "Para cada {a,b} pertenece a A, tiene supremo: Sí";
		else lbl_supremo->Text = "Para cada {a,b} pertenece a A, tiene supremo: No";

		if (infimo == true && supremo == true) {
			bt_HallarComplementos->Enabled = true;
			lbl_reticula->Text = "Es una retícula";
		}
		else {
			bt_HallarComplementos->Enabled = false;
			lbl_reticula->Text = "No es una retícula";
		}
	}
	private: System::Void bt_RelacionAleatoria_Click(System::Object^ sender, System::EventArgs^ e) {
		if (charOnum == true) {
			for (short i = 0; i < conjunto_caracter->getCantidad(); i++) {
				for (short j = 0; j < conjunto_caracter->getCantidad(); j++) {
					short aleatorio = rand() % (1 + 1 - 0) + 0;
					if (aleatorio == 1) conjunto_caracter->setRelacion(i, j, 1);
					else if (aleatorio == 0) conjunto_caracter->setRelacion(i, j, 0);
				}
			}
		}
		else {
			for (short i = 0; i < conjunto_numero->getCantidad(); i++) {
				for (short j = 0; j < conjunto_numero->getCantidad(); j++) {
					short aleatorio = rand() % (1 + 1 - 0) + 0;
					if (aleatorio == 1) conjunto_numero->setRelacion(i, j, 1);
					else if (aleatorio == 0) conjunto_numero->setRelacion(i, j, 0);
				}
			}
		}
		ListarRelacion();
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		pa_Inicio->BackgroundImage = FondoAzul;
		pa_ConjuntoA->BackgroundImage = FondoBlanco;
		pa_relacion->BackgroundImage = FondoBlanco;
		pa_EstablecerRelacion->BackgroundImage = FondoBlanco;
		pa_EstablecerRelacionCaracter->BackgroundImage = FondoBlanco;
		pa_OrdenParcial->BackgroundImage = FondoBlanco;
		pa_reticula->BackgroundImage = FondoBlanco;
		pa_Complementos->BackgroundImage = FondoBlanco;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (tb_NumeroElementos->Text->Length >= 3 || tb_NumeroElementos->Text->Length <= 0) {
			MessageBox::Show("Solo puede haber de 1 a 20 elementos en el conjunto A");
			tb_NumeroElementos->Text = "";
			tb_NumeroElementos->Focus();
			return;
		}

		if (rb_Numero->Checked == false && rb_Caracteres->Checked == false) {
			MessageBox::Show("Seleccione si el conjunto será de números o caracteres");
			return;
		}

		char str_numero[3];
		sprintf(str_numero, "%s", tb_NumeroElementos->Text);


		if (EsNumero(str_numero, tb_NumeroElementos->Text->Length) == false) {
			MessageBox::Show("El valor ingresado no es un número");
			tb_NumeroElementos->Text = "";
			tb_NumeroElementos->Focus();
			return;
		}

		short numero = atoi(str_numero);

		if (numero > 20 || numero <= 0) {
			MessageBox::Show("Solo puede haber de 1 a 20 elementos en el conjunto A");
			tb_NumeroElementos->Text = "";
			tb_NumeroElementos->Focus();
			return;
		}

		if (rb_Numero->Checked == true) {
			charOnum = false;
			conjunto_numero->setCantidad(numero);
		}
		else {
			charOnum = true;
			conjunto_caracter->setCantidad(numero);
		}

		tb_NumeroElementos->Text = "";

		pa_Inicio->Visible = false;
		pa_ConjuntoA->Visible = true;

	}
	private: System::Void bt_regresarInicio_Click(System::Object^ sender, System::EventArgs^ e) {
		pa_ConjuntoA->Visible = false;
		pa_Inicio->Visible = true;
		BorrarTodo();
	}
	private: System::Void bt_regresarReticula_Click(System::Object^ sender, System::EventArgs^ e) {
		pa_reticula->Visible = false;
		pa_OrdenParcial->Visible = true;
	}
	private: System::Void bt_HallarComplementos_Click(System::Object^ sender, System::EventArgs^ e) {
		pa_reticula->Visible = false;
		pa_Complementos->Visible = true;
		if (charOnum == false) {
			vector<int> complementos;
			String^ str_complementos = "";

			for (short i = 0; i < conjunto_numero->getCantidad(); i++) {
				str_complementos = "";
				complementos = conjunto_numero->HallarComplementos(i);

				for (short j = 0; j < complementos.size(); j++) {
					str_complementos += complementos[j];
					if (j != complementos.size() - 1) str_complementos += " ,";
				}
				if (complementos.size() != 0)lb_complementos->Items->Add("Complementos de " + conjunto_numero->getConjuntoNumero()[i] + ": " + str_complementos);
				else lb_complementos->Items->Add("Complementos de " + conjunto_numero->getConjuntoNumero()[i] + ": No tiene");
			}
		}
		else {
			vector<char> complementos;
			String^ str_complementos = "";

			for (short i = 0; i < conjunto_caracter->getCantidad(); i++) {
				str_complementos = "";
				complementos = conjunto_caracter->HallarComplementos(i);

				for (short j = 0; j < complementos.size(); j++) {
					string std_str_caracter(1, complementos[j]);
					String^ sys_str_caracter = gcnew String(std_str_caracter.c_str());

					str_complementos += sys_str_caracter;
					if (j != complementos.size() - 1) str_complementos += " ,";
				}

				string std_str_caracter(1, conjunto_caracter->getConjuntoCaracter()[i]);
				String^ sys_str_caracter = gcnew String(std_str_caracter.c_str());

				if (complementos.size() != 0)lb_complementos->Items->Add("Complementos de " + sys_str_caracter + ": " + str_complementos);
				else lb_complementos->Items->Add("Complementos de " + sys_str_caracter + ": No tiene");
			}
		}
	}
	private: System::Void bt_regresarComplementos_Click(System::Object^ sender, System::EventArgs^ e) {
		lb_complementos->Items->Clear();
		pa_Complementos->Visible = false;
		pa_reticula->Visible = true;
	}

	private: System::Void bt_RegresarCaracterRelacion_Click(System::Object^ sender, System::EventArgs^ e) {
		pa_EstablecerRelacionCaracter->Visible = false;
		pa_relacion->Visible = true;
	}
	};
}