#include <stdio.h>

long long int potencia_fatorial_crescente(int x, int n) {
    long long int resultado = 1;
    for (int i = 0; i < n; i++) {
        resultado *= (x + i);
    }
    return resultado;
}

long long int potencia_fatorial_decrescente(int x, int n) {
    long long int resultado = 1;
    for (int i = 0; i < n; i++) {
        resultado *= (x - i);
    }
    return resultado;
}

int main() {
    int x, n;
    FILE *arquivo;

    x = 5;
    n = 3;
    printf("teste com x = 5 e n = 3:\n");
    printf("Crescente: %lld\n", potencia_fatorial_crescente(x, n));
    printf("Decrescente: %lld\n\n", potencia_fatorial_decrescente(x, n));

    arquivo = fopen("tabela_potencias.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }

    x = 5;
    fprintf(arquivo, "x fixo = %d | n de 2 até 10\n", x);
    fprintf(arquivo, "n\tCrescente\tDecrescente\n");
    printf("x fixo = %d | n de 2 até 10\n", x);
    printf("n\tCrescente\tDecrescente\n");

    for (n = 2; n <= 10; n++) {
        long long int cres = potencia_fatorial_crescente(x, n);
        long long int decres = potencia_fatorial_decrescente(x, n);
        printf("%d\t%lld\t\t%lld\n", n, cres, decres);
        fprintf(arquivo, "%d\t%lld\t\t%lld\n", n, cres, decres);
    }

    n = 4;
    fprintf(arquivo, "\nn fixo = %d | x de 2 até 10\n", n);
    fprintf(arquivo, "x\tCrescente\tDecrescente\n");
    printf("\nn fixo = %d | x de 2 até 10\n", n);
    printf("x\tCrescente\tDecrescente\n");

    for (x = 2; x <= 10; x++) {
        long long int cres = potencia_fatorial_crescente(x, n);
        long long int decres = potencia_fatorial_decrescente(x, n);
        printf("%d\t%lld\t\t%lld\n", x, cres, decres);
        fprintf(arquivo, "%d\t%lld\t\t%lld\n", x, cres, decres);
    }

    fclose(arquivo);
    printf("\nResultados salvos em 'tabela_potencias.txt'.\n");

    return 0;
}