#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct pessoas{
    char nome[30];
    int idade;
    double salario;
};

int main() {
    struct pessoas *a;
    struct pessoas *b;
    int ver = 1;
    int cont = 0,n;
    FILE *f_gravacao;
    FILE *f_leitura;

    printf("Quantas pessoas no maximo voce deseja registrar?");
    scanf("%d",&n);

    a = (struct pessoas *) malloc(sizeof(struct pessoas) *n);

     if (a == NULL) {
        perror("Erro: Nao foi possivel alocar memoria");
        return 1; 
    }

    while (1){
        if (cont >= n){
            break;
        }
       printf("Digite seu nome,sua idade e seu salario:"); 
       scanf("%29s%d%lf%*c",&a[cont].nome,&a[cont].idade,&a[cont].salario);
       cont++;
        printf("\nDeseja registrar outra pessoa?[1]SIM/[0]NAO: ");
        scanf("%d",&ver);
        if (ver == 0){
            break;
        }
    }
    f_gravacao = fopen("dados.dat","wb");
    if (f_gravacao == NULL) {
        perror("Erro ao abrir o arquivo!");
        return 1;
    }

    fwrite(a,sizeof(struct pessoas),cont,f_gravacao);
    
    fclose(f_gravacao);
    
//leitura dos dados gravados 
f_leitura = fopen("dados.dat","rb");

if (f_leitura == NULL){
    perror("Erro ao ler o arquivo");
    return 1;
}
 b = (struct pessoas *) malloc(sizeof(struct pessoas) *cont);

     if (b == NULL) {
        perror("Erro: Nao foi possivel alocar memoria");
        return 1; 
    }
    fread(b,sizeof(pessoas),cont,f_leitura);

    for (int i = 0;i < cont;i++){
        
        printf("NOME = %s |IDADE = %d | SALDO = R$%.2lf |\n",strupr(b[i].nome),b[i].idade,b[i].salario);
    }

    free(a);
    free(b);
    return 0;

}