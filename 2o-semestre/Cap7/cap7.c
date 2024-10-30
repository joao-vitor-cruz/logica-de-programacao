#include <stdio.h>
#include <stdlib.h>
#define ex3
 
#ifdef ex1
/*1 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    Receba dados via teclado em uma funcao e imprima estes conteudos no video,
    em outra funcao, no seguinte formato.
     estrutura: char, int, long, float, double, unsigned char, unsigned int,
                unsigned long
 
            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        int                 long                float     double          
              unsigned int        unsigned long       char      unsigned char
*/
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
 
    int main() {
        int x;
        do {
            struct dados membros;
        
            printf("Digite um caractere: ");
            scanf("%c", &membros.A);
            printf("Digite um numero inteiro: ");
            scanf("%d", &membros.B);
            printf("Digite um numero inteiro longo: ");
            scanf("%ld", &membros.C);
            printf("Digite um numero decimal: ");
            scanf("%f", &membros.D);
            printf("Digite um numero decimal longo: ");
            scanf("%lf", &membros.E);
            getchar();
            printf("Digite um caractere: ");
            scanf("%c", &membros.F);
            printf("Digite um inteiro positivo: ");
            scanf("%u", &membros.G);
            printf("Digite um inteiro positivo longo: ");
            scanf("%lu", &membros.H);

            printf("\n        10        20        30        40        50        60        70\n");
            printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");
            printf("    %d                 %ld                %f     %lf          \n", membros.B, membros.C, membros.D, membros.E);
            printf("          %u        %lu         %c        %c \n", membros.G, membros.H, membros.A, membros.F);
            printf("\nVocê deseja repetir o programa?\nDigite 1 para repitir ou 0 para finalizar: ");
            scanf("%d", &x);
            getchar();
        } while (x == 1);
        return 0;  
    }
 
#endif
 
#ifdef ex2
/*2 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
    estruturas de 4 elementos. Receba os dados pelo teclado em uma funcao
    e imprima-os no video em uma funcao. Utilize vetor de estruturas.
    Faca um menu com uma opcao para saida do programa.
        estrutura: nome, end, cidade, estado, cep */

struct dados {
    char nome[50];
    char end[60];
    char cidade[58];
    char estado[15];
    char cep[10];
};

struct dados endereco;

void receberDados() {
    printf("Digite seu nome: ");
    gets(endereco.nome);
    printf("Digite seu endereço: ");
    gets(endereco.end);
    printf("Digite sua cidade: ");
    gets(endereco.cidade);
    printf("Digite seu estado: ");
    gets(endereco.estado);
    printf("Digite seu CEP: ");
    gets(endereco.cep);
}

void imprimirDados() {
    printf("Seu nome é %s.\nSeu endereço é:\n%s\n%s\n%s\n%s\n", endereco.nome, endereco.end, endereco.cidade, endereco.estado, endereco.cep);
}

int main() {
    int x;
    do {
        receberDados();
        imprimirDados();
        printf("\nVocê deseja repetir o programa?\nDigite 1 para repitir ou 0 para finalizar: ");
        scanf("%d", &x);
        getchar();  
    } while (x == 1);
    return 0;
}

#endif

#ifdef ex3
/*3 - Escreva um programa com a estrutura de dados abaixo. Receba 2 datas via
    teclado na funcao main(). Faca uma funcao que calcule o numero de dias 
    entre elas e mostre o resultado no video na funcao main(). 
    Utilize vetor de estruturas.
                estrutura: dia, mes, ano
*/

struct dados {
    int dia;
    int mes;
    int ano;
};

struct dados data1;
struct dados data2;
// Cálculo errado
void calculoDatas() {
    int dias1 = data1.dia + (data1.mes * 30) + (data1.ano * 365);
    int dias2 = data2.dia + (data2.mes * 30) + (data2.ano * 365);

    dias1 > dias2 ? printf("O numero de dias entre as duas datas é: %d", (dias1 - dias2)) : printf("O numero de dias entre as duas datas é: %d", (dias2 - dias1));

}

int main() {
    int x;
    do {
        do {
            printf("Digite a primeira data:\nDia: ");
            scanf("%d", &data1.dia);
            if (data1.dia < 1 || data1.dia > 31) {
                printf("Dia inválido! Tente novamente\n");
            }
        } while (data1.dia < 1 || data1.dia > 31);

        do {
            printf("Mes: ");
            scanf("%d", &data1.mes);
            if (data1.mes < 1 || data1.mes > 12) {
                printf("Mes inválido! Tente novamente\n");
            }
        } while (data1.mes < 1 || data1.mes > 12);

        do {
            printf("Ano: ");
            scanf("%d", &data1.ano);
            if (data1.ano < 0) {
                printf("Ano inválido! Tente novamente\n");
            }
        } while (data1.ano < 0);

        do {
            printf("Digite a segunda data:\nDia: ");
            scanf("%d", &data2.dia);
            if (data2.dia < 1 || data2.dia > 31) {
                printf("Dia inválido! Tente novamente\n");
            }
        } while (data2.dia < 1 || data2.dia > 31);

        do {
            printf("Mes: ");
            scanf("%d", &data2.mes);
            if (data2.mes < 1 || data2.mes > 12) {
                printf("Mes inválido! Tente novamente\n");
            }
        } while (data2.mes < 1 || data2.mes > 12);

        do {
            printf("Ano: ");
            scanf("%d", &data2.ano);
            if (data2.ano < 0) {
                printf("Ano inválido! Tente novamente\n");
            }
        } while (data2.ano < 0);
        
        calculoDatas();

        printf("\nVocê deseja repetir o programa?\nDigite 1 para repitir ou 0 para finalizar: ");
        scanf("%d", &x);
        getchar();  
    } while (x == 1);
    return 0;
}
#endif

#ifdef ex4
/*4 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
    estrutura de 4 elementos. Receba dados via teclado e imprima-os no video.
    Faca um menu com as seguintes opcoes:
    1 - receber todos os dados
    2 - imprime todos os dados 
    3 - calcula o IMC de todas as pessoas. 
    4 - sair
        Calculo do IMC = peso/(altura*altura).
        estrutura: nome, peso, altura
    */
 
struct dados {
    char nome[30];
    float peso;
    float altura;
};
 
int main() {
    int x;
    struct dados imc[4];
    for(;;) {
        int opcao;
        printf("\nCalculador de IMC\n\n1 - receber todos os dados\n2 - imprime todos os dados \n3 - calcula o IMC de todas as pessoas. \n4 - sair\n\n");
        scanf("%d", &opcao);
 
        switch (opcao) {
            case 1:
            for (int i = 0; i < 4; i++) {
                getchar();
                printf("Digite os dados para o calculo %d de IMC:\nNome: ", i+1);
                gets(imc[i].nome);
                printf("Peso: ");
                scanf("%f", &imc[i].peso);
                printf("Altura: ");
                scanf("%f", &imc[i].altura);
            }
            break;
            case 2:
                for (int i = 0; i < 4; i++) {
                    printf("IMC %d:\nNome: %s\nPeso: %.2f\nAltura: %.2f\n\n", i+1, imc[i].nome, imc[i].peso, imc[i].altura);
                }
            break;
            case 3:
                for (int i = 0; i < 4; i++) {
                    printf("IMC %d (%s): %.2f\n\n", i+1, imc[i].nome, (imc[i].peso/(imc[i].altura*imc[i].altura)));
                }
                break;
            case 4:
                exit(0);
                break;
 
            default:
                printf("Opção inválida\n\n");
        }
    }
}
 
#endif