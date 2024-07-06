#include <iostream>
using namespace std;
#include <cstdlib>
#include "menu.h"
#include "funciones.h"
#include <stdlib.h>

void jugarJuego()
{
    int puntajeJugador1[3];
    int puntajeJugador2[3];
    string embaucado;
    string jugador1;
    string jugador2;
    establecerSemilla();
    int opcion;

    do
    {
        mostrarMenu();
        cin >> opcion;
        system("cls");
        switch (opcion)
        {
        case 1:
            limpiarVector(puntajeJugador1,3);
            limpiarVector(puntajeJugador2,3);
            generarNombre( jugador1, jugador2);
            system("cls");
            embaucado=generarEmbaucado();
            generarRondas (embaucado, jugador1,jugador2,puntajeJugador1,puntajeJugador2 , 0);
            generarRondas (embaucado, jugador1,jugador2,puntajeJugador1,puntajeJugador2 , 1);
            generarRondas (embaucado, jugador1,jugador2,puntajeJugador1,puntajeJugador2 , 2);
            generarGanador(puntajeJugador1,puntajeJugador2,jugador1,jugador2);
            break;
        case 2:
            cout << "Estadisticas de juego" << endl;
            mostrarEstadisticas( puntajeJugador1, puntajeJugador2, jugador1, jugador2);
            system("cls");
            break;
        case 3:
            mostrarCreditos();
            system("cls");
            break;
        case 4:
            cout << "Saliendo del juego..." << endl;
            break;
        default:
            cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
            break;
        }
        cout << endl;
    }
    while (opcion !=4);
}


