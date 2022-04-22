#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"

void main(){
    int num;
    lista *list; 
    cria_lista(list);
    scanf("%d", &num);
    list = int_to_big(num,list);
    imprimir(list);
}
