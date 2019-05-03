//
// Created by patricia on 10-04-2019.
//

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>


void iniciastack(ESTADO e, STACK *stack){
    *stack = NULL;
}
int cheia(STACK *stack){
    return (*stack == NULL || (*stack) -> anterior == NULL);
}

void push(ESTADO e, STACK *stack){
    STACK novastack = (STACK) malloc(sizeof(struct node));
    novastack -> e = e;
    novastack -> anterior = *stack;
    *stack = novastack;
}

void pop(ESTADO e, STACK *stack){
    STACK aux = *stack;
    aux = aux -> anterior;
    e = aux -> e;
    *stack = aux;
    printf("\n");
    printa(e);
    printf("\n");
    return e;
}