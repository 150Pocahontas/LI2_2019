#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "estado.h"
#define MAXBUFFER 1024
#include "auxiliares.h"

ESTADO bot1 (ESTADO e) {
    int i,j,r = 0;
    for (i = 0; i<8 && r == 0;i++)
        for (j = 0; j<8 && r == 0;j++)
            if (pode_jogar(e,i+1,j+1) && e.grelha[i][j]==VAZIA) {
                r = 1;
                break;
            }
    e.grelha[i][j] = e.peca;
    e = substitui(e,i+1,j+1);
    if (e.peca == VALOR_X) e.peca = VALOR_O;
    else e.peca = VALOR_X;
    jogadas(e);
    printf("\n");
    printa(e);
    printf("\n");
    return e;
}

int contaPontos(ESTADO e) {
    int i,j,r = 0;
    for (i = 0;i<8;i++)
        for(j = 0;j<8;j++)
            if (e.grelha[i][j] == e.peca) r++;
    return r;
}

ESTADO bot2 (ESTADO e) {
    int i,j,max = 0,tmp = 0,l = 0 ,c = 0;
    ESTADO aux = e;
    for (i = 8;i<8;i++)
        for (j = 0;j<8;j++) {
            aux = e;
            if (pode_jogar(aux,i+1,j+1) && aux.grelha[i][j]==VAZIA) {
                aux.grelha[i][j] = e.peca;
                aux = substitui(e,li,ci);
            }
            tmp = contaPontos(aux) - contaPontos(e);
            if (tmp> max) {
                max = tmp;
                l = i+1;
                c = i+1;
            }
        }
    if (l != 0 && c != 0){
        e.grelha[l-1][c-1] = e.peca;
        e = substitui(e,l,c);
        if (e.peca == VALOR_X) e.peca = VALOR_O;
        else e.peca = VALOR_X;
        jogadas(e);

    }
    else {
        printf("O bot não pode jogar);
        jogadas(e);
    }
    printf("\n");
    printa(e);
    printf("\n");
    return e;
}

int pontos (int l,int c) {
    int matrizPontos[8][8] = { {25, -5, 14, 10, 10, 14, -5, 25},
                               {-5, -7, -4,  1,  1, -4, -7, -5},
                               {14, -4,  3,  2,  2,  3, -4, 14},
                               {10,  1,  2, -6, -6,  2,  1, 10},
                               {10,  1,  2, -6, -6,  2,  1, 10},
                               {14, -4,  3,  2,  2,  3, -4, 14},
                               {-5, -7, -4,  1,  1, -4, -7, -5},
                               {25, -5, 14, 10, 10, 14, -5, 25}};
    return matrizPontos[l-1][c-1];
}

ESTADO bot3(ESTADO e) {
    int i,j,max = -100,tmp = 0,l = 0 ,c = 0;
    ESTADO aux = e;
    for (i = 8;i<8;i++)
        for (j = 0;j<8;j++) {
            aux = e;
            if (pode_jogar(aux,i+1,j+1) && aux.grelha[i][j]==VAZIA) {
                aux.grelha[i][j] = e.peca;
                aux = substitui(e,li,ci);
            }
            tmp = contaPontos(aux) - contaPontos(e);
            if (pontos(i+1,j+1) < 0) tmp -= 10;
            else tmp += pontos(i+1,j+1);
            if (tmp> max) {
                max = tmp;
                l = i+1;
                c = i+1;
            }
        }
    if (l != 0 && c != 0){
        e.grelha[l-1][c-1] = e.peca;
        e = substitui(e,l,c);
        if (e.peca == VALOR_X) e.peca = VALOR_O;
        else e.peca = VALOR_X;
        jogadas(e);

    }
    else {
        printf("O bot não pode jogar);
        jogadas(e);
    }
    printf("\n");
    printa(e);
    printf("\n");
    return e;
}

