//Algoritmo de ordenacao Quick_sort
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Funcao para medir o tempo de execucao
double medirTempo(clock_t inicio, clock_t fim){
	return ((double)(fim - inicio))/CLOCKS_PER_SEC;
}

void troca(int x[], int i, int j){
	int aux;
	aux = x[i];
	x[i] = x[j];
	x[j] = aux;
}
int particao(int x[], int p, int r){
	int pivo, i, j;
	pivo = x[(p+r)/2];
	i = p - 1;
	j = r + 1;
	while (i < j){
		do {
			j = j -1;
		}
		while (x[j] > pivo);
		do {
			i = i+1;
		}
		while (x[i] < pivo);
		if (i < j) troca (x,i,j);
		
	}
	return j;
}
void quicksort(int x[], int p, int r){
	int q;
	if (p < r){
		q = particao (x, p, r);
		quicksort(x, p, q);
		quicksort(x, q+1, r);
	}

}

int main(){
	int x[90000];
	int i; 
	//Inicializa o gerador de numeros aleatorios com uma
	//semente de tempo
	srand(time(NULL));
	clock_t inicio = clock(); //Inicia a contagem de tempo

	//carregano os numeros no vetor
	printf("Numeros gerados aleatoriamente: \n");
	for(i = 0; i<= 89999; i++){
		x[i] = rand() % 99000;
		//printf("Digite o numero %d: ", i+1);
		//scanf("%d \n", &x[i]);
	}
		//ordenado de forma crescente
		quicksort(x, 0, 89999);
	clock_t fim = clock();// Finaliza a contagem de tempo	
		//mostrando o vetor ordenado
		printf("\nVetor Ordenado: \n ");
	for(i = 0; i <= 89999; i++){
		printf(" %d\n", x[i]);
	}
	double tempoExecucao = medirTempo(inicio, fim);
	printf("Tempo de execucao: %f segundos\n", tempoExecucao);

	return 0;
}
