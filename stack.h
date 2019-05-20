#ifndef TESTES_STACK_H
#define TESTES_STACK_H
#include "estado.h"
#define MAXBUFFER 1024

typedef struct stack
{
    ESTADO e;
    struct stack *anterior;
}*STACK;

void iniciastack(STACK *stack);
int vazia(STACK *stack);
void push(ESTADO e, STACK *stack);
ESTADO pop(ESTADO e, STACK *stack);

#endif //TESTES_STACK_H
