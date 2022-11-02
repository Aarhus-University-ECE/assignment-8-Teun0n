#include "insertion_sort.h"
#include "linked_list.h"
#include <stdio.h>
#include <assert.h>



void sort(linked_list *llPtr)
{
 // Add your sort function here
    node_t* curr = llPtr->head->next; //current node
    node_t* last_sort = llPtr->head;//last sorted node
    node_t* temp;

    while(curr != NULL)
    {
        if (curr->data < last_sort->data) // if currents data is less than last sorted data.
        {
            last_sort->next=curr->next; //last_sorts next needs to be point at curr next, before currs next is changed
           
            temp = llPtr->head;//temp is set to point at first node.
             while (temp->next->data <= curr->data)
             /*temp is moved up the nodes until curr is larger than temps next,
              which is its right spot.*/
             {
                  temp = temp->next;//temp is moved to next node.
                }

              
               if (llPtr->head==temp)//if first value is equal to temp at any point.
               {
                    curr->next=llPtr->head; // curr next is set to point at first value
                     llPtr->head = curr; //first value is redefined to curr 

               }
               else 
               {
            
                curr->next = temp->next;//curr is set to point at temps next
                temp->next = curr; // temp is set to point at curr.
                }
        }
        last_sort = curr; //moves last_sorted to next node.
        curr = last_sort->next;//moves curr to next node.
    }
}