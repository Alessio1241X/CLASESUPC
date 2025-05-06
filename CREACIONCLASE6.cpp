#include "pch.h"
#include<iostream>
#include<conio.h>
using namespace System;
using namespace std;
int main(){
    char letra;
    Console::CursorVisible = false;//cursor no se ve
    while (!kbhit()) { //mientras no presione tecla
        cin >> letra;//leer la tecla
        if (letra == 'C'||letra=='U'||letra=='P') {//si tecla es U,P,Cmayuscula
            for (int i = 0; i < 10; i++) {
                system("cls");
                Console::SetCursorPosition(i, 1);
                cout << "UPC";
                _sleep(500);
            }
        }

    }
  
    return 0;
}
