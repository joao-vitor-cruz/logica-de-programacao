#include <stdio.h>
#define ex1

#ifdef ex1
/*1 - Escreva um programa que receba um numero N via teclado. Escreva uma funcao
    que retorne a soma dos algarismos do resultado de N!. O resultado deve ser
    mostrado na funcao main().
    Ex: se N = 4, N! = 24. Logo, a soma de seus algarismos e� 2 + 4 = 6.*/

int calculoFatorial(int n) {
    int aux = 0;
    int fat = 1;
    
    printf("O fatorial de %d", n);
    
    while (n>1) {
        fat *= n;
        n--;
    }
    
    printf(" é %d", fat);
    
    do {
        aux = aux + (fat%10);
        fat = fat/10;
    } while (fat>0);

    return aux;
}

int main() {
    int num = 0;
    printf("Digite um número: ");
    scanf("%d", &num);
    printf("\nA soma dos dígitos do fatorial deste número é: %d", calculoFatorial(num));
    return 0;
    }
#endif

#ifdef ex2
/*2 - Escreva um programa que receba dois numeros inteiros e execute as seguintes
    funçoes:
    - Verificar se o numero digitado e' positivo ou negativo. Sendo que o valor de
      retorno sera' 1 se positivo, 0 se negativo ou -1 se for igual a 0.
    - Se os 2 numeros sao positivos, retorne a soma dos N numeros existentes entre
      eles.
    - Se os 2 numeros sao negativos, retorne a multiplicacao dos N numeros existente
      entre eles.
    - Se 1. numero for positivo e o 2. negativo faca a divisao entre eles.*/

int verificar(int n) {
    if (n > 0) {
        return 1;
    } else if (n < 0) {
        return 0;
    } else {
        return -1;
    }
}

void positivos(int a, int b) {
    if (verificar(a) == 1 && verificar(b) == 1) {
        int soma = 0;
        printf ("A soma dos N digitos entre %d e %d ", a, b);
        if (a < b) {
            for (int i = a; i < (b - 1); i++) {
                soma += (a + 1);
                a++;
            }    
        } else if (a > b) {
            for (int i = b; i < (a - 1); i++) {
                soma += (b + 1);
                b++;
            }
        }
        printf("é: %d", soma);
    }
}

void negativos(int a, int b) {
    if (verificar(a) == 0 && verificar(b) == 0) {
        int multiplicacao = 1;
        printf ("A multiplicação dos N digitos entre %d e %d ", a, b);
        
        if (a > b) {
            for (int i = a; i > (b); i--) {
                printf("%d", a+1);
                multiplicacao *= (a + 1);
                a++;
            }    
        } else if (a < b) {
            for (int i = b; i < (a - 1); i++) {
                multiplicacao *= (b + 1);
                b++;
            }
        }
        
        printf("é: %d", multiplicacao);
    }
    
}

int main() {
    int a, b;
    printf("Digite dois números inteiros.\n");
    printf("Primeiro número: ");
    scanf("%d", &a);
    printf("Segundo número: ");
    scanf("%d", &b);
    positivos(a, b);
    negativos(a, b);
    
    return 0;
}
#endif
