#include "funciones.h"
using namespace std;

void juego(){
    srand(time(0));

    char jugadores[2][50];
    int stock[2]={6,6};
    int puntaje[2]= {0,0};
    int dados[12];
    int  dadosUsados=0;

    //0 para jugador 1 / 1 para jugador 2
    int jugador = 0;
    int cantidad = stock[jugador];

    cout<<"ingrese el nombre del jugador 1: ";
    cin.getline(jugadores[0], 50);
    cout<<"ingrese nombre del jugador 2 :";
    cin.getline(jugadores[1], 50);

    system("cls");
    int dado1;
    int dado2;

    do{
    dado1 = rand() % 6 + 1;
    dado2 = rand() % 6 + 1;

    cout<<"-el jugador que tire el dado con el numero mas grande comenzara-"<<endl;
    cout<<" "<<endl;
    cout<<"el jugador: "<<jugadores[0] <<" tiro un: "<< dado1 <<endl;
    cout<<"el jugador: "<< jugadores[1] <<" tiro un: "<< dado2 <<endl;
    cout<<" "<<endl;

    if(dado1==dado2){
    cout<<"empataron, se volvera a lanzar los dados."<<endl;
    cout<<" "<<endl;
    }
    }while(dado1==dado2);

    int jugadorActual;
    if(dado1>dado2){
             jugadorActual = 0;
             cout<<"el jugador: "<<jugadores[0] <<" comenzara."<<endl;
    }else{
         jugadorActual = 1;
        cout<<"el jugador: "<<jugadores[1] <<" comenzara."<<endl;
    }
    system("pause");

    int sumaObjetivo = tiradaDadosObjetivo();
    cout << "la suma objetivo a conseguir es de: "<< sumaObjetivo<<endl;


    //tiradaDeTurno(dados, stock, jugadorActual, jugadores, sumaObjetivo);
    int puntos= tiradaDeTurno(dados, stock, jugadorActual, jugadores, sumaObjetivo);

    puntaje[jugadorActual] += puntos;

    int otroJugador = (jugadorActual+1)%2;
    stock[otroJugador] +=  dadosUsados;
    system("pause");




    /*
    falta

    -transferencia de dados proceso


    -ciclo de rondas falta
    -estadistica falta
    -menu falta

    -creditos falta
    */


}

int tiradaDadosObjetivo(){
 cout<<" "<<endl;
 int dadoDoce1= rand() % 12 +1;
 int dadoDoce2= rand() % 12 +1;
 cout<<"el primer dado objetivo es: "<<dadoDoce1<<endl;
 cout<<"el segundo dado objetivo es: "<<dadoDoce2<<endl;
 cout<<" "<<endl;
 return dadoDoce1+dadoDoce2;
 }


int tiradaDeTurno(int dados[], int stock[], int jugadorActual, char jugadores[2][50], int sumaObjetivo){
    cout<<" "<<endl;

    int cantidad = stock[jugadorActual];
        sumaObjetivo= sumaObjetivo;
    int acumSeleccion = 0;
    int seleccion;
    int dadosUsados=0;

    cout<<"es el turno de: "<<jugadores[jugadorActual]<<endl;
    cout<<"la suma objetivo a conseguir es de: "<<sumaObjetivo<<endl;
    cout<<" "<<endl;

    for (int i = 0; i < cantidad; i++) {
        dados[i] = rand() % 6 + 1;
        cout << "Dado " << i + 1 << ": " << dados[i] << endl;
        }

        cout<<"Seleccione los dados a sumar para llegar al obejtivo."<<endl;
        cout<<"Presiona 0 para finalizar."<<endl;
        cout<<""<<endl;

    while(true){
        cin>>seleccion;
        if(seleccion!=0){
        acumSeleccion += dados[seleccion-1];
        dadosUsados++;

        }else break;
    };


    if(acumSeleccion==sumaObjetivo){


            cout<<"alcanzaste el objetivo de: "<<sumaObjetivo<<endl;
            cout<<"y seleccionaste "<< dadosUsados<<" cantidad de dados"<<endl;
            int puntajeTurno = acumSeleccion* dadosUsados;


        cout<<"el puntaje a sumar es de: "<<puntajeTurno<<endl;
        return puntajeTurno;
    }else {

        cout<<"no alcanzaste el objetivo y no sumas puntos"<<endl;
         dadosUsados=0;
        return 0;
    }
}
