#include <stdio.h>

#define TAM 19 

long long int fatorial(int n) {
    long long int res = 1;
    for (int i = 2; i <= n; i++)
        res *= i;
    return res;
}

long long int fatorial_duplo(int n) {
    long long int res = 1;
    for (int i = n; i >= 1; i -= 2)
        res *= i;
    return res;
}

int main() {
    long long int fatoriais_normais[TAM];
    long long int fatoriais_duplos[TAM];
    int numeros[TAM];
    int i;
    FILE *arquivo;

    for (i = 0; i < TAM; i++) {
        numeros[i] = i + 2;
        fatoriais_normais[i] = fatorial(numeros[i]);
        fatoriais_duplos[i] = fatorial_duplo(numeros[i]);
    }

    printf("Tabela 1 - Fatorial Normal e Fatorial Duplo\n");
    printf("N\tFatorial\tFatorial Duplo\n");
    for (i = 0; i < TAM; i++) {
        printf("%d\t%lld\t%lld\n", numeros[i], fatoriais_normais[i], fatoriais_duplos[i]);
    }

    printf("\nTabela 2 - Com Diferença\n");
    printf("N\tFatorial\tFatorial Duplo\tDiferença\n");
    for (i = 0; i < TAM; i++) {
        long long int dif = fatoriais_normais[i] - fatoriais_duplos[i];
        printf("%d\t%lld\t%lld\t%lld\n", numeros[i], fatoriais_normais[i], fatoriais_duplos[i], dif);
    }


    arquivo = fopen("fatoriais.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }

    fprintf(arquivo, "Tabela - Fatoriais\n");
    fprintf(arquivo, "N\tFatorial\tFatorial Duplo\tDiferença\n");
    for (i = 0; i < TAM; i++) {
        long long int dif = fatoriais_normais[i] - fatoriais_duplos[i];
        fprintf(arquivo, "%d\t%lld\t%lld\t%lld\n", numeros[i], fatoriais_normais[i], fatoriais_duplos[i], dif);
    }

    fclose(arquivo);
    printf("\nArquivo 'fatoriais.txt' salvo com sucesso.\n");

    return 0;
}