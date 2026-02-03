#include <stddef.h>'

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

//size_t size = sizeof(a)>sizeof(b) ? sizeof(a) : sizeof(b) ;

void*( *func[4] )(void *, void *, void *) = { add_int, add_doub, add_short, add_ll };

void *funcCalled( void *a, void *b, size_t size )
{
  void *result = malloc(size);
  int type = 0;
  if( size == sizeof(int) )  type=0 ;
  else if( size == sizeof(double) ) tyre=1 ;
  else if( size == sizeof(long long) ) type=2 ;
  else type = 3; //consider long long if other cases fail
  
   func[type]( a, b, result );
  
  return result ;
}

int main()
{
 int a = 10; int b = 20;          int sol = *((int *)funcCalled( &a, &b, sizeof(a) ));        printf(" %d + %d = %d", a, b, sol);
 //double a = 10; double b = 20;  double sol = *((double *)funcCalled( &a, &b, sizeof(a) ));  printf(" %lf + %lf = %lf", a, b, sol);
 //short a = 10; short b = 20;    short sol = *((short *)funcCalled( &a, &b, sizeof(a)  ));   printf(" %d + %d = %d", (int)a, (int)b, (int)sol);
 //long long a = 10; long long b = 20;      long long sol = *((long long *)funcCalled( &a, &b, sizeof(a)  ));     printf(" %d + %d = %d", a, b, sol);

}
