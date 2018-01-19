#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void printlength(FILE *file){
  fseek(file, 0, SEEK_END);
  int lengthOfFile = ftell(file);
  printf("%d\n", lengthOfFile);
}
