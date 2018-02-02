
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #include <sys/types.h>
// #include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define N 32

int main( int argc, char** argv ) {

    double data[N];
    double values[N];

    int code;
    int fd;

    ssize_t count;

    time_t t;
    srand((unsigned) time(&t));

    /* generate random numbers and store them in an array */
    for( int i = 0; i < N; i++ ) {
        data[i] = ((double) rand())/RAND_MAX;
    } // for

    /* print the contents of the array */
    for( int i = 0; i < N; i++ ) {
        printf( "data[%03d] = %6.4f\n", i, data[i] );
    } // for

    /* write the contents of the data array to a file */
    fd = open( "rng.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU );
  
    count = write( fd, data, (size_t) sizeof(data) );

    code = close( fd );

    /* read the contents of a file into an array */
    fd = open( "rng.txt", O_RDONLY );

    count = read( fd, values, sizeof(values));

    code = close( fd );

    for( int i = 0; i < N; i++ ) {
        printf( "read %8.4f\n", values[i] );
    } // for

} // main( int, char** )
