#include<iostream>
#include<stdafx.h>
#include<conio.h>

using namespace System;
using namespace std;

int main(array<System::String^>^args) {

	int fil, col;

	fil = 1; col = 1;
	int n = 4;

	while( fil<=n){

		while (col<=n) {
			cout << "*";
			col++;
		}
		cout << "\n";
		col = 1;
		fil++;
	}
	_getch();
	return 0;
}