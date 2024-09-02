#include <stdio.h>
#include <locale.h>
#define ex1

#ifdef ex1
/*1 - Escreva um programa para adivinhar um numero entre 1 e 99 que o usuario
    pensou. Digite via teclado os simbolos =, > ou < a cada pergunta. Utilize o
    comando if-else.*/

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8"); 
    
	int x = 50;
	int min = 1;
	int max = 100;
	char resposta;

	printf("Irei adivinhar o número que você pensar. Um número será mostrado a seguir, escreva >, < ou = para indicar o quão próximo o número mostrado está do seu.\n");

	while (1) {
		printf("O número é %d.\n", x);
		scanf(" %c", &resposta);

		if (resposta == '>') {
			min = x + 1;
			x = (x + max) / 2;
		} else if (resposta == '<') {
			max = x - 1;
			x = (min + x) / 2;
		} else if (resposta == '=') {
			printf("Adivinhei!! O número é %d!\n", x);
			break;
		} else {
			printf("Valor inválido, digite novamente.\n");
		}
	}

		return 0;
	}
#endif

#ifdef ex2
/*2 - Reescreva o programa do exercicio anterior agora utilizando o comando switch.
    Conte o n. de tentativas e imprima o resultado no video.*/

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8"); 
    
	int x = 50;
	int min = 1;
	int max = 100;
	char resposta;

	printf("Irei adivinhar o número que você pensar. Um número será mostrado a seguir, escreva >, < ou = para indicar o quão próximo o número mostrado está do seu.\n");

	while (1) {
		printf("O número é %d.\n", x);
		scanf(" %c", &resposta);
        
        switch (resposta) {
            case '>': 
            {
                min = x + 1;
			    x = (x + max) / 2;
			    break;
            }
            
            case '<':
            {
                max = x - 1;
                x = (min + x)/2;
                break;
            }
            
            case '=':
            {
                printf("Adivinhei!! O número é %d!\n", x);
                return 0;
            }
            
            default:
            {
                printf("Valor inválido, digite novamente");
            }
        }
	}
}
#endif

#ifdef ex3
/*3 - Escreva um programa que receba via teclado numeros inteiros positivos.
    Quando o numero digitado for negativo o programa deve parar e calcula a
    media dos valores positivos digitados.*/

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    int x, verificador;
    int y = 0;
    int contador = 0;
    printf("Digite números inteiros positivos. Quando um número negativo for digitado, retornarei a média dos valores positivos digitados anteriormente.\n");
    
    while (1) {
        verificador = scanf("%d", &x);
        
        if (verificador != 1) {
            while (getchar() != '\n');
            printf("Você não digitou um número. Tente novamente.\n");
            continue;
        } else if (x >= 0) {
            y += x;
            contador++;
        } else if (x < 0) {
            if (contador == 0) {
                printf("Não foi digitado nenhum valor positivo.\n");
            } else {
                printf("A média dos valores digitados anteriormente é: %.2f\n", (float)y/contador);
            return 0;
            }
        }
    }
}
#endif

#ifdef ex4

#endif

#ifdef ex5

#endif
