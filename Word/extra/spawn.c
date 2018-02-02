
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>

int main( int argc, char** argv ) {
    pid_t success;
    int status;
    int options;

    int fd[2];

    int recv;
    int send;

    status = pipe( fd );
    if( status == -1 ) {
        perror( "pipe" );
    } // if

    int pid = fork();
    if( pid == -1 ) {
        perror( "fork" );
    } // if

    if( pid == 0 ) {
        printf( "Child process.\n" );

        ssize_t n = read( fd[0], &recv, sizeof(int) );
        if( n == -1 ) {
            perror( "read" );
        } // if

        printf( "number received from parent process = %d\n", recv );

        status = close( fd[0] );
        if( status == -1 ) {
            perror( "close" );
        } // if
    } // if
    else {
        printf( "Parent process.\n" );

        send = 99;
        ssize_t n = write( fd[1], &send, sizeof(int) );
        if( n == -1 ) {
            perror( "write" );
        } // if

        success = waitpid( pid, &status, options );
        if( success == -1 ) {
            perror( "waitpid" );
        } // if

        status = close( fd[1] );
        if( status == -1 ) {
            perror( "close" );
        } // if

    } // else

    printf( "\n\n" );

    exit(0);
} // main( int, char** )
