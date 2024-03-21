#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* n_letras(int n)
{
    char* p = (char *)calloc(n,sizeof(char));
    for (int i = 0; i < n; i++)
    {
        while(getchar()!='\n'){};
        printf("Insert the letter number %d:",i+1);
        scanf("%c",&p[i]);
    }
    return p;
}

char* repete_letras(char* vec, int nrep)
{
    char* p1 = (char *)calloc((strlen(vec) * nrep),sizeof(char));
    for (int i = 0; i < strlen(vec); i++)
        for (int j = 0; j < nrep; j++)
            p1[i*nrep+j]=vec[i];
    return p1;
}
//
char* recebe_texto()
{
    int n=50;
    char* p = (char *)malloc(sizeof(char)*n);
    
    printf("Insert a text with a maximum of 50 characters and ending with ##:\n");
    fgets(p,n,stdin);
    if(strstr(p,"##")==NULL)
    {
        printf("Error missing the ##\n");
        p[0]='\0';
        return NULL;
    }
    else
    {
        *(strstr(p,"##"))='\0';
        p=(char*)realloc(p,sizeof(char)*(strlen(p)+1));
        return p;
    }
}