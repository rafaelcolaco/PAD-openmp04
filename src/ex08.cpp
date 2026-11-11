#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <omp.h>

int main() {
    int n = 10000;
    int vet[10000];
    int hist[10] = {0};

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        vet[i] = rand() % 10;
    }

    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        int val = vet[i];
        #pragma omp critical
        {
            hist[val]++;
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("Valor %d: %d\n", i, hist[i]);
    }

    return 0;
}
