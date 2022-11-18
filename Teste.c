#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

struct ponto{

    int *X;
    int *Y;
};

typedef struct ponto Ponto;


Ponto *alocamemoria(int n){
    
    Ponto *pontos=malloc(sizeof(Ponto)*n);
    for(int i=0;i<n;i++){
        pontos[i].X=malloc(sizeof(int));
    }
    
    for(int i=0;i<n;i++){
        pontos[i].Y=malloc(sizeof(int));
    }

    return pontos;
}

int agrupaPontos(Ponto *pontos,int n,int k){

    float distancias[k][n];
    Ponto *centros=alocamemoria(k);
    
    for(int i=0;i<k;i++){
        printf("X centro %d =%d  ",i,*centros[i].X=-20+rand()%50);
        printf("Y centro %d =%d\n",i,*centros[i].Y=-20+rand()%50);
    }


    printf("Centro 0\n\n\n");

    for(int i=0;i<n;i++)printf("Distancia %d =%f\n",i,sqrt(pow((*pontos[i].X - *centros[0].X ),2) + pow((*pontos[i].Y- *centros[0].Y),2)));

    printf("Centro 1\n\n\n");

    for(int i=0;i<n;i++)printf("Distancia %d =%f\n",i,sqrt(pow((*pontos[i].X - *centros[1].X ),2) + pow((*pontos[i].Y- *centros[1].Y),2)));


}


int main(){

    int n=0;
    
    n=5;

    srand(time(NULL));

    Ponto *pontos=alocamemoria(n);
    
    for(int i=0;i<n;i++){
        printf("X[%d] =%d  ",i,*pontos[i].X=-20+rand()%50);
        printf("Y[%d] =%d\n",i,*pontos[i].Y=-20+rand()%50);
    }
    
    printf("\n\n\n\n");

    agrupaPontos(pontos,n,2);



}