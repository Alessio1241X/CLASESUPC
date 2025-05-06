#include<iostream>

using namespace std;
#define N 10
#define M 10
int main() {
	
int numero;


for (int i = 0; i <= N; i++) {
	for (int j = 0; j <= N; j++) {
		if (i == j || j == 0 ||i==N||i==0|| j== N) {
			cout << "* ";
			// i==j-> diagonal
			// j==0 -> vertical izquierda
			// i==N -> horizontal inferior
			// i==0 -> horizontal superior
			// j==N -> vertical derecha
		}
		else {
			cout << "  ";
		}
	}
	cout << endl;
}
return 0;
}
