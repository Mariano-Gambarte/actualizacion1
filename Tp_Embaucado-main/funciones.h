#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void obtenerNumeroNombreNaipe(int id, string &numeroNaipe, string &nombreNaipe,int &valor);
string obtenerNroNaipe(int id, int &valor);
void obetenerNumeroAleatorio(int rango);
void generarTirada(int v[], int tam);
int obtenerNumeroAleatorio(int rango);
void obtenerMano(int v[], int tam);
void mostrarMano(int v[], int tam,int puntaje[],string embaucado,int ronda);
int contarNumeros(int v[], int tam, int comparacion);
bool verificarVector(int v[],  int tam);
bool verificarManos(int v1[],int v2[],int tam);
void establecerSemilla();
string generarEmbaucado();
void generarNombre(string &jugador1, string &jugador2);
void generarRondas (string embaucado, string jugador1, string jugador2,int puntaje1[], int puntaje2[], int ronda );
void limpiarVector(int vec[], int tam);
int sumarVector(int vec[], int tam);
void generarGanador(int j1[],int j2[], string n1, string n2);
int mayorVector(int vec[], int tam);
void generarDesempate(int vec1[], int vec2[], string jugadore1, string jugador2);
#endif // FUNCIONES_H_INCLUDED
