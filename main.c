#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"


void main(){
    int num;
    lista *list; 
    printf("aqui");
    cria_lista(list);
    

    scanf("%d", &num);
    list = int_to_big(num,list);

    printf("entao eh isso");
    
    imprimir(list);
    

}
