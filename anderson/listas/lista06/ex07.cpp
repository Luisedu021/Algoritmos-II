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
    int ver = 1,ver2= 0, posicao;
    int cont = 0,n,id_desejado;
    int encontrado;
    FILE *f_gravacao;
    FILE *f_leitura;
    double novo_salario;

    FILE *f_atualizacao;
    struct pessoas p_temp;
    
    

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

printf("BANCO DE DADOS ANTIGO: ");
for (int i = 0;i < cont;i++){
            printf("NOME = %s |ID = %d | SALDO = R$%.2lf |\n",strupr(b[i].nome),b[i].id,b[i].salario);
        }

printf("Voce deseja atualizar o salario de alguem no banco de dados?");
printf("\n1[SIM]|0[NAO]");
scanf("%d%*c",&ver);

if (ver == 1){
    printf("Entre com o id da pessoa que voce quer atualizar o salario:");
    scanf("%d%*c",&id_desejado);




f_atualizacao = fopen("dados.dat", "r+b"); 
        if (f_atualizacao == NULL) {
            perror("Erro ao abrir arquivo para atualizacao");
            return 1;
        }

    
//sabendo a posicao exata que quero pegar 
int i = 0;
   while(fread(&p_temp,sizeof(struct pessoas), 1, f_atualizacao) == 1){
    if (p_temp.id == id_desejado){
        posicao = 1;
        encontrado = 1;
        break;
    }
    i++;
   }

if (encontrado){
    printf("Pessoa encontrada: %s. Digite o NOVO salario: ", p_temp.nome);
            scanf("%lf", &novo_salario);
}

fseek(f_atualizacao,posicao * sizeof(struct pessoas),SEEK_SET);
fwrite(&p_temp, sizeof(struct pessoas), 1, f_atualizacao);
printf("\nSalario atualizado com sucesso!\n");

}
    if (not encontrado){
        printf("ID nao encontrado!");
    }
printf("BANCO DE DADOS NOVO: ");
for (int i = 0;i < cont;i++){
            printf("NOME = %s |ID = %d | SALDO = R$%.2lf |\n",strupr(b[i].nome),b[i].id,b[i].salario);
        }
    fclose(f_atualizacao);
    fclose(f_leitura);
    free(a);
    free(b);
    return 0;

}