/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "word.h"

int a = 0;
int i = 0;
char word[20] = {0};
int test;
char str[5000] = {0};
char *ptr;
char linetransfer[50] = {0};
int j = 0;
int c = 0;
char wordlist[60000][20];
int wordcountarr[6000] = {0};
size_t lent;

char **wordcount(ssize_t read, size_t len, FILE * inputstream, char *line, int *letterz){

  //printf("%s\n", "Help");
  while ((read = getline(&line, &len, inputstream)) != -1){
    //printf("%s\n", "Help");
    if( read > 0 ){
      for(int k = 0; line[k]; k++){
        line[k] = tolower(line[k]);
      }

      //printf("%s\n", "Help" );
      ptr = strtok(line, ".;!?-,/\n\" ");
      //printf("%s", "Help");
      while( ptr != NULL){
          //printf("%s\n", ptr );
          //test = checknum();
          //printf("%d\n", test);
          //if(test != -1 ){
          //  wordcountarr[test] += 1;
          //}//if
          //else{
            //wordlist[a] = malloc(strlen(word) + 1);
            strncpy(wordlist[a], ptr, strlen(ptr));
            //wordcountarr[a] += 1;
            a++;
            ptr = strtok(NULL, ".;!?-,/\n\" ");
            //}//else
        }//while
      }//if
      //printf("> %s\n", line);
    }//while
    //for(int k = 0; k < (sizeof(wordcountarr)/sizeof(wordcountarr[0])); k++){
        //printf("%d", wordcountarr[k] );
      //}
      //printf("%s\n", "Help" );
    printf("%d\n ", a);
    //printf("%s\n", wordlist[a-8]);
    char *returnarr = calloc(a-1, sizeof(char));
    for(int c = 0; c < a; c++) {
      //returnarr[c] =  (char) wordlist[c];
      printf("%s\n", wordlist[c]);
    }
    printf("%s\n", "help" );
    //printf("%s\n", wordlist[0]);

    return wordlist;
  }//while

int checknum(){
    //printf("%s\n", ptr );
    for(int b = 0; b < (sizeof(wordlist)/sizeof(wordlist[0])); b++){
      //printf("%s\n","Help" );
      if(!strcmp(wordlist[b], ptr)){
        //printf("%s\n", "Help");
        return b;
      }
      else{
        break;
      }
    }
    //printf("%lu\n", (sizeof(wordlist)/sizeof(wordlist[0])));
    return -1;
}
*/
