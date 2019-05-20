#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "estado.h"
#include "auxiliares.h"
#define MAXBUFFER 1024

int jog_valida(ESTADO e, int l, int c,int ml, int mc){
    l += ml;
    c += mc;
    if( l==0 || l==7 || c==0 || c==7 || e.grelha[l+ml][c+mc] == e.peca || e.grelha[l+ml][c+mc] == VAZIA) return 0;
    else{
        l += ml;
        c += mc;
        while(l != 0 && l != 7 &&  c != 0 && c != 7) {
            if (e.grelha[l + ml][c + mc] == VAZIA) return 0;
            else if (e.grelha[l + ml][c + mc] == e.peca) return 1;
            else {
                l += ml;
                c += mc;
            }   
        }
    }
    return 0;
}


ESTADO substitui(ESTADO e, int l, int c, int ml, int mc){
    int lt;
    int ct;
    if (pode_jogar(e, l, c)){
        lt = l + ml;
        ct = c + mc;
        if (e.peca == VALOR_X){
            while (e.grelha[l + ml][c + mc] == VALOR_O){
                e.grelha[l + ml][c + mc] = VALOR_X;
            }
        }else {
            while (e.grelha[l + l][c + mc] == VALOR_X){
                e.grelha[l + ml][c + mc] = VALOR_O;
                if (ml > 0) lt++;
                else if (ml < 0) lt--;
                if (mc > 0) ct++;
                else if (mc < 0) ct--;
            }
        }
    }
    return e;
}


int pode_jogar(ESTADO e , int l , int c){
    if (jog_valida(e,l,c,-1,0)) return 1;
    if (jog_valida(e,l,c,-1,1))  return 1;
    if (jog_valida(e,l,c,-1,-1)) return 1;
    if (jog_valida(e,l,c,0,-1)) return 1;
    if (jog_valida(e,l,c,0,1)) return 1;
    if (jog_valida(e,l,c,1,0)) return 1;
    if (jog_valida(e,l,c,1,1)) return 1;
    if (jog_valida(e,l,c,1,-1)) return 1;
    return 0;
}                                                             


ESTADO pode_substituir (ESTADO e , int l , int c){
    if (jog_valida(e,l,c,-1,0)) e = substitui(e,l,c,-1,0);
    if (jog_valida(e,l,c,-1,1)) e = substitui(e,l,c,-1,1);
    if (jog_valida(e,l,c,-1,-1))e = substitui(e,l,c,-1,-1);
    if (jog_valida(e,l,c,0,-1)) e = substitui(e,l,c,0,1);
    if (jog_valida(e,l,c,0,1)) e = substitui(e,l,c,0,1);
    if (jog_valida(e,l,c,1,0)) e = substitui(e,l,c,1,0);
    if (jog_valida(e,l,c,1,1)) e = substitui(e,l,c,1,1);
    if (jog_valida(e,l,c,1,-1)) e = substitui(e,l,c,1,-1);
    return e;
}


char conta_peca(ESTADO e){
    int x=0;
    int o=0;
    char v;
    for(int i=0;i<8;i++){
        for(int j=0;j <8;j++){
            if( e.grelha[i][j] == VALOR_X) x++;
            else {
                if(e.grelha[i][j]== VALOR_O) o++;
            }
        }
    }
    printf("X: %d  O: %d\n",x ,o);
    if(x>o) v = 'X';
    else v ='O';
    if(x == 0 || o == 0) printf("o jogo acabou, venceu: %c \n", v);
    return v;
}


void jogadas(ESTADO e){
    int pj=0;
    int i, j;
    for (i = 0;i<8;i++) {
        for (j = 0; j < 8; j++) {
            if (pode_jogar(e, i + 1, j + 1)) pj = 1;
        }
    }
    if(pj==0){
        printf("Sem jogadas possiveis");
        if(e.peca == VALOR_O) e.peca = VALOR_X;
        else e.peca = VALOR_O;
    }
}

/*
ESTADO substitui(ESTADO e, int l, int c){
    int lt;
    int ct;
    if(jog_valida_cima(e,l,c)) {
        lt = l-2;
        ct = c-1;
        if (e.peca == VALOR_X){
            while (e.grelha[lt][ct] ==VALOR_O) {
                e.grelha[lt][ct] = VALOR_X;
                lt--;
            }
        }
        else {
            while (e.grelha[lt][ct] ==VALOR_X) {
                e.grelha[lt][ct] = VALOR_O;
                lt--;
            }
        }
    }
    if(jog_valida_baixo(e,l,c)) {
        lt = l;
        ct = c-1;
        if (e.peca == VALOR_X) {
            while (e.grelha[lt][ct] == VALOR_O) {
                e.grelha[lt][ct] = VALOR_X;
                lt++;
            }
        }
        else {
            while (e.grelha[lt][ct] ==VALOR_X) {
                e.grelha[lt][ct] = VALOR_O;
                lt++;
            }
        }
    }
    if(jog_valida_direita(e,l,c)) {
        lt = l-1;
        ct = c;
        if (e.peca == VALOR_X) {
            while (e.grelha[lt][ct] ==VALOR_O) {
                e.grelha[lt][ct] = VALOR_X;
                ct++;
            }
        }
        else {
            while (e.grelha[lt][ct] ==VALOR_X) {
                e.grelha[lt][ct] = VALOR_O;
                ct++;
            }
        }
    }
    if(jog_valida_esquerda(e,l,c)) {
        lt = l-1;
        ct = c-2;
        if (e.peca == VALOR_X) {
            while (e.grelha[lt][ct] ==VALOR_O) {
                e.grelha[lt][ct] = VALOR_X;
                ct--;
            }
        }
        else {
            while (e.grelha[lt][ct] ==VALOR_X) {
                e.grelha[lt][ct] = VALOR_O;
                ct--;
            }
        }
    }
    if(jog_valida_cima_dir(e,l,c)) {
        lt = l-2;
        ct = c;
        if (e.peca == VALOR_X) {
            while (e.grelha[lt][ct] ==VALOR_O) {
                e.grelha[lt][ct] = VALOR_X;
                lt--;
                ct++;
            }
        }
        else {
            while (e.grelha[lt][ct] ==VALOR_X) {
                e.grelha[lt][ct] = VALOR_O;
                lt--;
                ct++;
            }
        }
    }
    if(jog_valida_cima_esq(e,l,c)) {
        lt = l-2;
        ct = c-2;
        if (e.peca == VALOR_X) {
            while (e.grelha[lt][ct] ==VALOR_O) {
                e.grelha[lt][ct] = VALOR_X;
                lt--;
                ct--;
            }
        }
        else {
            while (e.grelha[lt][ct] ==VALOR_X) {
                e.grelha[lt][ct] = VALOR_O;
                lt--;
                ct--;
            }
        }
    }
    if(jog_valida_baixo_dir(e,l,c)) {
        lt = l;
        ct = c;
        if (e.peca == VALOR_X) {
            while (e.grelha[lt][ct] ==VALOR_O) {
                e.grelha[lt][ct] = VALOR_X;
                lt++;
                ct++;
            }
        }
        else {
            while (e.grelha[lt][ct] ==VALOR_X) {
                e.grelha[lt][ct] = VALOR_O;
                lt++;
                ct++;
            }
        }
    }
    if(jog_valida_baixo_esq(e,l,c)) {
        lt = l;
        ct = c-2;
        if (e.peca == VALOR_X) {
            while (e.grelha[lt][ct] ==VALOR_O) {
                e.grelha[lt][ct] = VALOR_X;
                lt++;
                ct--;
            }
        }
        else {
            while (e.grelha[lt][ct] ==VALOR_X) {
                e.grelha[lt][ct] = VALOR_O;
                lt++;
                ct--;
            }
        }
    }
    return e;
}
*/
