/*3.Realice un programa que calcule y muestre la salida estandar la suma de los cuadrados de los 10 
primeros enteros mayores que cero*/
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