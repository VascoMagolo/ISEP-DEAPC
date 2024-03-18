
#include<stdio.h>
//this program will print the sequence 10 89 80
//v1 = 10 because the pointer n is pointing to the first element of the array
//v2 = *(n+2) - v1 = 99 - 10 = 89
//n = n+3 this means that the pointer n is now pointing to the 4th element of the array
int main()
{
 int num[]={10,21,99,52,80};
 int *n,v1,v2;
 n = num;
 v1 = *n;
 v2 = *(n+2) - v1;
 n = n+3; 
 
 printf("Seq: %d %d %d ", v1,v2,*n ); 
 return(0);
}



/*exerc 4

*/
