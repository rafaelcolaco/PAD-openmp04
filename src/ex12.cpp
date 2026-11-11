#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <omp.h>

int main() {
    int total = 10000000;
    int dentro = 0;
    double pi = 0.0;

    omp_set_num_threads(4);

    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        int nt = omp_get_num_threads();
        unsigned int seed = time(NULL) + id * 100;
        int qtd = total / nt;
        int cont_local = 0;

        for (int i = 0; i < qtd; i++) {
            double x = (double)rand_r(&seed) / RAND_MAX;
            double y = (double)rand_r(&seed) / RAND_MAX;

            if (x * x + y * y <= 1.0) {
                cont_local++;
            }
        }

        #pragma omp atomic
        dentro += cont_local;

        #pragma omp barrier

        #pragma omp single
        {
            pi = 4.0 * (double)dentro / (double)(qtd * nt);
            printf("Pi aproximado: %f\n", pi);
        }
    }

    return 0;
}
