#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funcao para medir o tempo de execucao
double medirTempo(clock_t inicio, clock_t fim) {
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

void troca(int x[], int i, int j) {
    int aux;
    aux = x[i];
    x[i] = x[j];
    x[j] = aux;
}

int particao(int x[], int p, int r) {
    int pivo, i, j;
    pivo = x[(p + r) / 2];
    i = p - 1;
    j = r + 1;
    while (i < j) {
        do {
            j = j - 1;
        } while (x[j] < pivo);  // Modificado para ordem decrescente
        do {
            i = i + 1;
        } while (x[i] > pivo);  // Modificado para ordem decrescente
        if (i < j)
            troca(x, i, j);
    }
    return j;
}

void quicksort(int x[], int p, int r) {
    int q;
    if (p < r) {
        q = particao(x, p, r);
        quicksort(x, p, q);
        quicksort(x, q + 1, r);
    }
}

int main() {
    int x[9];
    int i;

    // Inicializa o gerador de numeros aleatorios com uma
    // semente de tempo
    srand(time(NULL));
    clock_t inicio = clock();  // Inicia a contagem de tempo

    // Carregano os numeros no vetor
    printf("Numeros gerados aleatoriamente: \n");
    for (i = 0; i <= 8; i++) {
        x[i] = rand() % 9;
    }

    // Ordenado de forma decrescente
    quicksort(x, 0, 8);

    clock_t fim = clock();  // Finaliza a contagem de tempo

    // Mostrando o vetor ordenado
    printf("\nVetor Ordenado: \n ");
    for (i = 0; i <= 8; i++) {
        printf(" %d\n", x[i]);
    }

    double tempoExecucao = medirTempo(inicio, fim);
    printf("Tempo de execucao: %f segundos\n", tempoExecucao);

    return 0;
}

