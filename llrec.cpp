#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot)
{
    smaller = nullptr;
    larger = nullptr;
    if(head == nullptr){
        return;
    }
    Node* curr = head;
    head = head->next;
    curr->next = nullptr;
    if(curr->val <= pivot){
        if(smaller == nullptr) smaller = curr;
        else smaller->next = curr;

        llpivot(head, smaller->next, larger, pivot);
    }
    else if(curr->val > pivot){
        if(larger == nullptr) larger = curr;
        else larger->next = curr;

        llpivot(head, smaller, larger->next, pivot);
    }
}