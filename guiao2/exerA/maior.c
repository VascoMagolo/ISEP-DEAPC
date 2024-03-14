#include <stdio.h>

int omaior(int a, int b)
{
    if (a>b) return a;
    else return b;
}

int main ()
{
    int a,b,m;
    printf("Insere o primeiro numero:\n");
    scanf("%d",&a);
    printf("Insere o segundo numero:\n");
    scanf("%d",&b);
    m=omaior(a,b);
    printf("O maior número é :%d\n",m);

    return 0;
}