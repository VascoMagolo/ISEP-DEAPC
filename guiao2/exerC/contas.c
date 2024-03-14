#include <stdio.h>
#include "funcoes.h"

int main ()
{
    int a,b;
    printf("Insere o primeiro numero:\n");
    scanf("%d",&a);
    printf("Insere o segundo numero:\n");
    scanf("%d",&b);
    printf("O maior número é :%d\n",omaior(a,b));
    printf("A média é :%f\n",media(a,b));
    return 0;
}