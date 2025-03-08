#include "llrec.h"
#include <iostream>

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot)
{
    // appease the lord of unit testing
    smaller = nullptr;
    larger = nullptr;

    if(head == nullptr){
        return;
    }

    Node* curr = head;

    head = head->next;
    //unlink on the way in
    curr->next = nullptr;

    //recurse smaller
    if(curr->val <= pivot){
        if(smaller == nullptr) smaller = curr;
        else smaller->next = curr;

        llpivot(head, smaller->next, larger, pivot);
    }
    //recurse larger
    else if(curr->val > pivot){
        if(larger == nullptr) larger = curr;
        else larger->next = curr;

        llpivot(head, smaller, larger->next, pivot);
    }
}