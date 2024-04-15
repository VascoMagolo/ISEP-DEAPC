/*
 *   concelhos.c
 *
 *   ISEP, 2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcoes.h"

int main() {
    setlocale(LC_CTYPE, "");

    concelho tabela1[MAX_CONCELHOS];

    int NConcelhos = ler_tabela("concelhos_utf8.csv",tabela1);

    lista_tabela(tabela1, NConcelhos);
    printf("\nResumo\n");
    resumo_tabela(tabela1, NConcelhos);

    printf("\nÁrea total: %f km²\n", total_area(tabela1,NConcelhos));

    printf("\nÁrea média por concelho: %f km²\n", media_area(tabela1,NConcelhos));

    printf("\nPopulação total: %d\n", total_pop(tabela1,NConcelhos));

    printf("\nDensidade populacional média: %f hab/km²\n", densidade(tabela1,NConcelhos));

    printf("\nRelação de género média: %f homens por cada 100 mulheres\n", h100m(tabela1,NConcelhos));

    printf("\nConcelho com maior população\n");
    int cmaxp = max_pop(tabela1,NConcelhos);
    lista_concelho(tabela1,cmaxp);

    printf("\nConcelho com maior densidade populacional\n");
    int cmaxd = max_densidade(tabela1,NConcelhos);   
    lista_concelho(tabela1,cmaxd);

    printf("\nConcelho com maior relação de género\n");
    int cmaxh = max_h100m(tabela1,NConcelhos);
    lista_concelho(tabela1,cmaxh);

    printf("\nConcelho com maior área\n");
    int cmaxa = max_area(tabela1,NConcelhos);
    lista_concelho(tabela1,cmaxa);

    printf("\nLista dos concelhos com a população maior que o dobro da média nacional\n");
    int total = total_pop(tabela1, NConcelhos);
    float media = media_pop(total, NConcelhos);
    int index = 0;
    concelho *tab_area_max = filtra_pop(tabela1, NConcelhos, media, &index);
    lista_tabela(tab_area_max, index);

    printf("\nLista ordenada por área\n");
    concelho *tab_area = copia_tabela(tabela1,NConcelhos);
    ordem_area(tab_area,NConcelhos);
    resumo_tabela(tab_area, NConcelhos);
    free(tab_area);

    printf("\nLista ordenada por densidade populacional\n");
    concelho *tab_densidade = copia_tabela(tabela1,NConcelhos);
    ordem_densidade(tab_densidade,NConcelhos);
    resumo_tabela(tab_densidade, NConcelhos);
    free(tab_densidade);


    printf("\nLista ordenada por população\n");
    concelho *tab_pop = copia_tabela(tabela1,NConcelhos);
    ordem_pop(tab_pop,NConcelhos);
    resumo_tabela(tab_pop, NConcelhos);
    free(tab_pop);

    printf("\nLista ordenada por relação de género\n");
    concelho *tab_h100m = copia_tabela(tabela1,NConcelhos);
    ordem_h100m(tab_h100m,NConcelhos);
    resumo_tabela(tab_h100m, NConcelhos);
    free(tab_h100m);

    return 0;
}