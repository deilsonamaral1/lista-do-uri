#include <stdio.h>

main() {

    /*criando a matriz e  criando as variaveis */

    float M[12][12];
    int linha, l, coluna;
    char T; // vai indica se vai ser soma ou media "leitura da operaçao"
    float calculo;


    /* atribuindo os valores na variaveis */

    scanf("%d", &l);
    getchar();
    scanf("%c", &T);

    /* preenchendo a matriz, 
    no primeiro FOR ele esta percorrendo a linha,
    ja no segundo FOR ele esta percorrendo coluna,
    no SCANF esta preenchendo a matriz*/

    for(linha = 0; linha < 12; linha ++){
        for(coluna = 0; coluna < 12; coluna ++){
            scanf("%f", &M[linha][coluna]);
        }
    }

    /*no IF vais ser a parte do calculo da media ja que coloquei ele igua a M "media".
    */
    
    if (T == 'M'){

        /* neste FOR vai ser pecorrido a coluna e depois vai ser feiro o calculo */
        
        for(coluna = 0; coluna < 12; coluna ++){
            calculo = calculo + M[coluna][l];
        }
        //calculo da media 
        calculo = calculo/12.0;
    }

    /* no else vai ser quando for o SOMA "S"*/
    else {
        for (coluna = 0; coluna < 12; coluna ++){
            calculo = calculo + M[coluna][l];
        }
    }
    printf ("%0.1f\n", calculo);


}