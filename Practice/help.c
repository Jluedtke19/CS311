#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "word.h"
struct hash *hashTable = NULL;
char wordlist[60000][20];
int a = 0;
char *ptr;

int size = 2000;


int hashnum(char *name){
  int returnval = 0;
  for(int i = 0; i < strlen(name); i ++){
    returnval += ((int)name[i] - 96);
  }
  return returnval % size;
}

struct node * createNode( char *name) {
    struct node *newnode;
    newnode = (struct node *) malloc(sizeof(struct node));
    strcpy(newnode->name, name);
    newnode->next = NULL;
    newnode->count = 1;
    //printf("%s\n", "Help" );
    return newnode;
}

void insertToHash(char *name) {
  //printf("%s\n","Help" );
    int hashIndex = hashnum(name);
    printf("%d\n", hashIndex );
    struct node *newnode = createNode(name);
    struct node *iteraten = createNode(name);
    //printf("%s\n", "Help" );
    /* head of list for the bucket with index "hashIndex" */
    //if it is the head or not
    if (!hashTable[hashIndex].head) {
      printf("%s\n", "Help" );
        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count = 1;
        return;
    }

    iteraten = hashTable[hashIndex].head;
    while(iteraten != NULL){
      if(!strcmp((iteraten->name), name)){
        printf("%s\n", "Help" );
        iteraten->count += 1;
        return;
      }
      else{
        iteraten = iteraten->next;
        continue;
      }

    }
    /* adding new node to the list */
    newnode->next = (hashTable[hashIndex].head);
    /*
     * update the head of the list and no of
     * nodes in the current bucket
     */
    hashTable[hashIndex].head = newnode;
    hashTable[hashIndex].count++;
    return;
}

void searchInHash(char *name) {
    int hashIndex = hashnum(name), flag = 0;
    struct node *myNode;
    myNode = hashTable[hashIndex].head;
    if (!myNode) {
        printf("Search element unavailable in hash table\n");
        return;
    }
    while (myNode != NULL) {
        if (myNode->name == name) {
            printf("Name     : %s\n", myNode->name);
            flag = 1;
            break;
        }
        myNode = myNode->next;
    }
    if (!flag)
        printf("Search element unavailable in hash table\n");
    return;
}

void display() {
    struct node *myNode;
    int i;
    for (i = 0; i < size; i++) {
        if (hashTable[i].count == 0)
            continue;
        myNode = hashTable[i].head;
        if (!myNode)
            continue;
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
    //printf("%d\n", a);
    //printf("%s\n", wordlist[a-8]);
    char *returnarr = calloc(a-1, sizeof(char));
    for(int c = 0; c < a; c++) {
      //printf("%s\n", wordlist[c]);
    }
    //printf("%s\n", "help" );
  }

int main(int argc, char** agrv){
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  int letterz[26] = {0};
  int *p;

  FILE * inputstream = fopen( "beemovie.txt", "r");

  if( inputstream == NULL){
    printf("No file\n");
    return 1;
  }//if

  wordcount(read, len, inputstream, line, letterz);

  for(int j = 0; j < a; j++ ){
    //printf("%s\n",wordlist[j] );
  }
  //for(int i = 0; i < a-1; i++){
    //insertToHash(wordlist[i]);
  //}
  char *dog = "dog";
  insertToHash(dog);

  fclose( inputstream );
  free( line );

  return -1;

}
