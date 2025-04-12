#include <stdio.h>
#include <stdlib.h>

int soma_quadrados_digitos(int n) {
    int soma = 0;
    while (n > 0) {
        int digito = n % 10;
        soma += digito * digito;
        n /= 10;
    }
    return soma;
}

int eh_numero_feliz(int n) {
    int visitados[1000] = {0};

    while (n != 1 && visitados[n] == 0) {
        visitados[n] = 1;
        n = soma_quadrados_digitos(n);
    }

    return n == 1;
}

int main() {
    int limite;
    printf("Digite até qual número deseja verificar: ");
    scanf("%d", &limite);

    printf("Números felizes entre 1 e %d:\n", limite);
    for (int i = 1; i <= limite; i++) {
        if (eh_numero_feliz(i))
            printf("%d ", i);
    }

    printf("\n");
    return 0;
}
