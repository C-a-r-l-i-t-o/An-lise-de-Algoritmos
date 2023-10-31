#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Funcao para medir o tempo de exeucao
double medirTempo(clock_t inicio, clock_t fim){
	return((double)(fim - inicio))/CLOCKS_PER_SEC;
}
void intercala(int x[], int inicio, int fim, int meio){	int poslivre, inicio_vet1, inicio_vet2, i;
	int aux [90000];
	inicio_vet1 = inicio;
	inicio_vet2 = meio +1;
	poslivre = inicio;

	while (inicio_vet1<= meio && inicio_vet2 <= fim){
		if (x[inicio_vet1] <= x[inicio_vet2]){
			aux[poslivre] = x[inicio_vet1];
			inicio_vet1 = inicio_vet1 + 1;
		} else{
			aux[poslivre]= x[inicio_vet2];
			inicio_vet2 = inicio_vet2 + 1; 		
		}
		poslivre = poslivre + 1;
	}
	//se ainda existem numeros no primeiro vetor
	//que não foram intercalados
		for(i = inicio_vet1; i <= meio; i++){
			aux[poslivre]= x[i];
			poslivre = poslivre + 1;
		}
	//se ainda existem numeros no segundo vetor
	//que não foram intercalados
		for(i = inicio_vet2;i <= fim;i ++){
			aux[poslivre] = x[i];
			poslivre = poslivre +1;
		}
	//retorna os valores do vetor aux para o vetor x
	for(i = inicio; i <= fim;i ++){
		x[i] = aux[i];
	}
}
void merge(int x[], int inicio, int fim){
	int meio;
	if (inicio < fim){
		meio = (inicio+ fim)/2;
		merge(x, inicio, meio);
		merge(x, meio + 1, fim);
		intercala(x, inicio, fim, meio);
	}
}

int main(){
	int x[90000];
	int i;
	//Iniciando o gerador de numeros aleatorios com uma
	//semente de tempo
	srand(time(NULL));
	//carregando os numeros no vetor
	for( i = 0; i <= 89999; i++){
		x[i] = rand() %99000;
		//printf("Digite o numero %d: ", i +1);
		//scanf("%d", &x[i]);
	}
	clock_t inicio = clock();//Inicia a contagem de tempo
	//ordenando de forma crescente
	merge (x, 0, 89999);
	//mostrando o vetor ordenado
	for(i = 0; i <= 89999; i++){
		printf("%d numero: %d \n", i+1, x[i]);
	}
	clock_t fim = clock();//Finaliza a contagem de tempo

	double tempoExecucao = medirTempo(inicio,fim);
	printf("Tempo de execucao: %f segundos \n", tempoExecucao);

	return 0;
}
