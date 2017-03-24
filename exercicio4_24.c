#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

void *threadPrimos(int numero){
    int x, y;
    int divisor, verifica, limite;

    printf("\nPRIMOS: ");
    for(x = 0; x < numero; x++){
        if(x >= 1){//Verifica se o número é maior que 1
            divisor = 2;
            verifica = 1;
            limite = sqrt(x);//Determina o limite de busca de divisão
            while(verifica && divisor <= limite){
                if(x%divisor == 0){//Se o número for divisível por divisor, este não é primo
                    verifica = 0;//Definindo como primo
                }
                divisor++;//Incrementando para realizar testes
            }
            if(verifica == 1)//É primo, caso contrário não é primo
                printf("%d ", x);
        }     
    }
    printf("\n\n");
}

int main(){
    int numero;
    pthread_t thread;

    printf("Informe um valor: ");
    scanf("%d", &numero);

    pthread_create(&thread, NULL, threadPrimos(numero), NULL);//Criando a thread
    // pthread_join(thread, NULL);
    return 0;
}
