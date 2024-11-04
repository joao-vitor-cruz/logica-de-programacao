#include <stdio.h>
#define ex1

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
    
        printf("Digite um caractere: ");
        scanf("%c", pA);
        printf("Digite um numero inteiro: ");
        scanf("%d", pB);
        printf("Digite um numero inteiro longo: ");
        scanf("%ld", pC);
        printf("Digite um numero decimal: ");
        scanf("%f", pD);
        printf("Digite um numero decimal longo: ");
        scanf("%lf", pE);
        getchar();
        printf("Digite um caractere: ");
        scanf("%c", pF);
        printf("Digite um inteiro positivo: ");
        scanf("%u", pG);
        printf("Digite um inteiro positivo longo: ");
        scanf("%lu", pH);

        printf("\n        10        20        30        40        50        60        70\n");
        printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");
        printf("    %d                 %ld                %f     %lf          \n", B, C, D, E);
        printf("          %u        %lu         %c             %c \n", G, H, A, F);
        printf("\nVocê deseja repetir o programa?\nDigite 1 para repitir ou 0 para finalizar: ");
        scanf("%d", &x);
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

int comparacao() {
    for (i = 0; filmePesquisado[i] != '\0'; i++) {
        if (filmePesquisado[i] != filme1[i]) {
            break;
        }
    }
    if (filmePesquisado[i] == '\0' && filme1[i] == '\0')
        printf("%s\n%d unidade(s)\n", filme1, quantidade1);
}

int main() {
    printf("Digite a primeira palavra: ");
    gets(str1);
    printf("Digite a segunda palavra: ");
    gets(str2);
    
    comparacao();
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

#endif

#ifdef ex4
/*4 - Escreva um programa que receba via teclado numeros inteiros positivos usando
    ponteiros. Quando o numero digitado for negativo o programa deve parar e calcula
    a media dos valores digitados e mostrar o resultado. Todos os calculos devem ser
    feitos usando ponteiro.
*/

#endif

#ifdef ex5
/*5 - Com a estrutura abaixo, defina um vetor de estruturas de 4 elementos.
    Receba os dados via teclado numa funcao usando ponteiros. Imprima os dados
    recebidos no video numa usando ponteiros. Utilize um comando de loop. 
    O vetor de estruturas de ser declarado como variavel global
       estrutura: nome, end, cidade, estado, cep
*/

#endif

#ifdef ex6
/*6 - Escreva um programa com a estrutura abaixo. Receba 2 datas via teclado 
    usando ponteiros. Calcule e exiba o numero de dias entre as duas datas
    usando ponteiros. Utilize um vetor de estruturas.
    	estrutura: dia, mes e ano
*/

#endif
