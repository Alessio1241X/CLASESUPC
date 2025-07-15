#include <iostream>
#include "funcionesvideojuego_v3.h"
#include "assets.h"

// TODO: Iniciar la programcion incial del videojuego

void Nivel01() {
	bool Nivel_finalizado = false;
	bool se_mostro_poder = false;

	Dibujar_Mapa01(mapa01, filas_mapa01, columnas_mapa01);
	Dibujar_jugador(prota, 19, 10);
	inicializarTroncos();
	vidas();
	DibujarCastor(castor_data, 10, 10, 60, 20);
	unsigned long long tiempo_anterior = GetTickCount64();
	do {

		if (_kbhit()) {//detecta si se presiona alguna tecla
			Leer_movimiento(mapa01);
			Dibujar_jugador(prota, filas_jugador, columnas_jugador);
		}




		unsigned long long tiempo_actual = GetTickCount64();

		if (tiempo_actual - tiempo_anterior >= 100) {  // actualiza cada 100ms
			for (int i = 0; i < MAX_TRONCOS; i++) {
				if (!(troncos[i].activo)) continue; // Si el tronco no está activo, no lo dibujamos
				if (tiempo_actual <= troncos[i].tiempo_de_aparicion) continue;

				DibujarTroncos(mapa01, tronco_data, i);

			}


			tiempo_anterior = tiempo_actual;
		}
		if (jugador.troncos_esquivados >= 10) {
			jugador.poderes[0].avilitado = true;
			Tronco_Destruido(arbol_data, mapa01, tronco_data);
			if (!se_mostro_poder) {

				MostrarPoder_1();
				se_mostro_poder = true;
			}
		}
		else {
			Colision_HitboxJugador_Tronco(mapa01);
		}
		troncos_esquivados();

		if (jugador.vidas <= 0) {
			system("cls");
			dibujargameover(gameover, 50, 80);
			jugador.perdio = true;
			break;

		}

		if (jugador.troncos_destruidos == 3) {
			DibujarCastor(castor_data, 10, 10, 60, 20);
			_sleep(2000);
			Nivel_finalizado = true;
			system("cls");
			nivel_juego++;

		}



	} while (!Nivel_finalizado);

	jugador.troncos_esquivados = 0; // Reiniciar el contador de troncos esquiados al finalizar el nivel
	jugador.troncos_destruidos = 0; // Reiniciar el contador de troncos destruidos al finalizar el nivel
	jugador.vidas = 3; // Reiniciar las vidas al finalizar el nivel
	jugador.poderes[0].avilitado = false; // Reiniciar el poder al finalizar el nivel
	_sleep(500);
}

void Nivel02() {
	bool Nivel_finalizado = false;
	bool se_mostro_poder = false; // Variable para controlar si se ha mostrado el poder
	jugador.gano = false; // Reiniciar el estado de jugador al finalizar el nivel
	jugador.perdio = false; // Reiniciar el estado de jugador al finalizar el nivel
	
	Dibujar_mapa02(mapa02, filas_mapa02, columnas_mapa02);
	Dibujar_jugador(prota, 19, 10);
	inicializarTroncos();
	Dibujar_maquina(maquina_data, 15, 15);
	vidas();
	unsigned long long tiempo_anterior = GetTickCount64();//tiempo de troncos
	unsigned long long tiempo_castor_anterior = GetTickCount64();//tiempo de castor
	do {
		if (_kbhit()) {//detecta si se presiona alguna tecla
			Leer_movimiento(mapa02);
			Dibujar_jugador(prota, filas_jugador, columnas_jugador);
		}

		unsigned long long tiempo_actual = GetTickCount64();
		if (tiempo_actual - tiempo_anterior >= 100) {  // actualiza cada 100ms

			if (tiempo_actual - tiempo_castor_anterior >= 20000) {//20 seg	
				Aparecer_Castor(castor_data); //FUNCION DE CASTOR
				tiempo_castor_anterior = tiempo_actual;//se reinicia el tiempo de aparacion del castor
			}

			if (!(jugador.cordenadas.Y + 4 == maquina.cordenadas.Y)) {//para alinear al jugador con la maquina

				Limpiar_objeto(mapa02, filas_mapa02, columnas_mapa02, maquina.cordenadas.X, maquina.cordenadas.Y, 15, 15);
				MoverMaquinaHaciaJugador();
				Dibujar_maquina(maquina_data, 15, 15);

			}

			if (Rango_de_Altura(jugador.Hitbox.Y, 3, maquina.cordenadas.Y, filas_maquina)) {
				for (int i = 0; i < MAX_TRONCOS; i++) {
					if (Rango_de_Altura(maquina.cordenadas.Y + 7, filas_maquina - 7, troncos[i].cordenadas.Y, dimensiones_tronco_filas)) {
						troncos[i].activo = true; // Activar tronco cuando la maquina esta en rango de altura

					}					
				}
			}

			for (int i = 0; i < MAX_TRONCOS; i++) {
				if (!(troncos[i].activo)) continue; // Si el tronco no está activo, no lo dibujamos

				Tronco_devuelto(mapa02, tronco_data);
				
				if (!troncos[i].varia_derecha) {
					DibujarTroncos(mapa02, tronco_data, i);
				}
				

				//moverTroncos();
				if (troncos[i].varia_derecha) {
					Limpiar_objeto(mapa02, filas_mapa01, columnas_mapa01,
					troncos[i].cordenadas.X, troncos[i].cordenadas.Y, dimensiones_tronco_filas, dimensiones_tronco_columnas);
					troncos[i].cordenadas.X += 2; // Mover tronco hacia la derecha
				
					DibujarTroncosDerecha(mapa02, tronco_data, i);

					if (Hay_colision(maquina.Hitbox.X, maquina.Hitbox.Y, maquina.Hitbox_ancho, maquina.Hitbox_alto, troncos[i].cordenadas.X,
						troncos[i].cordenadas.Y, dimensiones_tronco_filas, dimensiones_tronco_columnas)) {
						maquina.vidas--; // Restar vida a la maquina si colisiona con un tronco
						troncos[i].activo = false;// Desactivar tronco al colisionar con la maquina
						troncos[i].varia_derecha = false; // Reiniciar la posicion del tronco
						Borrar_troncos(mapa02, tronco_data, i); // Borrar tronco si colisiona con la maquina
					}

				}
			}

			tiempo_anterior = tiempo_actual;
		}



		if (jugador.troncos_esquivados >= 15) {
			jugador.poderes[1].avilitado = true;
			if (!se_mostro_poder) {
				
				MostrarPoder_1();
				se_mostro_poder = true; 
			}
		}
		else {
			Colision_HitboxJugador_Tronco(mapa02);
		}
		troncos_esquivados();

		if (maquina.vidas <= 0 ) {
			system("cls");
			dibujargameover(ganaste, 50, 80);
			jugador.gano = true; // Cambiar el estado de jugador a ganado
			_sleep(3000);
			system("cls");//Limpiamos pantalla
			dibujarfondocreditos();
			creditos();
			Nivel_finalizado = true;
			break;
		}

		if (jugador.vidas <= 0) {
			system("cls");
			dibujar_gameover(gameover, 50, 80);
			jugador.perdio = true;
			Nivel_finalizado = true;

			break;

		}

	} while (!Nivel_finalizado);

	jugador.troncos_esquivados = 0; // Reiniciar el contador de troncos esquiados al finalizar el nivel
	jugador.troncos_destruidos = 0; // Reiniciar el contador de troncos destruidos al finalizar el nivel
	
	jugador.vidas = 3; // Reiniciar las vidas al finalizar el nivel
	jugador.poderes[0].avilitado = false; // Reiniciar el poder al finalizar el nivel
	jugador.poderes[1].avilitado = false; // Reiniciar el poder al finalizar el nivel
	jugador.cordenadas.X = columnas_jugador; // Reiniciar la posicion del jugador al finalizar el nivel
	jugador.cordenadas.Y = filas_jugador; // Reiniciar la posicion del jugador al finalizar el nivel
	jugador.Hitbox.X = columnas_jugador; // Reiniciar la Hitbox del jugador al finalizar el nivel
	jugador.Hitbox.Y = filas_jugador; // Reiniciar la Hitbox del jugador al finalizar el nivel
	nivel_juego = 1;

	maquina.vidas = 5; // Reiniciar las vidas de la maquina al finalizar el nivel
	_sleep(500);
}


void jugar() {
	switch (nivel_juego) {
	case 1: Nivel01(); break;
	case 2: Nivel02(); break;
	}
}

int main() {

	configurarConsola();


	Dibujar_Presentacion(presentacion_matris, 50, 80);//Llamar a la funcion dibujar presentacion
	bool opcion_elegida = false;
	int num_opcion;
inicio:
	do
	{
		if (_kbhit()) {
			Dibujar_Presentacion(presentacion_matris, 50, 80);

			char o = _getch();
			if (o == ENTER) {
				opcion_elegida = true;
				num_opcion = position_flecha / 5;
			}
		}
	} while (!opcion_elegida);

	if (num_opcion == 0) {
		do
		{
			system("cls");//Limpiamos pantalla
			jugar();
		} while (!(jugador.perdio || jugador.gano));
		opcion_elegida = false;
		num_opcion = -1;
		jugador.perdio = false; // Reiniciar el estado de jugador al finalizar el juego
		jugador.gano = false; // Reiniciar el estado de jugador al finalizar el juego
		goto inicio; // Volver al inicio del juego si se pierde o se gana

	}

	if (num_opcion == 1) {
		system("cls");//Limpiamos pantalla
		dibujarfondoinstrucciones();
		mostrarinstrucciones();

		do
		{
			if (_kbhit()) {
				opcion_elegida = false;
				num_opcion = -1;
				system("cls");
				goto inicio;
			}
		} while (true);

	}

	if (num_opcion == 2) {
		system("cls");//Limpiamos pantalla
		dibujarfondocreditos();
		creditos();

		do {
			if (_kbhit()) {
				opcion_elegida = false;
				num_opcion = -1;
				system("cls");
				goto inicio;
			}

		} while (true);
	}

	return 0;
}