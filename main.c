#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include "header_Connect4.h"
#include <time.h>
#include <windows.h>
        //Aarón Férreo Morales *Coordinador*
        //Luis Gómez Alonso
        //Antonio Castro Blanco
        //Gonzalo García Cortés

int main() //Revisar evaluación horizontal!
    {

        system("color 0B"); //color del tablero
        srand(time(NULL)); //número aleatorio

        char tablero[6][7], c, e; //caracteres para evaluación de ordenador
        int  cont=0, nale;
        int contadorsecuencia=0; //comprobador de secuencia del ciclo de evaluación



        inicio_array(tablero);
        nale=rand()%2;
printf("Se disputara un duelo intelectual entre usted y Pablo.I\nNuestra inteligencia artificial\n");
    if(nale==1){printf("\nEmpieza Pablo" ); meter_fichaO(tablero); cont++;} //caso si empieza máquna
        else printf("Empieza el jugador");
        while (ganador_X_O(tablero)!=1 && ganador_X_O(tablero)!=2 && cont!=21)
        {


            impr_tablero(tablero);
            meter_ficha(tablero);



//ciclo de evaluación
contadorsecuencia=0;
while (contadorsecuencia!=1){ //comprobar si te puede ganar.
        c='O'; e='X';
        if(eval_vertical(tablero, c ,e)==1){contadorsecuencia=1;}
        if (contadorsecuencia==0) if (eval_horizontal(tablero, c ,e)==1){contadorsecuencia=1;}
        if (contadorsecuencia==0) if (eval_diagonal(tablero, c ,e)==1){contadorsecuencia=1;}
        //comprobar si te puede complicar la vida.
        c='X'; e='O';
        if(eval_vertical(tablero, c, e)==1){contadorsecuencia=1;}
        if (contadorsecuencia==0) if (eval_horizontal(tablero, c, e)==1){contadorsecuencia=1;}
        if (contadorsecuencia==0) if (eval_diagonal(tablero,c, e)==1){contadorsecuencia=1;}
        if (contadorsecuencia==0)  meter_fichaO(tablero); contadorsecuencia=1;


    cont++;}
    printf("Pablo ha metido ficha de manera inteligente");
    }

impr_tablero(tablero);
if (cont==21) printf("\nPablo y usted han empatado intelectos"); //Conclusión
else{
    if (ganador_X_O(tablero)==1) printf("\nHa derrotado a Pablo.I\n\tFELICIDADES!");
    else printf("\nPablo le ha derrotado\n\t No pierda la esperanza, vuelva a intentarlo");

    }

    printf("\t\nEspera algunos segundos y se cerrara automaticamente");
Sleep(6000);

   }
