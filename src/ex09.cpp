#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <omp.h>

int main() {
    int n = 10000;
    int vet[10000];
    int pares = 0;
    int impares = 0;

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        vet[i] = rand() % 1000;
    }

    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        if (vet[i] % 2 == 0) {
            #pragma omp atomic
            pares++;
        } else {
            #pragma omp atomic
            impares++;
        }
    }

    printf("Pares: %d\n", pares);
    printf("Impares: %d\n", impares);

    return 0;
}
