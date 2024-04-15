#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include "funcoes.h"
/*
 * B.1
 * Leitura de ficheiro com nome em nomefich para vetor de concelhos em lista.
 * Retorna número de concelhos lidos.
 */
int ler_tabela(char *nomefich, concelho *tab) {
    FILE *file = fopen(nomefich,"r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    int count = 0;
    char ch;
    while((ch = fgetc(file)) != EOF) {
        if(ch == '\n') {
            count++;
        }
    }
    printf("Number of lines: %d\n", count);

    if (count > MAX_CONCELHOS) {
        printf("Not enough space in tab to store all concelhos.\n");
        fclose(file);
        return -1;
    }

    rewind(file);
    char line[100];
    for(int i = 0; i < count; i++) {
        if (fgets(line, 100, file) == NULL) {
            fprintf(stderr, "Error reading file\n");
            perror(", Error reading file");
            fclose(file);
            return -1;
        }

        char *token = strtok(line, ",");
        if (token == NULL) {
            fprintf(stderr, "Error reading file\n");
            perror(", Error reading file");
            fclose(file);
            return -1;
        }
        strcpy(tab[i].nome, token);

        token = strtok(NULL, ",");
        tab[i].homens = token ? atoi(token) : 0;

        token = strtok(NULL, ",");
        tab[i].mulheres = token ? atoi(token) : 0;

        token = strtok(NULL, ",");
        tab[i].area = token ? atof(token) : 0.0;
    }

    fclose(file);
    return count;
}

/*
 * Apresenta informação sobre um concelho
 */
void lista_concelho(concelho *tab, int ic) {
    if ( ic<0 ) return;
    mbstate_t t;
    concelho c = tab[ic];
    const char *scopy = c.nome;
    memset(&t, '\0', sizeof (t));
    int n = mbsrtowcs(NULL, &scopy, strlen (scopy), &t);  // Comprimento do nome
    int populacao_total = c.homens + c.mulheres;
    float densidade_populacional = populacao_total / c.area;
    float relacao_genero = (float)(c.homens * 100) / c.mulheres;
    printf("%3d ", ic+1);
    printf("%s%*s ", c.nome, 28-n, "");
    printf("%9d ", c.homens);
    printf("%9d ", c.mulheres);
    printf("%9.2f ", c.area);
    printf("%9d ", populacao_total);
    printf("%9.2f ", densidade_populacional);
    printf("%9.2f ", relacao_genero);
    printf("\n");
}

/*
 * Cabeçalho a usar nas listas e nos resumos.
 */
void cabecalho() {
    printf("Num      Concelho                   Homens  Mulheres   Área(km²) Pop_total Hab/km^2    H/100M\n");
}

/*
 * Apresenta tabela completa.
 */
void lista_tabela(concelho *lista, int nc) {
    cabecalho();
    if ( ! lista ) return;
    for( int i=0 ; i<nc ; i++ ) 
	    lista_concelho(lista,i);
}

/*
 * Apresenta resumo de tabela.
 */
void resumo_tabela(concelho *tab, int nc) {
    const int linhas_resumo = 5;
    if ( ! tab ) return;
    if ( nc<2*linhas_resumo )	// Se tabela é pequena, 
	    lista_tabela(tab,nc);   // é listada na totalidade
    else {
        int i;
	    cabecalho();
        for( i=0 ; i<linhas_resumo ; i++ )       // Início da tabela
	        lista_concelho(tab,i);
        printf("    . . .\n");
        for( i=nc-linhas_resumo ; i<nc ; i++ )   // Fim da tabela
	        lista_concelho(tab,i);
    }
}

/*
 * B.2.a)
 * Determina área total do conjunto de concelhos
 */
float total_area(concelho *lista, int nc) {
	float total = 0.;
    for (int i = 0; i < nc; i++)
    {
        total += lista[i].area;
    }
    return total;
}

/*
 * B.2.b)
 * Determina área média por concelho
 */
float media_area(concelho *lista, int nc) {
	float total = 0.;
    for (int i = 0; i < nc; i++)
    {
        total += lista[i].area;
    }
    float media = total/nc;
    return media;
}

/*
 * B.4.a)
 * Determina população total do conjunto de concelhos
 */
int total_pop(concelho *tab, int nc) {
	int total = 0;
    for (int i = 0; i < nc; i++) {
        total += tab[i].homens + tab[i].mulheres;
    }
    return total;
}
/*
 * Retorna a média da população
 */
float media_pop(int total, int nc){
    return total/nc;
}


/*
 * Filtra concelhos com população superior a 2*media da população nacional
 */
concelho *filtra_pop(concelho *tab_in, int nc, int media, int *index){
    concelho *tab_out = malloc(nc * sizeof(concelho));
    if (tab_out == NULL) {
        printf("Error allocating memory.\n");
        return NULL;
    }
    *index = 0;
    for(int i = 0; i < nc; i++){
        if((tab_in[i].homens+tab_in[i].mulheres) > 2*media)
        {
            tab_out[*index] = tab_in[i];
            (*index)++;
        }
    }
    
    tab_out = realloc(tab_out, *index * sizeof(concelho));
    if (tab_out == NULL) {
        printf("Error reallocating memory.\n");
        return NULL;
    }
    return tab_out;
}
/*
 * Retorna a média da densidade populacional do pais inteiro em habitantes por km²
 */
float densidade(concelho *tab, int nc){
    float densidade=0;
    for (int i = 0; i < nc; i++)
    {
        densidade=+(tab[i].homens+tab[i].mulheres)/tab[i].area;
    }
    return densidade/nc;
}
/*
 * B.2.c1)
 * Determina índice do concelho com maior área.
 */
int max_area(concelho *tab, int nc) {
    if (nc <= 0) {
        return -1;
    }

    int max_index = 0;

    for (int i = 1; i < nc; i++) {
        if (tab[i].area > tab[max_index].area) {
            max_index = i; 
        }
    }

    return max_index;
}


/*
 * Determina índice do concelho com maior população.
 */
int max_pop(concelho *tab, int nc) {
    if (nc <= 0) {
        return -1;
    }

    int max_index = 0;

    for (int i = 1; i < nc; i++) {
        if (tab[i].homens+tab[i].mulheres > tab[max_index].homens+tab[max_index].mulheres) {
            max_index = i; 
        }
    }

    return max_index;
}

/*
 * Determina índice do concelho com maior densidade.
 */
int max_densidade(concelho *tab, int nc) {
    if (nc <= 0) {
        return -1;
    }

    int max_index = 0;

    for (int i = 1; i < nc; i++) {
        if ((tab[i].homens+tab[i].mulheres)/tab[i].area > (tab[max_index].homens+tab[max_index].mulheres)/tab[max_index].area) {
            max_index = i; 
        }
    }

    return max_index;
}
/*
* Retorna a relação de género do pais inteiro homens por cada 100 mulheres
*/
float h100m(concelho *tab, int nc){
    float h100m=0;
    for (int i = 0; i < nc; i++)
    {
        h100m=+(tab[i].homens*100)/tab[i].mulheres;
    }
    return h100m/nc;
}
/*
 * Determina índice do concelho com maior relação h/100m.
 */
int max_h100m(concelho *tab, int nc) {
    if (nc <= 0) {
        return -1;
    }

    int max_index = 0;

    for (int i = 1; i < nc; i++) {
        if ((tab[i].homens*100)/tab[i].mulheres > (tab[max_index].homens*100)/tab[max_index].mulheres) {
            max_index = i; 
        }
    }

    return max_index;
}



/*
 * B.3.a)
 * Copia tabela para tabela nova.
 */
concelho *copia_tabela(concelho *tab_in, int nc) {
    concelho *tab_out = malloc(nc * sizeof(concelho));
    if (tab_out == NULL) {
        printf("Error allocating memory.\n");
        return NULL;
    }

    for (int i = 0; i < nc; i++) {
        tab_out[i]=tab_in[i];
    }

    return tab_out;
}

/*
 * Ordena tabela por ordem decrescente por área.
 */
void ordem_area(concelho *tab_ord, int nc) {
	for (int i = 0; i < nc; i++) {
        for (int j = i+1; j < nc; j++) {
            if (tab_ord[i].area < tab_ord[j].area) {
                concelho temp = tab_ord[i];
                tab_ord[i] = tab_ord[j];
                tab_ord[j] = temp;
            }
        }
    }

}
/*
 * Ordena tabela por ordem decrescente por população.
 */
void ordem_pop(concelho *tab_ord, int nc) {
	for (int i = 0; i < nc; i++) {
        for (int j = i+1; j < nc; j++) {
            if (tab_ord[i].homens+tab_ord[i].mulheres < tab_ord[j].homens+tab_ord[j].mulheres) {
                concelho temp = tab_ord[i];
                tab_ord[i] = tab_ord[j];
                tab_ord[j] = temp;
            }
        }
    }

}
/*
 * Ordena tabela por ordem decrescente por densidade populacional.
 */
void ordem_densidade(concelho *tab_ord, int nc){
    for (int i = 0; i < nc; i++) {
        for (int j = i+1; j < nc; j++) {
            if ((tab_ord[i].homens+tab_ord[i].mulheres)/tab_ord[i].area < (tab_ord[j].homens+tab_ord[j].mulheres)/tab_ord[j].area) {
                concelho temp = tab_ord[i];
                tab_ord[i] = tab_ord[j];
                tab_ord[j] = temp;
            }
        }
    }
}


/*
 * Ordena tabela por ordem decrescente por homens por 100 mulheres.
 */
void ordem_h100m(concelho *tab_ord, int nc) {
	for (int i = 0; i < nc; i++) {
        for (int j = i+1; j < nc; j++) {
            if ((tab_ord[i].homens*100)/tab_ord[i].mulheres < (tab_ord[j].homens*100)/tab_ord[j].mulheres) {
                concelho temp = tab_ord[i];
                tab_ord[i] = tab_ord[j];
                tab_ord[j] = temp;
            }
        }
    }

}
