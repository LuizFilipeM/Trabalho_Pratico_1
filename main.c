#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"

void main(){
    int num;
    lista *list;
    list = (lista*)malloc(sizeof(lista));

    cria_lista(list);
        printf("eh isso\n");


    scanf("%d", &num);

    list = int_to_big(num);
    
    imprimir(list);
    printf("entao eh isso");

}
