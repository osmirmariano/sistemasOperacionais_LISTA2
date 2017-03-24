#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int vetor[1000];

void *fibonacciCalculo(int valor){
    int anterior = 0, atual = 1;
    int resultado = 0;
    int i;

    //int vetor[valor];
    vetor[0] = 0;
    vetor[1] = 1;

    for(i=2; i<=valor; i++){
        resultado = atual + anterior;
        anterior = atual;
        atual = resultado;
        vetor[i] = resultado;
    }
}

int main(){
    int valor, x;
    pthread_t tred;

    printf("INFORME NÚMERO DE ELEMENTOS FIBONACCI: ");
    scanf("%d", &valor);
    
    pthread_create(&tred, NULL, fibonacciCalculo(valor), NULL);
    wait();
    for(x = 0; x < valor; x++){
        printf("%d\n", vetor[x]);
    }
    
    return 0;
}
