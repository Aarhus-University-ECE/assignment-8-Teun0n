#include "insertion_sort.h"
#include "linked_list.h"
#include <stdio.h>



void sort(linked_list *llPtr)
{
 // Add your sort function here

node_t *curr=llPtr->head->next;
node_t *last_sort = llPtr->head;
node_t *ptr_first=createNode(0);
ptr_first->next=llPtr->head;

    while(curr!=NULL)
    {
        ptr_first->next=llPtr->head;
        //curr->next=last_sort->next;

        if(curr->data<last_sort->data)
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
                    if(ptr_first->next->next->data>=curr->data)
                    {
                        curr->next=ptr_first->next->next;
                        ptr_first->next->next=curr;
                    }
                    ptr_first=ptr_first->next;
                }
            }
            curr=last_sort->next;

        }
        else
        {
        curr=curr->next;
        last_sort=last_sort->next;
        }
        
    }
}