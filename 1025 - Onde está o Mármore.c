#include <stdio.h>
#include <stdlib.h>
int compara(const void * a, const void * b) {//FUNÇÃO COMPARATIVA PARA O QSORT
    if( *(int*)a<*(int*)b)
        return -1;
    if(*(int*)a==*(int*)b)
        return 0;
    if(*(int*)a>*(int*)b)
        return 1;
}

void buscaBinaria(int n, int q, int marmores[], int consultas[], int posicao[]) {
    int i;
    for(i=0;i<q;i++) {//BUSCA BINARIA
        int inicio = 0, final = n-1, meio;
        posicao[i] = 0;
        while(inicio <= final) {//VERIFICA SE O NUM DA CONSULTA ESTA PRESENTE
            meio = (inicio+final)/2; //BUSCA NO MEIO DA SEQUENCIA
            if(consultas[i] == marmores[meio]){//NUMERO ENCONTRADO
                posicao[i] = meio+1;
                while(1) {//ESTE WHILE ENCONTRA A MENOR POSIÇÃO POSSIVEL POIS PODEM HAVER Nº REPETIDOS
                    if(marmores[meio] == marmores[meio-1]) {
                        meio--;
                        posicao[i]=meio+1;
                    } else {break;}
                }
                break;
            }
            else if(inicio == final){//NAO FOI ENCONTRADO
                break;
            }
            else if(consultas[i] > marmores[meio])
                inicio = meio + 1;//PARTE PARA A OUTRA METADE
            else {
                final = meio - 1;
            }
        }
    }
}

int main(){
    int q,n,count=1, d=65;//COUNT É O NUMERO SERIAL
    while(d--) { //RODA ENQUANTO NÃO FOR ZERO
        scanf("%d %d",&n,&q);
        if(n == 0 && q == 0)
            break;
        int i,j;
        int marmores[n+1], consultas[q+1];
        for(i=0;i<n;i++) {//LEITURA DOS NUMEROS DAS PEÇAS DE MARMORE
            scanf("%d",&marmores[i]);
        }
        for(i=0;i<q;i++) {//LEITURA DAS CONSULTAS
            scanf("%d",&consultas[i]);
        }
        int posicao[q+1];
        qsort(marmores,n,sizeof(int),compara);//PRIMEIRO ORDENA-SE O VETOR COM QUICKSORT
        buscaBinaria(n, q, marmores, consultas,posicao);//UMA VEZ ORDENADO FAZ-SE BUSCA BINARIA
        printf("CASE# %d:\n",count);
        for(i=0;i<q;i++) {//PRINTAR AS CONSULTAS
            if(posicao[i] > 0)
                printf("%d found at %d\n", consultas[i],posicao[i]);
            else {
                printf("%d not found\n", consultas[i]);
            }
        }
        count++;
    }
    return 0;
}
