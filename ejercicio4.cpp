/*4. Escriba un programa que tome cada 4 horas la temperatura exterior,
leyéndola durante un período de 24 horas. Es decir, debe leer 6 temperaturas.
Calcule la temperatura media del día, la temperatura más alta y la más baja.*/

#include<iostream>
using namespace std;

int main() {
	int suma = 0, cuadrado;

	for (int i = 1; i <= 10;i++) {
		cuadrado = i * i;
		suma = suma + cuadrado;
	}

	cout << "La suma de los 10 primeros cuadrados es: " << suma << endl;



	return 0;
}