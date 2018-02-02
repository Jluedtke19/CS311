
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BINS 20
#define LENGTH_OF_LONGEST_BAR 48
#define LARGEST_MULTIPLE_OF_MEAN 4
#define MEAN 1.0
#define SIZE 512

double rng( double mean ) {
  return -mean * log( ((double) rand())/RAND_MAX );
} // rng( double )

int main( int argc , char** argv ) {

  int histogram[BINS];
  // initialize array
  for( int i = 0; i < BINS; i++ ) {
    histogram[i] = 0;
  } // for

  // initialize random number generator
  time_t t;
  srand( (unsigned) time(&t) );

  for( int i = 0; i < SIZE; i++ ) {
    double x = rng( MEAN );

    if( x <= LARGEST_MULTIPLE_OF_MEAN * MEAN ) {
      x = BINS * x/LARGEST_MULTIPLE_OF_MEAN;
      int index = trunc( x );
      histogram[ index ]++;
    } // if

  } // for

//  for( int i = 0; i < BINS; i++ ) {
//    printf( "histogram[%04d] = %04d\n", i, histogram[i] );
//  } // for

  // find number of times that the most
  // common value occurred
  int largestCount;
  for( int i = 0; i < BINS; i++ ) {
    if( histogram[i] > largestCount ) {
      largestCount = histogram[i];
    } // if
  } // for

  // normalize values
  for( int i = 0; i < BINS; i++ ) {
    int length = (int) (LENGTH_OF_LONGEST_BAR * ((double) histogram[i])/largestCount);
    histogram[i] = length;
//    printf( "length = %d\n", length );
  } // for

  // print chart
  for( int i = 0; i < BINS; i++ ) {
    for( int j = 0; j < histogram[i]; j++ ) {
      printf( "*" );
    } // for
    printf( "\n" );
  } // for

} // main( int, char** )
