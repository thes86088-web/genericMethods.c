void *add( void *a, void *b ){ 

  void *result = malloc( sizeof(a) );
  result = (void *)( (*((type *)a)) + (*((type *)b)) )  ;
  return result ;
}

size_t size = sizeof(a)>sizeof(b) ? sizeof(a) : sizeof(b) ;



void *funcCalled( void *a, void *b, size_t size, void*( *func[4] )(void *, void *, void *) )
{
  void *result = malloc(size);

  if( size == sizeof(int) )
    func[0]( a, b, result );
  
  else if( size == sizeof(double) )
    func[1]( a, b, result );
  
  else if( size == sizeof(short) )
    func[2]( a, b, result );

  else if( size == sizeof(byte) )
    func[3]( a, b, result );
  
  return result ;
}
