#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para medir o tempo de execução
double medirTempo(clock_t inicio, clock_t fim) {
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

void insertionSortRecursive(int x[], int n) {
    if (n <= 1) {
        return; // Caso base: um único elemento está sempre ordenado.
    }

    // Classificar os primeiros n-1 elementos
    insertionSortRecursive(x, n - 1);

    // Inserir o último elemento (x[n-1]) na posição correta
    int eleito = x[n - 1];
    int j = n - 2;

    while (j >= 0 && x[j] > eleito) {
        x[j + 1] = x[j];
        j--;
    }

    x[j + 1] = eleito;
}

int main() {
    int x[90000];
    int i;
    srand(time(NULL));

    for (i = 0; i < 90000; i++) {
        x[i] = rand() % 99000;
    }

    clock_t inicio = clock();
    insertionSortRecursive(x, 90000);
    clock_t fim = clock();

    printf("\nNumeros ordenados: \n");
    for (i = 0; i < 90000; i++) {
        printf("%d numero:%d \n", i + 1, x[i]);
    }

    double tempoExecucao = medirTempo(inicio, fim);
    printf("Tempo de execucao: %f segundo\n", tempoExecucao);

    return 0;
}

