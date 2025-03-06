#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot)
{
    if(head == NULL)
    {
        return;
    }
    else if(head->val < pivot){
        smaller = head;
        llpivot(head->next, smaller->next, larger, pivot);
        if(smaller->next != NULL)
        {
            if(smaller->next->val >= pivot)
            {
                smaller->next = NULL;
            }
        }
    }
    else{
        larger = head;
        llpivot(head->next, smaller, larger->next, pivot);
        if(larger->next != NULL)
        {
            if(larger->next->val < pivot)
            {
                larger->next = NULL;
            }
        }
    }
}