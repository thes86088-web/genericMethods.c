#include <stdio.h>
#include <stdlib.h>


int *add( int *a, int *b )
{ int *t = malloc(sizeof(int));
 *t = (*a)+(*b);
  return t; }
int *sub( int *a , int *b ){ 
  int *t = malloc(sizeof(int));
 *t = (*a)-(*b);
  return t; }
int *mul( int *a , int *b  ){ 
  { int *t = malloc(sizeof(int));
 *t = (*a)*(*b);
  return t; }int *divi( int *a , int *b  ){ 
    { int *t = malloc(sizeof(int));
 *t = ((*a)/(*b)) ;
  return t; }

int *((*func)[4])(int *, int *) = {add, sub, mul, divi} ;

int main()
{
  int a = 10; int b=20;
  printf(" %d + %d = %d \n", a, b, *(func[0](a,b)) );
  printf(" %d - %d = %d \n", a, b, *(func[1](a,b)) );
  printf(" %d * %d = %d \n", a, b, *(func[2](a,b)) );
  printf(" %d / %d = %d \n", a, b, *(func[3](a,b)) );
}
