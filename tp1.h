typedef struct celula celula;
typedef struct lista lista;
lista *int_to_big (int, lista*);

 
void cria_lista(lista *);
int vazia(lista*);
void insere(lista*, int);


void criar();
void destruir();
lista *somar(lista*, lista*);
lista *subtrair(lista*, lista*);
lista *multiplicar(lista*, lista*);
lista *dividir(lista*, lista*);
void imprimir(lista*);
