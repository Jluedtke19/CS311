#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "word.h"

int * lettercount(ssize_t read, size_t len, FILE * inputstream, char *line, int *letterz){
  int len2;
  int count;
  while ((read = getline(&line, &len, inputstream)) != -1){
    if( read > 0 ){
      //len2 = strlen(line);
      //printf("%d\n", len2);
      for( int i = 0; i < strlen(line); i++){
        char c = tolower(line[i]);
        printf("%c", line[i]);
        if( 'a' <= c && c <= 'z'){
          //printf("%c", c);
          letterz[c-'a']++;
        }//i
      }//for
      //printf("> %s\n", line);
    }//if
  }//while
  return letterz;
}//lettercount
