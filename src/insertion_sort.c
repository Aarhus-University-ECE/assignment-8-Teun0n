#include "insertion_sort.h"
#include "linked_list.h"
#include <stdio.h>



void sort(linked_list *llPtr)
{
 // Add your sort function here

node_t *curr=llPtr->head->next;//points to value being checked
node_t *last_sort = llPtr->head;
node_t *ptr_first=createNode(0);
ptr_first->next=llPtr->head;

    while(curr!=NULL)
    {
        printf("while 1 \n");
        ptr_first->next=llPtr->head;//is reset to point to first element
        

        if(curr->data<last_sort->data) //checks if 
        {
            last_sort->next=curr->next;

            if (curr->data<llPtr->head->data)
            {
                curr->next=llPtr->head;
                llPtr->head=curr;
            }
            else
            {
                while(ptr_first->next->data<curr->data)
                {
                    printf("while2 \n");
                    if(ptr_first->next->next->data>=curr->data)
                    {
                        curr->next=ptr_first->next->next;
                        ptr_first->next->next=curr;
                    }
                    ptr_first=ptr_first->next;
                    break;
                }
            }
            curr=last_sort->next;

        }
        else
        {
        curr=curr->next;//moves up a node.
        last_sort=last_sort->next;//moves up a node.
        }
        
    }
}