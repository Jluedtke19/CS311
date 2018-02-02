#include <stdio.h>

#include <sys/types.h>
#include <unistd.h>

int main( int argc, char** argv ) {

    printf( "Process id = %d\n", getpid() );
    printf( "Parent process id = %d\n", getppid() );

} // main( int, char** )
