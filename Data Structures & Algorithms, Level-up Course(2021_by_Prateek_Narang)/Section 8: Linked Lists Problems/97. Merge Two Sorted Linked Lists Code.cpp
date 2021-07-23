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

//-------MergeTwoSortedLinkedList----// Time = O(N+M) and Space = O(N+M)
node *merge(node *head1, node *head2)
{
    // base case
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    // recursive case
    node *head;

    if (head1->data < head2->data)
    {
        head = head1;
        head->next = merge(head1->next, head2);
    }
    else
    {
        head = head2;
        head->next = merge(head1, head2->next);
    }
    return head;
}
