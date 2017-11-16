#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include "header_Connect4.h"
#include <time.h>
#include <windows.h>

void inicio_array(char tablero[6][7]) //formateo tablero
{
    int i,j;
    for(i=0;i<6;i++)
        {
            for(j=0;j<7;j++)
            {
                tablero[i][j]=' ';
            }
        }
}

void impr_tablero(char tablero[6][7]) //impresión tablero
{
    int i, j;

    printf("\n\n ---  ---  ---  ---  ---  ---  --- \n");
    for(i=0;i<6;i++)
    {
        for(j=0;j<7;j++)
        {
            printf("| %c |", tablero[i][j]);
        }
        printf("\n");
        printf(" ---  ---  ---  ---  ---  ---  --- ");
        printf("\n");
    }
    printf("  0    1    2    3    4    5    6  ");
}

void meter_ficha(char tablero[6][7]) //meter ficha humano
{
    int i, j;
while /*poner un limite de columna*/(j>6 || j<0 || i<0){
    printf("\nTu turno\n\tMete ficha: ");
    fflush(stdin); //para que al meter una secuencia de números no ejecute todos
    scanf("%d",&j);
    i=5;

    while (tablero[i][j]!=' ')
    {
        i--;
    }
}
tablero[i][j]='X';
}

int eval_vertical(char tablero[6][7], char c, char e) //movimiento máquna de defensa y ataque vertical
{
  int i,j,cont;

for (i=0;i<7;i++){
cont=0;
for(j=5;j>=0;j--)
{
if (tablero[j][i]==c)
cont++;
else {if (tablero[j][i]==e)
cont=0;}
if (cont==3) if (tablero[j+1][i]==' ') { tablero[j+1][i]='O';  return 1; printf("%d", j+1);}
}
}return 0;}

int eval_horizontal(char tablero[6][7], char c, char e)//movimiento máquina de defensa y ataque en horizontal
{
    int i, j, q;
    int cont[7];

    for (i=5;i>=0;i--)// evalua desde abajo hacia arriba.
    {
        for(j=0;j<7;j++){//evalua desde la izquierda a la derecha
                {if (tablero[i][j]==c) cont[j]=1;
                    else if(tablero[i][j]==e) cont[j]=0; else cont[j]=2;}}



        for(j=0;j<4;j++)//evaluamos grupos de 4 términos
        {if(cont[j]*cont[j+1]*cont[j+2]*cont[j+3]==2) //si esta condición se da intentamos localizar el hueco.
            for(q=j;q<j+4;q++) //Ponemos en el hueco una O
                { if (cont[q]==2) if(i==5){tablero[i][q]='O'; return 1;} else if(tablero[i+1][q]!=' ') { tablero[i][q]='O'; return 1; }}
                }


    }


return 0;
}

int eval_diagonal(char tablero [6][7], char c, char e)// movimiento máquina de defensa y ataque en diagonal
{
int i, j, h, cont[4];

for(i=5;i>2;i--) //ciclo para ir subiendo de arriba a abajo
{
    for(j=0;j<4;j++)//ciclo para ir de la derecha a la izquierda
    {
        for(h=0;h<4;h++)//incrementador para evaluación del contador. de izquierda a derecha.
        {
            if (tablero[i-h][j+h]==e) cont[h]=0; else if (tablero[i-h][j+h]==c) cont[h]=1; else
if (tablero[i-h][j+h]==' ')  cont[h]=2;
        }

    if(cont[0]*cont[1]*cont[2]*cont[3]==2)// esto significa peligro 3 con X y una vacía.
        {if (cont[0]==2)/* para el caso 0*/{if (i==5){ tablero [i][j]='O'; return 1;} else if(tablero[i+1][j]!=' ') {tablero[i][j]='O'; return 1;}}
        if (cont[1]==2)/* para el caso 1*/if (tablero[i][j+1]!=' ') {tablero[i-1][j+1]='O'; return 1;}
        if (cont[2]==2)/* para el caso 2*/if (tablero[i-1][j+2]!=' ') {tablero[i-2][j+2]='O';   return 1;}
        if (cont[3]==2)/* para el caso 2*/if (tablero[i-2][j+3]!=' ') {tablero[i-3][j+3]='O';   return 1;}
        }

         for(h=0;h<4;h++)//incrementador para evaluación del contador. de derecga a izquierda.
        {
            if (tablero[i-h][6-j-h]==e) cont[h]=0; else if (tablero[i-h][6-j-h]==c) cont[h]=1; else if (tablero[i-h][6-j-h]==' ')  cont[h]=2;
        }

    if(cont[0]*cont[1]*cont[2]*cont[3]==2)// esto significa peligro 3 con X y una vacía.
        {if (cont[0]==2)/* para el caso 0*/{if (i==5){ tablero [i][6-j]='O'; return 1;} else if(tablero[i+1][6-j]!=' ') {tablero[i][6-j]='O';  return 1;}}
        if (cont[1]==2)/* para el caso 1*/if (tablero[i][5-j]!=' ') {tablero[i-1][5-j]='O';  return 1;}
        if (cont[2]==2)/* para el caso 2*/if (tablero[i-1][4-j]!=' ') {tablero[i-2][4-j]='O'; return 1;}
        if (cont[3]==2)/* para el caso 2*/if (tablero[i-2][3-j]!=' ') {tablero[i-3][3-j]='O'; return 1;}

        }
    }
}return 0;
}



int ganador_X_O(char tablero[6][7]) //comprobar ganador
{
   int i, j, contX, contO;
for(i=0;i<7;i++){//Vertical
        contX=0; contO=0;
    for(j=0;j<6;j++){
        if (tablero[j][i]=='X'){ contX++; contO=0;}
        else if (tablero[j][i]=='O'){contO++; contX=0;}
        else {contX=0; contO=0;}
      if (contO==4) return 2;
      if (contX==4) return 1;
    }

}
for(i=0;i<6;i++){ //horizontal
        contX=0; contO=0;
    for(j=0;j<7;j++){
        if (tablero[i][j]=='X'){ contX++; contO=0;}
        else if (tablero[i][j]=='O'){contO++; contX=0;}
        else {contX=0; contO=0;}
      if (contO==4) return 2;
      if (contX==4) return 1;
    }

}

        for(i=0;i<6;i++) //diagonal
    {
        for(j=0;j<7;j++)
        {
            if (tablero [i][j]=='X'){
if (tablero [i+1][j+1]=='X' && tablero [i+2][j+2]=='X' && tablero [i+3][j+3]=='X' && j+3<7 && i+3<6 )return 1;
if (tablero [i-1][j+1]=='X' && tablero [i-2][j+2]=='X' && tablero [i-3][j+3]=='X' && j+3<7 && i-3>=0)return 1;
if (tablero [i+1][j-1]=='X' && tablero [i+2][j-2]=='X' && tablero [i+3][j-3]=='X' && j-3>=0 && i+3<6 )return 1;
if (tablero [i-1][j-1]=='X' && tablero [i-2][j-2]=='X' && tablero [i-3][j-3]=='X' && j-3>=0 && i-3>=0 )return 1;}


            if (tablero [i][j]=='O'){
if (tablero [i+1][j+1]=='O' && tablero [i+2][j+2]=='O' && tablero [i+3][j+3]=='O' && j+3<7 && i+3<6 )return 2;
if (tablero [i-1][j+1]=='O' && tablero [i-2][j+2]=='O' && tablero [i-3][j+3]=='O' && j+3<7 && i-3>=0)return 2;
if (tablero [i+1][j-1]=='O' && tablero [i+2][j-2]=='O' && tablero [i+3][j-3]=='O' && j-3>=0 && i+3<6 )return 1;
if (tablero [i-1][j-1]=='O' && tablero [i-2][j-2]=='O' && tablero [i-3][j-3]=='O' && j-3>=0 && i-3>=0 )return 1;}
        }
}
    return 0;
}

int meter_fichaO(char tablero[6][7]) //movimiento aleatorio
{
    int i=5, col;
for(;;){
    col=rand()%7;
    i=5;
    while (i>=0)
    {
        if (tablero[i][col]==' '){tablero[i][col]='O';
        return 1;}
        else i--;}}}

