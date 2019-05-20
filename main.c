#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "estado.h"
#include "auxiliares.h"
#include "comandos.h"
#include "stack.h"
//#include "bot.h"
#define MAXBUFFER 1024

ESTADO interpretar(ESTADO e, char *linha,STACK *s){

    int n,nivel;
    char ficheiro[MAXBUFFER];
    char cmd[MAXBUFFER];
    char peca[MAXBUFFER];
    char l,c, modo,p;
    n = sscanf(linha,"%s",cmd);
    switch(toupper(cmd[0])){
        case 'N':
            sscanf(linha,"%s %s",cmd,peca);
            modo = 'M';
            if (e.peca == VALOR_X) p= 'O';
            else p = 'X';
            printf("%c %c", modo,p);
            e = cmd_novo_jogo(e,toupper(peca[0]),s);
            printf("\n");
            printa(e);
            printf("\n");
            break;
        case 'L':
            sscanf(linha,"%s %s",cmd,ficheiro);
            e = cmd_ler_fich(e,ficheiro,s);
            iniciastack(s);
            push(e,s);
            printf("\n");
            printa(e);
            printf("\n");
            break;
        case 'E':
            sscanf(linha,"%s %s",cmd,ficheiro);
            cmd_escrever_fich(e,ficheiro);
            break;
        case 'J':
            sscanf(linha,"%c %c %c",cmd,&l,&c);
            /*printf("%d\n",jog_valida_cima(e,3,3));
            printf("%d\n",jog_valida_baixo(e,3,3));
            printf("%d\n",jog_valida_direita(e,3,3));
            printf("%d\n",jog_valida_esquerda(e,3,3));
            printf("%d\n",jog_valida_cima_dir(e,3,3));
            printf("%d\n",jog_valida_cima_esq(e,3,3));
            printf("%d\n",jog_valida_baixo_dir(e,3,3));
            printf("%d\n",jog_valida_baixo_esq(e,,3));
            printf("%d\n",pode_jogar(e,4,3));*/
            e = cmd_jogar(e,l,c,s);
            conta_peca(e);
            if (e.peca == VALOR_X) p = 'X';
            else p = 'O';
            printf("%c %c", modo,p);
            printf("\n");
            printa(e);
            printf("\n");
            break;
        case 'S': //jodadas validas "."
            cmd_pos_valida(e);
            printf("\n\n");
            break;
        case 'H': //sugestão "?"
            cmd_sugestao(e);
            printf("\n\n");
            break;
        case 'U': //desfazer jogada
            if (vazia(s) == 0) e = pop(e,s);
            else printf("Não é possivel desfazer jogada\n");
            break;
        case 'A':
            sscanf(linha,"%s %s %d",cmd,peca,&nivel); //se peça=X joga primeiro
            modo = 'A';
            if (e.peca == VALOR_X) p = 'O';
            else p = 'X';
            printf("%c %c", modo,p);
            e=cmd_novo_jogo(e,toupper(peca[0]),s);
            printf("\n");
            printa(e);
            printf("\n");
            break;
        case 'Q':
            exit(0);
        default:
            printf("Comando inválido\n");
    }
    return e;
}


void interpretador(ESTADO e,STACK *s){
    char linha[MAXBUFFER];
    printf("Reversi > ");
    while(fgets(linha,MAXBUFFER,stdin)){
        e = interpretar(e,linha,&s);
        printf("Reversi > ");
    }
}


int main() {
    ESTADO e = {0};
    STACK *s;
    printf("Para começar a jogar em modo manual executar o comando: N <Peça> (X ou O) \n");
    printf("Para começar a jogar em modo automatico executar o comando: A <Peça> <nivel> (1,2 ou 3) \n");
    interpretador(e,s);
    return 0;
}


