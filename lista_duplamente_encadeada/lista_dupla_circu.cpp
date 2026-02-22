#include <stdio.h>
#include <stdlib.h>

struct celula_dupla {
    int conteudo;
    struct celula_dupla *seg; 
    struct celula_dupla *ant; 
};


void insere_inicio(int valor, struct celula_dupla *cabeca);
void imprimir_lista(struct celula_dupla *cabeca);
void remover_lista(int valor_remov, struct celula_dupla *cabeca);


int main() {
    struct celula_dupla *minha_lista;

    minha_lista = (struct celula_dupla *) malloc(sizeof(struct celula_dupla));
    if (minha_lista == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return 1;
    }

    minha_lista->seg = minha_lista;
    minha_lista->ant = minha_lista;

    printf("Lista vazia criada.\n");
    imprimir_lista(minha_lista); 

    insere_inicio(10, minha_lista); 
    insere_inicio(20, minha_lista); 
    insere_inicio(30, minha_lista); 
    
    imprimir_lista(minha_lista); 

    printf("\nRemovendo 20...\n");
    remover_lista(20, minha_lista);
    imprimir_lista(minha_lista); 

    printf("\nTentando remover 50 (nao existe)\n");
    remover_lista(50, minha_lista);
    imprimir_lista(minha_lista); 

    printf("\nRemovendo 10...\n");
    remover_lista(10, minha_lista);
    imprimir_lista(minha_lista); 

    printf("\nRemovendo 30...\n");
    remover_lista(30, minha_lista);
    imprimir_lista(minha_lista); 

    free(minha_lista);

    return 0;
}


void insere_inicio(int valor, struct celula_dupla *cabeca) {

    struct celula_dupla *nova_celula;
    nova_celula = (struct celula_dupla *) malloc(sizeof(struct celula_dupla));

    if (nova_celula == NULL) {
        return; 
    }
    
    nova_celula->conteudo = valor;

    nova_celula->seg = cabeca->seg; 
    nova_celula->ant = cabeca;      

    cabeca->seg->ant = nova_celula; 
    cabeca->seg = nova_celula;
}


void imprimir_lista(struct celula_dupla *cabeca) {
    struct celula_dupla *p;

    p = cabeca->seg;

    printf("Lista: [");
    while (p != cabeca) {
        printf(" %d ", p->conteudo);
        p = p->seg; 
    }
    printf("]\n");
}


void remover_lista(int valor_remov, struct celula_dupla *cabeca) {
    struct celula_dupla *p = cabeca->seg;

    while (p != cabeca && p->conteudo != valor_remov) {
        p = p->seg;
    }

    if (p == cabeca) {
        return; 
    }

    p->ant->seg = p->seg;
    p->seg->ant = p->ant;

    free(p);
}