#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct ponto
{
    int *X;
    int *Y;
};

typedef struct ponto Ponto;

Ponto *alocamemoria(int n)
{

    Ponto *pontos = malloc(sizeof(Ponto) * n);
    for (int i = 0; i < n; i++)
    {
        pontos[i].X = malloc(sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        pontos[i].Y = malloc(sizeof(int));
    }

    return pontos;
}

int ***agrupaPontos(Ponto *pontos, int n, int k)
{
    int i, j;
    float distancias[k][n], menordistancia[n], menor = 9999;

    int ***grupos = malloc(sizeof(int) * k);
    for (j = 0; j < n; j++)
    {
        grupos[j] = malloc(sizeof(float) * n);
        for (i = 0; i < n; i++)
        {
            grupos[j][i] = malloc(sizeof(float) * 2);
        }
    }
    Ponto *centros = alocamemoria(k);

    for (i = 0; i < k; i++)
    {
        printf("X centro %d =%d  ", i, *centros[i].X = -20 + rand() % 50);
        printf("Y centro %d =%d\n", i, *centros[i].Y = -20 + rand() % 50);
    }

    for (j = 0; j < k; j++)
    {
        printf("\n\nCentro %d\n\n", j);
        for (i = 0; i < n; i++)
        {
            printf("Distancia %d =%f\n", i, distancias[j][i] = sqrt(pow((*pontos[i].X - *centros[j].X), 2) + pow((*pontos[i].Y - *centros[j].Y), 2)));
        }
    }

    for (i = 0; i < n; i++)
    {
        menor = 9999;
        for (j = 0; j < k; j++)
        {
            if (distancias[j][i] < menor)
            {
                menordistancia[i] = distancias[j][i];
                menor = distancias[j][i];
            }
        }
    }

    for (i = 0; i < n; i++)
        printf("\n\nA menor distancia do ponto %d eh %f", i, menordistancia[i]);

    for (j = 0; j < k; j++)
    {
        for (i = 0; i < n; i++)
        {

            if (distancias[j][i] == menordistancia[i])
            {
                printf("\n\nO ponto %d pertence ao centro %d\n\n", i, j);
                grupos[j][i][0] = *pontos[i].X;
                grupos[j][i][1] = *pontos[i].Y;
            }else {
                grupos[j][i][0]=0;
                grupos[j][i][1]=0;
            }

        }
    }
    return grupos;
}

int main()
{

    int n = 0, k=3;
    int ***grupos;
    n = 7;

    srand(time(NULL));

    Ponto *pontos = alocamemoria(n);

    for (int i = 0; i < n; i++)
    {
        printf("X[%d] =%d  ", i, *pontos[i].X = -20 + rand() % 50);
        printf("Y[%d] =%d\n", i, *pontos[i].Y = -20 + rand() % 50);
    }

    printf("\n\n\n\n");

    grupos=agrupaPontos(pontos, n, k);

    for(int i=0;i<k;i++){
        printf("Componentes do centro %d:\n\n",i);
        for(int j=0;j<n;j++){
            if(grupos[i][j][0]!=0 && grupos[i][j][1]!=0)
            printf("X=%d  Y=%d\n",grupos[i][j][0],grupos[i][j][1]);
        }
        printf("\n\n\n");

    }
}