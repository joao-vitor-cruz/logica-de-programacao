#include <stdio.h>
#define ex5

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
        
        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }
        
        if (a < b) {
            for (int i = (a + 1); i < b; i++) {
                soma += i;
            }    
        }
        
        printf("A soma dos N digitos entre %d e %d é: %d\n", a, b, soma);
    }
}

void negativos(int a, int b) {
    if (verificar(a) == 0 && verificar(b) == 0) {
        int multiplicacao = 1;
        
        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }

        for (int i = (a + 1); i < b; i++) {
            multiplicacao *= i;
        }
        
        printf("A multiplicação dos N dígitos entre %d e %d é: %d\n", a, b, multiplicacao);
    }
}

void diferentes(int a, int b) {
    if ((verificar(a) != verificar(b))) {
        float resultado = 0;
        
        if (a < b) {
            int temp = a;
            a = b;
            b = temp;
        }
        
        resultado = (float)a/b;
        printf("O resultado da divisão entre %d e %d é %.2f", a, b, resultado);
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
    diferentes (a, b);

    return 0;
}
#endif

#ifdef ex3
/*3 - Escreva um programa que receba na funcao main() 2 valores inteiro. Escreva
    uma funcao para cada operacoes aritmeticas e passe como parametro os 2
    valores recebidos na funcao main(). Retorne os resultados usando o comando
    return e imprima os 4 resultados no video na funcao main().
*/

int soma(int a, int b) {
    return a + b;
}

int subtracao(int a, int b) {
    return a - b;
}

int multiplicacao(int a, int b) {
    return a * b;
}

float divisao(int a, int b) {
    return (float)a / b;
}

int main() {
    int a, b;
    
    printf("Digite dois valores inteiros.\n");
    printf("Primeiro valor: ");
    scanf("%d", &a);
    printf("Segundo valor: ");
    scanf("%d", &b);
    printf("+: %d\n-: %d\n×: %d\n÷: %.1f\n", soma(a,b), subtracao(a,b), multiplicacao(a,b), divisao(a,b));
    
    return 0;
}
#endif

#ifdef ex4
/*4 - Reescreva o programa do exercicio anterior para receber via teclado n
    valores. Os n valores nao sao definidos previamente.
*/

int soma(int num, int resultado) {
    return resultado + num;
}

int subtracao(int num, int resultado) {
    return resultado - num;
}

int multiplicacao(int num, int resultado) {
    return resultado * num;
}

float divisao(int num, int resultado) {
    return (float)resultado / num;
}

int main() {
    int n, num, resultSoma, resultSubt, resultMult;
    float resultDiv;
    
    printf("Digite quantos números serão digitados: ");
    scanf("%d", &n); 
    
    for(int i = 0; i < n; i++){
        printf("Digite o %dº número: ", i+1);
        scanf("%d", &num);
        if (i == 0) {
            resultSoma = num;
            resultSubt = num;
            resultMult = num;
            resultDiv = (float)num;
            //printf("i = 0 / %d %d %d %.1f\n",resultSoma, resultSubt, resultMult, resultDiv);
        } else {
            resultSoma = soma(num, resultSoma);
            resultSubt = subtracao(num, resultSubt);
            resultMult = multiplicacao(num, resultMult);
            resultDiv = divisao(num, resultDiv);
            //printf("%d %d %d %.1f\n",resultSoma, resultSubt, resultMult, resultDiv);
        }
    }

    printf("+: %d\n-: %d\n×: %d\n÷: %.1f\n", resultSoma, resultSubt, resultMult, resultDiv);

    return 0;
}
#endif

#ifdef ex5
/*5 - Escreva um programa que receba n valores inteiros via teclado na funcao main().
    Faca uma calculadora com as 4 operacoes aritmeticas.(utilize o comando switch).
    As operacoes aritmeticas devem ser funcoes. O resultado acumulado deve ser 
    mostrado na funcao main().
*/

int soma(int num, int resultado) {
    return resultado + num;
}

int subtracao(int num, int resultado) {
    return resultado - num;
}

int multiplicacao(int num, int resultado) {
    return resultado * num;
}

float divisao(int num, int resultado) {
    return (float)resultado / num;
}

int main() {
    int n, num, resultSoma, resultSubt, resultMult;
    float resultDiv;
    
    while (1) {
        int i = 0;
        printf("Digite o %dº número: ", i+1);
        scanf("%d", &num);

        if (i == 0) {
            resultSoma = num;
            resultSubt = num;
            resultMult = num;
            resultDiv = (float)num;
            i++;
            //printf("i = 0 / %d %d %d %.1f\n",resultSoma, resultSubt, resultMult, resultDiv);
        } else {
            resultSoma = soma(num, resultSoma);
            resultSubt = subtracao(num, resultSubt);
            resultMult = multiplicacao(num, resultMult);
            resultDiv = divisao(num, resultDiv);
            //printf("%d %d %d %.1f\n",resultSoma, resultSubt, resultMult, resultDiv);
        }
    }

    printf("+: %d\n-: %d\n×: %d\n÷: %.1f\n", resultSoma, resultSubt, resultMult, resultDiv);

    return 0;
}

#endif
