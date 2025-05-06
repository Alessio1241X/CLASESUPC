#include<iostream>

using namespace std;
#define N 10
#define M 10
int main() {
	/*int numero;
	srand(time(NULL));
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			numero= (rand() % 25) + 65;
			cout << (char)numero << " ";
		}
		cout << "\n";
	}

		int numero;
		srand(time(NULL));
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= i; j++) {
				numero = (rand() % 25) + 65;
				cout << (char)numero << " ";
			}
			cout << "\n";
		}
	int numero;

		srand(time(NULL));
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= i; j++) {
				if (i == j) {//imprimir la diagonal
				
				numero = (rand() % 25) + 65;//del 65 al 90
				cout << (char)numero << " ";
			}
			else {
				cout << " ";
			}
		}
			cout << endl;*/
	
	int numero;

	srand(time(NULL));
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (i == j || j == 0 || i == N) {
				//i==j ->la diagonal
				//j==0 ->borde vertical
				//i==N ->borde horizontal

				numero = (rand() % 25) + 65;//del 65 al 90
				cout << (char)numero << " ";
			}
			else {
				cout << "  ";
			}
		}
		cout << endl;

	}
	return 0;
}