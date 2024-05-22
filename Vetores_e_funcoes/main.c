#include <stdio.h>
#define exercicio_nota

#ifdef exercicio_funcao
float volume;

void Esfera(int raio) {
    volume = (4 * 3.14 * (raio * raio * raio)) / 3;
}

int main() {
    int raio;
    do {
        printf("Digite o valor do raio da esfera para o seu volume ser calculado.\n");
        scanf("%d", &raio);
        if (raio < 0) {
            printf("O valor do raio não pode ser negativo.\n");
        }
    } while (raio < 0);
    Esfera(raio);
    printf("O volume da esfera é igual a %.1f\n", volume);
    return 0;
}
#endif

#ifdef exercicio_vetor
int main(){
    int numeros[6], quantidadePar = 0, posiçãoPar[6];
    for (int i = 0; i < 6; i++) {
        printf("Digite o %dº número: ", i + 1);
        scanf("%d", &numeros[i]);
        if (numeros[i] % 2 == 0) {
            quantidadePar++;
            printf("O número %d, na posição %d, é par.\n", numeros[i], i + 1);
        }
    }
    printf("No total, tem %d números pares nesse conjunto.\n", quantidadePar);
    return 0;
}
#endif

#ifdef exercicio_nota
int vetorA[20], vetorB[20], vetorC[20], vetorD[20];
int x = 0, y = 0;

void Armazena_AB(int k) {
    for (int i=0; i < k; i++) {
        printf("Digite o %dº número do vetor A: ", i+1);
        scanf("%d", &vetorA[i]);
        if (vetorA[i]%2 == 0) {
            vetorD[x] = vetorA[i];
            x++;
        } else {
            vetorC[y] = vetorA[i];
            y++;
        }
    }

    for (int i=0; i < k; i++) {
        printf("Digite o %dº número do vetor B: ", i+1);
        scanf("%d", &vetorB[i]);
        if (vetorB[i]%2 == 0) {
            vetorD[x] = vetorB[i];
            x++;
        } else {
            vetorC[y] = vetorB[i];
            y++;
        }
    }
}

void Menor_Multiplo5() {
    int menorMultiplo = -1;
    for (int i = 0; i < x; i++) {
        if (vetorD[i] % 5 == 0) {
            if (menorMultiplo == -1 || vetorD[i] < menorMultiplo) {
                menorMultiplo = vetorD[i];
            }
        }
    }

    if (menorMultiplo == -1) {
        printf("\nNão há múltiplos de 5 no vetor D.\n");
    } else {
        printf("\nO menor múltiplo de 5 no vetor D é %d\n", menorMultiplo);
    }
}

void Media_Multiplos11() {
    int dividendo = 0, divisor = 0;
    for (int i = 0;i < y;i++) {
        if (vetorC[i] % 11 == 0) {
            dividendo += vetorC[i];
            divisor++;
        }
    }
    if (divisor == 0){
        printf("Não há múltiplos de 11 no vetor C.\n");
    } else {
        float divisao = dividendo/divisor;
        printf("A média dos múltiplos de 11 no vetor C é %.1f\n", divisao);
    }
}

int main() {
    int k;
    while (k<5 || k>20) {
        printf("Digite qual será o tamanho dos vetores (entre 5 e 20): ");
        scanf("%d", &k);
        if (k<5 || k>20) {
            printf("Valor inválido!\n");
        }
    }

    Armazena_AB(k);

    printf("\nValores do vetor A: ");
    for(int i = 0;i < k;i++){
            if (i > 0 && i < k) {
                printf(", ");
            }
        printf("%d", vetorA[i]);
    }

    printf("\nValores do vetor B: ");
    for(int i = 0;i < k;i++){
            if (i > 0 && i < k) {
                printf(", ");
            }
        printf("%d", vetorB[i]);
    }

    printf("\nValores do vetor C (ímpares): ");
    if (y == 0) {
        printf("Nenhum valor");
    } else {
        for(int i = 0;i < y;i++){
            if (i > 0 && i < y) {
                printf(", ");
            }
        printf("%d", vetorC[i]);
        }
    }

    printf("\nValores do vetor D (pares): ");
    if (x == 0) {
        printf("Nenhum valor");
    } else {
        for(int i = 0;i < x;i++){
            if (i > 0 && i < x) {
                printf(", ");
            }
        printf("%d", vetorD[i]);
        }
    }
    Menor_Multiplo5();
    Media_Multiplos11();
    return 0;
}
#endif