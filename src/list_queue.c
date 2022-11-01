#include "list_queue.h"
#include <stdbool.h>
#include <assert.h>

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
      return 1;//returns 1 if queue size is 0 meaning its empty.
    }
  else
  {
    return 0; //if queue isn't empty it returns 0.
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

  else //queue isn't empty.
  {
    q->rear->next=insert;//if node isn't first rear is set to point at node.

  }
  q->rear=insert;//rear is set to equal insert, because rear is always the last added node.
  q->size++;//one is added to size.
}

int dequeue(queue *q)
{
  // Add your dequeue function
  
  assert(q->size>0);// if queue is empty, dequeue can't happen.
  int front_data=q->front->data;//front datas value is saved in front_data, before dequeue.
  

  if(q->size==1)
  /*if size is equal to one when queue goes through, dequeue function size will be 0 after, meaning queue needs to be intialized*/
  {
    init_queue(q);//queue is initialized.
  }
  else
  {
    
      q->front=q->front->next;//next in queue is now front.
      q->size--;//queue size is reduced by one.
  }
  return front_data;//fronts data before dequeue is returned.
}
