#include <stdio.h>
#include <stdlib.h>
/*
Lista encadeada: é uma representação de uma sequencia de objetos na memoria do computador

cada elemento da sequencia é armazenado em uma "celula" da lista


cada celula contem um objeto de determinado tipo e o endereco da celula seguinte(se fo a ultima é NULL)
*/

struct celula_dupla {
    int conteudo;
    struct celula_dupla *seg; 
    struct celula_dupla *ant;

    //podem existir outros dados
};

// seg deve ser um ponteiro

void insere_dupla(int valor, struct celula_dupla *cabeca);

void imprimir(struct celula *cabeca);


int main() {

    struct celula_dupla *minha_lista;

    minha_lista = (struct celula_dupla *) malloc(sizeof(struct celula_dupla ));

    minha_lista->seg = NULL;
  

    return 0;
}

void insere_dupla(int valor, struct celula_dupla *cabeca){
    struct celula_dupla *nova_celula;
    nova_celula = (struct celula_dupla *) malloc(sizeof(struct celula_dupla));

    nova_celula->seg = cabeca->seg;
    nova_celula->ant = cabeca;
    cabeca->seg = nova_celula;

    if(nova_celula->seg != NULL){
       nova_celula->ant = nova_celula->conteudo;
    }
}

void imprimir(struct celula *cabeca){
    struct celula *p;

    p = cabeca->seg;
    printf("Lista: [");
    while( p != NULL){
        
        printf(" %d ", p->conteudo);
        
        p = p->seg;
    }
        printf("]\n");
}


void remover(int valor_remov,struct celula *cabeca){
    struct celula *anterior = cabeca;
    struct celula *atual = cabeca->seg;

    while ( atual != NULL  && atual->conteudo != valor_remov ){
       
            anterior = atual;

            atual = atual->seg;
        

    }
    if(atual == NULL){
        return ;
    }

    anterior->seg = atual->seg;
    free(atual);
}