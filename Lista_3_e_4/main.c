#include <stdio.h>
#include <stdlib.h>
#include <math.h>
<<<<<<< HEAD
#define exercicio2b
=======
#define exercicio3
>>>>>>> 7c96201 (Exercício 3 adicionado)

#ifdef exercicio1a
int main() {
   int k;
   int multiplo = 3;
   printf("Digite um número x e eu mostrarei uma sequência com x mútilplos de 3\n");
   scanf("%d", &k);
   for (int i; i < k; i++) {
      printf("%d. %d\n", i + 1, multiplo);
      multiplo = multiplo + 3;
   }
   return 0;
}
#endif

#ifdef exercicio1b
int main() {
   int k;
   int multiplo = 4;
   printf("Digite um número x e eu mostrarei uma sequência com x mútilplos de 1/2\n");
   scanf("%d", &k);
   for (int i; i < k; i++) {
      printf("%d. 1/%d\n", i + 1, multiplo);
      multiplo = multiplo + 4;
   }
   return 0;
}
#endif

#ifdef exercicio2a
int main() {
   int k;
   int multiplo1 = 2;
   int multiplo2 = 5;
   printf("Digite um número x e eu vou multiplicar 2/5 por 2 x vezes\n");
   scanf("%d", &k);
   for (int i = 0; i < k; i++) {
      printf("%d. %d/%d\n", i + 1, multiplo1, multiplo2);
      multiplo1 = multiplo1 + 2;
      multiplo2 = multiplo2 + 5;
   }
   return 0;
}
#endif

#ifdef exercicio2b
int main() {
   int k, x = 2, multiplo1, multiplo2 = 8;
   do {
      printf("Digite um número x e eu vou mostrar x números de uma sequência.\n");
      scanf("%d", &k);
      if(k <= 0) {
         printf("Digite um número válido!\n");
      }
   } while (k <= 0);
   for (int i = 0; i < k; i++) {
      multiplo1 = x * x;
      if (multiplo1 % multiplo2 == 0) {
         printf("%d. %d\n", i + 1, multiplo1 / multiplo2);
      } else {
         printf("%d. %d/%d\n", i + 1, multiplo1, multiplo2);
      }
         multiplo2 = multiplo2 + 8;
         x = x + 2;
      }
   return 0;
}
<<<<<<< HEAD
=======
#endif

#ifdef exercicio3
int main() {
   int k = 0, idade[2];
   idade[0] = -1;
   idade[1] = 0;
   while (k <= 0) {
      printf("Digite quantos indivíduos o programa somará a idade\n");
      scanf("%d", &k);

      if (k <= 0) {
         printf("Digite um número maior que 0.\n");
      }
   }

   for (int i = 0; i < k; i++) {
      while(idade[0] < 0) {
         printf("Digite a idade do indivídio %d: ", i + 1);
         scanf("%d", &idade[0]);
         if (idade[0] < 0) {
            printf("Digite uma idade válida!\n");
         } else {
            idade[1] += idade[0];
         }
      }
      idade[0] = -1;
   }

   printf("A soma das idades dos %d indivíduos é %d", k, idade[1]);
   return 0;
}
>>>>>>> 7c96201 (Exercício 3 adicionado)
#endif