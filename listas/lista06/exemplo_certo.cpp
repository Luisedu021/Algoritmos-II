#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoas {
    char nome[30];
    int id;
    double salario;
};

// --- Função auxiliar para verificar o conteúdo do arquivo ---
// É uma boa prática criar funções para tarefas repetidas
void exibir_dados_arquivo() {
    FILE *file;
    struct pessoas p;
    
    file = fopen("dados.dat", "rb");
    if (file == NULL) {
        printf("Nao foi possivel ler o arquivo para verificacao.\n");
        return;
    }

    printf("\n--- Conteudo Atual do Arquivo ---\n");
    // fread retorna o número de itens lidos com sucesso.
    // O loop continua enquanto ele conseguir ler 1 item completo.
    while (fread(&p, sizeof(struct pessoas), 1, file) == 1) {
        printf("ID: %d, Nome: %s, Salario: R$%.2lf\n", p.id, p.nome, p.salario);
    }
    printf("-----------------------------------\n\n");
    fclose(file);
}


int main() {
    struct pessoas *a;
    int ver = 1;
    int cont = 0, n;
    FILE *f_gravacao;

    printf("Quantas pessoas no maximo voce deseja registrar? ");
    scanf("%d", &n);
    getchar(); // Limpa o buffer

    a = (struct pessoas *) malloc(sizeof(struct pessoas) * n);
    if (a == NULL) {
        perror("Erro de alocacao de memoria");
        return 1;
    }

    // --- SEÇÃO DE GRAVAÇÃO INICIAL (igual ao seu código) ---
    while (cont < n) {
        printf("\n--- Pessoa %d ---\n", cont + 1);
        printf("Digite o nome: ");
        scanf("%29s", a[cont].nome);
        printf("Digite o ID: ");
        scanf("%d", &a[cont].id);
        printf("Digite o salario: ");
        scanf("%lf", &a[cont].salario);
        getchar();

        cont++;

        if (cont < n) {
            printf("\nDeseja registrar outra pessoa? [1]SIM / [0]NAO: ");
            scanf("%d", &ver);
            getchar();
            if (ver == 0) {
                break;
            }
        }
    }

    f_gravacao = fopen("dados.dat", "wb");
    if (f_gravacao == NULL) {
        perror("Erro ao abrir arquivo para gravacao");
        free(a);
        return 1;
    }
    fwrite(a, sizeof(struct pessoas), cont, f_gravacao);
    fclose(f_gravacao);
    printf("\nDados iniciais gravados com sucesso!\n");
    free(a); // Libera 'a' pois não precisaremos mais dele

    // --- SEÇÃO DE ATUALIZAÇÃO ---
    
    // Exibe os dados antes da atualização para o usuário saber o que tem no arquivo
    exibir_dados_arquivo();

    printf("Voce deseja atualizar o salario de alguem? [1]SIM / [0]NAO: ");
    scanf("%d", &ver);

    if (ver == 1) {
        int id_desejado;
        double novo_salario;
        int encontrado = 0;
        long posicao_registro = -1; // Usamos 'long' para posições de arquivo
        
        FILE *f_atualizacao;
        struct pessoas p_temp; // Struct temporária para ler o arquivo

        printf("Entre com o id da pessoa que voce quer atualizar o salario: ");
        scanf("%d", &id_desejado);

        // Abre para leitura e escrita, sem apagar o conteúdo
        f_atualizacao = fopen("dados.dat", "r+b"); 
        if (f_atualizacao == NULL) {
            perror("Erro ao abrir arquivo para atualizacao");
            return 1;
        }

        // 1. Encontrar o registro
        int i = 0;
        while (fread(&p_temp, sizeof(struct pessoas), 1, f_atualizacao) == 1) {
            if (p_temp.id == id_desejado) {
                posicao_registro = i; // Guarda o índice do registro (0, 1, 2...)
                encontrado = 1;
                break; // Sai do loop pois já encontrou
            }
            i++;
        }

        if (encontrado) {
            // 2. Pedir o novo dado
            printf("Pessoa encontrada: %s. Digite o NOVO salario: ", p_temp.nome);
            scanf("%lf", &novo_salario);

            // Atualiza o salário na nossa struct temporária
            p_temp.salario = novo_salario;

            // 3. Posicionar o cursor no local exato para sobrescrever
            // O cálculo é: indice * tamanho_da_struct
            fseek(f_atualizacao, posicao_registro * sizeof(struct pessoas), SEEK_SET);

            // 4. Escrever o registro ATUALIZADO por cima do antigo
            fwrite(&p_temp, sizeof(struct pessoas), 1, f_atualizacao);

            printf("\nSalario atualizado com sucesso!\n");

        } else {
            printf("\nID %d nao encontrado no arquivo.\n", id_desejado);
        }

        // 5. Fechar o arquivo
        fclose(f_atualizacao);
        
        // Se algo foi encontrado, exibe o resultado final
        if(encontrado) {
            printf("\n--- Verificando o arquivo apos a atualizacao ---\n");
            exibir_dados_arquivo();
        }

    }

    printf("\nPrograma finalizado.\n");
    return 0;
}