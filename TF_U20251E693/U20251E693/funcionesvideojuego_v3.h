#ifndef FUNCIONESVIDEOJUEGO_V1
#define FUNCIONESVIDEOJUEGO_V1

#include "conio.h"
#include <iostream>
#include <windows.h>

#define ENTER 13
#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77

using namespace std;
using namespace System;


// variables iniciales


const int niveles_del_juego = 2;

//dimenciones tronco
int dimensiones_tronco_filas = 12, dimensiones_tronco_columnas = 4;


// cordenadas iniciales del jugador
const int coord_x_jugador = 20;
const int coord_y_jugador = 27;


bool mapa_inicializado = false;
// dimensiones del jugador
int filas_jugador = 19;
int columnas_jugador = 10;

// dimewsiones de la maquina
int filas_maquina = 15;
int columnas_maquina = 15;


//cordenadas iniciales de la maquina
int coord_x_maquina = 60;
int corrd_y_maquina = 25;

// Nivel del juego
int nivel_juego = 1;

// dimensiones de los mapas
int filas_mapa01 = 50, columnas_mapa01 = 80;
int filas_mapa02 = 50, columnas_mapa02 = 80;

// estructuras
struct Poder {
	string nombre;
	bool avilitado;
};

struct Cordenadas {
	int X;
	int Y;
};

struct Tronco {
	int tiempo_de_aparicion;
	bool activo;
	bool varia_derecha = false; // si es true, el tronco se mueve a la derecha
	Cordenadas cordenadas;
};

struct Maquina {
	int vidas = 5;
	int Hitbox_ancho = 14; // ancho de la hitbox de la maquina
	int Hitbox_alto = 15; // alto de la hitbox de la maquina
	Cordenadas cordenadas = { coord_x_maquina, corrd_y_maquina };
	Cordenadas Hitbox = { coord_x_maquina + 8, corrd_y_maquina };
};

struct Jugador {
	int vidas = 3;
	bool perdio = false;
	bool gano = false;
	int troncos_esquivados = 0;
	int troncos_destruidos = 0;
	Cordenadas cordenadas = { coord_x_jugador, coord_y_jugador };
	Cordenadas Hitbox = { coord_x_jugador + 1, coord_y_jugador + 16 };
	int Hitbox_ancho = 8; // ancho de la hitbox del jugador
	int Hitbox_alto = 3; // alto de la hitbox del jugador
	Poder poderes[2] = { {"romper tronco", false}, {"devolver tronco", false} };
};

const int MAX_TRONCOS = 3;
Tronco troncos[MAX_TRONCOS];
struct Castor {
	int tiemp_esta;
	Cordenadas cordenadas;
};

Castor castores[1];
Jugador jugador;//Se define como estructura
Maquina maquina;

void gotoxi(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//void maximizarConsola() {
//	HWND consola = GetConsoleWindow();
//	ShowWindow(consola, SW_MAXIMIZE); // Maximiza la ventana
//}


void configurarConsola() {
	int maxAncho = Console::LargestWindowWidth;
	int maxAlto = Console::LargestWindowHeight;
	Console::WriteLine("Máximo permitido: {0}x{1}", maxAncho, maxAlto);
	Console::SetBufferSize(800, 800);  // columnas, filas
	Console::SetWindowSize(800, 800);  // columnas, filas
}



// Dibujos


/*
Colores para la la pantalla de presentacion
los colores se dibujan en funcion del valor entero en el arreglo.
(color del sesped) 0: verde oliva brillante -> #65a01e -> lo más parecido en ANSI \033[48;5;70m \033[0m
(color de las ramas) 1: gris marron claro -> #83786f -> en ANSI \033[48;5;102m \033[0m
(color del musgo) 2: verde oliva oscuro -> #4a5f41 -> en ANSI \033[48;5;58m \033[0m
(color del tronco de arbol) 3: marron oscuro -> #4e342e -> en ANSI \033[48;5;52m \033[0m
(color del interior del trnco) 4: marron terracota calido -> #A9745B -> en ANSI \033[48;5;137m \033[0m
(color de las letras del titulo) 5: gris azulado muy oscuro -> \033[48;5;235m \033[0m
*/
int position_flecha = 0;



void Dibujar_Presentacion(int* matriz, int filas, int columnas, int coords_x_iniciales = 0, int coords_y_iniciales = 0) {

	int coord_escribir_X = 40;
	int coord_escribir_Y = 20;

	Console::CursorVisible = false;
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {// barremos el arreglo en forma de una matriz
			gotoxi(j + coords_x_iniciales, i + coords_y_iniciales);//Establecemos sus cordenadas segun su posicion 

			switch (matriz[(coords_y_iniciales + (i * columnas)) + (j + coords_x_iniciales)]) {
			case 0: cout << "\033[48;5;70m \033[0m"; break;
			case 1: cout << "\033[48;5;102m \033[0m"; break;
			case 2: cout << "\033[48;5;58m \033[0m"; break;
			case 3: cout << "\033[48;5;52m \033[0m"; break;
			case 4: cout << "\033[48;5;137m \033[0m"; break;
			case 5: cout << "\033[48;5;235m \033[0m"; break;
			}
		}

	}

	cout << "\033[48;5;102m\033[30m";
	gotoxi(coord_escribir_X, coord_escribir_Y);
	cout << "JUGAR";

	gotoxi(coord_escribir_X, coord_escribir_Y + 5);
	cout << "Instrucciones";

	gotoxi(coord_escribir_X, coord_escribir_Y + 10);
	cout << "Creditos";

	char t = _getch();

	if (t == ARRIBA) {
		position_flecha -= 5;
	}
	else if (t == ABAJO) {
		position_flecha += 5;
	}

	if (position_flecha > 10 || position_flecha < 0) {
		position_flecha = 0;
	}
	gotoxi(coord_escribir_X - 6, coord_escribir_Y + position_flecha);
	cout << "-->";
	cout << "\033[0m";
}

/*
Colores para mapa01
los colores se dibujan en funcion de un valor entero en el arreglo.
(color del borde) 0: marron oscuro -> #4e342e -> Lo mas parecido en ANSI \033[48;5;52m \033[0m
(colore del sesped) 1: verde brillante -> #21bf07 -> lo más parecido en ANSI \033[48;5;34m \033[0m
(color del camino) 2: arena claro -> #d2b48c -> lo más parecido en ANSI \033[48;5;180m \033[0m
*/

void Dibujar_Mapa01(int* matriz, int filas, int columnas) {// argumentos, un arreglo por referencia, numero filas, numero de colunas, obsional coords inciales
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {// barremos el arreglo en forma de una matriz
			gotoxi(j, i);//Establecemos sus cordenadas segun su pocision 

			switch (matriz[(i * columnas) + j]) {
			case 0: cout << "\033[48;5;52m \033[0m"; break;
			case 1: cout << "\033[48;5;34m \033[0m"; break;
			case 2: cout << "\033[48;5;180m \033[0m"; break;
			}
		}

	}
}
void Dibujar_mapa02(int* matriz, int filas, int columnas) {
	Console::CursorVisible = false;
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {// barremos el arreglo en forma de una matriz
			gotoxi(j, i);//Establecemos sus cordenadas segun su pocision 

			switch (matriz[i * columnas + j]) {
			case 1: cout << "\033[48;5;28m \033[0m"; break;
			case 2: cout << "\033[48;5;196m \033[0m"; break;
			case 3: cout << "\033[48;5;226m \033[0m"; break;
			case 4: cout << "\033[48;5;179m \033[0m"; break;
			case 5: cout << "\033[48;5;94m \033[0m"; break;
			}
		}
	}
}
/*
Colores para dibujar personaje
Los colores se dibujaran en funcion de un valor entero en arreglo.
(piel del personaje) 3: durazno suave -> #ffd787 -> en ANSI \e[48;5;222m \e[0m
(polo del personaje) 4: blanco puro -> #ffffff -> en ANSI \033[48;5;231m \033[0m
(pantalon del personaje) 5: violeta azulado brillante -> #6f51ff -> en ANSI \033[48;5;99m \033[0m
(zapatos, zombrero y ojos) 6: negro puro -> #000000 -> en ANSI \033[48;5;16m \033[0m
*/
void Dibujar_jugador(int* matriz, int filas, int columnas) {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {// barremos el arreglo en forma de una matriz
			gotoxi(j + jugador.cordenadas.X, i + jugador.cordenadas.Y);//Establecemos sus cordenadas segun su pocision 

			switch (matriz[i * columnas + j]) {
			case -1: break;
			case 3: cout << "\033[48;5;222m \033[0m"; break;
			case 4: cout << "\033[48;5;231m \033[0m"; break;
			case 5: cout << "\033[48;5;99m \033[0m"; break;
			case 6: cout << "\033[48;5;16m \033[0m"; break;

			}
		}
	}
}
/*
Colores para dibujar el tronco
(efecto del tronco) 6: negro puro -> #000000 -> en ANSI \033[48;5;16m \033[0m
(color del tronco) 7: marron oscuro -> #563416 -> en ANSI  \033[48;5;94m \033[0m
*/
void DibujarTronco(int* matriz, int filas, int columnas, int coord_x_tronco, int coord_y_tronco) {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			gotoxi(j + coord_x_tronco, i + coord_y_tronco);
			switch (matriz[i * columnas + j]) {
			case 6: cout << "\033[48;5;16m \033[0m"; break;
			case 7: cout << "\033[48;5;99m \033[0m"; break;
			}
		}
	}
}


/*
Colores para dibujar la maquina
(bordes de la maquina) 6: negro puro -> #000000 -> en ANSI \033[48;5;16m \033[0m
(color del tronco) 7: marron oscuro -> #563416 -> en ANSI  \033[48;5;94m \033[0m
(cabeza de la mquina) 8: gris oscuro -> #4a4545 -> en ANSI \033[48;5;59m \033[0m
(ventana de la maquina) 9: verde menta muy claro -> #c1f1e6 -> en ANSI \033[48;5;159m \033[0m
(segunda tonalidad de la ventana de la maquina) 10: verde azulado grisásceo suave -> #9abeb9 -> en ANSI \033[48;5;152m \033[0m
(luces de la maquina) 11: rojo puro -> #ff0000 -> en ANSI \033[48;5;196m \033[0m
(luces de la maquina) 12: verde lima -> #40ff00 -> en ANSI \033[48;5;118m \033[0m

*/
void Dibujar_maquina(int* matriz, int filas, int columnas) {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			gotoxi(j + maquina.cordenadas.X, i + maquina.cordenadas.Y);
			switch (matriz[i * columnas + j]) {
			case -1: break;
			case 6: cout << "\033[48;5;16m \033[0m"; break;
			case 7: cout << "\033[48;5;94m \033[0m"; break;
			case 8: cout << "\033[48;5;59m \033[0m"; break;
			case 9: cout << "\033[48;5;159m \033[0m"; break;
			case 10:cout << "\033[48;5;152m \033[0m"; break;
			case 11:cout << "\033[48;5;196m \033[0m"; break;
			case 12:cout << "\033[48;5;118m \033[0m"; break;
			}
		}
	}
}
/*
Colores para dibujar el arbol

(color del tronco) 7: marron oscuro -> #563416 -> en ANSI  \033[48;5;94m \033[0m
(color del musgo) 13: verde oliva oscuro -> #4a5f41 -> en ANSI \033[48;5;58m \033[0m

*/


void DibujarArbol(int* matriz, int filas, int columnas, int coord_x_arbol, int coord_y_arbol) {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			gotoxi(j + coord_x_arbol, i + coord_y_arbol);
			switch (matriz[i * columnas + j]) {
			case -1:break;
			case 7: std::cout << "\033[48;5;94m \033[0m"; break; // Marrón (tronco)
			case 13: cout << "\033[48;5;58m \033[0m"; break; // Verde oliva oscuro(hojas)
			}
		}
	}
}
// Colores para dibujar castor
// espacios en blanco = -1
// #000000 -> bordes en negro del castor = 6
// #c7961c -> color del pelaje del castor = 13
// #c7961c -> color de las ojeras del castor = 14
// #714646 -> color de la nariz del castor = 15
// #714646 -> color marron del castor = 0
// #ffffff -> color de dientes del castor (blanco) = 4

void DibujarCastor(int* matriz, int filas, int columnas, int coord_x_castor, int coord_y_castor) {
	Console::CursorVisible = false;
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			gotoxi(j + coord_x_castor, i + coord_y_castor);
			switch (matriz[i * columnas + j]) {
			case -1: break;
			case 0: cout << "\033[48;5;52m \033[0m"; break;
			case 4: cout << "\033[48;5;231m \033[0m"; break;
			case 6: cout << "\033[48;5;16m \033[0m"; break;
			case 13: cout << "\033[48;5;136m \033[0m"; break;
			case 14: cout << "\033[48;5;136m \033[0m"; break;
			case 15: cout << "\033[48;5;95m \033[0m"; break;
			}
		}
	}
}

void dibujarperdiste(int* matriz, int filas, int columnas) {
	Console::CursorVisible = false;
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			gotoxi(j, i);
			switch (matriz[i * columnas + j]) {
			case 0: cout << "\033[48;5;88m \033[0m"; break;   // borde rojo oscuro
			case 1: cout << "\033[48;5;196m \033[0m"; break;  // fondo rojo brillante
			}
		}
	}
}

// mostrar el mensaje game over
void dibujar_gameover(int* matriz, int filas, int columnas) {
	Console::CursorVisible = false;
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {// barremos el arreglo en forma de una matriz
			gotoxi(j, i);//Establecemos sus cordenadas segun su pocision 

			switch (matriz[(i * columnas) + j]) {
			case 1: cout << "\033[48;5;22m \033[0m"; break;
			case 2: cout << "\033[48;5;196m \033[0m"; break;
			case 3: cout << "\033[48;5;226m \033[0m"; break;
			case 4: cout << "\033[48;5;16m \033[0m"; break;

			}
		}
	}
}
// dibujar ventana de ganaste (YOU WIN)
void dibujargameover(int* matriz, int filas, int columnas) {
	Console::CursorVisible = false;
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			gotoxi(j, i);
			switch (matriz[i * columnas + j]) {
			case 1: cout << "\033[48;5;22m \033[0m"; break;   
			case 2: cout << "\033[48;5;120m \033[0m"; break;  
			case 3: cout << "\033[48;5;196m \033[0m"; break;
			case 4: cout << "\033[48;5;58m \033[0m"; break;   // borde verde oscuro
			case 5: cout << "\033[48;5;16m \033[0m"; break;   // borde verde oscuro
			case 6: cout << "\033[48;5;215m \033[0m"; break;   // borde verde oscuro
			}
		}
	}
}


// mostrar instrucciones 
void mostrarinstrucciones() {
	cout << "\033[48;5;34m\033[30m";
	gotoxi(30, 2);
	cout << "INSTRUCCIONES";
	gotoxi(2, 4);
	cout << "1. Los controles para moverse son las flechitas";
	gotoxi(2, 6);
	cout << "2. El jugador comenzara con 3 vidas.";
	gotoxi(2, 8);
	cout << "3. Los poderes disponibles son: Destruir troncos, Revertir trayectoria.";
	gotoxi(2, 10);
	cout << "4. Cada 20 segundos habrá una posibilidad que aparezca un castor";
	gotoxi(5, 11);
	cout << "y te brinde una vida extra (DISPONIBLE PARA EL NIVEL 02).";
	gotoxi(2, 13);
	cout << "5. El jugador tiene que esquivar los troncos, y por cada uno que le choque";
	gotoxi(5, 14);
	cout << "perdera una vida. ";
	gotoxi(2, 16);
	cout << "6. En el primer nivel el jugador tendra que esquivar troncos, y cuando ";
	gotoxi(5, 17);
	cout << "esquive 10 troncos podra lanzar un poder para destruirlos.";
	gotoxi(2, 19);
	cout << "7. Cuando se destruye un tronco se planta un arbol automaticamente.";
	gotoxi(2, 21);
	cout << "8. El nivel 1 se pasa cuando plantemos 3 arboles.";
	gotoxi(2, 23);
	cout << "9. En el segundo nivel el jugador tendra otro poder que le permitira revertir";
	gotoxi(5, 24);
	cout << "la direccion de los troncos para poder destruir la maquina enemiga. ";
	gotoxi(2, 26);
	cout << "10. La maquina enemiga tiene 5 vidas por cada tronco que le choca pierde una.";
	gotoxi(2, 28);
	cout << "11. Por cada 15 troncos que esquive el jugador este obtendra un poder";
	gotoxi(6, 29);
	cout << "el cual revierte la direccion de los troncos";
	cout << "\033[0m";
}

// dibujar instrucciones
void dibujarfondoinstrucciones() {
	Console::SetWindowSize(80, 50);
	Console::SetBufferSize(80, 50);
	const int FILAS = 50;
	const int COLUMNAS = 80;
	int matrizfondo[FILAS * COLUMNAS];
	for (int i = 0; i < FILAS; i++) {
		for (int j = 0; j < COLUMNAS; j++) {
			if (i == 0 || i == 49 || j == 0 || j == 79)
			{
				matrizfondo[i * COLUMNAS + j] = 0;
			} //borde
			else
			{
				matrizfondo[i * COLUMNAS + j] = 1;
			} //fondo
		}
	}
	Console::CursorVisible = false;
	for (int i = 0; i < FILAS; i++) {
		for (int j = 0; j < COLUMNAS; j++) {
			Console::SetCursorPosition(j, i);
			switch (matrizfondo[i * COLUMNAS + j]) {
			case 0: cout << "\033[48;5;52m \033[0m"; break;
			case 1: cout << "\033[48;5;34m \033[0m"; break;
			}
		}
	}
}
void creditos() {
	cout << "\033[48;5;180m \033[30m";
	gotoxi(30, 2);
	cout << "CREDITOS";
	gotoxi(2, 4);
	cout << "AUTORES/PROGRAMADORES/DISEÑADORES";
	gotoxi(2, 6);
	cout << "- Jeremi Porras U20251F491";
	gotoxi(2, 8);
	cout << "- Alessio Ccasani U20251E693";
	gotoxi(2, 10);
	cout << "- Emerson Nolasco U20251F206";
	gotoxi(2, 13);
	cout << "UNIDOS POR EL CAMBIO";
	gotoxi(2, 16);
	cout << "La tala de árboles destruye hogares naturales,";
	gotoxi(5, 17);
	cout << "altera el clima y pone en riesgo nuestro futuro.";
	cout << "\033[0m";
}

void dibujarfondocreditos() {
	Console::SetWindowSize(80, 50);
	Console::SetBufferSize(80, 50);
	const int FILAS = 50;
	const int COLUMNAS = 80;
	int matrizfondo[FILAS * COLUMNAS];
	for (int i = 0; i < FILAS; i++) {
		for (int j = 0; j < COLUMNAS; j++) {
			if (i == 0 || i == 49 || j == 0 || j == 79)
			{
				matrizfondo[i * COLUMNAS + j] = 0;
			} //borde
			else
			{
				matrizfondo[i * COLUMNAS + j] = 1;
			} //fondo
		}
	}
	Console::CursorVisible = false;
	for (int i = 0; i < FILAS; i++) {
		for (int j = 0; j < COLUMNAS; j++) {
			Console::SetCursorPosition(j, i);
			switch (matrizfondo[i * COLUMNAS + j]) {
			case 0: cout << "\033[48;5;34m \033[0m"; break;
			case 1: cout << "\033[48;5;180m \033[0m"; break;
			}
		}
	}
}
// Movimientos 
void Limpiar_objeto(int* mapa, int filas, int columnas, int x, int y, int filas_jugador, int columnas_jugador) {
	for (int i = 0; i < filas_jugador; i++) {
		for (int j = 0; j < columnas_jugador; j++) {
			gotoxi(x + j, y + i);
			int valor_fondo = mapa[(y + i) * columnas + (x + j)];
			if (nivel_juego == 1) {
				switch (valor_fondo) {
				case 0: cout << "\033[48;5;52m \033[0m"; break;
				case 1: cout << "\033[48;5;34m \033[0m"; break;
				case 2: cout << "\033[48;5;180m \033[0m"; break;
				}

			} else if(nivel_juego == 2) {
				switch (valor_fondo) {
				case 1: cout << "\033[48;5;28m \033[0m"; break;
				case 2: cout << "\033[48;5;196m \033[0m"; break;
				case 3: cout << "\033[48;5;226m \033[0m"; break;
				case 4: cout << "\033[48;5;179m \033[0m"; break;
				case 5: cout << "\033[48;5;94m \033[0m"; break;
				}
			}
			else {
				cout << " "; // si no es ninguno de los dos niveles, limpiamos con un espacio en blanco
			}
		}
	}
}


bool Leer_movimiento(int* mapa) {
	if (_kbhit()) {


		char t = _getch();

		//RestaurarFondoDebajoJugador(filas_jugador, columnas_jugador);
		Limpiar_objeto(mapa, filas_mapa01, columnas_mapa01, jugador.cordenadas.X, jugador.cordenadas.Y, filas_jugador, columnas_jugador);

		switch (t) {
		case ARRIBA: (jugador.cordenadas.Y > 0) ?
			jugador.cordenadas.Y-- :
			jugador.cordenadas.Y++; break;
		case ABAJO: (jugador.cordenadas.Y + filas_jugador < filas_mapa01 - 2) ? jugador.cordenadas.Y++ : jugador.cordenadas.Y--; break;
		case DERECHA: (jugador.cordenadas.X + columnas_jugador < columnas_mapa01) ? jugador.cordenadas.X++ : jugador.cordenadas.X--; break;
		case IZQUIERDA: (jugador.cordenadas.X > 0) ? jugador.cordenadas.X-- : jugador.cordenadas.X++; break;
		default: return false;
		}
		jugador.Hitbox.X = jugador.cordenadas.X + 1; // actualizamos la hitbox del jugador
		jugador.Hitbox.Y = jugador.cordenadas.Y + 16; // actualizamos la hitbox del jugador

		return true;

	}
	return false;
}



bool Hay_colision(int obj01_x, int obj01_y, int obj01_ancho, int obj01_alto, int obj02_x, int obj02_y, int obj02_ancho, int obj02_alto) {
	return (
		obj01_x < obj02_x + obj02_ancho &&
		obj01_x + obj01_ancho > obj02_x &&
		obj01_y < obj02_y + obj02_alto &&
		obj01_y + obj01_alto > obj02_y
		);
}

bool Rango_de_Altura(int y_jugador, int alto_jugador, int y_maquina, int alto_maquina) {
	// Ver si se superponen los intervalos [y, y+alto)
	return (y_jugador < y_maquina + alto_maquina) && (y_maquina < y_jugador + alto_jugador);
}

// cambiar el valor de las vidas y mostrar la actualizacion
void vidas() {

	// Mostrar el número de vidas actuales en pantalla
	gotoxi(3, 49);
	cout << "\033[0;97mVIDAS: " << jugador.vidas << "   \033[0m"; // texto blanco
}

void troncos_esquivados() {
	gotoxi(20, 49);

	cout << "Troncos esquivados: " << jugador.troncos_esquivados << "\033[0m";
}
void MostrarPoder_1() {
	if (jugador.troncos_esquivados >= 10) {
		gotoxi(46, 49);
		cout << "\033[0;32mPoder de romper activado!\033[0m" << endl;
	}
}
void MostrarPoder_2() {
	if (jugador.troncos_esquivados >= 15) {
		gotoxi(46, 49);
		cout << "\033[0;32mPoder de devolver troncos activados!\033[0m" << endl;
	}
}

void inicializarTroncos() {
	srand(time(NULL));

	int tiempo_base = GetTickCount();


	for (int i = 0; i < MAX_TRONCOS; i++) {
		troncos[i].cordenadas.X = 70; // posición horizontal aleatoria
		if (nivel_juego == 2) {
			troncos[i].cordenadas.X = 60;

		}
		troncos[i].cordenadas.Y = (i * 14) + 6; // posicion vertical diferentes 
		troncos[i].tiempo_de_aparicion = tiempo_base + (rand() % 5000);
		if (nivel_juego == 2) {
			troncos[i].activo = false; continue;
		}
		troncos[i].activo = true;
	}
}

void DibujarTroncos(int* mapa, int* matriz_tronco, int i) {

	int tiempo_base = GetTickCount();

	Limpiar_objeto(mapa, filas_mapa01, columnas_mapa01,
		troncos[i].cordenadas.X, troncos[i].cordenadas.Y, dimensiones_tronco_filas, dimensiones_tronco_columnas);

	

	if (troncos[i].cordenadas.X < 1) {
		if (nivel_juego == 1) {

			troncos[i].cordenadas.X = columnas_mapa01 - dimensiones_tronco_columnas;//  vuelve a aparecer a la derecha
		}
		else {
			troncos[i].cordenadas.X = 58; // en el nivel 2 vuelve a aparecer a la derecha
		}
		troncos[i].tiempo_de_aparicion = tiempo_base + (rand() % 5000);
		jugador.troncos_esquivados++; // incrementa el contador de troncos esquivados
		if (nivel_juego == 2) troncos[i].activo = false; // si es el nivel 2, el tronco se desactiva
		return;
	}

	if (nivel_juego == 1 ) {

		troncos[i].cordenadas.X -= 1;
	}
	else if(nivel_juego == 2 ) {
		troncos[i].cordenadas.X -= 2; // en el nivel 2 los troncos se mueven mas rapido
	}


	DibujarTronco(matriz_tronco, dimensiones_tronco_filas, dimensiones_tronco_columnas, troncos[i].cordenadas.X, troncos[i].cordenadas.Y);	
}

void DibujarTroncosDerecha(int* mapa, int* matriz_tronco, int i) {
	int tiempo_base = GetTickCount();


	if (troncos[i].cordenadas.X >= 78) {
		troncos[i].cordenadas.X = columnas_mapa01 - dimensiones_tronco_columnas; // vuelve a aparecer a la derecha
		troncos[i].tiempo_de_aparicion = tiempo_base + (rand() % 5000);
		jugador.troncos_esquivados++; // incrementa el contador de troncos esquivados
		if (nivel_juego == 2) troncos[i].activo = false; // si es el nivel 2, el tronco se desactiva
		troncos[i].varia_derecha = false;
		return;
	}

	DibujarTronco(matriz_tronco, dimensiones_tronco_filas, dimensiones_tronco_columnas, troncos[i].cordenadas.X, troncos[i].cordenadas.Y);
}


void Borrar_troncos(int* mapa, int* matriz_tronco,int i) {

	Limpiar_objeto(mapa, filas_mapa01, columnas_mapa01,
		troncos[i].cordenadas.X, troncos[i].cordenadas.Y, dimensiones_tronco_filas, dimensiones_tronco_columnas);

}

void MoverMaquinaHaciaJugador() {
	if (maquina.cordenadas.Y < jugador.cordenadas.Y + 4) {//Tienen diferente altura para que esten alineados se le suma +4
		maquina.cordenadas.Y++; // La máquina baja un paso
		maquina.Hitbox.Y = maquina.cordenadas.Y + 2; // Actualizamos la hitbox de la maquina
	}
	else if (maquina.cordenadas.Y > jugador.cordenadas.Y + 4) {
		maquina.cordenadas.Y--; // La máquina sube un paso
		maquina.Hitbox.Y = maquina.cordenadas.Y; // Actualizamos la hitbox de la maquina
	}

}
void Colision_HitboxJugador_Tronco(int* mapa) {
	for (int i = 0; i < MAX_TRONCOS; i++) {
		if (troncos[i].activo && Hay_colision(jugador.Hitbox.X, jugador.Hitbox.Y, jugador.Hitbox_ancho, jugador.Hitbox_alto,
			troncos[i].cordenadas.X, troncos[i].cordenadas.Y, dimensiones_tronco_columnas, dimensiones_tronco_filas)) {
			// si hay colision con un tronco
			jugador.vidas -= 1;
			inicializarTroncos(); // reiniciamos los troncos
			jugador.cordenadas.X = coord_x_jugador; // reiniciamos la posicion del jugador
			jugador.cordenadas.Y = coord_y_jugador; // reiniciamos la posicion del jugador
			system("cls"); // limpiamos la pantalla

			if (nivel_juego == 1) {
				// si el jugador pierde una vida en el nivel 1, reiniciamos el mapa
				Dibujar_Mapa01(mapa, filas_mapa01, columnas_mapa01); // dibujamos el mapa
			}
			else if (nivel_juego == 2) {
				maquina.cordenadas.Y = corrd_y_maquina;// reiniciamos la posicion de la maquina
				
				// si el jugador pierde una vida en el nivel 2, reiniciamos el mapa
				Dibujar_mapa02(mapa, filas_mapa02, columnas_mapa02); // dibujamos el mapa
			}
			vidas();

			return;
		}
	}
}
void Tronco_Destruido(int* arbol, int* mapa, int* matriz_tronco) {
	for (int i = 0; i < MAX_TRONCOS; i++) {


		if (!troncos[i].activo) {
			DibujarArbol(arbol, 15, 10, troncos[i].cordenadas.X, troncos[i].cordenadas.Y);
		}

		if (troncos[i].activo && Hay_colision(jugador.Hitbox.X, jugador.Hitbox.Y, jugador.Hitbox_ancho, jugador.Hitbox_alto,
			troncos[i].cordenadas.X, troncos[i].cordenadas.Y, dimensiones_tronco_columnas, dimensiones_tronco_filas)) {
			// si hay colision con un tronco
			if (jugador.poderes[0].avilitado) { // si el poder de romper tronco esta activado
				troncos[i].activo = false; // desactivamos el tronco
				jugador.troncos_esquivados++; // incrementamos el contador de troncos esquivados
				Borrar_troncos(mapa, matriz_tronco, i); // borramos el tronco de la pantalla
				// dibujamos el arbol en la posicion del tronco destruido
				DibujarArbol(arbol, 15, 10, troncos[i].cordenadas.X, troncos[i].cordenadas.Y);
				jugador.troncos_destruidos++;
			}
		}

	}
}
void Tronco_devuelto(int* mapa, int* matriz_tronco) {
	for (int i = 0; i < MAX_TRONCOS; i++) {
		if (troncos[i].activo && Hay_colision(jugador.Hitbox.X, jugador.Hitbox.Y, jugador.Hitbox_ancho, jugador.Hitbox_alto,
			troncos[i].cordenadas.X, troncos[i].cordenadas.Y, dimensiones_tronco_columnas, dimensiones_tronco_filas)) {
			// si hay colision con un tronco
			if (jugador.poderes[1].avilitado) { // si el poder de romper tronco esta activado
				//troncos[i].activo = false; // desactivamos el tronco	
				troncos[i].varia_derecha = true;
				
			}
		}

	}
}
void Aparecer_Castor(int* castor) {
	if (jugador.vidas<3) {
			for (int i = 0; i < 1; i++) {
				castores[i].cordenadas.X = 60; // posición horizontal aleatoria
				castores[i].cordenadas.Y = (i * 14) + 6; // posicion vertical diferentes 
				castores[i].tiemp_esta = 7000 + (rand() % 5000);
				jugador.vidas++;
				vidas();//actualiza el valor de las vidas
				DibujarCastor(castor, 10, 10, 60, 20);
			}
		}
	}



#endif