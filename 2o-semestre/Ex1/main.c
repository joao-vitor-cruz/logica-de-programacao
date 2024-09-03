#include <stdio.h>
#define ex1

#ifdef ex1
/*1 - Escreva um programa que permute o conteúdo de duas variáveis sem utilizar uma
    variável auxiliar.*/
int main() {
    int num1, num2, verificador;
    
    printf("Digite dois números.\n");
    printf("Primeiro número: ");
    scanf("%d", &num1);
    printf("Segundo número: ");
    scanf("%d", &num2);
    printf("\nSeus números foram permutados:\nPrimeiro número pré permutação: %d\nSegundo número pré permutação: %d\n", num1, num2);
    
    num1 += num2;
    num2 = num1 - num2;
    num1 -= num2;
    
    printf("Primeiro número pós permutação: %d\nSegundo número pós permutação: %d\n", num1, num2);
    
    return 0;
}
#endif

#ifdef ex2
/*2 - Escreva um programa que receba dados via teclado para variaveis do tipo short,
    long, int, float, double e um char e imprima-os no video no seguinte
    formato:
            10        20        30        40        50        60
    12345678901234567890123456789012345678901234567890123456789012345
        short               long                int
                float               double              char*/

int main() {
    short num1;
    long num2;
    int num3;
    float num4;
    double num5;
    char letra;
    
    printf("Digite um número inteiro curto: ");
    scanf("%hd", &num1);
    printf("Digite um número inteiro longo: ");
    scanf("%ld", &num2);
    printf("Digite um número inteiro: ");
    scanf("%d", &num3);
    printf("Digite um número em ponto flutuante: ");
    scanf("%f", &num4);
    printf("Digite mais um número em ponto flutuante: ");
    scanf("%lf", &num5);
    
    while(getchar() != '\n');
    
    printf("Digite um caracter: ");
    scanf("%c", &letra);
    
    printf("\t10\t20\t30\t40\t50\t60\n");
    printf("1234567890123456789012345678901234567890123456789015\n");
    printf("\t%hd\t\t%ld\t\t%d\n", num1, num2, num3);
    printf("\t\t%.1f\t\t%.3lf\t\t%c\n", num4, num5, letra);
    
    return 0;
} 
#endif
#ifdef ex3
/*3 - Escreva um programa que receba via teclado um tempo em segundos e converta
    para horas, minutos e segundos.
    Ex.: recebe 3850 segundos que converte para 1h 4min 10s.*/
#endif
#ifdef ex4
/*4 - Faça um programa para ler um numero inteiro, positivo de tres digitos, e gerar
    outro número formado pelos dígitos invertidos do número lido.
    Ex:   NúmeroLido = 123
        NúmeroGerado = 321*/
#endif
#ifdef ex5
/*5 - Escreva um programa que determine o menor multiplo de um numero inteiro. Este
    multiplo deve ser maior que o limite minimo recebido. Recebe os 2 numeros via
    teclado.
    Ex: menor multiplo de 13 maior que 100. Resultado: 104.*/
#endif
