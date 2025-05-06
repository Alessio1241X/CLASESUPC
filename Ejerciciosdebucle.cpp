/*1.Realice un program que solicite de la entrda estandar un entero del 1 al 10 y muestre en la salida estandar su tabla
de multiplicar

#include <iostream>
using namespace std;

int main() {

	int numero ;
	do {
		cout << "Ingrese un numero del 1 al 10: "; cin >> numero;
	} while ((numero < 1) || (numero > 10));

	for (int i = 1; i <= 12; i++) {
		cout << numero << " * " << i << " = " << numero * i << endl;
	}


	
	return 0;
}*/