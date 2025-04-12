#include <stdio.h>
#include <math.h>

int eh_numero_armstrong(int n) {
    int soma = 0, original = n, digito;

    while (n > 0) {
        digito = n % 10; 
        soma += pow(digito, 3);  
        n /= 10;  
    }

    return soma == original;
}

int main() {
    printf("Números de Armstrong entre 1 e 100:\n");
    for (int i = 1; i <= 100; i++) {
        if (eh_numero_armstrong(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
