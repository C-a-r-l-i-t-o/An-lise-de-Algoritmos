#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para medir o tempo de execução
double medirTempo(clock_t inicio, clock_t fim) {
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

// Função recursiva para Selection Sort
void selectionSortRecursive(int x[], int n, int i) {
    if (i >= n - 1) {
        return; // Caso base: todos os elementos estão ordenados.
    }

    int eleito = x[i];
    int menor = eleito;
    int pos = i;

    // Encontre o menor elemento à direita do elemento eleito
    for (int j = i + 1; j < n; j++) {
        if (x[j] < menor) {
            menor = x[j];
            pos = j;
        }
    }

    // Troque o elemento eleito com o menor elemento encontrado
    x[pos] = eleito;
    x[i] = menor;

    // Chame recursivamente a função para o próximo elemento
    selectionSortRecursive(x, n, i + 1);
}

int main() {
    int x[90000];
    int i;
    srand(time(NULL));

    for (i = 0; i < 90000; i++) {
        x[i] = rand() % 99000;
    }

    clock_t inicio = clock();
    selectionSortRecursive(x, 90000, 0);
    clock_t fim = clock();

    printf("\nNumeros ordenados: \n");
    for (i = 0; i < 90000; i++) {
        printf("%d numero: %d \n", i + 1, x[i]);
    }

    double tempoExecucao = medirTempo(inicio, fim);
    printf("Tempo de execucao: %f segundos \n", tempoExecucao);

    return 0;
}

