#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int n,i,aux=0;
    scanf("%d",&n);
    getchar();
    char str[2501];
    char palavra[50][51];
    while(n--){
        scanf("%[^\n]s",&str);//Ler até encontrar uma quebra de linha
        i = 0;
        int numPalavra = 0, posicao = 0;
        int tamanhoDeStr = strlen(str);
        while(i<tamanhoDeStr){ //Separar em palavras
            if(str[i] != ' '){
                palavra[numPalavra][posicao] = str[i];
                posicao++;
                if(i == tamanhoDeStr - 1)
                    palavra[numPalavra][posicao] = '\0';
            }
            else {
                palavra[numPalavra][posicao] = '\0';
                numPalavra++;
                posicao = 0;
            }
            i++;
        }
        int j, fimDaOrdenacao = numPalavra;
        char strAux[51];
        for(i=0;i<numPalavra;i++){ //ORDENAÇÃO BUBBLESORT
            for(j=0;j<fimDaOrdenacao;j++){
                if(strlen(palavra[j]) < strlen(palavra[j+1])){//ORDENA BASEADO NO TAMANHO DAS STRINGS
                    strcpy(strAux, palavra[j]);
                    strcpy(palavra[j],palavra[j+1]);
                    strcpy(palavra[j+1],strAux);
                }
            }
            fimDaOrdenacao--;
        }
        for(i=0;i<numPalavra+1;i++){
            if(i == numPalavra)
                printf("%s",palavra[i]);
            else
                printf("%s ",palavra[i]);
        }
        printf("\n");
        getchar();
    }
    return 0;
}
