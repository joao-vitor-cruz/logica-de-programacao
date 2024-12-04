#include <stdio.h>
#define ex6

/*1 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    A estrutura e' uma variavel LOCAL na funcao main(). Receba via teclado o
    conteudo de cada um dos membros numa funcao e imprima-os no video no
    seguinte formato(tamb m numa fun  o).

    estrutura: char, int, long, float, double, unsigned char, unsigned int,
    unsigned long

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long
*/
#ifdef ex1

struct dados {
        char A;
        int B;
        long C;
        float D;
        double E;
        unsigned char F;
        unsigned int G;
        unsigned long H;
    };

void recebe(struct dados *pont) {

    printf("Digite um caractere: ");
    scanf(" %c", &pont->A);
    printf("Digite um numero inteiro: ");
    scanf("%d", &pont->B);
    printf("Digite um numero inteiro longo: ");
    scanf("%ld", &pont->C);
    printf("Digite um numero decimal: ");
    scanf("%f", &pont->D);
    printf("Digite um numero decimal longo: ");
    scanf("%lf", &pont->E);
    printf("Digite um caractere: ");
    scanf(" %c", &pont->F);
    printf("Digite um inteiro positivo: ");
    scanf("%u", &pont->G);
    printf("Digite um inteiro positivo longo: ");
    scanf("%lu", &pont->H);
}

void imprime(struct dados *pont) {
    printf("\n        10        20        30        40        50        60        70\n");
    printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");
    printf("    %d                 %ld                %f     %lf          \n", pont->B, pont->C, pont->D, pont->E);
    printf("          %u        %lu         %c        %c \n", pont->G, pont->H, pont->A, pont->F);
}

int main() {
    int x;
    struct dados membros;
    struct dados *prt;
    prt = &membros;
    do {
        recebe(prt);
        imprime(prt);
        printf("\nVocê deseja repetir o programa?\nDigite 1 para repitir ou 0 para finalizar: ");
        scanf("%d", &x);
        getchar();
    } while (x == 1);
    return 0;  
}
 
#endif

/*
2 - Escreva um programa que receba em uma funcao 2 strings de ate' 10 caracteres
    passando como parametro ponteiro.
    Os vetores devem ser declarados como variaveis LOCAIS na funcao main().
    Escreva uma funcao para comparar as 2 strings. Passe como parametros para 
    a funcao as 2 strings usando ponteiros e retorne como resultado se IGUAIS 1 
    ou se DIFERENTES 0. Mostre o resultado no video na funcao main().
*/

#ifdef ex2

void recebe(char (*pont1)[11], char (*pont2)[11]) {
    printf("Digite a primeira palavra: ");
    scanf("%s", *pont1);
    printf("Digite a segunda palavra: ");
    scanf("%s", *pont2);
}

int compara(char (*pont1)[11], char (*pont2)[11]) {
    int i;
    for (i = 0;(*pont1)[i] != 0 && (*pont2)[i] != 0;i++) {
        if ((*pont1)[i] != (*pont2)[i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int x;
    do {
        char str1[11], str2[11], (*pont1)[11], (*pont2)[11];
        pont1 = &str1;
        pont2 = &str2;
        recebe(pont1, pont2);
        //printf("%s e %s\n", str1, str2); //teste
        printf("%d\n", compara(pont1, pont2));
        printf("\nVocê deseja repetir o programa?\nDigite 1 para repitir ou 0 para finalizar: ");
        scanf("%d", &x);
        getchar();
    } while (x == 1);
    return 0;
}

#endif

/*
3 - Escreva um programa que receba n valores via teclado e receba tambem a
    operacao a ser executada. Quando for digitado "=" o programa deve mostrar
    o resultado acumulado dos n valores. As operacoes aritmeticas e a entrada
    de dados devem ser funcoes que recebe os valores usando ponteiros.  
    As variaveis sao LOCAIS na funcao main().
*/
#ifdef ex3
int soma(float num, float resultado) {
    return resultado + num;
}

int subtracao(float num, float resultado) {
    return resultado - num;
}

int multiplicacao(float num, float resultado) {
    return resultado * num;
}

float divisao(float num, float resultado) {
    return resultado / num;
}

int main() {
    int x = 1;
    while (x == 1) {
        float num, resultado;
        char operador;
        int i = 0;
        
        while (1){

            if (i == 0) {
                printf("Digite o %do número: ", i+1);
                scanf("%f", &num);
                resultado = num;
                i++;
            } else {
                printf("Digite qual operação deseja fazer:\n+: soma\n-: subtração\n*: multiplicação\n/: divisão\n=: resultado\n");
                scanf(" %c", &operador);
                
                if (operador != '=') {
                    printf("Digite o %do número: ", i+1);
                    scanf("%f", &num);
                }

                switch (operador) {
                    case '+': resultado = soma(num, resultado);
                        i++;
                        break;
                    case '-': resultado = subtracao(num, resultado);
                        i++;    
                        break;
                    case '*': resultado = multiplicacao(num, resultado);
                        i++;
                        break;
                    case '/': resultado = divisao(num, resultado);
                        i++;
                        break;
                    case '=': printf("O resultado das operações é %.2f\n\nVocê deseja repetir o programa?\nDigite 1 para repitir ou 0 para finalizar:", resultado);
                    scanf("%d", &x);
                    getchar();
                    break;
                    
                    default: printf("opção inválida");
                    

                }
            }
        }
    }

    return 0;
}
#endif
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
        printf("\nDigite o nome do %do endereco: ", (i+1));
        scanf("%s", (*prt)[i].nome);
        printf("Digite o endereço do %do endereco: ", (i+1));
        scanf("%s", (*prt)[i].end);
        printf("Digite o cidade do %do endereco: ", (i+1));
        scanf("%s", (*prt)[i].cidade);
        printf("Digite o estado do %do endereco: ", (i+1));
        scanf("%s", (*prt)[i].estado);
        printf("Digite o CEP do %do endereco: ", (i+1));
        scanf("%s", (*prt)[i].cep);
    }
}

void imprimir(struct dados (*prt)[4]) {
    for(int i = 0; i<4; i++) {
        printf("\n%do endereco: \n\nNome: %s\nEndereço: %s\nCidade: %s\nEstado: %s\nCEP: %s\n", (i+1), (*prt)[i].nome, (*prt)[i].end, (*prt)[i].cidade, (*prt)[i].estado, (*prt)[i].cep);
    }
}

int main() {
    int x = 0;
    while (1) {
        struct dados endereco[4];
        struct dados (*prt)[4] = &endereco;
        int opcao;
        printf("Escolha uma opção:\n\n1- Registrar endereços\n2- Listar endereços\n3- Sair\n\n");
        scanf("%d", &opcao);
        
        switch (opcao) {

            case 1: registrar(prt);x++; break;
            case 2:
                if (x > 0) {
                    imprimir(prt);
                } else {
                    printf("Você não registrou nenhum filme.\n\n");
                }
                break;
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

#ifdef ex6
struct dados {
  char nome[30];
  char end[50];
  char cidade[20];
  char estado[15];
  char cep[9];
};

void registrar(struct dados (*prt)[4]) {
    for(int i = 0; i<4; i++) {
        printf("\nDigite o nome do %do endereco: ", (i+1));
        scanf("%s", (*prt)[i].nome);
        printf("Digite o endereço do %do endereco: ", (i+1));
        scanf("%s", (*prt)[i].end);
        printf("Digite o cidade do %do endereco: ", (i+1));
        scanf("%s", (*prt)[i].cidade);
        printf("Digite o estado do %do endereco: ", (i+1));
        scanf("%s", (*prt)[i].estado);
        printf("Digite o CEP do %do endereco: ", (i+1));
        scanf("%s", (*prt)[i].cep);
    }
}

int pesquisar(struct dados (*prt)[4]) {
    char nomeEndereco[30];
    printf("\nDigite o nome do endereco a ser pesquisado: ");
    scanf("%s", nomeEndereco);
    for(int i = 0; i<4; i++) {
        for (int j = 0;(*prt)[i].nome[j] != '\0' && nomeEndereco[j] != '\0'; j++) {
            if ((*prt)[i].nome[j] == nomeEndereco[i]){
                return i;
            }
        }
    }
    return -1;
}

void alterar(struct dados (*prt)[4]) {
    int filmePesquisado = pesquisar(prt);
    printf("\nDigite o nome do endereco: ");
    scanf("%s", (*prt)[filmePesquisado].nome);
    printf("Digite o endereço do endereco: ");
    scanf("%s", (*prt)[filmePesquisado].end);
    printf("Digite o cidade do endereco: ");
    scanf("%s", (*prt)[filmePesquisado].cidade);
    printf("Digite o estado do endereco: ");
    scanf("%s", (*prt)[filmePesquisado].estado);
    printf("Digite o CEP do endereco: ");
    scanf("%s", (*prt)[filmePesquisado].cep);
}

void imprimir(struct dados (*prt)[4]) {
    for(int i = 0; i<4; i++) {
        printf("\n%do endereco: \n\nNome: %s\nEndereço: %s\nCidade: %s\nEstado: %s\nCEP: %s\n", (i+1), (*prt)[i].nome, (*prt)[i].end, (*prt)[i].cidade, (*prt)[i].estado, (*prt)[i].cep);
    }
}

void exclui(struct dados (*prt)[4]) {
    int filmePesquisado = pesquisar(prt);
    (*prt)[filmePesquisado].nome[0] = '\0';
    (*prt)[filmePesquisado].end[0] = '\0';
    (*prt)[filmePesquisado].cidade[0] = '\0';
    (*prt)[filmePesquisado].estado[0] = '\0';
    (*prt)[filmePesquisado].cep[0] = '\0';
    printf("Excluído com sucesso.\n");
}

int main() {
    int x = 0;
    while (1) {
        struct dados endereco[4];
        struct dados (*prt)[4] = &endereco;
        int opcao, filmePesquisado;
        printf("Escolha uma opção:\n\n1- Registrar endereços\n2- Listar endereços\n3- Procurar registros\n4- Alterar registros\n5- Excluir registros\n6- Sair\n\n");
        scanf("%d", &opcao);
        
        switch (opcao) {

            case 1: registrar(prt);x++; break;
            case 2:
                if (x > 0) {
                    imprimir(prt);
                } else {
                    printf("Você não registrou nenhum filme.\n\n");
                }
                break;
            case 3: filmePesquisado = pesquisar(prt);
            if (filmePesquisado == -1){
                printf("Filme nao foi encontrado.\n");
            } else {
                printf("Nome: %s\nEndereço: %s\nCidade: %s\nEstado: %s\nCEP: %s\n", (*prt)[filmePesquisado].nome, (*prt)[filmePesquisado].end, (*prt)[filmePesquisado].cidade, (*prt)[filmePesquisado].estado, (*prt)[filmePesquisado].cep);
            }
            break;
            case 4: alterar(prt); break;
            case 5: exclui(prt); break;
            case 6: return 0;
            default: printf("Opção inválida");
        }
    }
}

#endif