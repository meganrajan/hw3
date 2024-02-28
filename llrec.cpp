#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {

    if (head == NULL) {
        smaller = NULL;
        larger = NULL;
        return;
    }

    llpivot(head->next, smaller, larger, pivot);

    // check value of current node and assign to appropriate smaller/larger array
    if (head->val <= pivot) {
        head->next = smaller;
        smaller = head;
    } 

    else {
        head->next = larger;
        larger = head;
    }

    head = NULL;
}


/*
head contained 2 4 8 3. If we used 5 as the pivot and called:
llpivot(head, smaller, larger, 5);
Then:
head should be an empty list
smaller should contain 2 4 3
larger should contain 8

*/