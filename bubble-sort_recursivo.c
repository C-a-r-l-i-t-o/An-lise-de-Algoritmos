#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para medir o tempo de execução
double medirTempo(clock_t inicio, clock_t fim) {
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

void bubbleSort(int x[], int n) {
    if (n <= 1) {
        return; // Caso base: o vetor já está ordenado.
    }

    for (int i = 0; i < n - 1; i++) {
        if (x[i] > x[i + 1]) {
            // Troca os elementos se estiverem fora de ordem
            int temp = x[i];
            x[i] = x[i + 1];
            x[i + 1] = temp;
        }
    }

    // Chamada recursiva para ordenar o restante do vetor
    bubbleSort(x, n - 1);
}

int main() {
    int x[90000], i;
    srand(time(NULL));

    for (i = 0; i < 90000; i++) {
        x[i] = rand() % 99000;
    }

    clock_t inicio = clock();
    bubbleSort(x, 90000);
    clock_t fim = clock();

    printf("\nNumeros ordenados: \n");
    for (i = 0; i < 90000; i++) {
        printf("%d numero: %d\n", i + 1, x[i]);
    }

    double tempoExecucao = medirTempo(inicio, fim);
    printf("Tempo de execucao: %f segundo\n", tempoExecucao);

    return 0;
}

