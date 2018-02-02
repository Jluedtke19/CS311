/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "word.h"
struct hash *hashTable = NULL;
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
    int hashIndex = hashnum(name);
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
        printf("\nData at index %d in Hash Table:\n", i);
        printf("VoterID     Name          Age   \n");
        printf("--------------------------------\n");
        while (myNode != NULL) {
            printf("%-15s", myNode->name);
            myNode = myNode->next;
        }
    }
    return;
}
*/
