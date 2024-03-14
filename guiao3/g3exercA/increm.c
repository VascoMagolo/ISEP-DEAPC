#include <stdio.h>
#include "funcoes.h"
int main(){
    int e=10, f=10;
    incrementa(e,&f);
    printf("%d, %d",e,f);
    return 0;
}