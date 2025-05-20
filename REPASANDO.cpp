/*Ejercicio 12 3A:Solicite un codigo de salida de 4 digitos y determine el departamento,
hora de salida y si se realizan paradas o no 
#include<iostream>
using namespace std;
int main() {
	int codigo,depaco,hour,para;
	string depa,reali;
	cout << "Ingrese un codigo de salida entre (1011-3392): "; cin >> codigo;
	if (codigo < 1011 || codigo>3392) {
		cout << "Codigo invalido" << endl;
		cout << "Ingrese un nuevo codigo entre (1011-3392):  "; cin >> codigo;
	}
	depaco= codigo/ 1000;
	hour=codigo % 1000/10;
	para = codigo % 10;
	if (depaco == 1) {
		depa = "Tumbes";
	}else if (depaco == 2) {
		depa = "Arequipa";
	}else if (depaco == 3) {
				depa = "Puno";
		}

	if (para == 1) {
		reali = "S";
	}
	else if (para == 2) {
		reali = "N";
	}
	else {
		reali = "Informacion no disponible";
	}

	cout << "\nCodigo de salida: " << codigo << endl;
	cout << "Departamento de destino: " << depa << endl;
	cout << "Hora de salida: " << hour << endl;
	cout << "Realizan paradas: " << reali << endl;
	return 0;
}

*/
/*Ejercicio 10 hoja 3B: Recibr datos de la cantidad de anos que ekempleado
labora en la entidad y los estudios realizados y nos determine e imprima el puntaje obtenido
#include<iostream>
using namespace std;
int main() {
	int edad,temp,punt=0,suma=0;
	string estu;

	cout << "Ingrese la cantidad de años que labora: "; cin >> edad;
	cout << "Ingrese el grado de estudios: ";cin >> estu;

	if (edad < 5) {
		temp = 5;
	}
	else {
		temp = 10;
	}
	if (estu == "Primarios") {
		punt = 5;
	}
	else if (estu == "Secundarios") {
		punt = 10;
	}
	else if (estu == "Universitarios") {
		punt = 20;
	}
	else if (estu == "Posgrado"){
		punt=30;
	}

	suma = temp + punt;
	cout << "\nPuntaje obtenido: " << suma << endl;

	return 0;
}*/
/*Escriba Naciones Unidas programa en C++ que Permita imprimir los cinco Primerosnúmeros positivos.
//while
#include<iostream>
using namespace std;

int main(){
	int contador=1;

	while (contador <= 5) {
		cout << "contador= " << contador << "\n";
		contador++;}
return 0;
}*/
//DO WHILE
/*#include<iostream>
using namespace std;
int main() {
	int contador = 1;
	do {
		cout << "contador= " << contador << "\n";
		contador++;
	} while (contador <= 5);


	return 0;
}*/
//FOR
/*#include<iostream>
using namespace std;
int main() {
	for (int contador = 1;contador <= 5;contador++) {
		cout << "contador= " <<contador<<"\n";
	}

	return 0;
}*/
/*Dado un numero n=7 generar 7,6,5,4,3,2,1 
#include<iostream>
using namespace std;

int main() {
	int n;
	cout << "Ingrese la cantidad de terminos: "; cin >> n;
	while (n>0) {
		cout << n << " ";
		n--;
	}

	return 0;
}*/
/*Elaborar un programa en C++ que muestre los números 
parescomprendidos entre 10 y 20 inclusive
//FOR
#include<iostream>
using namespace std;
int main() {
	cout << "Los numeros pares entre 10 y 20 son:\n";
	for (int i = 10;i <= 20;i+=2) {
		cout << i << "\n";
	}
	return 0;
}
*/
/*Mostrar la tabla de caracteres ASCII a partir del Código 32 (el espacio enblanco) 
hasta el Código 164 (o sea la ñ) sin incluir las minúsculas (rangodel 97 al 122)
#include<iostream>
using namespace std;

int main() {
	for (int i = 32;i <= 164;i++) {
		if (i < 97 || i >> 122) {
			cout << char(i) << " " << i << "\n";
		}
	}
	return 0;
}*/
/*Realizar una aplicación en C++ que imprime los 6 primeros
numeros pares que hay entre 1 y 20
#include<iostream>
using namespace std;
int main() {
	int num=0, cont=0;
	while (num <= 20) {
		num++;
			if (num % 2 == 0) {
			cont++;
			cout<<num << "\n";
		}
			if (cont == 6) {
				break;
			}

	}
	return 0;*/
/*Realizar una aplicación en C++ que suma los números pares 
comprendidos entre 1 y 10 inclusive
#include<iostream>
using namespace std;
int main() {
	int suma = 0;
	for (int i = 1;i <= 10;i++) {
		if (i % 2 != 0) {//deja de lado a los impares
			continue;
		
		suma += i; //realiza la suma de pares
	}
	cout << "La suma es: " << suma << endl;
	return 0;
}*/
/*
#include<iostream>
#include<math.h>
using namespace std;

int main() {
	float x, y,ope=0;
	cout << "Ingresa el valor de x: "; cin >> x;
	cout << "Ingresa el valor de y: "; cin >> y;

	ope = (sqrt(x)) / (pow(y, 2) - 1);

	cout << "\nEl resultado es: " << ope << endl;

	return 0;
}*/
/*Ejercicio 1: Suma de los primeros N números naturales
#include<iostream>
using namespace std;

int main() {
	int sum=0,num;
	cout << "Ingrese la cantidad de terminos: "; cin >> num;
	for (int i = 0; i <= num; i++) {
		sum += i;
	}
	cout << "\nLa suma de los numeros son: " << sum << endl;


	return 0;
}*/
//S = 1² + 2³ + 3⁴ + 4⁵ + ... + N ^ (N + 1)
/*#include<iostream>
#include<math.h>
using namespace std;
int main() {
	int N;
	float sum = 0;
	cout << "Ingrese la cantidad de terminos: "; cin >> N;
	
	for (int i = 1; i <= N;i++) {
		sum += pow(i, i + 1);
	}
	cout << "\nEl resultado es: " << sum << endl;

	return 0;
}*/
/*
#include <iostream>
#include <windows.h>  // Para manejar la consola (SetConsoleCursorPosition, etc.)
#include <conio.h>     // Para _getch()
#include <thread>      // Para sleep


class Console {
public:
	static void SetCursorVisible(bool visible) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO cursorInfo;
		GetConsoleCursorInfo(hConsole, &cursorInfo);
		cursorInfo.bVisible = visible;
		SetConsoleCursorInfo(hConsole, &cursorInfo);
	}

	static void SetCursorPosition(int x, int y) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos;
		pos.X = x;
		pos.Y = y;
		SetConsoleCursorPosition(hConsole, pos);
	}
};
using namesace std;
int main() {
	Console::SetCursorVisible(false);

	int x = 0, y = 0;

	//Predionar una tecla para iniciar la animacion.

	cin.get();

	while (x <= 20) {
		//system("cls");

		Console::SetCursorPosition(x, y);
		cout << "* ";
		Sleep(100);
		x++;

	}

	while (x > 0) {
		Console::SetCursorPosition(x, y);
		cout << "*";
		Sleep(100);
		y++;
		x--;

	}

	while (x <= 20) {
		//system("cls");

		Console::SetCursorPosition(x, y);
		cout << "* ";
		Sleep(100);
		x++;
	}
	system("pause");
	return 0;
}*/
/*
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
#define N 5

int main() {
	int numero;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			if (i == j || j == 0 || i == N) {
				//i==j Diagonal
				//j==0 Vertical izquierda
				//i==N Horizontal inferior
				cout << "* ";
			}
			else {
				cout << "  ";
			}
		}
		cout << endl;
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= 11; j++) {
			if (i == j || j == 0 || i == N || j == 6 || j == i + 6) {
				//i==j Diagonal
				//j==0 Vertical izquierda
				//i==N Horizontal inferior
				cout << "* ";
			}
			else {
				cout << "  ";
			}
		}
		cout << endl;
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= 17; j++) {
			if (i == j || j == 0 || i == N || j == 6 ||j==12|| j == i + 6 || j == i + 12) {
				cout << "* ";
			}
	else {
		cout << "  ";
			}
	}
	cout << endl;
}
	return 0;

}*/
//Triangulo en ascendente
/*
#include <iostream>

using namespace std;

int main()
{
	int numero = 0;
	for (int i = 0; i <= 4; i++) {
		for (int j = 0; j <= 14; j++) {
			if (i == 4 ||j == 0 ||i == j || j == 5||  j == 10 || i + 5 == j||  i + 10 == j)
			{
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}
	for (int i = 0; i <= 4; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (i == 4 ||j == 0 || i == j || j == 5||  i + 5 == j)
			{
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}
	for (int i = 0; i <= 4; i++){
		for (int j = 0; j <= 4; j++)
		{
			if (i == 4 || j == 0||  j == i){
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}
	return 0;
}*/
//ROMBO
/*
#include <iostream>
using namespace std;
int main() {
	
	for (int i = 0; i <= 8; i++) {
		for (int j = 0; j <= 8; j++) {
			if (i + j == 4||j==i+4||j+4==i||i+j==12)
			{
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}
	return 0;
}*/
/*
#include<iostream>
#define N 5
using namespace std;
int main() {
	int numero;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N - i; j++) {
			cout << "  ";
		}
		for (int j = 1; j <= 2 * i - 1; j++) {
			cout << "* ";
		}
		cout << endl;
	}
	return 0;
}*/
//TRIANGULO
/*
#include<iostream>
#include<cstdlib>
using namespace std;
int main() {
	for (int i= 0; i <= 5; i++) {
		for (int j = 0; j <= i; j++) {
			cout << "* ";
		}
		cout << endl;
	}
	return 0;
}*/
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
#define N 5

int main() {
	system("color 0a");
	int numero;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			if (i == j || j == 0 || i == N) {
				cout << "* ";
			}
			else {
				cout << "  ";
			}
		}
		cout << endl;
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= 11; j++) {
			if (i == j || j == 0 || i == N || j == 6 || j == i + 6) {
				cout << "* ";
			}
			else {
				cout << "  ";
			}
		}
		cout << endl;
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= 17; j++) {
			if (i == j || j == 0 || i == N || j == 6 || j == i + 6 || j == i + 12 || j == 12) {
				cout << "* ";
			}
			else {
				cout << "  ";
			}
		}
		cout << endl;
	}
	return 0;

}