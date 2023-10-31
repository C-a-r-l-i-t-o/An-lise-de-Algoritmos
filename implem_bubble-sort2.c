#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Funcao para medir o tempo de execucao
double medirTempo(clock_t inicio, clock_t fim){
	return((double)(fim - inicio))/CLOCKS_PER_SEC;
}
int main(){
	int x[90000], n, i, aux, troca;
	//Inicializa o gerador de numeros aleatorios com uma
	//semente de tempo
	srand(time(NULL));	
	
	
	//carregando os numeros no vetor
	for(i = 0; i<= 89999; i++){
		x[i] = rand()% 99000;
		//Gere numeros aleatorios entre 0 a 99000
		//printf("Digite o numero %d: ", i+1);
		//scanf("%d",&x[i]);
	}
	clock_t inicio = clock();//Inicio a contagem de tempo

	//ordenando de forma decrescente
	//laco com a quantidade de elementos do vetor 
	//e enquanto houver troca
	n = 1;
	troca = 1;
	while(n <= 90000 && troca == 1){
		troca = 0;
		for( i = 0; i <= 89999; i++){
			if (x[i] < x[i+1]){
				troca = 1;
				aux = x[i];
				x[i] = x[i+1];
				x[i+1] = aux;
			}
		}
		n = n + 1;
	}
	clock_t fim = clock();//Finaliza a contagem de tempo

	//mostrando o vetor ordenado
	for(i = 0; i <= 89999; i++){
		printf("%d numero: %d\n", i+1, x[i]);
	}
	double tempoExecucao = medirTempo (inicio, fim);
	printf("Tempo de execucao: %f segundos\n",tempoExecucao);
	return 0;
}

