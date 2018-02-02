#include <stdio.h>
#include <stidlib.h>

#include "averages.h"

int main( int argc, char** argv) {
  double num1 = 3.0;
  double num2 = 4.0;

  if( argc > 2 ) {
    num1 = atof( argv[1] );
    num2 = atof( argv[2] );
    
  double arithmeticMeanValue = arithmeticMean( num1, y );
  double geometricMeanValue = geometricMean( num1, y );
  double harmonicMeanValue = harmonicMean( num1 , y );

  printf( "arithmetic mean of %8.4f and %8.4f = %8.4f\n", 
      num1, y, arithmeticMeanValue );
  printf( "geometric mean of %8.4f and %8.4f = %8.4f\n", 
      num1 , y, geometricMeanValue );
  printf( "harmonic mean of %8.4f and %8.4f = %8.4f\n", 
      num1, y, harmonicMeanValue );
}
