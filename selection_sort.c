//Algoritmo de ordenacao por selecao (selection sort)
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Funcao para medir o tempo de execucao 
double medirTempo(clock_t inicio, clock_t fim){
	return ((double)(fim -inicio))/CLOCKS_PER_SEC;
}

int main(){
	int x[90000];
	int i, j, eleito, menor, pos;
	//Iniciando o gerador de numeros aleatorios com uma 
	//semente de tempo
	srand(time(NULL));
	//carregando os numeros no vetor
	for(i=0; i <= 89999; i++){
		x[i] = rand() %99000;
		//printf("Digite o numero %d: ", i+1);
		//scanf("%d", &x[i]);
	}
	clock_t inicio = clock();//Inicia a contagem de tempo
	//ordenando de forma crescente
	//laco que percorre da primeira posicao
	//a penultima posicao do vetor
	//elegendo um numero para ser comparado
	for( i = 0; i <= 89998; i ++){
		eleito = x[i];
		//encontrando o menor numero a direita do eleito
		//com sua respectica posicao
		//posicao do eleito = i
		//primeiro numeor a direita do 
		//eleito na posicao = i+1
		menor = x[i+1];
		pos = i +1;
		//laco que percorre os elementos 
		//que estao a direita do 
		//numero eleito, retornando o 
		//menor numero a direita 
		//e sua posicao
		for(j = i+1; j <= 89999; j++){
			if(x[j]< menor){
			menor = x [j];
			pos = j;
			}
		}
		//troca do numero eleito com o numero da posicao pos
		//o numero da posicao pos é o menor numero a direita
		//do numero eleito
		if(menor < eleito){
			x[i] = x[pos];
			x[pos] = eleito;
		}
	}
	clock_t fim = clock();//Finaliza a contagem de tempo
			      //
	// mostrando o vetor ordenado
	for (i = 0; i <= 89999; i++){
		printf("%d numero: %d \n",i+1 ,x[i]);
	}
	double tempoExecucao = medirTempo(inicio, fim);
	printf("Tempo de execucao: %f segundos \n", tempoExecucao);

	return 0;
}
