#include "list_queue.h"
#include <stdbool.h>
#include <assert.h>
/*typedef struct qnode
{
  int data;
  struct qnode *next;
} qnode;

typedef struct queue
{
  int size;
  qnode *front;
  qnode *rear;
} queue;*/


void init_queue(queue *q)
{
  // Add your init_queue
  q->size=0; //queue is empty at initialization.
  q->front=NULL; //front pointer isn't pointing at nothing (NULL) at initialization.
  q->rear=NULL; //rear isn't pointing at anything either.
}

int empty(queue *q)
{
  // Add your empty function
  if(q->size==0)
    {
      return 1;//returns if queue size is 0 meaning its empty.
    }
  else
  {
    return 0;
  }
    
}

void enqueue(queue *q, int x)
{
  // Add your enqueue function
  qnode *insert =malloc(sizeof(qnode)); //a new node is made 
  insert->next=NULL; //new node points at NULL.
  insert->data=x;//new nodes data is set to input x.

  if(q->size==0)//if queue is empty node is at the front of queue.
  {
    q->front=insert;//front pointer is set to point at insert.
  }
  else
  {
    q->rear->next=insert;//if node isn't first rear is set to point at node.
  }
  q->rear=insert;
  q->size++;
}

int dequeue(queue *q)
{
  // Add your dequeue function
  assert(q->size>0);

  int front_data = q->front->data;
  int queue_size = q->size;
  if(q->size==1)
  {
    init_queue(q);
  }
  else{
    for(int i=0;i<queue_size-1,i++)
    {
      q->rear=q->rear->next;
      q->front=q->rear->next;
    }

    q->rear->next=q->front;
    q->size=queue_size-1;
  }
  

  return front_data;
}
