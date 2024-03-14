#include <stdio.h>
#include "funcoes.h"
#include "menus.h"
int main ()
{
    int n;
    float vetor[50], soma,media, maior=0.0;
    char escolha;

    n=menu_qtosnums();

    menu_leNvalores(n,vetor);

    soma=somarElementosVetor(vetor,n,&maior);
    media=soma/(float)n;

    escolha=menu_escolha();
    if(escolha=='A' || escolha=='a') 
    {
        printf("Calculo do maior!\n"); printf("Maior é :%.2f\n",maior);
    }
    else if(escolha=='E' || escolha=='e') 
    {
       printf("Calculo da media!\n"); printf("Media é :%.2f\n",media);
    }
    else printf("Invalido\n");
    return 0;
}