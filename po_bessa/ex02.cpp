#include <stdio.h>

#define max 100

void enfileira(int fila[],int valor);
int desenfilera(int fila[]);

int main(){

int queue[max];

queue[0] = 2;
queue[1] = 2;

for(int i = 2;i <6;i++){
    printf("%d ",queue[i]);
}
desenfilera(queue);
desenfilera(queue);

return 1;
}

void enfileira(int fila[],int valor){

if(fila[1] == 100){
    printf("Overflow\n");
    return ;
}
fila[fila[1]] = valor;
fila[1] = fila[1] + 1;

}

int desenfilera(int fila[]){
    int valor;
    if(fila[0] == fila[1]){
        printf("Fila vazian");
        return -1;
    }
    valor = fila[fila[0]];
    fila[0] = fila[0] + 1;

    return valor;
    
}