#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int dado;
    struct cel *prox;
} celula;

typedef struct{
    cel *fim;
    cel *inicio;

}fila;

void enfileira(int dado,fila *f){
    celula *nova;
    nova = (celula*) malloc(sizeof(celula));
    if(nova == NULL){
        printf("Erro ao alocar a memoria\n");
        return ;
    }
    nova->dado = dado;
    nova->prox = NULL;

    if(f->inicio == NULL){
        f->inicio = nova;

    }
    else{
        f->fim->prox = nova;
    }



    f->fim = nova;

}