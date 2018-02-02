#include <stdlib.h>
#include <stdio.h>
#include <time.h>



double randomnum(){
  return (double)rand() / (double)RAND_MAX;
}


double burst(double bmid, double bvar){
  double reval = (bmid + (bvar - 2*(bvar *randomnum())));
  if(reval < 0){
    return 0;
  }
  else{
  return reval;
  }
}

double arrival( double amid, double avar){
  double reval = (amid + (avar - 2*(avar *randomnum())));
  if(reval <= 0){
    return 0;
  }
  else{
    return reval;
  }
}
