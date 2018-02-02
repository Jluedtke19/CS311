time_t
srand(time(NULL));

int random = 20;
for(int i = 0; i <random; i ++){
  double randnum = (double)rand()/(double)RAND_MAX;
  double starval = 0.0;
  for( int j = 0; j < 26; j++){
    if(randnum >= starval && randnum < cdf[j]){
      printf("%c", 'a ' + j);
      break;
    }
  }

}
