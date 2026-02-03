void *add_int( void *a, void *b, void *result ){ 

}

void *add_doub( void *a, void *b, void *result ){ 

}

void *add_short( void *a, void *b, void *result ){ 

}

void *add_byte( void *a, void *b, void *result ){ 

}

size_t size = sizeof(a)>sizeof(b) ? sizeof(a) : sizeof(b) ;

void*( *func[4] )(void *, void *, void *) = { add_int, add_doub, add_short, add_byte };

void *funcCalled( void *a, void *b, size_t size, void*( *func[4] )(void *, void *, void *) )
{
  void *result = malloc(size);
  int type = 0;
  if( size == sizeof(int) )  type=0 ;
  else if( size == sizeof(double) ) tyre=1 ;
  else if( size == sizeof(short) ) type=2 ;
  else type = 3; //consider byte if other cases fail
  
   func[type]( a, b, result );
  
  return result ;
}
