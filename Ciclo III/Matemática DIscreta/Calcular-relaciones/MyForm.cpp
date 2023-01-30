#include "MyForm.h"
#include <ctime>
#include <stdlib.h>
using namespace TrabajoParcialMatemáticaDiscreta;

int main() {
	srand(time(NULL));
	Application::EnableVisualStyles();
	Application::Run(gcnew MyForm());


	return 0;
}
