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
		}
		else {
			cout << "  ";
		}
	}
	cout << endl;
}
return 0;
}