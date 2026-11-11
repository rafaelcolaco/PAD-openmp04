#include <cstdio>
#include <omp.h>

int main() {
    int vet[4];
    int res[4];

    omp_set_num_threads(4);

    #pragma omp parallel
    {
        int id = omp_get_thread_num();

        vet[id] = (id + 1) * 10;
        printf("Etapa 1 - Thread %d gravou %d\n", id, vet[id]);

        #pragma omp barrier

        int prox = (id + 1) % 4;
        res[id] = vet[id] + vet[prox];
        printf("Etapa 2 - Thread %d somou %d + %d = %d\n", id, vet[id], vet[prox], res[id]);
    }

    return 0;
}
