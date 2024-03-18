/*exerc 3
valor py=0x130098FC
valor px=0x13009908

printf(“%d %d\n”,x,y);
printf (“%d %d\n”, *px, *py);
printf (“%d %d\n”,&px,&py);
printf (“%d %d\n”,&x,&y);

isto irá imprimir:
10 20
10 20
13009904 13009900
13009908 130098FC

se px=py
printf(“ %d %x %x %d %d %x %x %d”, x, &x, px, *px, y, &y, py, *py);
isto imprime:
10 13009908 130098FC 20 20 130098FC 130098FC 20
*/
#include <stdio.h>
int main()
{
  int x=10, y=20;
  int *px, *py;
  px = &x;
  py = &y;
  printf("%d %d\n",x,y);
  printf("%d %d\n", *px, *py);
  printf("%d %d\n",&px,&py);
  printf("%d %d\n",&x,&y);
  printf(" %d %x %x %d %d %x %x %d\n", x, &x, px, *px, y, &y, py, *py);
  px=py;
  printf(" %d %x %x %d %d %x %x %d\n", x, &x, px, *px, y, &y, py, *py);  
  return(0);
}