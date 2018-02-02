#include <stdio.h>
#include <string.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define maxlength 40
#define pagesize 4096

int main(int argc, char** argv) {

  struct stat sb;
  off_t len;
  void *p;

  int fd = open( "schlager.txt", O_RDWR);
  if (fd == -1) {
    perror ("open");
    return 1;
  }

  p == mmap (0, pagesize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (p == MAP_FAILED) {
    perror ("mmap");
    return 1;
  }

  void *cp = p;

  for (int i = 0; i < 5; i++){
    int n = *((int *) cp);
    printf( "n = %d\n" , n);

    cp += sizeof(int);
    printf ("german = %s\n", (char *) cp);
    cp += maxlength;
    printf( "english = %s\n", (char *) cp);
    cp += maxlength;
    printf( "\n");
  }
  cp = p + sizeof(int);
  strcpy( cp, "THESE ARE THE LYRICS OF A SONG I LIKE");
  if( close(fd) == -1){
    perror("close");
    return 1;
  }
  if (munmap (p, pagesize) == -1){
    perror ("munmap");
    return 1;
  }
}

