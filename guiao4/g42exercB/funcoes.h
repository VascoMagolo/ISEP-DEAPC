#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_LINHA (100)	  	// Comprimento maximo de uma linha
#define MAX_CONCELHOS (400)	// Numero maximo de concelhos
typedef struct {
    char  nome[80];
    int   homens;
    int   mulheres;
    float area;
} concelho;

int ler_tabela(char *nomefich, concelho *tab);
void lista_concelho(concelho *tab, int ic);
void cabecalho();
void lista_tabela(concelho *lista, int nc);
void resumo_tabela(concelho *tab, int nc);
float total_area(concelho *lista, int nc);
float media_area(concelho *lista, int nc);
int total_pop(concelho *tab, int nc);
float media_pop(int total, int nc);
concelho *filtra_pop(concelho *tab_in, int nc, int media, int *index);
float densidade(concelho *tab, int nc);
int max_area(concelho *tab, int nc);
int max_pop(concelho *tab, int nc);
int max_densidade(concelho *tab, int nc);
float h100m(concelho *tab, int nc);
int max_h100m(concelho *tab, int nc);
concelho *copia_tabela(concelho *tab_in, int nc);
void ordem_area(concelho *tab_ord, int nc);
void ordem_pop(concelho *tab_ord, int nc);
void ordem_densidade(concelho *tab_ord, int nc);
void ordem_h100m(concelho *tab_ord, int nc);
#endif