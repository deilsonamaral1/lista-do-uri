#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, menor = 0, posicao  = 0;
	// Ler o vetor n
	scanf("%d", & n);
	int vetor[n + 1];
	int i;

	for(i = 0; i < n; i++){
		//ler os valores do vetor
		scanf("%d", & vetor[i]);
		if(i == 0){
			// definir a variavel nempr como posiçao inicial para parametro
			menor = vetor[i];
			posicao = 0;
			// posicao inicial

		}
		if(menor > vetor[i]){
			/* se o valor for  do vetor for menor, entao esse sera o novo valor da variavel menor */
			menor = vetor[i];

			posicao = 0;//e a posiçao
		}
		printf("Menor valor: %d\nPosicao: %d\n",menor, posicao);
		return 0;
	}
}
