#ifndef PROJ_COMANDOS_H
#define PROJ_COMANDOS_H
#include "stack.h"

#endif //PROJ_COMANDOS_H
ESTADO cmd_novo_jogo(ESTADO e, char jog, STACK *s );
ESTADO cmd_ler_fich(ESTADO e,char tabuleiro[],STACK *s);
void cmd_escrever_fich(ESTADO e,char tabuleiro[]);
ESTADO cmd_jogar(ESTADO e, char l, char c,STACK *s);
void cmd_pos_valida(ESTADO e);
void cmd_sugestao(ESTADO e);
