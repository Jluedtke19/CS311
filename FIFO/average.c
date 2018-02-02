#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "queue.h"

double burstsum(node first){
  double timecount = 0;
  if(first == NULL){
    return timecount;
  }
  else{
    while (first != NULL){
      timecount += first ->burst;
      first = first ->next;
    }
  }
  return timecount;
}

double waitav(int size, node first){
  return (burstsum(first)/size);
}

double arravbt(node first,int size){
  double arrcount = 0;
  if(first == NULL){
    return arrcount;
  }
  else{

    while (first!= NULL){
      if (first->previous == NULL){
        arrcount += first->arrival;
      }else{
      arrcount += (first->arrival - first->previous->arrival);
    }
      first = first->next;
    }
  }
  return (arrcount/size);
}

double arrav(node first, int size){
  double timecount = 0;
  if(first == NULL){
    return timecount;
  }
  else{
    node waitnode = first;
    while (waitnode != NULL){
      timecount += waitnode->arrival;
      waitnode = waitnode ->next;
    }
  }
  return (timecount/size);
}
