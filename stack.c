#include "stack.h"
#include <stdlib.h>
#include <stdio.h>


void iniciastack(STACK *stack){
    *stack = NULL;
}


int vazia(STACK *stack){
    return (*stack == NULL || (*stack) -> anterior == NULL);
}


void push(ESTADO e, STACK *stack){
    STACK novastack = (STACK) malloc(sizeof(struct stack));
    novastack -> e = e;
    novastack -> anterior = *stack;
    *stack = novastack;
}


ESTADO pop(ESTADO e, STACK *stack){
    STACK aux = *stack;
    aux = aux -> anterior;
    e = aux -> e;
    *stack = aux;
    printf("\n");
    printa(e);
    printf("\n");
    return e;
}