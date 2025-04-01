#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20
int main(){

    double vt[N];
    
    double *puntero;
    srand(time(NULL));
    

    for(puntero=vt ;puntero<vt+N; puntero++){
       *puntero=1+(rand()%100);
       printf("\n%f", *puntero);
    }
return 0;
}