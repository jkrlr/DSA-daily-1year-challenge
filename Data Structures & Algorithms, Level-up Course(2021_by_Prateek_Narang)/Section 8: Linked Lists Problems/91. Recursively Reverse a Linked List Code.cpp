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

//-------recReverseLinkedList----//
node *recReverse(node *head)
{
    //base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    //recursive case
    node *sHead = recReverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return sHead;
}
