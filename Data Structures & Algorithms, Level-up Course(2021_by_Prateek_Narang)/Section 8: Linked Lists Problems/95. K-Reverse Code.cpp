#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

//-------K-ReverseLinkedList----// Time = O(N) and Space = O(N/k)
node *kReverse(node *head, int k)
{
    /* base case */
    if (head == NULL)
    {
        return NULL;
    }

    /* recursive case */
    // reverse the first k nodes
    node *prev = NULL;
    node *current = head;
    node *temp;
    int cnt = 1;

    while (current != NULL && cnt <= k)
    {
        // store the next
        temp = current->next;

        //update the current
        current->next = prev;

        // prev and current
        prev = current;
        current = temp;
        cnt++;
    }
    if (temp != NULL)
    {
        head->next = kReverse(temp, k); // Imp. Tricky step
    }

    return prev;
}
