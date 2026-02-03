#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

enum{ ADD, SUB, MUL, DIVI };

void *add_int( void *a, void *b, void *result ){ 
  *((int *)result) = *((int *)a) + *((int *)b) ; 
}

void *add_doub( void *a, void *b, void *result ){ 
  *((double *)result) = *((double *)a) + *((double *)b) ; 
}

void *add_short( void *a, void *b, void *result ){ 
  *((short *)result) = *((short *)a) + *((short *)b) ; 
}

void *add_ll( void *a, void *b, void *result ){ 
  *((long long *)result) = *((long long *)a) + *((long long *)b) ; 
}

void *sub_int( void *a, void *b, void *result ){ 
  *((int *)result) = *((int *)a) - *((int *)b) ; 
}

void *sub_doub( void *a, void *b, void *result ){ 
  *((double *)result) = *((double *)a) - *((double *)b) ; 
}

void *sub_short( void *a, void *b, void *result ){ //bug 10-20 = 30
  *((short *)result) = *((short *)a) - *((short *)b) ; 
}

void *sub_ll( void *a, void *b, void *result ){ //bug 10-20 = very large fixed -ve number
  *((long long *)result) = *((long long *)a) + *((long long *)b) ; 
}

void *mul_int( void *a, void *b, void *result ){ 
  *((int *)result) = (*((int *)a)) * (*((int *)b) ); 
}

void *mul_doub( void *a, void *b, void *result ){ 
  *((double *)result) = (*((double *)a)) * (*((double *)b) ) ; 
}

void *mul_short( void *a, void *b, void *result ){ 
  *((short *)result) = (*((short *)a)) * (*((short *)b) ) ; 
}

void *mul_ll( void *a, void *b, void *result ){ 
  *((long long *)result) = (*((long long *)a)) * (*((long long *)b) ) ; 
}

void *divi_int( void *a, void *b, void *result ){ 
  *((int *)result) = (*((int *)a)) / (*((int *)b) ) ; 
}

void *divi_doub( void *a, void *b, void *result ){ 
  *((double *)result) = (*((double *)a)) / (*((double *)b) ) ; 
}

void *divi_short( void *a, void *b, void *result ){ 
  *((short *)result) = (*((short *)a)) / (*((short *)b) ) ; 
}

void *divi_ll( void *a, void *b, void *result ){ //bug 10/20 = very large fixed +ve number
  *((long long *)result) = (*((long long *)a)) / (*((long long *)b) ) ; 
}

//size_t size = sizeof(a)>sizeof(b) ? sizeof(a) : sizeof(b) ;
                                                                      
/*    datatype   operation
            \    /                    */
void*( *func[4][4] )(void *, void *, void *) = {  { add_int,   sub_int,   mul_int,   divi_int },
                                                  { add_doub,  sub_doub,  mul_doub,  divi_doub },
                                                  { add_short, sub_short, mul_short, divi_short },
                                                  { add_ll,    sub_ll,    mul_ll,    divi_ll }
                                                };
                                                 


void *funcCalled( void *a, void *b, size_t size, int operation )
{
  void *result = malloc(size);
  int type = 0;
  if( size == sizeof(int) )  type=0 ;
  else if( size == sizeof(double) ) type=1 ;
  else if( size == sizeof(long long) ) type=2 ;
  else type = 3; //consider long long if other cases fail
  
   func[type][operation]( a, b, result );
  
  return result ;
}

int main()
{
 char op[4] = { '+', '-', '*', '/' };
// int a = 10; int b = 20;                   for( int i = 0;i<4;i++) printf(" %d %c %d = %d \n",   a, op[i], b, *((int *)funcCalled( &a, &b, sizeof(a), i )) );
 //double a = 10; double b = 20;           for( int i = 0;i<4;i++) printf(" %lf %c %lf = %lf \n", a, op[i], b, *((double *)funcCalled( &a, &b, sizeof(a), i )) );
 //short a = 10; short b = 20;             for( int i = 0;i<4;i++) printf(" %d %c %d = %d \n",    a, op[i], b, *((short *)funcCalled( &a, &b, sizeof(a), i  )));
 //long long a = 10; long long b = 20;     for( int i = 0;i<4;i++) printf(" %ld %c %ld = %ld \n", a, op[i], b, *((long long *)funcCalled( &a, &b, sizeof(a), i )) );

}
