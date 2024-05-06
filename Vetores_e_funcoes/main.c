#include <stdio.h>
#define exercicio_vetor

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