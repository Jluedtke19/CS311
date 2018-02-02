#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "queue.h"
time_t t;
int size;

struct Node {
  node next;
  node previous;
  double arrival, burst, wait;
};

node last;
node first;

int enqueue (double bmid, double bvar,
	  double amid, double avar) {

  node temp;
  temp = (node)malloc(sizeof(struct Node));
  temp->burst = randomnum();
  if (last == NULL && first == NULL) {
    temp->next = NULL;
    temp->previous = NULL;
    last = temp;
    first = temp;
    temp->arrival = 0;
    temp->burst = burst(bmid, bvar);
    temp->wait = 0;
  }

  else {
    last->next = temp;
    temp->previous = last;
    temp->arrival = temp->previous->arrival + arrival(amid, avar);
    temp->burst = burst(bmid,bvar);
    double holder = burstsum(first) - temp->arrival;
    if (holder <=0 ){
    temp->wait = 0;
  } else{
    temp->wait = holder;
  }
    last = temp;
  }
  return 1;
} // enqueue

int dequeue () {
  // catch empty queue
  if (first == NULL) {
    return -1;
  }

  if (last = first) {
    return -1;
  }
  node result = first;

  first = first->next;
  return result->burst;
}

void iterate(){
  node thing = first;
  while(thing != NULL){
    printf("%f, %f, %f\n", thing->burst, thing->arrival, thing->wait);
    thing = thing->next;
  }
}
int main (int argv, char** argc) {
  size = 100;
  srand(time(NULL));
  for (int i = 0; i <size; i ++){
    enqueue(5, 2, 2, 1);
  }
  iterate();
  printf("Average wait : %f\n", waitav(size, first));
  printf("Average arrival between : %f \n", arravbt(first, size));
  //printf("Average arrival : %f \n", arrav());
  printf("Burst sum : %f \n", burstsum(first));
  //for (int i = 0; i <100; i ++){
  //  printf("Random num : %f\n", arrival(100, 50));
  //}
  return 1;
}
