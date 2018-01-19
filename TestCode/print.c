#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void printtxt(char *array, int start, int end, FILE *file){
    int fo = fread(array,end,start,file);
    printf("%s\n", array);
  }
