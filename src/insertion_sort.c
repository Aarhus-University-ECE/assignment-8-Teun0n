#include "insertion_sort.h"
#include "linked_list.h"
#include <stdio.h>
#include <assert.h>



void sort(linked_list *llPtr)
{
 // Add your sort function here
//pointing to NULL at some point, should run if fixed
assert(llPtr->head!=NULL);//if list is empty it can't be sorted.
node_t *curr=llPtr->head->next;//points to value being checked, starts at second node.
node_t *last_sort = llPtr->head;//points to last sorted node, starts at first node
node_t *ptr_first=createNode(0); //"dummy node" which has a meaningless value.
ptr_first->next=llPtr->head; //"dummy node" is set to point to first node.

    while(curr!=NULL)
    {
        printf("while 1 \n");
        ptr_first->next=llPtr->head;//is reset to point to first element
        

        if(curr->data<last_sort->data) //checks if next node is larger than last sorted
        {
            last_sort->next=curr->next; // if next node is larger then the order is correct

            if (curr->data<llPtr->head->data) // if current node is smaller than first node
            {
                curr->next=llPtr->head; //current node's next is set to first node
                llPtr->head=curr; //and llPtr head, which is the first value in node_t, is set to current value.
            }
            else //if current data isn't smaller than next ptr_first:
            {
                //while(ptr_first->next->data<=curr->data)
                while(ptr_first->next->data>curr->data)
                
                {
                    printf("while2 \n");
                    if(ptr_first->next->data<=curr->data)
                    {
                        curr->next=ptr_first->next->next;
                        break;
                    }
                    else
                    {
                        ptr_first=ptr_first->next;
                    }
                }
                 
            }
            last_sort=curr;
        }
        else// if curr is larger than last sort
        {
        curr=curr->next;//moves up a node.
        last_sort=last_sort->next;//moves up a node.
        }
        
    }
    
}