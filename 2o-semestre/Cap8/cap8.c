#include <stdio.h>
#define ex6

#ifdef ex1
/*1 - Escreva um programa que receba via teclado usando ponteiros um char,
    int, long, unsigned, float, double, unsigned long e unsigned char,
    e imprima-os no video utilizando ponteiros no seguinte formato:

            10        20        30        40        50        60
    123456789012345678901234567890123456789012345678901234567890
        int                 long                unsigned
                  float               double              char
             unsigned long       unsigned char
*/
int main() {
    int x;
    do {
        char A;
        int B;
        long C;
        float D;
        double E;
        unsigned char F;
        unsigned int G;
        unsigned long H;
        
        char *pA = &A;
        int *pB = &B;
        long *pC = &C;
        float *pD = &D;
        double *pE = &E;
        unsigned char *pF = &F;
        unsigned int *pG = &G;
        unsigned long *pH = &H;
    
        printf('Digite um caractere: ');
        scanf('%c', pA);
        printf('Digite um numero inteiro: ');
        scanf('%d', pB);
        printf('Digite um numero inteiro longo: ');
        scanf('%ld', pC);
        printf('Digite um numero decimal: ');
        scanf('%f', pD);
        printf('Digite um numero decimal longo: ');
        scanf('%lf', pE);
        getchar();
        printf('Digite um caractere: ');
        scanf('%c', pF);
        printf('Digite um inteiro positivo: ');
        scanf('%u', pG);
        printf('Digite um inteiro positivo longo: ');
        scanf('%lu', pH);

        printf('\n        10        20        30        40        50        60        70\n');
        printf('1234567890123456789012345678901234567890123456789012345678901234567890\n');
        printf('    %d                 %ld                %f     %lf          \n', B, C, D, E);
        printf('          %u        %lu         %c             %c \n', G, H, A, F);
        printf('\nVocê deseja repetir o programa?\nDigite 1 para repitir ou 0 para finalizar: ');
        scanf('%d', &x);
        getchar();
    } while (x == 1);
    return 0;  
}

#endif

#ifdef ex2
/*2 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faça uma
    funcao para compara-las usando ponteiros e retorne como resultado se 
    sao IGUAIS 1 ou se sao DIFERENTES 0 para a funcao main(). 
    Imprima o resultado na funcao main(). Declare os vetores como variavel global
*/
char str1[11];
char str2[11];
char *pStr1 = &str1;
char *pStr2 = &str2;

int comparacao() {
    int i;
    for (i = 0; pStr1[i] != '\0'; i++) {
        if (pStr1[i] != pStr2[i]) {
            break;
        }
    }

    if (pStr1[i] == '\0' && pStr2[i] == '\0') {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int x;
    do{
        printf('Digite a primeira palavra: ');
        gets(str1);
        printf('Digite a segunda palavra: ');
        gets(str2);
        
        printf('%d', comparacao());
        printf('\nVocê deseja repetir o programa?\nDigite 1 para repitir ou 0 para finalizar: ');
        scanf('%d', &x);
        getchar();
    } while (x == 1);
    return 0;  
}
#endif
#ifdef ex3
/*3 - Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva 
    uma funcao que pesquise se esta letra existe no vetor abaixo usando ponteiros. 
    Imprima o resultado da pesquisa no video na funcao main(). Passe como informacao
    para a funcao a letra digitada usando ponteiros.(utilize o comando return). 
    O vetor deve ser declarado como variavel global.

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y
  */

 char vetor[] = {'b','d','f','h','j','k','m','o','q','s','u','w','y'};

int pesquisa(char *pLetra) {
    for (int i = 0; i < 13; i++) {
        if (vetor[i] == *pLetra) {
            return 1;
        }
    }
    return 0;
}

 int main() {
    int x;
    do {
        char letra;
        char *pLetra = &letra;
        printf("Digite uma letra: ");
        scanf("%c", pLetra);
        pesquisa(pLetra) == 1 ? printf("A letra está no vetor.") : printf("A letra não está no vetor");
        printf("\n\nVocê deseja repetir o programa?\nDigite 1 para repitir ou 0 para finalizar: ");
        scanf("%d", &x);
        getchar();
    } while (x==1);
    return 0;
 }

#endif

#ifdef ex4
/*4 - Escreva um programa que receba via teclado numeros inteiros positivos usando
    ponteiros. Quando o numero digitado for negativo o programa deve parar e calcula
    a media dos valores digitados e mostrar o resultado. Todos os calculos devem ser
    feitos usando ponteiro.
*/
int main() {
    int x;
    do {
        int a = 0;
        int soma = 0;
        int contador = 0;
        int *pA = &a;
        int *pSoma = &soma;
        int *pContador = &contador;

        printf("Digite numeros e quando o numero digitado for negativo a media deles sera calculada.\n");

        while (*pA >= 0) {
            printf("Digite um numero: ");
            scanf("%d", pA);
            if (*pA >= 0) {
                *pSoma += *pA;
                *pContador += 1;
            } else {
                printf("A media dos numeros e: %.2f\n", (float)*pSoma / *pContador);
            }
        }

        printf("\n\nVocê deseja repetir o programa?\nDigite 1 para repitir ou 0 para finalizar: ");
        scanf("%d", &x);
        getchar();
    } while (x==1);
}
#endif

#ifdef ex5
/*5 - Com a estrutura abaixo, defina um vetor de estruturas de 4 elementos.
    Receba os dados via teclado numa funcao usando ponteiros. Imprima os dados
    recebidos no video numa usando ponteiros. Utilize um comando de loop. 
    O vetor de estruturas de ser declarado como variavel global
       estrutura: nome, end, cidade, estado, cep
*/

struct dados {
    char nome[50];
    char end[60];
    char cidade[58];
    char estado[15];
    char cep[10];
};

struct dados endereco[4];
struct dados (*pEndereco)[4] = &endereco;

void receberDados() {
    for (int i = 0; i < 4; i++){
        printf("Digite seu nome: ");
        scanf("%s", (*pEndereco+i)->nome);
        printf("Digite seu endereço: ");
        scanf("%s", (*pEndereco+i)->end);
        printf("Digite sua cidade: ");
        scanf("%s", (*pEndereco+i)->cidade);
        printf("Digite seu estado: ");
        scanf("%s", (*pEndereco+i)->estado);
        printf("Digite seu CEP: ");
        scanf("%s", (*pEndereco+i)->cep);
    }
}

void imprimirDados() {
    for (int i = 0; i < 4; i++){
        printf("Seu nome é %s.\nSeu endereço é:\n%s\n%s\n%s\n%s\n", endereco[i].nome, endereco[i].end, endereco[i].cidade, endereco[i].estado, endereco[i].cep);
    }
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

#ifdef ex6
/*6 - Escreva um programa com a estrutura abaixo. Receba 2 datas via teclado 
    usando ponteiros. Calcule e exiba o numero de dias entre as duas datas
    usando ponteiros. Utilize um vetor de estruturas.
    	estrutura: dia, mes e ano
*/
struct dados {
    int dia;
    int mes;
    int ano;
};


int diasNoMes(int mes, int ano) {
    if (mes == 0) {
        return 0;
    }
    if (mes == 2) {
        return ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) ? 29 : 28;
    }
    return (mes == 4 || mes == 6 || mes == 9 || mes == 11) ? 30 : 31;
}

void calculoDatas(struct dados *prt1, struct dados *prt2) {
    int dias1 = 0, dias2 = 0, ano1 = 0, ano2 = 0, mes1 = 0, mes2 = 0, dia1 = 0, dia2 = 0;

    //Soma de dias do ano da data1 e 2
    for (int i = 1; i <= (*prt1).ano; i++) {
        if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
            dias1 += 366;
            ano1 += 366;
        } else {
            dias1 += 365;
            ano1 += 365;
        }
    }
    


    for (int i = 1; i <= (*prt2).ano; i++) {
        if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
            dias2 += 366;
            ano2 += 366;
        } else {
            dias2 += 365;
            ano2 += 365;
        }
    }

    //Soma de dias do mes da data1 e 2
    for (int i = 0; i < (*prt1).mes; i++) {
        dias1 += diasNoMes((i), (*prt1).ano);
        mes1 += diasNoMes((i), (*prt1).ano);
    }

    for (int i = 0; i < (*prt2).mes; i++) {
        dias2 += diasNoMes((i), (*prt2).ano);
        mes2 += diasNoMes((i), (*prt2).ano);
    }

    //Testes
    dia1 = (*prt1).dia;
    dias1 += (*prt1).dia;
    dia2 = (*prt2).dia;
    dias2 += (*prt2).dia;
    // printf("dias1 = %d, dias 2 = %d\nmes1 = %d, mes2 = %d\nano1 = %d, ano2 = %d\ndata total1 = %d, data total2 = %d\n", dia1, dia2, mes1, mes2, ano1, ano2, dias1, dias2);
    dias1 > dias2 ? printf("O numero de dias entre as duas datas é: %d", (dias1 - dias2)) : printf("O numero de dias entre as duas datas e: %d\n", (dias2 - dias1));

}

int main() {
    int x;
    do {
        struct dados data1;
        struct dados *prt1 = &data1;
        struct dados data2;
        struct dados *prt2 = &data2;

        do {
            printf("Digite a primeira data:\nDia: ");
            scanf("%d", &(*prt1).dia);
            if (data1.dia < 1 || data1.dia > 31) {
                printf("Dia inválido! Tente novamente\n");
            }
        } while (data1.dia < 1 || data1.dia > 31);

        do {
            printf("Mes: ");
            scanf("%d", &(*prt1).mes);
            if (data1.mes < 1 || data1.mes > 12) {
                printf("Mes inválido! Tente novamente\n");
            }
        } while (data1.mes < 1 || data1.mes > 12);

        do {
            printf("Ano: ");
            scanf("%d", &(*prt1).ano);
            if (data1.ano < 0) {
                printf("Ano inválido! Tente novamente\n");
            }
        } while (data1.ano < 0);

        do {
            printf("Digite a segunda data:\nDia: ");
            scanf("%d", &(*prt2).dia);
            if (data2.dia < 1 || data2.dia > 31) {
                printf("Dia inválido! Tente novamente\n");
            }
        } while (data2.dia < 1 || data2.dia > 31);

        do {
            printf("Mes: ");
            scanf("%d", &(*prt2).mes);
            if (data2.mes < 1 || data2.mes > 12) {
                printf("Mes inválido! Tente novamente\n");
            }
        } while (data2.mes < 1 || data2.mes > 12);

        do {
            printf("Ano: ");
            scanf("%d", &(*prt2).ano);
            if (data2.ano < 0) {
                printf("Ano inválido! Tente novamente\n");
            }
        } while (data2.ano < 0);
        
        calculoDatas(prt1, prt2);

        printf("\nVocê deseja repetir o programa?\nDigite 1 para repitir ou 0 para finalizar: ");
        scanf("%d", &x);
        getchar();  
    } while (x == 1);
    return 0;
}

#endif
