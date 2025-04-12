#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int eh_numero_automorfico(int n) {
    long long quadrado = (long long)n * n;

    int temp = n;
    int pot10 = 1;

    while (temp > 0) {
        pot10 *= 10;
        temp /= 10;
    }

    return (quadrado % pot10) == n;
}

int* buscar_automorficos(int limite, int* qtd_encontrados) {
    int* vetor = malloc(sizeof(int));
    int tamanho = 1;
    int count = 0;

    for (int i = 2; i <= limite; i++) {
        if (eh_numero_automorfico(i)) {
            if (count >= tamanho) {
                tamanho *= 2;
                vetor = realloc(vetor, tamanho * sizeof(int));
            }
            vetor[count++] = i;
        }
    }

    *qtd_encontrados = count;
    return vetor;
}

int main() {
    int n;
    printf("Digite o limite para buscar números automórficos: ");
    scanf("%d", &n);

    int qtd;
    int* automorficos = buscar_automorficos(n, &qtd);

    printf("\nNúmeros automórficos entre 2 e %d:\n", n);
    for (int i = 0; i < qtd; i++) {
        printf("%d ", automorficos[i]);
    }
    printf("\n");

    free(automorficos);
    return 0;
}
