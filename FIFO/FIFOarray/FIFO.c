#include <stdio.h>
#include <stdlib.h>
#define TEST 0;
#include <time.h>

time_t t;
double randomnum();
void fifo(int size, double bmid, double bvar,
	  double amid, double avar);


void fifo(int size, double bmid, double bvar,
	  double amid, double avar){

  srand(time(NULL));

  double burst[size], wait[size], arrival[size];

  for(int i = 0; i < size; i ++){
    wait[i] = 0;

    double storeb = (bmid + (bvar - 2*(bvar * randomnum())));

    //printf("Random Number:%f\n", randomnum());

    if( storeb < 0){
      burst[i] = 0;
    }
    burst[i] = storeb;

    double storea = (amid + (avar - 2*(avar * randomnum())));

    if( i == 0){
      arrival[i] = storea;
    }
    else if( storea < 0 ){
      arrival[i] = arrival[i-1] + storea;
    }
    else{
    arrival[i] = storea - 1;
    }
  }

  for(int a = 0; a < size; a++){
    double value = 0;
    //get previous values
    for( int b = 0; b < a; b++){
      value += burst[b];
	}
    //wait = start - arrival
    wait[a] = value - arrival[a];
  }

  printf("Waiting Times:\n");
  for(int i=0; i<size; ++i){
    printf("%f\n", wait[i]);
  }

  double result = 0;
  for(int i=0; i<size; ++i){
    result += wait[i];
  }
    result/=size;

    printf("Average Waiting Time:%f\n", result);
}

double randomnum(){
  return (double)rand() / (double)RAND_MAX;
}

int main( int argc, char** argv){
  fifo(10, 5, 2, 2, 1);
  printf("%f\n", randomnum());
}
