//
// Created by patricia on 10-04-2019.
//

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

//Inserir elementos no inicio

/*void push(ESTADO e){
    //criar um novo nodo temp e alocar memoria
    struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));

    //verificar se a stack esta cheia “out-of-memory”
    if (!temp) {
        printf("\nStack sobrelotada");
    }
    //introduzir os dados no respetivo campo em temp
    temp-> estado = e;
    //direcionar o apontador top para temp
    temp-> next = top;
    //tornar temp o topo da stack
    top = temp;
}
//Verificar se a stack esta vazia
int isEmpty(){
    return top == NULL;
}
//Indicar o elemento do topo da stack
int peek(){
    //verificar se esta vazia
    if (!isEmpty(top))
        return top-> e;
    else return NULL;
}

//Remover o elemento no topo da stack
void pop(){
    struct Node* temp;
    //verificar se esta vazia
    if (top == NULL) {
        printf("\nStack vazia");
    } else {
        //top fica com o valor de temp
        temp = top;
        //o nodo seguinte passa a ser o topo
        top = top->next;
        //libertar memoria do nodo de topo
        free(temp);
    }
}
//Mostrar o conteudo da stack
void display(){
    struct Node* temp;
    //verifica se esta vazia
    if (top == NULL) {
        printf("\nStack vazia");
    } else {
        temp = top;
        while (temp != NULL) {
            //imprime o valor do nodo
            printa(temp-> e);
            //direciona o apontador para temp
            temp = temp-> next;
        }
    }
}
void do_undo(ESTADO e){

    e = peek();
    pop();
    return e;
}*/