#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define exercicio1a

//Lista 1A
#ifdef exercicio1a
//1. Receba três números que garantam a existência de uma equação do 2º grau. Se houver raízes reais exiba-as, caso contrário informe ao usuário.

int main(){
    int a, b, c, delta;
    float x1, x2;
    printf("Digite três números inteiros para o cálculo de uma operação de segundo grau, onde os números digitados serão respectivamente A, B e C \n(A tem que ser diferente de 0)\n");
    scanf("%d %d %d", &a, &b, &c);
    while (a == 0){
        printf("O número designado para A é inválido, tente outro: ");
        scanf("%d", &a);
    }

    delta = (b * b) - (4 * a * c);

    if(delta < 0) {
        printf("A equação não retornou raízes reais.\n");
    } else if(delta == 0) {
        x1 = (-b + sqrt(delta))/(2*a);
        printf("A raíz retornada é %.1f\n", x1);
    } else {
        x1 = (-b - sqrt(delta))/(2*a);
        x2 = (-b + sqrt(delta))/(2*a);
        printf("As raízes retornadas são %.1f e %.1f\n", x1, x2);
    }
    // x1 = -b - raiz(b^2 - 4.a.c)/2.a
    // x2 = -b + raiz(b^2 - 4.a.c)/2.a
    return 0;
}
#endif

#ifdef exercicio2a
//2. - A FATEC RUBENS LARA faz o pagamento de seus professores por hora/aula. Faça um algoritmo que calcule e exiba o salário de um professor. Sabe-se que o valor da hora/aula segue a tabela abaixo: Professor Nível 1 R$55,00 por hora/aula Professor Nível 2 R$67,00 por hora/aula Professor Nível 3 R$78,00 por hora/aula.

int main(){
    int nivel = 0, aula;
    float hora, horaPorAula, salario;
    printf("Para realizar o cálculo do seu salário, insira quantas horas você trabalhou esse mês: ");
    scanf ("%f", &hora);
    printf("Insira quantas aulas foram dadas esse mês: ");
    scanf ("%d", &aula);
    horaPorAula = hora/aula;
    while (nivel == 0){
        printf("Digite em qual nível você está.\nOpções válidas: 1, 2 ou 3\n");
        scanf ("%d", &nivel);
        switch (nivel) {
        case 1:
            salario = horaPorAula * 55;
            break;
        case 2:
            salario = horaPorAula * 67;
            break;
        case 3: 
            salario = horaPorAula * 78;
            break;
        default:
            printf("Válor inválido!\n");
            nivel = 0;
            break;
        }
    }
    printf("Seu salário é de R$ %.2f", salario);
    return 0;
}
#endif


//Lista 1B
#ifdef exercicio1b
int main() {
    int x;
    printf("digite um número e eu direi seu antecessor e seu sucessor\n");
    scanf("%d", &x);
    printf("Antecessor: %d, Sucessor %d\n", x-1, x+1); 
    return 0;
} 
#endif

#ifdef exercicio2b
int main() {
    int numero;
    printf("digite um número\n");
    scanf("%d", &numero);
    if (numero > 0)
    {
        printf("esse número é positivo\n");    
     } else if(numero < 0) {
        printf("esse número é negativo\n");
     } else {
        printf("Esse número é zero\n");
     }
    return 0;
}
#endif

#ifdef exercicio3b
/* codigo original
int main() {
    int nota1, nota2, nota3, nota4;
    printf("Digite a nota da primeira prova.\n");
    scanf("%d", &nota1);
    printf("Digite a nota da segunda prova.\n");
    scanf("%d", &nota2);
    printf("Digite a nota da terceira prova.\n");
    scanf("%d", &nota3);
    printf("Digite a nota da quarta prova.\n");
    scanf("%d", &nota4);
    
    int media = (nota1 + nota2 + nota3 + nota4)/4;

    if(media >= 6){
        printf("Aprovado com média %d", media);
    } else {
        printf("Reprovado com média %d", media);
    } 
    return 0;
}

*/
// codigo cm ajuda do gpt

int main() {
    int nota[4];
    for(int i = 0; i < 4; i++) {
    printf("Digite a nota da prova %d.\n", i + 1);
    scanf("%d", &nota[i]);
    }
    int media = (nota[0] + nota[1] + nota[2] + nota[3])/4;

    if(media >= 6){
        printf("Aprovado com média %d", media);
    } else {
        printf("Reprovado com média %d", media);
    } 
    return 0;
}
#endif

#ifdef exercicio4b
void checarResto(int resto) {
    if(resto == 0){
        printf("os números são múltiplos\n");
    } else {
        printf("os números não são múltiplos\n");
    }
}

int main() {
    int x, y, resto;

    printf("Me fale dois números\n");
    scanf("%d\n %d", &x, &y);
    if(x > y) {
        resto = x % y;
        checarResto(resto);
    } else if(x < y) {
        resto = y % x;
        checarResto(resto);
    } else {
        printf("os números são iguais\n");
    }
    return 0;
}
#endif

#ifdef exercicio5b
int main() {
    int x, y, resto1, resto2;
    printf("Digite dois números\n");
    scanf("%d %d", &x, &y);
    resto1 = x % 2;
    resto2 = y % 2;
    if(resto1 == 0 && resto2 == 0) {
        printf("os números são pares\n");
    } else if(resto1 != 0 && resto2 != 0) {
        printf("os números são impares\n");
    } else {
        printf("um é par e outro é ímpar\n");
    }
    return 0;
}
#endif

#ifdef exercicio6b

void mensagemNumero(int numero) {
    printf("o número maior é %d", numero);
}

int main(){
    int x, y;
    printf("Digite dois número e o maior será mostrado\n");
    scanf("%d %d", &x, &y);
    if(x > y){
        mensagemNumero(x);
    } else if(y > x) {
        mensagemNumero(y);
    } else {
        printf("os números são iguais\n");
    }
    return 0;
}
#endif

#ifdef exercicio7b
int main(){
    int sexo = 0;
    float pesoIdeal, altura = 0;

    while (altura < 0.81) {
        printf("Vamos calcular o seu peso ideal! Digite sua altura: ");
        scanf("%f", &altura);
        if (altura < 0.81) {
            printf ("Insira uma altura válida!\n");
        }
    }
    while (sexo == 0) {
        printf("Para finalizar, precisamos saber qual é seu sexo. (digite 1 para masculino ou 2 para feminino): ");
        scanf("%d", &sexo);
    
        if (sexo == 1) {
            pesoIdeal = (72.7 * altura) - 58;
        } else if (sexo == 2) {
            pesoIdeal = (62.1 * altura) - 44.7;
        } else {
            printf("escolha um número válido!\n");
            sexo = 0;
        }
    }
    printf ("seu peso ideal é: %.2f kg", pesoIdeal);
    return 0;
}
#endif