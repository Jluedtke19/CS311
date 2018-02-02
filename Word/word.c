#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "word.h"
struct hash *hashTable = NULL;
int size = 10000;
int a = 0;
char *ptr;
char wordlist[500000][50];


int hashnum(char *name){
  int returnval = 0;
  //minus 96 becuase a starts at 1
  for(int i = 0; i < strlen(name); i ++){
    returnval += ((int)name[i] - 96);
  }
  //negative values for non letters
  if(returnval < 0){
    return (returnval * -1);
  }
  else{
  return returnval % size;
}
}

struct node * createNode( char *name) {
    struct node *newnode;
    newnode = (struct node *) malloc(sizeof(struct node));
    //Set node name
    strcpy(newnode->name, name);
    newnode->next = NULL;
    newnode->count = 1;
    //printf("%s\n", "Help" );
    return newnode;
}

void insertToHash(char *name) {
    int hashIndex = hashnum(name);
    //printf("%s\n", name );
    struct node *newnode = createNode(name);
    struct node *iteraten = createNode(name);
    //if it is the head or not
    if (!hashTable[hashIndex].head) {
      //printf("%s\n", "Help" );
        hashTable[hashIndex].head = newnode;
        //shows something is in it
        hashTable[hashIndex].count = 1;
        return;
    }
    iteraten = hashTable[hashIndex].head;
    //keep going till null
    while(iteraten != NULL){
      if(!strcmp((iteraten->name), name)){
        //printf("%s\n", "Help" );
        iteraten->count += 1;
        return;
      }
      else{
        iteraten = iteraten->next;
        continue;
      }
    }
    //if it isn't the head or a repeat word
    newnode->next = (hashTable[hashIndex].head);
    hashTable[hashIndex].head = newnode;
    return;
}


void display() {
    struct node *myNode;
    //go through the hash array
    for (int i = 0; i < size; i++) {
        myNode = hashTable[i].head;
        while (myNode != NULL) {
            printf("%-15s", myNode->name);
            printf("%d\n", myNode->count );
            myNode = myNode->next;
        }
    }
    return;
}
void wordcount(ssize_t read, size_t len, FILE * inputstream, char *line, int *letterz){
  while ((read = getline(&line, &len, inputstream)) != -1){
    if( read > 0 ){
      for(int k = 0; line[k]; k++){
        line[k] = tolower(line[k]);
      }
      ptr = strtok(line, ".;!?-,/\n\" ");
      while( ptr != NULL){
        strncpy(wordlist[a], ptr, strlen(ptr));
        a++;
        ptr = strtok(NULL, ".;!?-,/\n\" ");
        }//while
      }//if
      //printf("> %s\n", line);
    }//while
  }

int main(int argc, char** agrv){
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  int letterz[26] = {0};
  int *p;

  FILE * inputstream = fopen( "odyssey.txt", "r");

  if( inputstream == NULL){
    printf("No file\n");
    return 1;
  }//if



  wordcount(read, len, inputstream, line, letterz);
  hashTable = (struct hash *) calloc(a, sizeof(struct hash));
  for(int k = 0; k < a; k++ ){
    //printf("%s\n", wordlist[k] );
    insertToHash(wordlist[k]);
  }
  display();
  /*
  char *cat = "cat";
  char *hat = "hat";
  char *c ="c";
  char *ab = "ab";

  insertToHash(cat);
  insertToHash(cat);
  insertToHash(hat);
  insertToHash(c);
  insertToHash(ab);
  display();
  */
  fclose( inputstream );
  free( line );
  //printf("%s\n", "Help" );
  for(int i = 0; i <26; i++){
    //printf("%c = %d\n", 'a' + i, p[i]);
  }



  return -1;

}
