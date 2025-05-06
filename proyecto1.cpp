#include<iostream>
#include<cstdlib>
using namespace std;

int main() {
	srand(time(NULL));//Inicializa la semilla

	int numero = rand() % 256;//numero aleatorio de 0 a 9

	//mostrar numero 
	cout << "El numero aleatorio es: " << (char)numero;



	return 0;
}