#include <iostream>
#include <conio.h>
#include "juego.h"

using namespace std;
using namespace System;

int main() {
	char jdn;
	do {
		bool ganado = jugar();
		if (ganado) { Console::SetCursorPosition(25, 15); cout << "HAS GANADO"; }
		else { Console::SetCursorPosition(25, 15); cout << "HAS PERDIDO"; }
		Console::SetCursorPosition(11, 17); cout << "Presione ENTER para ir al MENU PRINCIPAL";
		Console::SetCursorPosition(11, 19); cout << "Presione CUALQUIER OTRA TECLA para SALIR";
		_sleep(1000);
		jdn = _getch();
	} while (jdn == ENTER);
	return 0;
}