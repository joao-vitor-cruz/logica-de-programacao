//item 5 e 6 -> nao usou o item 3 para pesquisar o nome

#include <stdio.h>
#include <stdlib.h>

int selecao, quantidade1, quantidade2, quantidade3;
char filme1[20], filme2[20], filme3[20];

void entradaDados() {
    int busca;

    printf("Digite o nome do 1o filme: ");
    gets(filme1);
    printf("Quantidade: ");
    scanf("%d", &quantidade1);
    getchar();

    do {
        busca = 0;
        printf("Digite o nome do 2o filme: ");
        gets(filme2);
        for (int i = 0; i < 20; i++) {
            if (filme2[i] != filme1[i]) {
                break;
            }
            if (filme2[i] == '\0' && filme1[i] == '\0') {
                busca = 1;
            }
        }
        if (busca == 1) {
            printf("Filme ja cadastrado. Favor inserir outro!\n");
        }
    } while (busca == 1);

    printf("Quantidade: ");
    scanf("%d", &quantidade2);
    getchar();

    do {
        busca = 0;
        printf("Digite o nome do 3o filme: ");
        gets(filme3);

        for (int i = 0; i < 20; i++) {
            if (filme3[i] != filme1[i]) {
                break;
            }
            if (filme3[i] == '\0' && filme1[i] == '\0') {
                busca = 1;
            }
        }

        for (int i = 0; i < 20; i++) {
            if (filme3[i] != filme2[i]) {
                break;
            }
            if (filme3[i] == '\0' && filme2[i] == '\0') {
                busca = 1;
            }
        }

        if (busca == 1) {
            printf("Filme ja cadastrado. Favor inserir outro!\n");
        }
    } while (busca == 1);

    printf("Quantidade: ");
    scanf("%d", &quantidade3);
    getchar();

    FILE *file = fopen("filmes.bin", "wb");
    fwrite(filme1, sizeof(filme1), 1, file);
    fwrite(&quantidade1, sizeof(quantidade1), 1, file);
    fwrite(filme2, sizeof(filme2), 1, file);
    fwrite(&quantidade2, sizeof(quantidade2), 1, file);
    fwrite(filme3, sizeof(filme3), 1, file);
    fwrite(&quantidade3, sizeof(quantidade3), 1, file);
    fclose(file);
}

void listarDados() {
        FILE *file = fopen("filmes.bin", "rb");
        fread(filme1, sizeof(filme1), 1, file);
        fread(&quantidade1, sizeof(quantidade1), 1, file);
        fread(filme2, sizeof(filme2), 1, file);
        fread(&quantidade2, sizeof(quantidade2), 1, file);
        fread(filme3, sizeof(filme3), 1, file);
        fread(&quantidade3, sizeof(quantidade3), 1, file);


        if (file == NULL) {
            printf("Arquivo nao encontrado, encerrando o programa...");
            exit(0);
        }

        if (filme1[0] != '*'){
            printf("%s\n", filme1);
            printf("%d unidade(s)\n\n", quantidade1);
        }

        if (filme2[0] != '*'){
            printf("%s\n", filme2);
            printf("%d unidade(s)\n\n", quantidade2);
        }

        if (filme3[0] != '*'){
            printf("%s\n", filme3);
            printf("%d unidade(s)\n\n", quantidade3);
        }

        fclose(file);
}

void pesquisarNome() {
    FILE *file = fopen("filmes.bin", "rb");
    if (file == NULL) {
        printf("Arquivo nao encontrado, encerrando o programa...");
        exit(0);
    }
    fread(filme1, sizeof(filme1), 1, file);
    fread(&quantidade1, sizeof(quantidade1), 1, file);
    fread(filme2, sizeof(filme2), 1, file);
    fread(&quantidade2, sizeof(quantidade2), 1, file);
    fread(filme3, sizeof(filme3), 1, file);
    fread(&quantidade3, sizeof(quantidade3), 1, file);
    fclose(file);

    char filmePesquisado[20];
    int i, cont = 0;
    printf("Digite o nome do filme que deseja pesquisar: ");
    gets(filmePesquisado);

    for (i = 0; filmePesquisado[i] != '\0'; i++) {
        if (filmePesquisado[i] != filme1[i]) {
            cont++;
            break;
        }
    }
    if (filmePesquisado[i] == '\0' && filme1[i] == '\0')
        printf("%s\n%d unidade(s)\n", filme1, quantidade1);

    for (i = 0; filmePesquisado[i] != '\0'; i++) {
        if (filmePesquisado[i] != filme2[i]) {
            cont++;
            break;
        }
    }
    if (filmePesquisado[i] == '\0' && filme2[i] == '\0')
        printf("%s\n%d unidade(s)\n", filme2, quantidade2);

    for (i = 0; filmePesquisado[i] != '\0'; i++) {
        if (filmePesquisado[i] != filme3[i]) {
            cont++;
            break;
        }
    }
    if (filmePesquisado[i] == '\0' && filme3[i] == '\0')
        printf("%s\n%d unidade(s)\n", filme3, quantidade3);


    if (cont == 3)
        printf("Nao ha nenhum filme com esse nome.\n");

}

void pesquisarLetra() {
    FILE *file = fopen("filmes.bin", "rb");
    if (file == NULL) {
        printf("Arquivo nao encontrado, encerrando o programa...");
        exit(0);
    }
    fread(filme1, sizeof(filme1), 1, file);
    fread(&quantidade1, sizeof(quantidade1), 1, file);
    fread(filme2, sizeof(filme2), 1, file);
    fread(&quantidade2, sizeof(quantidade2), 1, file);
    fread(filme3, sizeof(filme3), 1, file);
    fread(&quantidade3, sizeof(quantidade3), 1, file);
    fclose(file);

    char letraPesquisada;
    int cont1 = 0, cont2 = 0, cont3 = 0;
    printf("Digite a primeira letra do filme que deseja pesquisar: ");
    letraPesquisada = getchar();

    if (letraPesquisada != filme1[0]) {
        cont1++;
    }
    if (letraPesquisada != filme2[0]) {
        cont2++;
    }
    if (letraPesquisada != filme3[0]) {
        cont3++;
    }

    if (cont1 == 0) {
        printf("%s\n%d unidade(s)\n", filme1, quantidade1);
    }
    if (cont2 == 0) {
        printf("%s\n%d unidade(s)\n", filme2, quantidade2);
    }
    if (cont3 == 0) {
        printf("%s\n%d unidade(s)\n", filme3, quantidade3);
    }
    if (cont1 != 0 && cont2 != 0 && cont3 != 0) {
        printf("Nao existem filmes que comecem com essa letra.\n");
    }

}

void alterarDados() {
    FILE *file = fopen("filmes.bin", "rb");
    if (file == NULL) {
        printf("Arquivo nao encontrado, encerrando o programa...");
        exit(0);
    }


    fread(filme1, sizeof(filme1), 1, file);
    fread(&quantidade1, sizeof(quantidade1), 1, file);
    fread(filme2, sizeof(filme2), 1, file);
    fread(&quantidade2, sizeof(quantidade2), 1, file);
    fread(filme3, sizeof(filme3), 1, file);
    fread(&quantidade3, sizeof(quantidade3), 1, file);
    fclose(file);

    char filmePesquisado[20];
    int i, cont = 0, busca;

    printf("Digite o nome do filme que deseja alterar: ");
    gets(filmePesquisado);

    for (i = 0; filmePesquisado[i] != '\0'; i++) {
        if (filmePesquisado[i] != filme1[i]) {
            cont++;
            break;
        }
    }

    if (filmePesquisado[i] == '\0' && filme1[i] == '\0') {
        printf("Digite o novo nome do filme: ");
        do {
            busca = 0;
            gets(filme1);


            for (int j = 0; j < 20; j++) {
                if (filme1[j] != filme2[j]) {
                    break;
                }
                if (filme1[j] == '\0' && filme2[j] == '\0') {
                    busca = 1;
                    break;
                }
            }

            for (int j = 0; j < 20; j++) {
                if (filme1[j] != filme3[j]) {
                    break;
                }
                if (filme1[j] == '\0' && filme3[j] == '\0') {
                    busca = 1;
                    break;
                }
            }

            if (busca == 1) {
                printf("Filme ja cadastrado. Favor inserir outro!\n");
            }
        } while (busca == 1);

        printf("Digite a nova quantidade: ");
        scanf("%d", &quantidade1);
    }

    for (i = 0; filmePesquisado[i] != '\0'; i++) {
        if (filmePesquisado[i] != filme2[i]) {
            cont++;
            break;
        }
    }
    if (filmePesquisado[i] == '\0' && filme2[i] == '\0') {
        printf("Digite o novo nome do filme: ");
        do {
            busca = 0;
            gets(filme2);
            for (int j = 0; j < 20; j++) {
                if (filme2[j] != filme1[j]) {
                    break;
                }
                if (filme2[j] == '\0' && filme1[j] == '\0') {
                    busca = 1;
                    break;
                }
            }

            for (int j = 0; j < 20; j++) {
                if (filme2[j] != filme3[j]) {
                    break;
                }
                if (filme2[j] == '\0' && filme3[j] == '\0') {
                    busca = 1;
                    break;
                }
            }

            if (busca == 1) {
                printf("Filme ja cadastrado. Favor inserir outro!\n");
            }
        } while (busca == 1);

        printf("Digite a nova quantidade: ");
        scanf("%d", &quantidade2);
    }


    for (i = 0; filmePesquisado[i] != '\0'; i++) {
        if (filmePesquisado[i] != filme3[i]) {
            cont++;
            break;
        }
    }
    if (filmePesquisado[i] == '\0' && filme3[i] == '\0') {
        printf("Digite o novo nome do filme: ");
        do {
        busca = 0;
        gets(filme3);

        for (int j = 0; j < 20; j++) {
            if (filme3[j] != filme1[j]) {
                break;
            }
            if (filme3[j] == '\0' && filme1[j] == '\0') {
                busca = 1;
                break;
                }
            }

            for (int j = 0; j < 20; j++) {
                if (filme3[j] != filme2[j]) {
                    break;
                }
                if (filme3[j] == '\0' && filme2[j] == '\0') {
                    busca = 1;
                    break;
                }
            }

            if (busca == 1) {
                printf("Filme ja cadastrado. Favor inserir outro!\n");
            }
        } while (busca == 1);

        printf("Digite a nova quantidade: ");
        scanf("%d", &quantidade3);
    }

    if (cont == 3) {
        printf("Nao ha nenhum filme com esse nome.\n");
    }


    file = fopen("filmes.bin", "wb");
    fwrite(filme1, sizeof(filme1), 1, file);
    fwrite(&quantidade1, sizeof(quantidade1), 1, file);
    fwrite(filme2, sizeof(filme2), 1, file);
    fwrite(&quantidade2, sizeof(quantidade2), 1, file);
    fwrite(filme3, sizeof(filme3), 1, file);
    fwrite(&quantidade3, sizeof(quantidade3), 1, file);
    fclose(file);
}


void excluirDados() {
    FILE *file = fopen("filmes.bin", "rb");
    if (file == NULL) {
        printf("Arquivo nao encontrado, encerrando o programa...");
        exit(0);
    }
    fread(filme1, sizeof(filme1), 1, file);
    fread(&quantidade1, sizeof(quantidade1), 1, file);
    fread(filme2, sizeof(filme2), 1, file);
    fread(&quantidade2, sizeof(quantidade2), 1, file);
    fread(filme3, sizeof(filme3), 1, file);
    fread(&quantidade3, sizeof(quantidade3), 1, file);
    fclose(file);

    char filmePesquisado[20];
    int i, cont = 0;
    char seletor;
    printf("Digite o nome do filme que deseja excluir: ");
    gets(filmePesquisado);

    for (i = 0; filmePesquisado[i] != '\0'; i++) {
        if (filmePesquisado[i] != filme1[i]) {
            cont++;
            break;
        }
    }

    if (filmePesquisado[i] == '\0' && filme1[i] == '\0') {
        do {
            printf("Voce quer mesmo deletar este filme: %s?\n (s: sim | n: nao): ", filme1);
            seletor = getchar();
            if (seletor != 's' && seletor != 'n') {
                printf("Opcao invalida");
            }
        } while (seletor != 's' && seletor != 'n');

        if (seletor == 's') {
            filme1[0] = '*';
        }

        if (seletor == 'n') {
            printf("Retornando ao menu...\n");
        }
    }

    for (i = 0; filmePesquisado[i] != '\0'; i++) {
        if (filmePesquisado[i] != filme2[i]) {
            cont++;
            break;
        }
    }
    if (filmePesquisado[i] == '\0' && filme2[i] == '\0') {
        do {
            printf("Voce quer mesmo deletar este filme: %s?\n (s: sim | n: nao): ", filme2);
            seletor = getchar();
            if (seletor != 's' && seletor != 'n') {
                printf("Opcao invalida");
            }
        } while (seletor != 's' && seletor != 'n');

        if (seletor == 's') {
            filme2[0] = '*';
        }

        if (seletor == 'n') {
            printf("Retornando ao menu...\n");
        }
    }

    for (i = 0; filmePesquisado[i] != '\0'; i++) {
        if (filmePesquisado[i] != filme3[i]) {
            cont++;
            break;
        }
    }
    if (filmePesquisado[i] == '\0' && filme3[i] == '\0') {
      do {
            printf("Voce quer mesmo deletar este filme: %s?\n (s: sim | n: nao): ", filme3);
            seletor = getchar();
            if (seletor != 's' && seletor != 'n') {
                printf("Opcao invalida");
            }
        } while (seletor != 's' && seletor != 'n');

        if (seletor == 's') {
            filme3[0] = '*';
        }

        if (seletor == 'n') {
            printf("Retornando ao menu...\n");
        }
    }

    if (cont == 3)
        printf("Nao ha nenhum filme com esse nome.\n");


    fopen("filmes.bin", "wb");
    fwrite(filme1, sizeof(filme1), 1, file);
    fwrite(&quantidade1, sizeof(quantidade1), 1, file);
    fwrite(filme2, sizeof(filme2), 1, file);
    fwrite(&quantidade2, sizeof(quantidade2), 1, file);
    fwrite(filme3, sizeof(filme3), 1, file);
    fwrite(&quantidade3, sizeof(quantidade3), 1, file);
    fclose(file);


}

void saida() {
    exit(0);
}

int main(){


    for(; ;) {
    system("cls");
    printf("------------------------------FLAMES FILMES--------------------------------\n");
    printf("             1 Adicionar filmes           2 Catalogo                   +    \n");
    printf("             3 Pesquisar pelo nome        4 Pesquisa pela letra        |    \n");
    printf("             5 Alterar dados              6 Excluir dados          +---+---+\n");
    printf("                                 7 Sair                                |    \n");
    printf("                                                                       |    \n");
    printf("                                                                       +    \n");
    printf("\nSelecione uma opcao: ");
    scanf("%d", &selecao);
    getchar();
    system("cls");

    switch (selecao) {

        case 1:
            entradaDados();
            system("pause");
            break;
        case 2:
            listarDados();
            system("pause");
            break;
        case 3:
            pesquisarNome();
            system("pause");
            break;
        case 4:
            pesquisarLetra();
            system("pause");
            break;
        case 5:
            alterarDados();
            system("pause");
            break;
        case 6:
            excluirDados();
            system("pause");
            break;
        case 7:
            saida();
            break;

        default:
        printf("Valor invalido\n");
        system("pause");
        }
    }
}