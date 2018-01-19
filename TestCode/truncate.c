#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#include "truncate.h"

int fo;
char message[200];

int main(){  

  FILE *fp = fopen("./test.txt", "r");
  if( fp == NULL){
    perror("fopen");
  }

  printtxt(message,1, 53, fp);

  printlength(fp);
 
  fclose(fp);
  
  int ret;
  ret = truncate("./truncate.txt", 39);
  printf("%d\n", ret);
  perror("truncate");
  
  //printf("%s\n", "string");

  int retfalse;
  retfalse = truncate("./tesk.txt", 22);
  //printf("%d\n", retfalse);
  if(retfalse == -1){
    perror("truncate");
  }
  
  return 0;
}
