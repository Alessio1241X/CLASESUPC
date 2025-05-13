// 6.Escriba un programa que calcule x^y, donde tanto x como y son enteros
// positivos,sin utilizar la función pow
//
/*#include<iostream>
using namespace std;

int main() {
	
	int num = 1, x, y;
	cout << "Ingrese la base: "; cin >> x;
	cout << "Ingrese la potencia: "; cin >> y;
	for (int i = 0; i < y;i++) {
		num *= x;
	}
		cout << "\nEl resultado es: " << num << endl;
	
	

	return 0;
}*/
//7.Escriba un programa que calcule el valor de: 1+2+3+...+n//

/*#include<iostream>
using namespace std;

int main() {
	int n,num=0;
	cout << "Ingrese la cantidad de elementos: "; cin >> n;

	for (int i = 1;i <=n;i++) {
		num += i;
	}
	cout << "\nLa sumatoria es: " << num << endl;


	return 0;
}*/

//8.Escriba un programa que calcule el valor de:1+3+5+...+2n-1
/*#include<iostream>
using namespace std;

int main() {
	int n, num = 0,cam=0;
	cout << "Ingrese la cantidad de elementos: "; cin >> n;
	for (int i = 1;i <=n;i+=2) {
		num += i;
		cam = (2 * num) - 1;
	}
	cout << "\nEl resultado es: " << cam << endl;

	return 0;
}*/

//9.Escriba un programa que calcule el valor de: 1*2*3*...*n(factorial)
/*#include<iostream>
using namespace std;

int main() {
	int n, factorial= 1;

	cout << "Digite un numero: ";  cin >> n;
	for (int i = 1; i <= n;i++) {
		factorial *=i;
	}
	cout << "\nEl factorial del numero  es: " << factorial << endl;


	return 0;
}*/

//10.Escriba un programa que calcule el valor de: 1!+2!+3!+...+n!
//(suma de factoriales)

/*#include<iostream>
using namespace std;

int main() {
	int n, facto = 1,suma=0;
	cout << "Ingrese la cantidad de elementos: "; cin >> n;

	for (int i = 1;i <= n;i++) {
		facto *= i;
		suma += facto;
	}
	cout << "\nLa suma de factoriales es: " << suma << endl;






	return 0;
}*/

//11.Escriba un programa que calcule el valor de: 2^1+2^2+2^3+...+2^n

/*#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

int main() {

	int n,sum=0, eleva=0;
	cout << "Ingrese la cantidad de elementos: "; cin >> n;

	for (int i = 1;i <= n;i++) {
	
		eleva = pow(2, i);
		sum += eleva;
	}
	cout << "\nEl resultado es: " << sum << endl;


	system("pause");
	return 0;
}*/
//12.Hacer un programa que calcule el resultado de la expresion
//1-2+3-4+5-6...n
/*#include<iostream>
using namespace std;

int main() {
	int n, sum = 0;

	cout << "Ingrese la cantidad de elementos: "; cin >> n;
	for (int i = 1;i <= n;i++) {
		if (i % 2 == 0) {
			sum -= i;
		}
		else {
			sum += i;
		}

	}
	cout << "\nEl resultado es: " << sum << endl;



	return 0;
}*/
//13.Hacer un que programa que realize la serie fibonacci->1 1 2 3 5 8 13 n
/*#include<iostream>
using namespace std;
int main() {
	int n, x = 0,y=1,z=1;
	cout << "Digite la cantidad de elementos: "; cin >> n;
	cout << "1 ";
	for (int i = 1;i < n;i++) {
		z = x + y;//1 2
		cout << z << " ";//1 2
		x = y;//1 1
		y = z;//1 2
	}

	
	cout << "\n";


	return 0;
}*/

/*Ejercicio 14:
En una clase de 5 alumnos se han realizado tres exámenes y se requiere determinar el número de :
a) Alumnos que aprobaron todos los exámenes.
b) Alumnos que aprobaron al menos un examen.
c) Alumnos que aprobaron únicamente el último examen.
Realice un programa que permita la lectura de los datos y el calculo de 
las estadisticas*/


















