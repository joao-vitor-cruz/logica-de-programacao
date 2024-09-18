#include <stdio.h>
#define ex1

/* Duvidas:
precisa de setlocale?

*/
#ifdef ex1
/*1 - Escreva um programa para adivinhar um numero entre 1 e 99 que o usuario
    pensou. Digite via teclado os simbolos =, > ou < a cada pergunta. Utilize o
    comando if-else.*/

int main() {
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
    int x, verificador;
    int y = 0;
    int contador = 0;
    printf("Digite números inteiros positivos. Quando um número negativo for digitado, retornarei a média dos valores positivos digitados anteriormente.\n");
    
    while (1) {
       scanf("%d", &x);
        
        if (x >= 0) {
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
/*4 - Receba via teclado a distancia em km e a quantidade de litros de gasolina
    consumidos por um carro em um percurso.
    Calcule o consumo em km/l e escreva uma mensagem de acordo com a tabela 
    abaixo:
    CONSUMO (km/l) MENSAGEM
    menor que 8    Venda o carro!
    entre 8 e 14   Economico!
    maior que 14   Super economico!*/

int main() {
    float distancia, gasolina, consumo;
    
    printf("Digite respectivamente a distância que seu carro andou e quantos litros de gasolina foram gastos durante este percurso.\n");
    printf("Distância (em km):");
    scanf("%f", &distancia);
    printf("Gasolina (em L):");
    scanf("%f", &gasolina);
    
    consumo = distancia/gasolina;
    
    if (consumo < 8) {
        printf("Venda o carro!\n");
    } else if (consumo >= 8 && consumo <= 14) {
        printf("Economico!\n");
    } else if (consumo > 14) {
        printf("Super economico!\n");
    }
    return 0;
}
#endif

#ifdef ex5
/*5 - As ligacoes telefonicas são cobradas pela sua duracao. O sistema registra os
    instantes em que a ligacao foi iniciada e concluida.
    Escreva um programa que recebe via teclado dois instantes dados em
    horas, minutos e segundo e determina o intervalo de tempo
    (em horas, minutos e segundos) decorrido entre eles.*/

int main() {
    int horas1, minutos1, segundos1, horas2, minutos2, segundos2, peso1, peso2, horasR, minutosR, segundosR;
    printf("Digite o primeiro período:\n");
    printf("Hora(s): ");
    scanf("%d", &horas1);
    printf("Minuto(s): ");
    scanf("%d", &minutos1);
    printf("Segundo(s): ");
    scanf("%d", &segundos1);
    printf("\nDigite o segundo período:\n");
    printf("Hora(s): ");
    scanf("%d", &horas2);
    printf("Minuto(s): ");
    scanf("%d", &minutos2);
    printf("Segundo(s): ");
    scanf("%d", &segundos2);


    if (segundos1 >= 60) {
        minutos1 += segundos1/60;
        segundos1 %= 60;
    }
    if (minutos1 >= 60) {
        horas1 += minutos1/60;
        minutos1 %= 60;
    }

    if (segundos2 >= 60) {
        minutos2 += segundos2/60;
        segundos2 %= 60;
    }
    if (minutos2 >= 60) {
        horas2 += minutos2/60;
        minutos2 %= 60;
    }
    
    peso1 = horas1*3600 + minutos1*60 + segundos1;
    peso2 = horas2*3600 + minutos2*60 + segundos2;

    if (peso1 > peso2) {
        peso1 -= peso2;
        horasR = peso1/3600;
        peso1 %= 3600;
        minutosR = peso1/60;
        peso1 %= 60;
        segundosR = peso1;

        printf("O intervalo de tempo decorrido entre %dh %dmin %ds e %dh %dmin %ds foi %dh %dmin %ds", horas1, minutos1, segundos1, horas2, minutos2, segundos2, horasR, minutosR, segundosR);
    } else if (peso1 < peso2) {
        peso2 -= peso1;
        horasR = peso2/3600;
        peso2 %= 3600;
        minutosR = peso2/60;
        peso2 %= 60;
        segundosR = peso2;

        printf("O intervalo de tempo decorrido entre %dh %dmin %ds e %dh %dmin %ds foi %dh %dmin %ds", horas2, minutos2, segundos2, horas1, minutos1, segundos1, horasR, minutosR, segundosR);
    }
}

#endif
