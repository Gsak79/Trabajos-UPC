#pragma once
#include <iostream>
#include <conio.h>
using namespace std;
using namespace System;

#define IZQUIERDA 75
#define DERECHA 77
#define ENTER 13
#define ESPACIO 32
#define ESQUINASUPDER 187
#define LINEAHORIZONTAL 205
#define LINEAVERTICAL 186
#define ESQUINAINFIZQ 200
#define ESQUINAINFDER 188
#define ESQUINASUPIZQ 201

enum Color { Rojo, Amarillo, Blanco, Azul, Morado, Verde };

void colorearCaracter(Color color) {
	switch (color) {
	case Rojo: Console::ForegroundColor = ConsoleColor::Red; break;
	case Blanco: Console::ForegroundColor = ConsoleColor::White; break;
	case Amarillo: Console::ForegroundColor = ConsoleColor::Yellow; break;
	case Azul: Console::ForegroundColor = ConsoleColor::Blue; break;
	case Morado: Console::ForegroundColor = ConsoleColor::Magenta; break;
	case Verde: Console::ForegroundColor = ConsoleColor::Green; break;
	}
}

void LimpiarPantalla() {
	for (short f = 4; f < 33; f++) {
		for (short c = 3; c < 58; c++) {
			Console::SetCursorPosition(c, f); cout << " ";
		}
		cout << endl;
	}
}

void ImprimirInstrucciones() {
	Console::SetCursorPosition(18, 4); cout << "INSTRUCCIONES DEL JUEGO";
	Console::SetCursorPosition(3, 6); cout << "- Dispare a los enemigos para conseguir puntos";
	Console::SetCursorPosition(3, 7); cout << "- Subira de nivel si logra eliminar las 4 tandas de ";
	Console::SetCursorPosition(3, 8); cout << "  enemigos en cada nivel o si consigue 2500 puntos";
	Console::SetCursorPosition(3, 9); cout << "  cuando se haya acabado el tiempo";
	Console::SetCursorPosition(3, 10); cout << "- Comenzara el juego con 4 vidas";
	Console::SetCursorPosition(3, 11); cout << "- Perdera una vida si colisiona con un enemigo o si ";
	Console::SetCursorPosition(3, 12); cout << "  no logra conseguir 2500 puntos cuando se haya ";
	Console::SetCursorPosition(3, 13); cout << "  acabado el tiempo. En el ultimo caso, se reiniciara";
	Console::SetCursorPosition(3, 14); cout << "  el nivel";
	Console::SetCursorPosition(3, 15); cout << "- Ganara si logra conseguir terminar los 4 niveles";
	Console::SetCursorPosition(3, 16); cout << "- El juego se termina si pierde todas las vidas";
	Console::SetCursorPosition(20, 18); cout << "CONTROLES DE LA NAVE";
	Console::SetCursorPosition(6, 20);
	cout << "Flecha Izquierda -----> Mover Hacia La Izquierda";
	Console::SetCursorPosition(8, 22);
	cout << "Flecha Derecha -----> Mover Hacia La Derecha";
	Console::SetCursorPosition(15, 24); cout << "Espacio -----> Disparar";
	Console::SetCursorPosition(24, 26); cout << "PUNTUACIONES";
	Console::SetCursorPosition(12, 28); cout << "Avispa (-#-) --> 100 puntos - 1 vida";
	Console::SetCursorPosition(11, 30); cout << "Mariposa (>|<) --> 160 puntos - 1 vida";
	Console::SetCursorPosition(10, 32); cout << "Comandante (/$\\) --> 400 puntos - 2 vidas";
	Console::SetCursorPosition(9, 34); cout << "PRESIONE CUALQUIER TECLA PARA VOLVER ATRAS";
}
void ImprimirLogo() {
	Console::SetCursorPosition(5, 26); cout << (char)ESQUINASUPIZQ << (char)LINEAHORIZONTAL << (char)LINEAHORIZONTAL;
	Console::SetCursorPosition(5, 27); cout << (char)LINEAVERTICAL;
	Console::SetCursorPosition(5, 28); cout << (char)204 << (char)LINEAHORIZONTAL << (char)ESQUINASUPDER;
	Console::SetCursorPosition(5, 29); cout << (char)LINEAVERTICAL << " " << (char)LINEAVERTICAL;
	Console::SetCursorPosition(5, 30); cout << (char)ESQUINAINFIZQ << (char)LINEAHORIZONTAL << (char)ESQUINAINFDER << "ALAGA";
	Console::SetCursorPosition(5, 32); cout << "Hecho por: Salvador Cobos y Gonzalo Sakuda";
}

void DibujarMarco() {
	for (short i = 2; i < 58; i++) {
		Console::SetCursorPosition(i, 2); cout << (char)LINEAHORIZONTAL;
		Console::SetCursorPosition(i, 35); cout << (char)LINEAHORIZONTAL;
	}
	for (short i = 3; i < 35; i++) {
		Console::SetCursorPosition(1, i); cout << (char)LINEAVERTICAL;
		Console::SetCursorPosition(58, i); cout << (char)LINEAVERTICAL;
	}
	Console::SetCursorPosition(1, 2); cout << (char)ESQUINASUPIZQ;
	Console::SetCursorPosition(1, 35); cout << (char)ESQUINAINFIZQ;
	Console::SetCursorPosition(58, 2); cout << (char)ESQUINASUPDER;
	Console::SetCursorPosition(58, 35); cout << (char)ESQUINAINFDER;
}
