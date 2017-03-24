#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

void fibonacciCalculo(int valor){
    int anterior = 0, atual = 1;
    int resultado = 0;
    int i;

    int vetor[valor];
    vetor[0] = 0;
    vetor[1] = 1;

    for(i=2; i<=valor; i++){
        resultado = atual + anterior;
        anterior = atual;
        atual = resultado;
        vetor[i] = resultado;
    }
    //return vetor;
    // for(int x = 0; x < valor; x++){
    //     printf("%d\n", vetor[x]);
    // }
}

int main(){
    int valor, recebe;
    pthread_t tred;

    printf("INFORME NÚMERO DE ELEMENTOS FIBONACCI: ");
    scanf("%d", &valor);

    recebe = pthread_create(&tred, NULL, fibonacciCalculo(valor), NULL);

    if (recebe){
         printf("ERROR; retornando o código para pthread_create() is %d\n", recebe);
         exit(-1);
    }
    //pthread_join(tred, NULL);
    return 0;
}

