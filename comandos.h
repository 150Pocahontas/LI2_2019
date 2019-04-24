//
// Created by patricia on 17-04-2019.
//

#ifndef PROJ_COMANDOS_H
#define PROJ_COMANDOS_H

#endif //PROJ_COMANDOS_H
ESTADO cmd_novo_jogo(ESTADO e, char jog );
ESTADO cmd_ler_fich(ESTADO e, char buffer[]);
void cmd_escrever_fich(ESTADO e,char buffer[]);
ESTADO cmd_jogar(ESTADO e, char l, char c);
void cmd_pos_valida(ESTADO e);
void cmd_sugestao(ESTADO e);
