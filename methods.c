void *add( void *a, void *b ){ 

  void *result = malloc( sizeof(a) );
  result = (void *)( (*((type *)a)) + (*((type *)b)) )  ;
  return result ;
}

size_t size = sizeof(a)>sizeof(b) ? sizeof(a) : sizeof(b) ;



void *funcCalled( void *a, void *b, size_t size, void*( *func[4] )(void *, void *, void *) )
{
  void *result = malloc(size);
  int type = 0;
  if( size == sizeof(int) )  type=0 ;
  else if( size == sizeof(double) ) tyre=1 ;
  else if( size == sizeof(short) ) type=2 ;
  else if( size == sizeof(byte) ) type = 3;
  
   func[type]( a, b, result );
  
  return result ;
}
