
#include <stdio.h>
#include <string.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define MAX_STRING_LENGTH 40
#define PAGE_SIZE 4096

int main( int argc, char** argv ) {

    struct stat sb;
    off_t len;
    void *p;

    int fd = open ( "schlager.txt", O_RDWR);
    if( fd == -1 ) {
        perror ("open");
        return 1;
    } // if

    p = mmap (0, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (p == MAP_FAILED) {
        perror ("mmap");
        return 1;
    } // if

    void *cp = p;

    for( int i = 0; i < 5; i++ ) {
        int n = *((int *) cp);
        printf( "n = %d\n", n );

        cp += sizeof(int);
        printf( "german = %s\n", (char *) cp );

        cp += MAX_STRING_LENGTH;
        printf( "english = %s\n", (char *) cp );

        cp += MAX_STRING_LENGTH;
        printf( "\n" );
    } // for

    cp = p + sizeof(int);
    strcpy( cp, "THESE ARE THE LYRICS OF A SONG I LIKE" );
    if( close(fd) == -1 ) {
        perror ("close");
        return 1;
    } // if

    if( munmap( p, 4096 ) == - 1 ) {
        perror ("munmap");
        return 1;
    } // if

} // main( int, char** )
