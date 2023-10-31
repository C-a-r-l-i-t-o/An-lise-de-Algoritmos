#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Funcao para medir o tempo de execucao
double medirTempo(clock_t inicio, clock_t fim){
	return((double)(fim - inicio))/CLOCKS_PER_SEC;
}

struct item {
    int chave;
};

void shellsort(struct item *v, int n) {
    int i, j, h;
    struct item aux;

    // Calcula o h inicial
    for (h = 1; h < n; h = 3 * h + 1);

    while (h > 0) {
        h = (h - 1) / 3; // Atualiza o valor de h
        for (i = h; i < n; i++) {
            aux = v[i];
            j = i;

            // Efetua comparações entre elementos com distância h
            while (j >= h && v[j - h].chave > aux.chave) {
                v[j] = v[j - h];
                j -= h;
            }
            v[j] = aux;
        }
    }
}

int main() {
    int n = 90000;
    struct item *item = malloc(n * sizeof(struct item));

    srand(time(NULL));
    //printf("Entre com o número de elementos: ");
    //scanf("%d", &n);
    //struct item item[n];
    
   // printf("Entre com os elementos:\n");
    for (int i = 0; i < n; i++) {
        item[i].chave = rand() %99000;
	    //scanf("%d", &item[i].chave);
    }
    clock_t inicio = clock();//Inicia a contagem de tempo
    shellsort(item, n);

    printf("Sorted list: ");
    for (int i = 0; i < n; i++) {
        printf("%d \n", item[i].chave);
    }
    clock_t fim = clock();//Finaliza a contagem de tempo    
    
    double tempoExecucao = medirTempo(inicio, fim);
    printf("\nTempo de execucao: %f segundos \n", tempoExecucao);

    free(item); //Libera a memoria alocada


    return 0;
}

