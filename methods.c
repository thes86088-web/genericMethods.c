void *add( void *a, void *b ){ 

  void *result = malloc( sizeof(a) );
  result = (void *)( (*((type *)a)) + (*((type *)b)) )  ;
  return result ;
}
