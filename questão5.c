#include <stdio.h>

double soma_fatoriais_inversos(int n) {
    double soma = 0.0;
    double fatorial = 1.0;

    for (int i = 1; i <= n; i++) {
        fatorial *= i;
        soma += 1.0 / fatorial;
    }

    return soma;
}

int main() {
    int n;
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Número inválido.\n");
        return 1;
    }

    double resultado = soma_fatoriais_inversos(n);
    printf("Soma dos fatoriais inversos até %d! = %.10lf\n", n, resultado);

    return 0;
}
