//o code a seguir é o bubblesort- algoritmo de ordenacao
//sera realizado uma versao sem implementar e outra com 
//implementacao

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Funcao para medir o tempo de execucao
double medirTempo(clock_t inicio, clock_t fim){
	return((double)(fim - inicio))/CLOCKS_PER_SEC;
}

int main(){
	int x[90000], n, i, aux;
	//Inicializa o gerador de numeros aleatorios com uma 
	//semente de tempo
	srand(time(NULL));

	//isso para carregar os numeros do vetor
	for (i = 0; i <= 89999; i++){
		x[i] = rand() % 99000;
		//Gere numeros aleatorios entre o a 99000
		
		//printf("Digite um numero: %d",i+1);
		//scanf("%d", &x[i]);	
	}
	//Mostra os números gerados aleatoriamente
	printf("Numeros gerados aleatoriamente: \n");
	for(i = 0; i< 90000; i++){
		printf("%d numero: %d\n",i+1, x[i]);
	}
	clock_t inicio = clock();//Inicia a contagem de tempo
	
	//ordenando de forma crescente
	//laco com o quantidade de elementos do vetor
	for( n = 0; n <= 90000; n++){
		//laco que percorre da primeira a 
		//penultima posicao do vetor
		for(i = 0;i <= 90000 - 1 ; i++){
			if (x[i] > x[i+1]){
				aux = x[i];
				x[i] = x[i+1];
				x[i+1] = aux;
			}
		} 
	}
	clock_t fim = clock(); //Finaliza a contagem de tempo

	//mostrando o vetor ordenado
	printf("\nNumeros ordenados:\n");
	for(i = 0; i<= 89999; i++){
		printf("%d numero: %d\n", i+1, x[i]);
	}

	double tempoExecucao = medirTempo(inicio, fim);
	printf("Tempo de execucao: %f segundos\n", tempoExecucao);
	
	return 0;

}
