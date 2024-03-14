#include <stdio.h>

int menu_qtosnums()
{
    int n;
    printf("Quantos números quer inserir?\n");
    scanf("%d",&n);
    printf("Vai inserir %d números\n",n);
    return n;
}

void menu_leNvalores (int n, float* vect)
{
    for (int i=0; i<n; i++)
    {
        printf("Insira o número %d:\n",i+1);
        scanf("%f",&vect[i]);
    }
}

char menu_escolha(){
    char c;
    printf("Escolha uma opção:\n");
    printf("A - Calculo do maior\n");
    printf("E - Calculo da média\n");
    scanf(" %c",&c);
    return c;
}