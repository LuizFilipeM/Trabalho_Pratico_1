#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"

struct celula{
    int valor;
    celula *prox;
    celula *ant;
};

struct lista{
    celula *primeiro;
    celula *ultimo;
};


lista* cria_lista(lista *ls){
    ls = (lista*)malloc(sizeof(lista));
    ls->primeiro = (celula*) malloc(sizeof(celula));
    ls->primeiro->prox = NULL;
    ls->primeiro->ant = NULL;
    ls->ultimo = ls->primeiro;
    
    return ls;
}

int vazia(lista* ls){
    return (ls->primeiro == ls->ultimo);
}

void insere(lista *ls, int x){
    ls->primeiro->valor = x;
    ls->primeiro->ant = (celula*)malloc(sizeof(celula));
    ls->primeiro->ant->prox = ls->primeiro;
    ls->primeiro = ls->primeiro->ant;
    ls->primeiro->ant = NULL;
}

lista* int_to_big(int x, lista* list){
    
    int temp;
    while(x != 0){
        temp = x % 10;
        if(temp!=0){
            insere(list, temp);
        }else {
            insere(list, 0);
            }
        
        x = (x - temp)/10;
    }
return list;
}

lista* somar(lista *x1, lista *x2){
    lista *list;
    list = cria_lista(list);
    int vai_um = 0, temp1;

    while(x1->ultimo->ant != NULL || x2->ultimo->ant != NULL || vai_um != 0)
    {
        
        
        if(vai_um == 0){
            if(x1->ultimo->ant != NULL && x2->ultimo->ant != NULL)
            {
                temp1 = x1->ultimo->valor + x2->ultimo->valor;
                
                if (temp1 > 9)
                {
                    
                    int temp2; 
                    temp2 = temp1 % 10;
                    insere(list, temp2);
                    vai_um = 1;
                } 
                else 
                {
                    
                    insere(list, temp1);
                    vai_um = 0;
                }
            }

            if(x1->ultimo->ant != NULL && x2->ultimo->ant == NULL) //o "if" é removivvel já que nunca entrará nele
            {
                temp1 = x1->ultimo->valor;
                
                if (temp1 > 9)
                {
                    int temp2;
                     
                    temp2 = temp1 % 10;
                    insere(list, temp2);
                    vai_um = 1;
                } 
                else 
                {
                    
                    insere(list, temp1);
                    vai_um = 0;
                }
            }

            if(x1->ultimo->ant == NULL && x2->ultimo->ant != NULL)
            {   temp1 = x2->ultimo->valor;
                if (temp1 > 9)
                {
                    
                    int temp2; 
                    temp2 = temp1 % 10;
                    insere(list, temp2);
                    vai_um = 1;
                } else {
                    
                    insere(list, temp1);
                    vai_um = 0;
                }
            }
        
        }// fim do "if" do vai_um == 0
        


        if(vai_um == 1)
        {
            if(x1->ultimo->ant != NULL && x2->ultimo->ant != NULL)
            {
                temp1 = x1->ultimo->valor + x2->ultimo->valor + 1;
                if (temp1 > 9)
                {
                    int temp2; 
                    temp2 = temp1 % 10;
                    insere(list, temp2);
                    vai_um = 1;
                }
                
                else 
                {
                    insere(list, temp1);
                    vai_um = 0;
                }
            }
        
            if(x1->ultimo->ant != NULL && x2->ultimo->ant == NULL)
            {  
                temp1 = x1->ultimo->valor + 1;
                if (temp1 > 9)
                {
                    int temp2; 
                    temp2 = temp1 % 10;
                    insere(list, temp2);
                    vai_um = 1;
                }
                
                else {
                    insere(list, temp1);
                    vai_um = 0;
                }

            if(x1->ultimo->ant == NULL && x2->ultimo->ant != NULL)
                temp1 = x1->ultimo->valor + 1;
                if (temp1 > 9)
                {
                    int temp2; 
                    temp2 = temp1 % 10;
                    insere(list, temp2);
                    vai_um = 1;
                }
                
                else {
                    insere(list, temp1);
                    vai_um = 0;
                }
            }
        
        }//fim do "if" vai_um == 1

        if(x1->ultimo->ant == NULL && x2->ultimo->ant != NULL) x2->ultimo = x2->ultimo->ant;
        if(x1->ultimo->ant != NULL && x2->ultimo->ant == NULL) x1->ultimo = x1->ultimo->ant;
        if(x1->ultimo->ant != NULL && x2->ultimo->ant != NULL) 
        {
            x2->ultimo = x2->ultimo->ant;
            x1->ultimo = x1->ultimo->ant;
        }
        }// fim do while
    return list;
}


lista *subtrair(lista *x1, lista *x2){
    

}

int* cria(){
    int *num;
    num = (int*)malloc(sizeof(int));
    return num;
}

void imprimir(lista *B){
    celula *aux;
    aux = B->primeiro->prox;
    while(aux != NULL){
        printf("%d", aux->valor);
        aux = aux->prox; 
    }
    printf("\n");
}
