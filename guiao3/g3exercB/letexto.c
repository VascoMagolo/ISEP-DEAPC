#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"funcoes.h"

#define StrToken ' '

int main()
{
    char* word;
    word=recebe_texto();
    int count=0; char* esp;
    if(word!=NULL)
    {   
        esp=strchr(word,StrToken);
        
        while(esp!=NULL)
        {
            count++;
            esp=strchr(esp+1,StrToken);
        }
        printf("%s\n number of characters: %ld\n spaces: %d\n",word, strlen(word),count);
        free(word);
    }
    return 0;
}