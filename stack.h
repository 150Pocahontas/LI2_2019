//
// Created by patricia on 10-04-2019.
//

#ifndef TESTES_STACK_H
#define TESTES_STACK_H
#include "estado.h"
#define MAXBUFFER 1024

typedef struct stack
{
    ESTADO e;
    struct stack *anterior;
}*STACK;

void iniciastack(ESTADO e, STACK *stack);
int cheia(STACK *stack);
void push(ESTADO e, STACK *stack);
void pop(ESTADO e, STACK *stack);

#endif //TESTES_STACK_H
