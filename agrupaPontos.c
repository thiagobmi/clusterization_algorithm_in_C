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
        pontos[i].X = malloc(sizeof(int));

    for (int i = 0; i < n; i++)
        pontos[i].Y = malloc(sizeof(int));

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
        *centros[i].X = -20 + rand() % 50;
        *centros[i].Y = -20 + rand() % 50;
    }

    for (j = 0; j < k; j++)
        for (i = 0; i < n; i++)
            distancias[j][i] = sqrt(pow((*pontos[i].X - *centros[j].X), 2) + pow((*pontos[i].Y - *centros[j].Y), 2));

    for (i = 0; i < n; i++)
    {
        menor = 9999;
        for (j = 0; j < k; j++)
            if (distancias[j][i] < menor)
            {
                menordistancia[i] = distancias[j][i];
                menor = distancias[j][i];
            }
    }

    for (j = 0; j < k; j++)
        for (i = 0; i < n; i++)
            if (distancias[j][i] == menordistancia[i])
            {
                grupos[j][i][0] = *pontos[i].X;
                grupos[j][i][1] = *pontos[i].Y;
            }

    return grupos;
}

Ponto *geraPontos(Ponto *pontos, int n)
{

    for (int i = 0; i < n; i++)
    {
        *pontos[i].X = -20 + rand() % 50;
        *pontos[i].Y = -20 + rand() % 50;
    }

    return pontos;
}

int main(int argc, char *argv[])
{

    int n = 0, k = 0;

    n = atoi(argv[1]);
    k = atoi(argv[2]);

    srand(time(NULL));

    Ponto *pontos = alocamemoria(n);
    pontos = geraPontos(pontos, n);
    agrupaPontos(pontos, n, k);
}