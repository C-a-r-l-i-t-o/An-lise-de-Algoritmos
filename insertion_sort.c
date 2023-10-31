//Algoritmo de ordenacao por insercao (insertion sort)
//
//
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Funcao para medir o tempo de execucao
double medirTempo(clock_t inicio, clock_t fim){
	return ((double)(fim - inicio))/CLOCKS_PER_SEC;
}
int main(){
	int x[90000];
	int i, j, eleito;
	//Inicializa o gerador de numeros aleatorios com uma 
	//semente de tempo
	srand(time(NULL));
	//carregando os numeros do vetor 
	for (i = 0; i<= 89999; i++){
		x[i] = rand() % 99000;
	//printf("Digite o numero %d: ", i+1);
	//scanf("%d", &x[i]);
	}
	clock_t inicio = clock();//Inicio a contagem de tempo

	//ordenando de forma crescente
	//laco com a quantidade de elementos do vetor - 1
	for (i = 1; i <= 89999; i++){
		eleito = x[i];
		j = i -1;
		//laco que percorre os elementos a 
		//esquerda do numero eleito 
		//ou ate encontrar a posicao para 
		//recolocacao do numero eleito
		//respeitando a ordenacao procurada
		while( j >= 0 && x[j] > eleito){
		x [j+1] = x[j];
		j = j - 1;
		}
		x[j+1] = eleito;
	}
	clock_t fim = clock();//Finaliza a contagem de tempo

	//mostrando o vetor ordenado
	for (i = 0; i <= 89999; i++){
		printf("%d numero:%d \n", i+1, x[i]);
	}
	double tempoExecucao = medirTempo(inicio, fim);
	printf("Tempo de execucao: %f segundos\n", tempoExecucao);
	return 0;
}
