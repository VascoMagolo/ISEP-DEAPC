#include<stdio.h>
int main()
{
 int num[]={10,11,12,13,15};
 int *n,*v1,v2=20;
 n = &v2;
 v1 = num;
 v2 = *n+4-*v1;
 *v1 = v2 + 5;
 v1 = v1 + 3;
 *v1 = v2-*v1-*n;
 n = v1-1;
 *n = 0;
 
 printf("Seq: %d %d %d %d %d\n",num[0] ,num[1],num[2],num[3],num[4]);
 return(0);
}