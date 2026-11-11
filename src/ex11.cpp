#include <cstdio>
#include <omp.h>

int main() {
    int dado = 0;
    int pronto = 0;

    omp_set_num_threads(4);

    #pragma omp parallel shared(dado, pronto)
    {
        int id = omp_get_thread_num();

        if (id == 0) {
            dado = 50;
            #pragma omp flush(dado)
            pronto = 1;
            #pragma omp flush(pronto)
            printf("Produtora (thread %d) enviou: %d\n", id, dado);
        } else {
            while (!pronto) {
                #pragma omp flush(pronto)
            }
            #pragma omp flush(dado)
            printf("Consumidora (thread %d) leu: %d\n", id, dado);
        }
    }

    return 0;
}
