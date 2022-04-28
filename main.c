#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"

void main(){
    int x, y;
    lista *list1, *list2, *resultado; 
    list1 = cria_lista(list1);
    list2 = cria_lista(list2);
    resultado = cria_lista(resultado);
    scanf("%d", &x);
    scanf("%d", &y);
    int_to_big(x, list1);
    int_to_big(y, list2);
    resultado = somar(list1, list2);
    imprimir(resultado);
}
