#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"

typedef struct BigNum{
    int valor;
    BigNum* prox;
} BigNum;


typedef struct lista{
    BigNum *primeiro, *ultimo;
} lista;


void cria_lista(lista *ls){
    ls->primeiro = (BigNum*) malloc(sizeof(BigNum));
    printf("aqui\n");

    ls->ultimo = ls->primeiro;
    ls->primeiro->prox = NULL;
   
}

int vazia(lista* ls){
    return (ls->primeiro == ls->ultimo);
}

void insere(lista *ls, int x){
    ls->ultimo->prox = (BigNum*)malloc(sizeof(BigNum));
    ls->ultimo = ls->ultimo->prox;
    ls->ultimo->valor = x;
    ls->ultimo->prox = NULL;
}

lista* int_to_big(int x){
    lista *list;// = (lista*)malloc(sizeof(lista));
    cria_lista(list);
    int temp;
    while(x != 0){
        temp = x % 10;
        insere(list, temp);
        x = (x - temp)/10;
    }
    return list;
}

lista* somar(lista *x1, lista *x2){
    lista *list;// = (lista*)malloc(sizeof(lista));
    cria_lista(list);
    while(x1->ultimo->prox->valor != 0 || x2->ultimo->prox->valor != 0){
        int temp1;
        temp1 = x1->primeiro->valor + x2->primeiro->valor;
        if (temp1 > 9){
            int temp2; 
            temp2 = temp1 % 9;
            insere(list, temp2);
            temp2 = (temp1 - temp2);
            insere(list,temp2);
        }
        else insere(list, temp1);
        
    }
}

lista *subtrair(lista *x1, lista *x2){
    int temp;
    temp = x1->primeiro->valor - x2->primeiro->valor;

}








int* cria(){
    int *num;
    num = (int*)malloc(sizeof(int));
    return num;
}

void imprimir(lista *B){
    while(B->ultimo->prox->valor != 0){
        printf("%d ", B->primeiro->valor);
        B->primeiro = B->primeiro->prox;
        printf("entrou");
    }
}
