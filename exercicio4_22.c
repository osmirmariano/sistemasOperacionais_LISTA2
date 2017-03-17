#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>

int totalPontos = 0;
int pontos = 0;
int i;
double X, Y;

void *geracaoPontos(void *x){
    for(i = 0; i < pontos; i++){
        X = (double)rand();
        Y = (double)rand();
        
        if((X*X)+(Y*Y) > 0){
            totalPontos++;
            printf("%d \n", totalPontos);
        }
            
    }
    return NULL;
}

int main(){
    srand(time(NULL));
    pthread_t thread;

    do{
        printf("Informe o total de pontos no quadrado: ");
        scanf("%d", &pontos);
    }while(pontos <= 0);
    
    pthread_create(&thread, NULL, &geracaoPontos, NULL);
    pthread_join(thread, NULL);

    double pi = ((4 * (float)totalPontos)/pontos);

    printf("O valor do ponto %d é %f \n", pontos, pi);
}