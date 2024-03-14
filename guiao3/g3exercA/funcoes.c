#include <stdio.h>
//
void incrementa(int a,int *p)
{
    a++;
    (*p)++;
    printf("a = %d, *p = %d\n", a, *p);
}

int multip(int a,int *vect)
{   
    int resultado=1;
    for(int i=0;i<a;i++){
        resultado=resultado*vect[i];
    }
    printf("resultado=%d\n",resultado);
    return resultado;
}