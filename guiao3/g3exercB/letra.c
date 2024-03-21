#include<stdio.h>
#include<stdlib.h>
#include"funcoes.h"

int main()
{
    int n=0;
    char* v;
    char* x;

    do{
        printf("Insert a number of letters between 1 and 50:");
        scanf("%d",&n);
    }while(n<1||n>50);

    v=n_letras(n);
    printf("%s\n",v);
    x=repete_letras(v,3);
    printf("%s\n",x);

    free(v);
    free(x);

    return 0;
}