#include <stdio.h>
#define ex4

/*4 - Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva 
    uma funcao que pesquise se esta letra existe no vetor abaixo usando ponteiros. 
    Imprima o resultado da pesquisa no video na funcao main(). Passe como informacao
    para a funcao a letra digitada e o vetor usando ponteiros e faca a pesquisa 
    usando ponteiros.(utilize o comando return). 
    O vetor deve ser declarado como variavel LOCAL na funcao main().

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y
*/
#ifdef ex4

int comparacao(char *pontLetra, char (*pontVetor)[13]) {
    for(int i = 0; i < 13; i++) {
        if ((*pontVetor)[i] == *pontLetra) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int x;
    
    do {
        char letra;
        char *pontLetra = &letra;
        char vetor[13] = {'b','d','f','h','j','k','m','o','q','s','u','w','y'};
        char (*pontVetor)[13] = &vetor;
        printf("Digite uma letra: ");
        scanf("%c", pontLetra);
        printf("voce digitou %c\n", *pontLetra);
        comparacao(pontLetra, pontVetor) == 1 ? printf("A letra está no vetor de caracteres.\n") : printf("A letra não está no vetor de caracteres\n");
        printf("O programa foi finalizado. Digite 0 para encerrar ou 1 para repetir: ");
        scanf("%d", &x);
        getchar();
    } while (x == 1);
    return 0;
}

#endif

/*
5 - Escreva um programa com a estrutura abaixo. Defina um vetor de estruturas
    de 4 elementos como variavel LOCAL na funcao main(). Receba os 4 registros
    sequencialmente pelo teclado numa funcao e imprima todos os registros no
    video em outra funcao. Faca um menu. Utilize ponteiros nas funcoes.
    Coloque no menu a opcao de sair tambem. Utilize o comando switch.
    (vetor de estruturas)
     estutura: nome, end, cidade, estado, cep
*/
#include <stdio.h>
#define ex5


/*4 - Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva 
    uma funcao que pesquise se esta letra existe no vetor abaixo usando ponteiros. 
    Imprima o resultado da pesquisa no video na funcao main(). Passe como informacao
    para a funcao a letra digitada e o vetor usando ponteiros e faca a pesquisa 
    usando ponteiros.(utilize o comando return). 
    O vetor deve ser declarado como variavel LOCAL na funcao main().

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y
*/
#ifdef ex4

int comparacao(char *pontLetra, char (*pontVetor)[13]) {
    for(int i = 0; i < 13; i++) {
        if ((*pontVetor)[i] == *pontLetra) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int x;
    
    do {
        char letra;
        char *pontLetra = &letra;
        char vetor[13] = {'b','d','f','h','j','k','m','o','q','s','u','w','y'};
        char (*pontVetor)[13] = &vetor;
        printf("Digite uma letra: ");
        scanf("%c", pontLetra);
        printf("voce digitou %c\n", *pontLetra);
        comparacao(pontLetra, pontVetor) == 1 ? printf("A letra está no vetor de caracteres.\n") : printf("A letra não está no vetor de caracteres\n");
        printf("O programa foi finalizado. Digite 0 para encerrar ou 1 para repetir: ");
        scanf("%d", &x);
        getchar();
    } while (x == 1);
    return 0;
}

#endif

/*
5 - Escreva um programa com a estrutura abaixo. Defina um vetor de estruturas
    de 4 elementos como variavel LOCAL na funcao main(). Receba os 4 registros
    sequencialmente pelo teclado numa funcao e imprima todos os registros no
    video em outra funcao. Faca um menu. Utilize ponteiros nas funcoes.
    Coloque no menu a opcao de sair tambem. Utilize o comando switch.
    (vetor de estruturas)
     estutura: nome, end, cidade, estado, cep
*/
#ifdef ex5
struct dados {
  char nome[30];
  char end[50];
  char cidade[20];
  char estado[15];
  char cep[9];
};

void registrar(struct dados (*prt)[4]) {
    for(int i = 0; i<4; i++) {
        printf("Digite o nome do %do endereco: ", (i+1));
        scanf("%s", &(*prt)[i].nome);
    }
}

void imprimir(struct dados (*prt)[4]) {
    
}

int main() {
    while (1) {
        struct dados endereco[4];
        struct dados (*prt)[4] = &endereco;
        int opcao;
        printf("Escolha uma opção:\n\n1- Registrar endereços\n2- Listar endereços\n3- Sair\n\n");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1: registrar(prt); break;
            case 2: imprimir(prt); break;
            case 3: return 0;
            default: printf("Opção inválida");
        }
    }
}
#endif


/*
6 - Acrescente ao menu do exercicio anterior as funcoes de procura, altera e
    exclui um registro sempre usando ponteiros.
*/
