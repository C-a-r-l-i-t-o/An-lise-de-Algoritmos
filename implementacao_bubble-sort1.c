//Esta versao e a primeira melhoria no code bubble-sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Funcao para medir o tempo de execucao
double medirTempo(clock_t inicio, clock_t fim){
	return((double)(fim - inicio))/CLOCKS_PER_SEC;
}



int main(){
	int x[90000], j, i, aux;
	//Inicializa o gerador  de numeros aleatorios com uma 
	//semente de tempo
	srand(time(NULL));

	//carregando os numeros no vetor
	for(i = 0; i <= 89999; i++){
		x[i] = rand() % 99000;
		//Gere numeros aleatorios entre 0 a 99000
		//printf("Digite o numero%d: ", i+1);
		//scanf("%d",&x[i]);
	}

	clock_t inicio = clock();//Inicio a contagem de tempo
	
	//ordenando de forma crescente
	//laco com a quantidade de elementos do vetor - 1
	for(j = 1; j <= 89999; j++){
		//laco que percorre da ultima posicao a 
		//posicao j do vetor
		for(i = 89999; i >=j; i--){
			if (x[i] < x[i-1]){
				aux = x[i];
				x[i] = x[i-1];
				x[i-1] = aux;
			}
		}
	}
	clock_t fim = clock();//Finaliza a contagem de tempo

	//mostrando o vetor ordenado
	printf("\nNumeros ordenados: \n");
	//mostrando o vetor ordenado
	for(i = 0; i <= 89999; i++){
		printf("%d numero: %d\n", i+1, x[i]);
	}
	double tempoExecucao = medirTempo(inicio, fim);
	printf("Tempo de execucao: %f segundo\n",tempoExecucao);
	return 0;

}
