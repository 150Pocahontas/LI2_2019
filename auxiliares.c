#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "estado.h"
#define MAXBUFFER 1024
#include "auxiliares.h"

//posso jogar a baixo? verifica para cima
int jog_valida_cima(ESTADO e, int l, int c){
    l -= 1;
    if( l==0 || e.grelha[l-1][c-1] == e.peca || e.grelha[l-1][c-1]==VAZIA) return 0;
    else{
        l -=1;
        while(l != 0){
            if(e.grelha[l-1][c-1]==VAZIA) return 0;
            else if(e.grelha[l-1][c-1]==e.peca) return 1;
            else l--;
        }
    }
    return  0;
}
int jog_valida_baixo(ESTADO e, int l, int c){
    l += 1;
    if(l==7 || e.grelha[l-1][c-1] == e.peca || e.grelha[l-1][c-1]==VAZIA) return 0;
    else{
        l +=1;
        while(l <= 8){
            if(e.grelha[l-1][c-1] == VAZIA) return 0;
            else if(e.grelha[l-1][c-1] == e.peca) return 1;
            else l++;
        }
    }
    return  0;
}
int jog_valida_direita(ESTADO e, int l, int c){
    c += 1;
    if(c==7 ||  e.grelha[l-1][c-1] == e.peca|| e.grelha[l-1][c-1] ==VAZIA) return 0;
    else{
        c += 1;
        while(c <= 8){
            if(e.grelha[l-1][c-1]==VAZIA) return 0;
            else if(e.grelha[l-1][c-1]==e.peca) return 1;
            else c++;
        }
    }
    return 0;
}
int jog_valida_esquerda(ESTADO e, int l, int c){
    c -= 1;
    if(c==0 || e.grelha[l-1][c-1] == e.peca || e.grelha[l-1][c-1]==VAZIA) return 0;
    else{
        c -= 1;
        while(c!= 0){
            if(e.grelha[l-1][c-1]==VAZIA) return 0;
            else if(e.grelha[l-1][c-1]==e.peca) return 1;
            else c--;
        }
    }
    return 0;
}
int jog_valida_cima_dir(ESTADO e, int l, int c){
    l -= 1;
    c += 1;
    if(l == 0 || c == 7|| e.grelha[l-1][c-1] == e.peca || e.grelha[l-1][c-1]==VAZIA) return 0;
    else{
        l -= 1; c += 1;
        while(l != 0 || c <= 8 ){
            if(e.grelha[l-1][c-1]==VAZIA) return 0;
            else if(e.grelha[l-1][c-1]==e.peca) return 1;
            else {
                l--;
                c++;
            }
        }
    }
    return 0;
}
int jog_valida_cima_esq(ESTADO e, int l, int c){
    l -= 1;
    c -= 1;
    if(l==0 || c == 0|| e.grelha[l-1][c-1] == e.peca || e.grelha[l-1][c-1]==VAZIA) return 0;
    else {
        l -= 1;
        c -= 1;
        while (l != 0 || c != 0) {
            if (e.grelha[l - 1][c - 1] == VAZIA) return 0;
            else if (e.grelha[l - 1][c - 1] == e.peca) return 1;
            else {
                l--;
                c--;
            }
        }
    }
    return 0;
}
int jog_valida_baixo_dir(ESTADO e, int l, int c){
    l += 1;
    c += 1;
    if(l== 7 || c == 7|| e.grelha[l-1][c-1] == e.peca || e.grelha[l-1][c-1]==VAZIA) return 0;
    else{
        l += 1;
        c += 1;
        while (l <= 8 || c <= 8) {
            if (e.grelha[l - 1][c - 1] == VAZIA) return 0;
            else if (e.grelha[l - 1][c - 1] == e.peca) return 1;
            else {
                l++;
                c++;
            }
        }
    }
    return 0;
}
int jog_valida_baixo_esq(ESTADO e, int l, int c){
    l += 1;
    c -= 1;
    if(l == 7 || c == 0 || e.grelha[l-1][c-1] == e.peca || e.grelha[l-1][c-1]==VAZIA) return 0;
    else{
        l +=1;
        c -= 1;
        while(l <= 8 || c != 0 ) {
            if (e.grelha[l - 1][c - 1] == VAZIA) return 0;
            else if (e.grelha[l - 1][c - 1] == e.peca) return 1;
            else {
                l++;
                c--;
            }
        }
    }
    return 0;
}
int pode_jogar(ESTADO e , int l, int c){
    if (jog_valida_cima(e,l,c)) return 1;
    if (jog_valida_baixo(e,l,c)) return 1;
    if (jog_valida_direita(e,l,c)) return 1;
    if (jog_valida_esquerda(e,l,c)) return 1;
    if (jog_valida_cima_dir(e,l,c)) return 1;
    if (jog_valida_cima_esq(e,l,c)) return 1;
    if (jog_valida_baixo_dir(e,l,c)) return 1;
    if (jog_valida_baixo_esq(e,l,c)) return 1;
    return 0;
}
ESTADO substitui(ESTADO e, int l, int c){
    int lt;
    int ct;
    if(jog_valida_cima(e,l,c)) {
        lt = l-2;
        ct = c-1;
        if (e.peca == VALOR_X) {
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
