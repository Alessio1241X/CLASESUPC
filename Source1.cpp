#include<iostream>

using namespace std;
#define N 10
#define M 10
int main() {
	int numero;
	srand(time(NULL));
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			numero = (rand() % 25) + 65;
			cout << (char)numero << " ";
		}
		cout << "\n";
	}

	return 0;
}