#ifndef HEADER_CONNECT4_H_INCLUDED
#define HEADER_CONNECT4_H_INCLUDED

    void inicio_array(char tablero[6][7]);
    void impr_tablero(char tablero[6][7]);

    void meter_ficha(char tablero[6][7]);

    int eval_vertical(char tablero[6][7], char c, char e);
    int eval_horizontal(char tablero[6][7], char c, char e);
    int eval_diagonal(char tablero [6][7], char c, char e);
    int ganador_X_O(char tablero[6][7]);
    int meter_fichaO(char tablero[6][7]);

#endif // HEADER_CONNECT4_H_INCLUDED
