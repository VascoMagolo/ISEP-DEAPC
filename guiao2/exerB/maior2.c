#include <stdio.h>
#include "funcoes.h"

int main ()
{
    int a,b;
    printf("Insere o primeiro numero:\n");
    scanf("%d",&a);
    printf("Insere o segundo numero:\n");
    scanf("%d",&b);
    printf("A média é :%d\n",omaior(a,b));

    return 0;
}