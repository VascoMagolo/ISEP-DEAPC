#include <stdio.h>

int omaior(int a, int b)
{
    if (a>b) return a;
    else return b;
}

float media(int soma, int n)
{
    return (((float)(soma))/(float)n);
}

float somarElementosVetor(float v[],int n,float *m)
{
    float soma=0;
    for(int i=0;i<n;i++)
    {
        soma+=v[i];
        (*m)=omaior((*m),v[i]);
    }
    return soma;
}