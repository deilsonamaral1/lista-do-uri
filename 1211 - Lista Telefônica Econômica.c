#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//FUNÇÃO QUE COMPARA DUAS STRINGS E ENTREGA O NUMERO DE CARACTERES ECONOMIZADOS
int comparaStrings(char str1[], char str2[], int tamanhoLinha) {
    int i, resultado=0;
    for(i=0;i<tamanhoLinha;i++) {
        if(str1[i] == str2[i]) {
            resultado++;
        }
        else {
            break;
        }
    }
    return resultado;
}

int main(){
    int n;
    while((scanf("%d",&n))!= EOF) {
        char linhas[n+1][201];
        int i,j,aux;
        for(i=0;i<n;i++){ //FOR PARA PREENCHER AS STRINGS
            scanf("%s",&linhas[i]);
        }
        int tamanhoLinha = strlen(linhas[0]);
        int caracteresEconomizados=0, resultado=0;
        for(i=0;i<n-1;i++) { //FOR COMPARA NUMEROS DA LISTA
            for(j=i+1;j<n;j++) {
                aux = comparaStrings(linhas[i], linhas[j], tamanhoLinha);
                if(j==i+1)
                    caracteresEconomizados = aux;//VALOR INICIAL DE CARACTERES ECONOMIZADOS
                else if(caracteresEconomizados < aux){//SE O NOVO VALOR FOR MAIOR, ATRIBUI-SE A ELE
                    caracteresEconomizados = aux;
                }
            }
            resultado += caracteresEconomizados; //SOMA-SE AO RESULTADO QUE É O VALOR TOTAL DE CARACTERES ECONOMIZADOS
        }
        if(n==1) //SE HOUVER APENAS UM NUMERO, NÃO HÁ COMO ECONOMIZAR
            resultado = 0;
        printf("%d\n", resultado);
    }
    return 0;
}
