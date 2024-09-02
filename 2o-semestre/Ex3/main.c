#include <stdio.h>
#define ex1

#ifdef ex1
/*1 - Escreva um programa que receba um numero N via teclado. Escreva uma funcao
    que retorne a soma dos algarismos do resultado de N!. O resultado deve ser
    mostrado na funcao main().
    Ex: se N = 4, N! = 24. Logo, a soma de seus algarismos e� 2 + 4 = 6.*/

int calculoFatorial(int num) {
    int fatorial = 1;
    int resultado = 0;
    int x;
    int decimal = 10000;
    for (int i = 0; i < num; i++) {
        fatorial =+ fatorial * (i+1);
    }

    while (decimal > 1) {
    x = fatorial/decimal;
    resultado =+ x;
    fatorial =- x*decimal - fatorial;
    decimal /= 10;
    printf("resultado: %d, decimal: %d, fatorial: %d\n", resultado, decimal, fatorial);
    }

    return resultado;
}
int main() {
    int num = 0;
    printf("Digite um número de 1 a 8: ");

    while (num < 1 || num > 8) {
        scanf("%d", &num);
        if (num < 1 || num > 8) {
            printf("Valor inválido!\n");
        }
    }

    printf("\nA soma dos dígitos do fatorial deste número é: %d", calculoFatorial(num));
    return 0;
    }
#endif
