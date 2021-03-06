#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define RAND0() ((double)rand()/(double)RAND_MAX)
#define RAND(a, b) a + RAND0() * (b - a) 
#define POW(x) ((x) * (x))


double distancia (double x, double y){
    return sqrt(x * x + y * y);
}

int main(int argc, char**argv){
    double pi = 0, pontos, raio = 1.0;
    int i, quantidade = 0, recebe;
    pthread_t tred;

    do{
        printf("\nInforme a quantidade de pontos que deseja gerar: ");
        scanf("%lf", &pontos);
    }while(pontos <= 0);

    for(i = 0; i < pontos; i++){
        quantidade += distancia(RAND(-raio, raio), RAND(-raio, raio)) < raio;    
    }
    
    recebe = pthread_create(&tred, NULL, (void*)distancia, NULL);
    if (recebe){
         printf("ERROR; retornando o código para pthread_create() is %d\n", recebe);
         exit(-1);
    }
    pthread_join(tred, NULL);

    pi = ((4.0*quantidade)/pontos);
    printf("\nO valor do pi: %lf\n\n", pi);

    return 0;   
}