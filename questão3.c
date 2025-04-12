#include <stdio.h>

int soma_divisores(int n) {
    int soma = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0)
            soma += i;
    }
    return soma;
}

void mostrar_divisores(int n) {
    printf("Divisores próprios de %d: ", n);
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0)
            printf("%d ", i);
    }
    printf("\n");
}

int sao_amigaveis(int a, int b) {
    int soma_a = soma_divisores(a);
    int soma_b = soma_divisores(b);

    mostrar_divisores(a);
    printf("Soma dos divisores de %d: %d\n", a, soma_a);

    mostrar_divisores(b);
    printf("Soma dos divisores de %d: %d\n", b, soma_b);

    return soma_a == b && soma_b == a;
}

void buscar_amigaveis_ate(int limite) {
    for (int i = 2; i <= limite; i++) {
        int soma_i = soma_divisores(i);
        if (soma_i > i && soma_i <= limite) {
            if (soma_divisores(soma_i) == i) {
                printf("\n===> %d e %d são amigáveis!\n", i, soma_i);
                mostrar_divisores(i);
                printf("Soma de %d = %d\n", i, soma_i);
                mostrar_divisores(soma_i);
                printf("Soma de %d = %d\n", soma_i, i);
            }
        }
    }
}

int main() {
    int n, a, b;

    printf("Digite dois números para verificar se são amigáveis:\n");
    scanf("%d %d", &a, &b);

    if (sao_amigaveis(a, b))
        printf(">>> %d e %d são números amigáveis!\n", a, b);
    else
        printf(">>> %d e %d NÃO são números amigáveis.\n", a, b);

    printf("\nAgora digite um limite para buscar todos os pares amigáveis até ele: ");
    scanf("%d", &n);

    buscar_amigaveis_ate(n);

    return 0;
}
