#ifndef PROJ_AUXILIARES_H
#define PROJ_AUXILIARES_H

int jog_valida(ESTADO e,int l, int c, int ml, int mc);
/*int jog_valida_cima(ESTADO e, int l, int c);
int jog_valida_baixo(ESTADO e, int l, int c);
int jog_valida_esquerda(ESTADO e, int l, int c);
int jog_valida_direita(ESTADO e, int l, int c);
int jog_valida_cima_dir(ESTADO e, int l, int c);
int jog_valida_cima_esq(ESTADO e, int l, int c);
int jog_valida_baixo_dir(ESTADO e, int l, int c);
int jog_valida_baixo_esq(ESTADO e, int l, int c);
 */
int pode_jogar(ESTADO e , int l, int c);
ESTADO substitui(ESTADO e, int l, int c,int ml, int mc);
ESTADO pode_substituir (ESTADO e , int l , int c);
void jogadas(ESTADO e);
char conta_peca(ESTADO e);

#endif //PROJ_AUXILIARES_H
