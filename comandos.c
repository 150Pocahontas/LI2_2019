//
// Created by patricia on 17-04-2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "estado.h"
#define MAXBUFFER 1024
#include "auxiliares.h"
#include "comandos.h"

ESTADO cmd_novo_jogo(ESTADO e, char jog ){

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            e.grelha[i][j] = VAZIA;
        }
    }

    // estado inicial do tabuleiro. Inicio do jogo!
    e.grelha[3][4] = VALOR_X;
    e.grelha[4][3] = VALOR_X;
    e.grelha[3][3] = VALOR_O;
    e.grelha[4][4] = VALOR_O;

    if(jog == 'X'){
        e.peca = VALOR_X;
    }
    else if(jog == 'O') {
        e.peca = VALOR_O;
    }else e.peca = VAZIA;

    //e.grelha[2][2] = VALOR_X;
    return e;
}

ESTADO cmd_ler_fich(ESTADO e){

    FILE *tabuleiro;
    char modo, p;
    char linha[MAXBUFFER];

    tabuleiro = fopen("CLionProjects/Projeto_LI2/tabuleiro.txt","r");

    if(tabuleiro==NULL){
        printf("Ficheiro não existe\n");
        return e;
    }

    fscanf(tabuleiro,"%c %c", &modo, &p);
    if (modo == 'M') e.modo = 0;
    else e.modo = 1;

    if(p== 'X') e.peca = VALOR_X;
    if(p=='O') e.peca = VALOR_O;
    if(p=='-') e.peca = VAZIA;

    fseek(tabuleiro,1,SEEK_CUR);

    for(int i=0; i<8;i++){
        fgets(linha,MAXBUFFER,tabuleiro);
        printf("%s",linha);
        for(int j=0, c=0; linha[j]!= '\n' && c<8 ;j++){
            if(linha[j]=='X') {
                e.grelha[i][c]=VALOR_X;
                c++;
            }
            else if(linha[j]=='O'){

            e.grelha[i][c]=VALOR_O;
            c++;
            }
            else if(linha[j]=='-') {
                e.grelha[i][c]=VAZIA;
                c++;
            }
            else if(linha[j]=='.') {
                e.grelha[i][c]= VAZIA;
                c++;
            }
        }
    }
    fclose(tabuleiro);
    return e;
}


void cmd_escrever_fich(ESTADO e){

    FILE *tabuleiro;
    char modo, p;

    tabuleiro = fopen("CLionProjects/Projeto_LI2/tabuleiro.txt","r");

    if (e.modo == 0) modo = 'M';
    else modo = 'A';

    if(e.peca == VALOR_X) p = 'X';
    if (e.peca == VALOR_O) p = 'O';
    if(e.peca==VAZIA) p = '-';
    fprintf(tabuleiro,"%c %c", modo,p);
    fprintf(tabuleiro,"\n");
    for(int i=0; i<8;i++){
        for(int j=0; j<8;j++){
            if(e.grelha[i][j]==VALOR_X) fprintf(tabuleiro,"X ");
            else if(e.grelha[i][j]==VALOR_O) fprintf(tabuleiro,"O ");
            else if(e.grelha[i][j]==VAZIA) fprintf(tabuleiro,"- ");
            else if (pode_jogar(e,i,j)) fprintf(tabuleiro,".");
        }
        fprintf(tabuleiro,"\n");
    }
    fclose(tabuleiro);
}


ESTADO cmd_jogar(ESTADO e, char l, char c){
    int li = l - 48;
    int ci = c - 48;

    if(e.peca != VAZIA){
        if (pode_jogar(e,li,ci) && e.grelha[li-1][ci-1]==VAZIA) {
            e.grelha[li - 1][ci - 1] = e.peca;
            e = substitui(e,li,ci);
            if (e.peca == VALOR_X) e.peca = VALOR_O;
            else e.peca = VALOR_X;
            jogadas(e);
        }else printf("Jogada Invaĺida\n\n");
    }else printf("O jogo ainda não começou\n\n");
    return e;
}


void cmd_pos_valida(ESTADO e) {
    int i,j;
    printf("  1 2 3 4 5 6 7 8\n");
    for (i = 0;i<8;i++) {
        printf("%d ",i+1);
        for (j = 0; j < 8; j++) {
            if (e.grelha[i][j] == VALOR_X) printf("X ");
            else if (e.grelha[i][j] == VALOR_O) printf("O ");
            else if (pode_jogar(e, i + 1, j + 1)){
                printf(". ");
            }
            else printf("- ");
        }
        putchar('\n');
    }
}


void cmd_sugestao(ESTADO e) {
    int i, j;
    int ci = 3, cj = 3;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (pode_jogar(e, i + 1, j + 1)) {
                if ((i == 0 && (j == 0 || j == 7)) || (i == 7 && (j == 0 || j == 7))) {
                    ci = i;
                    cj = j;
                } else if ((i == 0 && j != 1 && j != 6) || (i == 7 && j != 1 && j != 6) ||
                           (j == 0 && i != 1 && i != 6) || (j == 7 && i != 1 && i != 6)) {
                    if ((ci == 0 && (cj == 0 || cj == 7)) || (ci == 7 && (cj == 0 || cj == 7)));
                    else {
                        ci = i;
                        cj = j;
                    }
                } else if ((i == 1 && j != 1 && i != 6) || (i == 6 && j != 1 && i != 6) ||
                           (j == 1 && i != 1 && i != 6) || (j == 6 && i != 1 && i != 6)) {
                    if (ci == 0 || ci == 7 || cj == 0 || cj == 7);
                    else {
                        ci = i;
                        cj = j;
                    }
                } else if (i == 2 || j == 2 || i == 5 || j == 5) {
                    if (ci == 0 || ci == 7 || cj == 0 || cj == 7 ||
                        ci == 1 || ci == 6 || cj == 1 || cj == 6);
                    else {
                        ci = i;
                        cj = j;
                    }
                }
            }
        }
    }
    printf("  1 2 3 4 5 6 7 8\n");
    for (i = 0; i < 8; i++) {
        printf("%d ", i + 1);
        for (j = 0; j < 8; j++) {
            if (e.grelha[i][j] == VALOR_X) printf("X ");
            else if (e.grelha[i][j] == VALOR_O) printf("O ");
            else if (pode_jogar(e, i + 1, j + 1) && i == ci && j == cj) printf("? ");
            else printf("- ");
        }
        putchar('\n');
    }
}