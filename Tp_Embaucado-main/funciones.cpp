#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include <stdlib.h>


void establecerSemilla()
{
    srand(time(nullptr));
}

string obtenerNroNaipe (int id, int &valor)
{
    string numeroNaipe;
    switch (id)
    {
    case 1:
        numeroNaipe="10";
        valor = 10;
        break;
    case 2:
        numeroNaipe="J";
        valor = 11;
        break;
    case 3:
        numeroNaipe="Q";
        valor = 12;
        break;
    case 4:
        numeroNaipe="K";
        valor = 15;
        break;
    case 5:
        numeroNaipe="A";
        valor = 20;
        break;
    }
    return (numeroNaipe);
}

void obtenerNumeroNombreNaipe(int id, string &numeroNaipe, string &nombreNaipe,int &valor)
{
    if(id < 6)
    {
        nombreNaipe = "Corazon";
    }
    else if(id < 11)
    {
        nombreNaipe = "Diamante";
        id -= 5;

    }
    else if(id < 16)
    {
        nombreNaipe = "Pica";
        id -= 10;
    }
    else
    {
        nombreNaipe = "Trebol";
        id -= 15 ;
    }
    numeroNaipe=obtenerNroNaipe(id,valor);
}

int obtenerNumeroAleatorio(int rango)
{
    return rand()%rango + 1;
}
void generarNombre(string &jugador1, string &jugador2)
{
    char confirmacion;
    do
    {
        cout << "ingrese el nombre del Jugador1 : ";
        cin >> jugador1;
        cout << "ingrese el nombre del Jugador2 : ";
        cin >> jugador2;
        cout << endl;
        cout << "Confirmar nombre ?"<< "  " << "S/N ";
        cin >> confirmacion;
    }
    while(confirmacion!='S');
}


void obtenerMano(int v[], int tam)
{
    int i;
    int rango = 20;
    for(i = 0; i <tam;  i++)
    {
        v[i] = obtenerNumeroAleatorio(rango);
    }
}
void mostrarMano(int v[], int tam,int puntaje[], string embaucado,int ronda)
{
    int i, valor;
    string palo, numero;
    for(i = 0; i <tam;  i++)
    {
        obtenerNumeroNombreNaipe(v[i], numero, palo, valor);
        cout << numero << " " << palo << endl;
        if(palo!= embaucado)
        {
            puntaje[ronda]+=valor;
        }
    }
    cout << endl;
}
int contarNumeros(int v[], int tam, int comparacion)
{
    int contar = 0;
    int i;
    for (i = 0; i < tam; i++)
    {
        if(v[i]==comparacion)
        {
            contar++;
        }
    }
    return contar;
}
bool verificarVector(int v[],  int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        if(contarNumeros(v, tam, v[i]) > 1)
        {
            return false;
        }
    }
    return true;
}
bool verificarManos(int v1[],int v2[],int tam)
{
    for(int i=0; i<tam; i++)///para cada carta de la mano 1
    {

        for(int x=0; x<tam; x++)///veo la carta de la mano 2
        {
            if(v1[i]==v2[x])
            {
                return false;

            }
        }
    }
    return true;
}
string generarEmbaucado()
{
    int idEmbaucado=obtenerNumeroAleatorio(4);
    string palo;
    switch (idEmbaucado)
    {
    case 1:
        palo="Corazon";
        break;
    case 2:
        palo="Diamante";
        break;
    case 3:
        palo="Pica";
        break;
    case 4:
        palo="Trebol";
        break;
    }
    return palo;

}
void limpiarVector(int vec[],int tam)
{

    for(int i=0; i<tam; i++)
    {
        vec[i]=0;

    }

}
void generarRondas (string embaucado, string jugador1, string jugador2,int puntajeJugador1[], int puntajeJugador2[], int ronda )
{
    int manoJugador1[5];
    int manoJugador2[5];
    do
    {
        obtenerMano(manoJugador1,5);
    }
    while(verificarVector(manoJugador1,5) !=true);
    cout << jugador1 << " : " << endl;
    mostrarMano(manoJugador1,5,puntajeJugador1,embaucado,ronda);
    cout << "------------" <<endl;
    cout << "CARTA DEL EMBAUCADO: " << embaucado <<endl;
    cout << "------------" <<endl;
    do
    {
        obtenerMano(manoJugador2,5);
    }
    while(verificarVector(manoJugador2,5) !=true || verificarManos(manoJugador1,manoJugador2,5) !=true);
    cout << jugador2 << " : " << endl;
    mostrarMano(manoJugador2,5,puntajeJugador2,embaucado,ronda);
    cout << "puntaje de  " <<jugador1 << " : " <<puntajeJugador1[ronda] <<endl;
    cout << "puntaje de  " <<jugador2 << " : " <<puntajeJugador2[ronda] <<endl;
    system("pause");
    system("cls");
}
int sumarVector(int vec[],int tam)
{
    int contar=0;
    for(int i=0; i<tam; i++)
    {
        contar+=vec[i];
    }
    return(contar);
}
void generarGanador(int j1[],int j2[], string n1, string n2)
{
    int PJ1,PJ2;
    PJ1=sumarVector(j1,3);
    PJ2=sumarVector(j2,3);
    cout << n1 << ": " << j1[0] << " + "<< j1[1] << " + "<< j1[2] << "  = " << PJ1 <<endl;
    cout << n2 << ": " << j2[0] << " + "<< j2[1] << " + "<< j2[2] << "  = " << PJ2 <<endl;
    if(PJ1>PJ2)
    {
        cout << "EL GANADOR ES: " << n1 << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "EL GANADOR ES: " << n2 << endl;
        system("pause");
        system("cls");
    }
}

int mayorVector(int vec[], int tam)
{
    int mayorPuntaje=vec[0];
    for (int i=1; i<tam; i++)
    {
        if(vec[i]>mayorPuntaje)
        {
            mayorPuntaje=vec[i];
        }
    }
    return (mayorPuntaje);
}

void generarDesempate(int vec1[], int vec2[],string jugador1, string jugador2)
{
    int Mayorpuntaje1, Mayorpuntaje2;
    Mayorpuntaje1 = mayorVector(vec1,3);
    Mayorpuntaje2 = mayorVector(vec2,3);
    if(Mayorpuntaje1>Mayorpuntaje2)
    {
       cout << "Ganador jugador: " << jugador1;
    }
    else if (Mayorpuntaje2>Mayorpuntaje1){
        cout << "Ganador jugador: " << jugador2;
    }
    else {
     cout   << "Es un empate";
    }
}

