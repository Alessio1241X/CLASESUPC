
#include <iostream>
using namespace std;
int main() {

	int edad, num;
	char gene;
	string cate, cami, mensaje;

	cout << "Digite su edad: "; cin >> edad;
	cout << "Digite su genero M o F: "; cin >> gene;
	cout << "Digite su identificacion de 4 digitos: "; cin >> num;

	if (edad < 12) {
		cate = "Infantil";
	}
	else if (edad >= 12 && edad <= 17) {
		cate = "Juvenil";
	}
	else if (edad >= 18) {
		cate = "Adulto";
	}

	switch (num % 10) {
	case 0:cami = "Rojo";break;
	case 1:cami = "Rojo";break;
	case 2:cami = "Azul";break;
	case 3:cami = "Azul";break;
	case 4:cami = "Verde";break;
	case 5:cami = "Verde";break;
	case 6:cami = "Amarillo";break;
	case 7:cami = "Amarillo";break;
	case 8:cami = "Negro";break;
	case 9:cami = "Negro";break;
	default:
		break;
	}
	if (edad < 8) {
		mensaje = "No puede participar";
	}
	else if (edad >= 8 && edad <= 11) {
		if (gene == 'M') {
			mensaje = "Si puede participar";
		}
		else {
			mensaje = "Participa en deportes no competitivos";
		}
	}
	else if (edad < 17) {
		mensaje = "Si puede participar";
		if (num % 2 == 0) {
			mensaje = "Recibe bonificacion";
		}
	} else {
		mensaje = "Si puede participar";
	}
	cout << "\nEdad: " << edad << endl;
	cout << "Genero: " << gene << endl;
	cout << "ID: " << num <<  endl;
	cout << "Categoria: " << cate << endl;
	cout << "Color de camiseta: " << cami << endl;
	cout << "Resultado: " << mensaje << endl;
	return 0;
}

