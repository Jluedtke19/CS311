#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char** argv){
  char buffer[128];
  printf("%s\n", argv[0]);
  int opening = open("data.dat", O_RDONLY);
  if(opening  == -1){
    printf("%s\n", strerror(errno));
  }
  ssize_t op = read(opening,&buffer,200);
  if(op  == -1){
    perror("read");
  }
  printf("%s\n", buffer);
  int closing =close(opening);
}
