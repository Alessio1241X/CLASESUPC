/*4. Escriba un programa que tome cada 4 horas la temperatura exterior,
leyéndola durante un período de 24 horas. Es decir, debe leer 6 temperaturas.
Calcule la temperatura media del día, la temperatura más alta y la más baja.*/

/*#include<iostream>
using namespace std;

int main() {
	float media ,temperatura,tempalta=0,tempbaja=999, sumatemp=0;
	for (int i = 0; i <= 24;i+=4) {
		cout << "Ingrese la temperatura a las " << i << ":"; cin >> temperatura;
		sumatemp += temperatura;
		if (temperatura > tempalta) {
			tempalta = temperatura;
		}
		if (temperatura < tempbaja) {
			tempbaja = temperatura;
		}
	}
	media = sumatemp / 6;

	cout << "\nLa temperatura media es: " << media << endl;
	cout << "La temperatura alta es: " << tempalta << endl;
	cout << "La temperatura baja es: " << tempbaja << endl;
	return 0;
}
*/