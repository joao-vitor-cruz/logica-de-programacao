#include <stdio.h>
#define ex1

#ifdef ex1
/*1 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faça uma
    funcao para compara-las e retorne como resultado se são IGUAIS 1 ou se
    DIFERENTES 0 para a funcao main(). Imprima o resultado na funcao main().
    (Declare os vetores como variavel global) (nao pode usar funcao de biblioteca)*/

char str1[11], str2[11];
void comparação() {
    if (str1[11] == str2[11]) {
        printf("1");
    } else {
        printf("0");
    }
}

int main() {
    printf("Digite duas strings de 10 caracteres\nPrimeira string: ");
    scanf("%10s", &str1[11]);
    printf("Segunda string: ");
    scanf("%10s", &str2[11]);
    comparação();
    return 0;
}
#endif

#ifdef ex2
/*2 - Escreva um programa para receber 5 nomes, com até 7 caracteres, via teclado
    e imprima-os no video no seguinte formato:(Declare os 5 vetores como variaveis
    globais)

            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      nome1                                   nome5
                nome2               nome4
                          nome3
*/

char nome1[8], nome2[8], nome3[8], nome4[8], nome5[8];

int main() {
    printf("Digite 5 nomes.\nPrimeiro nome: ");
    scanf("%7s", &nome1[0]);
    printf("Segundo nome: ");
    scanf("%7s", &nome2[0]);
    printf("Terceiro nome: ");
    scanf("%7s", &nome3[0]);
    printf("Quarto nome: ");
    scanf("%7s", &nome4[0]);
    printf("Quinto nome: ");
    scanf("%7s", &nome5[0]);
    printf("        10        20        30        40        50\n");
    printf("12345678901234567890123456789012345678901234567890\n");
    printf("  %7s                                   %7s\n", nome1, nome5);
    printf("            %7s               %7s\n", nome2, nome4);
    printf("                      %7s\n", nome3);
    return 0;
}
#endif

#ifdef ex3
/*3 - Escreva um programa que receba uma string na funcao main(). Faca uma funcao que
    calcula o comprimento de uma string recebida via teclado. Mostre o valor do
    comprimento na funcao main().
    (Declare o vetor como variavel global) (nao pode usar funcao de biblioteca)*/

char str[11];

void comprimento(int contador) {
    for (int i = 0; ;i++) {
        if (str[i] == '\0') {
            printf("%d", contador);
            break;
        } else {
            contador++;
        }
    }
}
int main() {
    int contador;
    
    printf("Digite uma palavra com no máximo 10 letras: ");
    scanf("%10s", &str[0]);
    comprimento(contador);
    return 0;
}
#endif

#ifdef ex4
/*4 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
    para letras maiusculas. (nao pode usar funcao de biblioteca)*/

int main() {
    char str[11];

    printf("Digite uma palavra de 10 dígitos e eu a retornarei maiúscula.\n");
    scanf("%10s", &str[0]);

    for (int i = 0;str[i] != '\0'; i++)
        str[i] = str[i] & 0xDF;

    printf("%s", str);
}
#endif

#ifdef ex5
/*5 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
    para letras minusculas. (nao pode usar funcao de biblioteca)*/
int main() {
    char str[11];

    printf("Digite uma palavra de 10 dígitos e eu a retornarei minúscula.\n");
    scanf("%10s", &str[0]);

    for (int i = 0;str[i] != '\0'; i++)
        str[i] = str[i] | 0x20;

    printf("%s", str);
}
#endif
