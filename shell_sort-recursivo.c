#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para medir o tempo de execução
double medirTempo(clock_t inicio, clock_t fim) {
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

struct item {
    int chave;
};

void shellsortRecursivo(struct item *v, int n, int h) {
    if (h < 1) {
        return;
    }

    for (int i = h; i < n; i++) {
        struct item aux = v[i];
        int j = i;

        while (j >= h && v[j - h].chave > aux.chave) {
            v[j] = v[j - h];
            j -= h;
        }

        v[j] = aux;
    }

    shellsortRecursivo(v, n, (h - 1) / 3); // Chama a função recursivamente com um valor de h menor
}

int main() {
    int n = 90000;
    struct item *item = malloc(n * sizeof(struct item));

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        item[i].chave = rand() % 99000;
    }

    int h = 1;
    while (h < n) {
        h = 3 * h + 1;
    }
    h = (h - 1) / 3;

    clock_t inicio = clock();
    shellsortRecursivo(item, n, h);

    printf("Sorted list: ");
    for (int i = 0; i < n; i++) {
        printf("%d \n", item[i].chave);
    }
    clock_t fim = clock();

    double tempoExecucao = medirTempo(inicio, fim);
    printf("\nTempo de execução: %f segundos \n", tempoExecucao);
    
    free(item); // Libera a memória alocada

    return 0;
}

