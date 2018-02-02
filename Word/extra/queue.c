
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

#define NUMBER_OF_PROCESSES  128

// ratio of these 2 parameters will determine
// outcomes of experiment
const double meanInterarrivalTime = 2.0;
const double meanServiceTime = 1.0;

// keep track of how many processes are created
// id number of n-th process will be n
int processCount = 0;

struct process {
  int id;
  double interarrivalTime;
  double serviceTime;

  double arrivalTime;
  double serviceBeginsTime;
  double serviceEndsTime;
  double waitTime;
}; // struct process

struct node {
  struct process *payloadPointer;
  struct node *prev;
  struct node *next;
}; // struct node

struct queue {
  int size;
  struct node *tail;
  struct node *head;
}; // struct queue

typedef struct node Node, *Node_Pointer;
typedef struct process Process, *Process_Pointer;
typedef struct queue Queue, *Queue_Pointer;

double rng( double mean ) {
  return -mean * log( ((double) rand())/RAND_MAX );
} // rng( double )

Queue_Pointer makeQueue() {
  Queue_Pointer resultPointer = (Queue_Pointer) malloc( sizeof( Queue ) );
  resultPointer->size = 0;
  resultPointer->tail = NULL;
  resultPointer->head = NULL;
  return resultPointer;
} // makeQueue()

Process_Pointer makeProcess() {
  Process_Pointer pp =
    (Process_Pointer) malloc( sizeof( Process ) );
  pp->id = processCount++;
  pp->interarrivalTime = rng( meanInterarrivalTime );
  pp->serviceTime = rng( meanServiceTime );

  pp->arrivalTime = 0.0;
  pp->serviceBeginsTime = 0.0;
  pp->serviceEndsTime = 0.0;
  pp->waitTime = 0.0;

  return pp;
} // makeProcess()

int checkQueue( Queue_Pointer qp ) {
  if( qp->size == 0 ) {
    // queue is empty
    // there is no first element
    // there is no last element
    return qp->head == NULL && qp->tail == NULL;
  } // if
  else if( qp->size == 1 ) {
    // queue contains one element

    // tail has no predecessor
    int tailCheck = qp->tail->prev == NULL;

    // head has no successor
    int headCheck = qp->head->next == NULL;

    // tail and head are the same
    int sameCheck = qp->head == qp->tail;

    return tailCheck && headCheck && sameCheck;;
  } // else if
  else if( qp->size > 1 ) {
    // queue contains more than one element

    // the last element has no predecessor
    int tailCheck = qp->tail->prev == NULL;
    // the first element has no successor
    int headCheck = qp->head->next == NULL;

    // each element is correctly connected
    // to its predecessor and successor
    int connectedCheck = TRUE;
    int count = 0;
    Node_Pointer np = qp->tail;
    Node_Pointer pp = NULL;
    if( np != NULL ) {
      count++;
      pp = np;
      np = np->next;
    } // if
    while( np != NULL ) {
      count++;

      connectedCheck = connectedCheck && pp->next == np && np->prev == pp;

      pp = np;
      np = np->next;
    } // while

    int countCheck = count == qp->size;
    
    return tailCheck && headCheck && connectedCheck && countCheck;
  } // else if
  else {
    // size of queue must be non-negative
    return FALSE;
  } // else
} // checkQueue()

int isEmpty( Queue_Pointer qp ) {
  if( qp->size == 0 ) {
    return TRUE;
  } // if
  else {
    return FALSE;
  } // else
} // isEmpty()

void enqueue( Queue_Pointer qp, Process_Pointer pp ) {
  Node_Pointer np = (Node_Pointer) malloc( sizeof( Node ) );
  np->payloadPointer = pp;
  np->prev = NULL;
  np->next = NULL;

  if( isEmpty( qp ) ) {
    qp->tail = np;
    qp->head = np;
  } // if
  else {
    np->next = qp->tail;
    qp->tail->prev = np;
    qp->tail = np;
  } // else

  qp->size++;
} // enqueue()

Process_Pointer dequeue( Queue_Pointer qp ) {
  if( isEmpty( qp ) ) {
    // queue is empty
    // cannot remove a process from a queue that contains
    // no processes!
    return NULL;
  } // if
  else if( qp->tail == qp->head ) {
    // queue contains only one process
    Process_Pointer resultPointer = qp->head->payloadPointer;

    free( qp->head );

    qp->tail = NULL;
    qp->head = NULL;
    qp->size = 0;
    return resultPointer;
  } // else if
  else {
    // queue contains more than one process
    Process_Pointer resultPointer = qp->head->payloadPointer;
    Node_Pointer currentHead = qp->head;
    qp->head = currentHead->prev;
    qp->head->next = NULL;
    qp->size--;

    free( currentHead );

    return resultPointer;
  } // else
} // dequeue()

void copyQueue( Queue_Pointer dp, Queue_Pointer sp ) {
    // empty the destination queue
    while( !isEmpty( dp ) ) {
        Process_Pointer pp = dequeue( dp );
    } // while

    // copy everything in the source queue into
    // the destination queue
    while( !isEmpty( sp ) ) {
        Process_Pointer pp = dequeue( sp );
        enqueue( dp, pp );
    } // while
} // copyQueue( Queue_Pointer, Queue_Pointer )

void deleteQueue( Queue_Pointer qp ) {
    while( !isEmpty( qp ) ) {
        Process_Pointer pp = dequeue( qp );
        free( pp );
    } // while

    free( qp );
} // deleteQueue( QueuePointer )

int main( int argc, char** argv ) {

  // initialize random number generator
  time_t t;
  srand( (unsigned) time(&t) );

  Queue_Pointer qp = makeQueue();

  int n = NUMBER_OF_PROCESSES;
  for( int i = 0; i < n; i++ ) {
    enqueue( qp, makeProcess() );
  } // for

  if( checkQueue( qp ) ) {
      printf( "The structure of the queue is correct.\n" );
  } // if
  else {
      printf( "The structure of the queue is not correct.\n" );
  } // else

  // compute arrival times
  Queue_Pointer rp = makeQueue();
  double previousProcessArrivalTime = 0.0;
  while( !isEmpty(qp) ) {
      Process_Pointer pp = dequeue( qp );

      pp->arrivalTime = pp->interarrivalTime + previousProcessArrivalTime;
      previousProcessArrivalTime = pp->arrivalTime;

      enqueue( rp, pp );
  } // while

  copyQueue(qp, rp);

  // compute times at which each process
  // begins to receive service, when its service
  // ends, and how much time it waits for service
  //
  // compute mean interarrival times, service times,
  // and wait times
  Queue_Pointer sp = makeQueue();

  int count = 0;
  double sumOfInterarrivalTimes = 0.0;
  double sumOfServiceTimes = 0.0;
  double sumOfWaitTimes = 0.0;

  double clock = 0.0;
  while( !isEmpty( qp ) ) {
    Process_Pointer pp = dequeue( qp );
    count++;

    if( pp->arrivalTime > clock ) {
      pp->serviceBeginsTime = pp->arrivalTime;
    } // if
    else {
      pp->serviceBeginsTime = clock;
    } // else

    pp->serviceEndsTime = pp->serviceBeginsTime + pp->serviceTime;
    pp->waitTime = pp->serviceEndsTime - pp->arrivalTime;

    clock = pp->serviceEndsTime;

    double it = pp->interarrivalTime;
    double st = pp->serviceTime;
    double at = pp->arrivalTime;
    double bt = pp->serviceBeginsTime;
    double et = pp->serviceEndsTime;
    double wt = pp->waitTime;

    // print interarrival time, service time, arrival time,
    // time at which service begins, time at which service
    // ends, and time spent waiting for service for this process
//    printf( "(%8.4f, %8.4f, %8.4f, %8.4f, %8.4f, %8.4f)\n", 
//        it, st, at, bt, et, wt );
    
    sumOfInterarrivalTimes += it;
    sumOfServiceTimes += st;
    sumOfWaitTimes += wt;

    enqueue( sp, pp );
  } // while

  // print 3 averages  
  printf( "\n\n\tmean interarrival time = %8.4f\n",
	  sumOfInterarrivalTimes/count );
  printf( "\n\n\tmean service time = %8.4f\n",
	  sumOfServiceTimes/count );
  printf( "\n\n\tmean wait time = %8.4f\n",
          sumOfWaitTimes/count );

  // compute length of waiting line 
  int lengthOfWaitingLine = 0;

  // pointer to node that contains the
  // next process that will arrive
  Node_Pointer ap = sp->head;

  // pointer to node that contains the
  // next process that will depart
  Node_Pointer dp = sp->head;

  while( ap != NULL && dp != NULL ) {
    double nextArrivalTime = ap->payloadPointer->arrivalTime;
    double nextDepartureTime = dp->payloadPointer->serviceEndsTime;

    if( nextArrivalTime < nextDepartureTime ) {
      lengthOfWaitingLine = lengthOfWaitingLine + 1;

      int id = ap->payloadPointer->id;

      printf( "Process #%04d arrives at %8.4f\n", id, nextArrivalTime );
      printf( "\tThe number of processes in line is now %04d\n",
        lengthOfWaitingLine );

      ap = ap->prev;
    } // if
    else {
      lengthOfWaitingLine = lengthOfWaitingLine - 1;
  
      int id = dp->payloadPointer->id;

      printf( "Process #%04d departs at %8.4f.\n", id, nextDepartureTime );
      printf( "\tThe number of processes in line is now %04d\n",
        lengthOfWaitingLine );

      dp = dp->prev;
    } // else

  } // while

  // Allow all processes that are still in the system
  // to complete their work and exit from the system
  while( dp != NULL ) {
      double nextDepartureTime = dp->payloadPointer->serviceEndsTime;
      lengthOfWaitingLine = lengthOfWaitingLine - 1;
  
      int id = dp->payloadPointer->id;

      printf( "Process #%04d departs at %8.4f.\n", id, nextDepartureTime );
      printf( "\tThe number of processes in line is now %04d\n",
        lengthOfWaitingLine );

      dp = dp->prev;
  } // while

  deleteQueue( qp );
  deleteQueue( rp );
  deleteQueue( sp );

  exit(0);
} // main( int, char** )



  
