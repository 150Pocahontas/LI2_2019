//
// Created by patricia on 10-04-2019.
//

#ifndef TESTES_STACK_H
#define TESTES_STACK_H
#include "estado.h"
//Declarar o nodo da lista-ligada
struct Node {
    struct estado;
    struct Node* next;
};

struct Node* top;

void push(ESTADO e);
int isEmpty();
int peek();
void pop();
void display();
#endif //TESTES_STACK_H
