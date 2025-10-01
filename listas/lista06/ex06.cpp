#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct pessoas{
    char nome[30];
    int id;
    double salario;
};

int main() {
    struct pessoas *a;
    struct pessoas *b;
    int ver = 1,ver2= 0;
    int cont = 0,n,id_desejado;
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
       printf("Digite seu nome,seu id e seu salario:"); 
       scanf("%29s%d%lf%*c",&a[cont].nome,&a[cont].id,&a[cont].salario);
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

printf("Voce deseja procurar alguem no banco de dados?");
printf("\n1[SIM]|0[NAO]");
scanf("%d%*c",&ver);

if (ver == 1){
    printf("Entre com o id da pessoa:");
    scanf("%d%*c",&id_desejado);

    for (int i = 0;i < cont;i++){
        if (id_desejado == b[i].id){
            printf("NOME = %s |ID = %d | SALDO = R$%.2lf |\n",strupr(b[i].nome),b[i].id,b[i].salario);
            ver2++;
        }
    
        
    }
}
    if (ver2 == 0){
        printf("ID nao encontrado!");
    }
    fclose(f_gravacao);
    fclose(f_leitura);
    free(a);
    free(b);
    return 0;

}