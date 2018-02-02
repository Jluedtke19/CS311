#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>


int main(int argc, char** argv){

  struct stat bob;
  int result = stat("practice.c", &bob);
  time_t curtime;
  curtime = time(NULL);
  if(result == -1){
    perror("stat");
  }
  printf("%ld\n", (curtime -bob.st_atime)/3600);
}
