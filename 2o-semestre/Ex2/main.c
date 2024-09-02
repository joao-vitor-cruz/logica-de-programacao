#include <stdio.h>
#include <locale.h>
#define ex1
/*1 - Escreva um programa para adivinhar um numero entre 1 e 99 que o usuario
    pensou. Digite via teclado os simbolos =, > ou < a cada pergunta. Utilize o
    comando if-else.*/
#ifdef ex1
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

