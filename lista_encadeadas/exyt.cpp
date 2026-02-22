#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct ElementoLista{
    int valor;
    struct ElementoLista *prox;
};

typedef struct ElementoLista item;

//prototipos

void imprime_elemento(item* cabeca,int elemento_desejado);
int contando_elementos(item* cabeca);
void imprime(item *cabeca);
void insereFim(item* cabeca, int valor);
void libera(item* cabeca);
void inserir(item* cabeca,int ValorDesejado,int indice_esp);
void inserir_arq_texto(item* cabeca,FILE *desejado);

int main(){
 //criando cabeça da lista
char ver[10];
item cabeca;
cabeca.prox = NULL;
int indice;
int valor1;
FILE *arq_lista;

arq_lista = fopen("saida.txt","w");
if(arq_lista == NULL){
    exit(1);
}


 printf("Tamanho do item: %d bytes\n",sizeof(item));

//insere ao final da lista um item alocado dinamicamente
printf("Inserindos itens a lista...\n");
insereFim(&cabeca,15);
insereFim(&cabeca, 125);
insereFim(&cabeca,155);

system("PAUSE");
contando_elementos(&cabeca);
system("PAUSE");

printf("\nOs elementos:\n");
imprime(&cabeca);

printf("Deseja imprimir algum elemento em especifico?[S/N]");
scanf("%s%*c",ver);

if(toupper(ver[0]) == 'S'){
    printf("Qual elemento?");
    scanf("%d",&indice);
    imprime_elemento(&cabeca,indice);

}

system("PAUSE");
printf("\nDeseja colocar algum elemento na lista?\n");
scanf("%s%*c",ver);

if(toupper(ver[0]) == 'S'){
    printf("Qual elemento e em qual indice?");
    int indice1;
    scanf("%d%d",&indice1,&valor1);
    inserir(&cabeca,indice1,valor1);

}
printf("\nOs elementos:\n");
imprime(&cabeca);

printf("Deseja um arquivo com essa lista?");
char ver1[10];
scanf("%s",ver1);



if(toupper(ver1[0]) == 'S'){
    inserir_arq_texto(&cabeca,arq_lista);
    printf("Arquivo feito com sucesso!");
}

printf("\nLiberando elementos da lista");
libera(&cabeca);
fclose(arq_lista);

return 0 ;

}

//função para inserção 
void inserir_arq_texto(item* cabeca,FILE *desejado){
    item *atual = cabeca->prox;
    
    int i = 0;
    while(atual != NULL){
        i++;
        fprintf(desejado,"Valor do item %d: %3d\n",i,atual ->valor);
        atual = atual ->prox;
    }
    fprintf(desejado,"Total de itens na lista: %d\n",i);
}


void imprime(item* cabeca){
    //este item aponta para o item atual sendo impresso
    //como este item eh a cabeca,a impressao comeca no proximo item 
    item *atual = cabeca->prox;

    int i = 0;
    while(atual != NULL){
        i++;
        printf("Valor do item %d: %3d\n",i,atual ->valor);
        
        atual = atual ->prox;
    }
    printf("Total de itens na lista: %d\n",i);

}

void imprime_elemento(item* cabeca,int elemento_desejado){
    //este item aponta para o item atual sendo impresso
    //como este item eh a cabeca,a impressao comeca no proximo item 
    item *atual = cabeca->prox;

    int i = 0;
    while(atual != NULL){
        i++;
        if(i == elemento_desejado){
            printf("Valor do item %d: %3d\n",i,atual ->valor);
        }
        
        
        atual = atual ->prox;
    }

}

void insereFim(item* cabeca,int valor){

    item *novo = (item*)malloc(sizeof(item));

    novo->prox = NULL;
    novo->valor = valor;
    
    printf("Item de valor %3d alocado ao endereco: 0x%000000x\n",novo->valor,novo);

    item *atual = cabeca;
    while(atual->prox != NULL){
        atual = atual->prox;
    }
    atual->prox = novo;
}

void inserir(item* cabeca,int ValorDesejado,int indice_esp){
item *anterior = cabeca;
item *novo = (item*)malloc(sizeof(item));
int i = 0;

while(anterior != NULL){
    if(i == indice_esp - 1){
        novo->prox = anterior->prox;
        novo->valor= ValorDesejado;
        anterior->prox = novo;
        break;
    }
    anterior = anterior->prox;
    i++;
}

}

int contando_elementos(item* cabeca){

    item *atual = cabeca->prox;

    int i = 0;
    while(atual != NULL){
        i++;
        atual = atual->prox;
    }
    return i;

}

void libera(item* cabeca){
item* atual = cabeca ->prox;

item *liberado;

while(atual != NULL){
    liberado = atual;
    atual = atual ->prox;
    printf("Liberando o item de valor %3d na posicao %000000x\n",liberado->valor, liberado);
    free(liberado);
}

}