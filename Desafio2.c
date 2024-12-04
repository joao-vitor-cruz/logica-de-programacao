#include <stdio.h>

struct Filme {
    char nome[50];
    int quantidade;
    float preco;
    int mes;
    int ano;
};

void adicionarNovoFilme(FILE *arquivo);
void listarFilmes(FILE *arquivo);
void pesquisarFilmePorNome(FILE *arquivo, const char *nome);
void pesquisarFilmePorData(FILE *arquivo, int mes, int ano);
void listarFilmesPorPreco(FILE *arquivo);
void alterarQuantidade(FILE *arquivo, const char *nome);
void alterarPreco(FILE *arquivo, const char *nome);
void alterarTodosOsDados(FILE *arquivo, const char *nome);
void excluirFilme(FILE *arquivo, const char *nome);

int main() {
    FILE *arquivo;
    int opcao, mes, ano;
    char nome_procurado[50];

    arquivo = fopen("filmes.dat", "rb+");
    if (arquivo == NULL) {
        arquivo = fopen("filmes.dat", "wb+");
        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return 1;
        }
    }

    do {
    
        printf("\n----------------------------- MENU -----------------------------\n");
        printf("1 - Entrada de dados do filme\n");
        printf("2 - Lista todos os filmes na tela\n");
        printf("3 - Pesquisar um filme pelo nome completo\n");
        printf("4 - Pesquisar data de lançamento do filme (mês/ano)\n");
        printf("5 - Listar filmes por faixa de preço\n");
        printf("6 - Alterar quantidade em estoque (entrada e saída)\n");
        printf("7 - Alterar preço de um filme pesquisado pelo nome completo\n");
        printf("8 - Alterar todos os dados do filme pesquisado pelo nome completo\n");
        printf("9 - Excluir filme pesquisado pelo nome completo\n");
        printf("10 - Saída\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                adicionarNovoFilme(arquivo);
                break;
            case 2:
                listarFilmes(arquivo);
                break;
            case 3:
                printf("Digite o nome do filme: ");
                scanf("%49[^\n]", nome_procurado);
                pesquisarFilmePorNome(arquivo, nome_procurado);
                break;
            case 4:
                printf("Digite o mês e ano (MM AAAA): ");
                scanf("%d %d", &mes, &ano);
                pesquisarFilmePorData(arquivo, mes, ano);
                break;
            case 5:
                listarFilmesPorPreco(arquivo);
                break;
            case 6:
                printf("Digite o nome do filme: ");
                scanf("%49[^\n]", nome_procurado);
                alterarQuantidade(arquivo, nome_procurado);
                break;
            case 7:
                printf("Digite o nome do filme: ");
                scanf("%49[^\n]", nome_procurado);
                alterarPreco(arquivo, nome_procurado);
                break;
            case 8:
                printf("Digite o nome do filme: ");
                scanf("%49[^\n]", nome_procurado);
                alterarTodosOsDados(arquivo, nome_procurado);
                break;
            case 9:
                printf("Digite o nome do filme: ");
                scanf("%49[^\n]", nome_procurado);
                excluirFilme(arquivo, nome_procurado);
                break;
            case 10:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 10);

    fclose(arquivo);
    return 0;
}

void adicionarNovoFilme(FILE *arquivo) {
    struct Filme novo;
    printf("Digite o nome do filme: ");
    scanf("%49[^\n]", novo.nome);

    printf("Digite a quantidade em estoque: ");
    scanf("%d", &novo.quantidade);

    printf("Digite o preço do filme: ");
    scanf("%f", &novo.preco);

    printf("Digite o mês e ano de lançamento (MM AAAA): ");
    scanf("%d %d", &novo.mes, &novo.ano);

    fseek(arquivo, 0, SEEK_END);
    fwrite(&novo, sizeof(struct Filme), 1, arquivo);

    printf("Filme adicionado com sucesso!\n");
}

void listarFilmes(FILE *arquivo) {
    struct Filme filme;
    fseek(arquivo, 0, SEEK_SET);
    
    while (fread(&filme, sizeof(struct Filme), 1, arquivo)) {
        printf("Nome: %s\n", filme.nome);
        printf("Quantidade: %d\n", filme.quantidade);
        printf("Preço: %.2f\n", filme.preco);
        printf("Lançamento: %02d/%04d\n", filme.mes, filme.ano);
        printf("-----------------------------\n");
    }
}

void listarFilmesPorPreco(FILE *arquivo) {
    struct Filme filmes[100], temp;
    int count = 0;

    fseek(arquivo, 0, SEEK_SET);

    while (fread(&filmes[count], sizeof(struct Filme), 1, arquivo)) {
        count++;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (filmes[i].preco > filmes[j].preco) {
                temp = filmes[i];
                filmes[i] = filmes[j];
                filmes[j] = temp;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        printf("Nome: %s\n", filmes[i].nome);
        printf("Quantidade: %d\n", filmes[i].quantidade);
        printf("Preço: %.2f\n", filmes[i].preco);
        printf("Lançamento: %02d/%04d\n", filmes[i].mes, filmes[i].ano);
        printf("-----------------------------\n");
    }
}

void pesquisarFilmePorNome(FILE *arquivo, const char *nome) {
    struct Filme filme;
    int encontrado = 0;

    fseek(arquivo, 0, SEEK_SET);
    while (fread(&filme, sizeof(struct Filme), 1, arquivo)) {
     
        int j = 0;
        while (nome[j] != '\0' && filme.nome[j] != '\0' && nome[j] == filme.nome[j]) {
            j++;
        }

        if (nome[j] == '\0' && filme.nome[j] == '\0') { 
            printf("Nome: %s\n", filme.nome);
            printf("Quantidade: %d\n", filme.quantidade);
            printf("Preço: %.2f\n", filme.preco);
            printf("Lançamento: %02d/%04d\n", filme.mes, filme.ano);
            printf("-----------------------------\n");
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Filme não encontrado.\n");
    }
}

void pesquisarFilmePorData(FILE *arquivo, int mes, int ano) {
    struct Filme filme;
    int encontrado = 0;

    fseek(arquivo, 0, SEEK_SET);
    while (fread(&filme, sizeof(struct Filme), 1, arquivo)) {
        if (filme.mes == mes && filme.ano == ano) {
            printf("Nome: %s\n", filme.nome);
            printf("Quantidade: %d\n", filme.quantidade);
            printf("Preço: %.2f\n", filme.preco);
            printf("Lançamento: %02d/%04d\n", filme.mes, filme.ano);
            printf("-----------------------------\n");
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Nenhum filme encontrado para esta data.\n");
    }
}

void excluirFilme(FILE *arquivo, const char *nome) {
    struct Filme filme, filmes[100];
    int count = 0, encontrado = 0;

    fseek(arquivo, 0, SEEK_SET);

    while (fread(&filme, sizeof(struct Filme), 1, arquivo)) {
        if (encontrado == 0) {
          
            int j = 0;
            while (nome[j] != '\0' && filme.nome[j] != '\0' && nome[j] == filme.nome[j]) {
                j++;
            }

            if (nome[j] == '\0' && filme.nome[j] == '\0') {  
                encontrado = 1;
                continue; 
            }
        }
        filmes[count++] = filme;  
    }

    if (encontrado) {
   
        freopen("filmes.dat", "wb+", arquivo);  
        for (int i = 0; i < count; i++) {
            fwrite(&filmes[i], sizeof(struct Filme), 1, arquivo);
        }
        printf("Filme excluído com sucesso!\n");
    } else {
        printf("Filme não encontrado para exclusão.\n");
    }
}

void alterarQuantidade(FILE *arquivo, const char *nome) {
    struct Filme filme;
    int novoQuantidade;
    int encontrado = 0;

    fseek(arquivo, 0, SEEK_SET);
    while (fread(&filme, sizeof(struct Filme), 1, arquivo)) {
      
        int j = 0;
        while (nome[j] != '\0' && filme.nome[j] != '\0' && nome[j] == filme.nome[j]) {
            j++;
        }

        if (nome[j] == '\0' && filme.nome[j] == '\0') {
            printf("Filme encontrado. Quantidade atual: %d\n", filme.quantidade);
            printf("Digite a nova quantidade: ");
            scanf("%d", &novoQuantidade);
            filme.quantidade = novoQuantidade;
            fseek(arquivo, -sizeof(struct Filme), SEEK_CUR);
            fwrite(&filme, sizeof(struct Filme), 1, arquivo);
            printf("Quantidade alterada com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Filme não encontrado.\n");
    }
}

void alterarPreco(FILE *arquivo, const char *nome) {
    struct Filme filme;
    float novoPreco;
    int encontrado = 0;

    fseek(arquivo, 0, SEEK_SET);
    while (fread(&filme, sizeof(struct Filme), 1, arquivo)) {
       
        int j = 0;
        while (nome[j] != '\0' && filme.nome[j] != '\0' && nome[j] == filme.nome[j]) {
            j++;
        }

        if (nome[j] == '\0' && filme.nome[j] == '\0') {
            printf("Filme encontrado. Preço atual: %.2f\n", filme.preco);
            printf("Digite o novo preço: ");
            scanf("%f", &novoPreco);
            filme.preco = novoPreco;
            fseek(arquivo, -sizeof(struct Filme), SEEK_CUR);
            fwrite(&filme, sizeof(struct Filme), 1, arquivo);
            printf("Preço alterado com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Filme não encontrado.\n");
    }
}

void alterarTodosOsDados(FILE *arquivo, const char *nome) {
    struct Filme filme;
    float novoPreco;
    int novoQuantidade, novoMes, novoAno;
    int encontrado = 0;

    fseek(arquivo, 0, SEEK_SET);
    while (fread(&filme, sizeof(struct Filme), 1, arquivo)) {
    
        int j = 0;
        while (nome[j] != '\0' && filme.nome[j] != '\0' && nome[j] == filme.nome[j]) {
            j++;
        }

        if (nome[j] == '\0' && filme.nome[j] == '\0') {
            printf("Filme encontrado.\n");

            printf("Digite a nova quantidade: ");
            scanf("%d", &novoQuantidade);

            printf("Digite o novo preço: ");
            scanf("%f", &novoPreco);

            printf("Digite o novo mês e ano (MM AAAA): ");
            scanf("%d %d", &novoMes, &novoAno);

            filme.quantidade = novoQuantidade;
            filme.preco = novoPreco;
            filme.mes = novoMes;
            filme.ano = novoAno;

            fseek(arquivo, -sizeof(struct Filme), SEEK_CUR);
            fwrite(&filme, sizeof(struct Filme), 1, arquivo);
            printf("Dados alterados com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Filme não encontrado.\n");
    }
}