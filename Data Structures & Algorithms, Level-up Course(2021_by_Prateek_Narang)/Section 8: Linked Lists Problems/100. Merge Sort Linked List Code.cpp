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

//-------MergeTwoSortedLinkedList----// Time = O(NLogN) and Space = O(LogN)
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

node *midPoint(node *head)
{
    if (head == NULL)
    {
        return head;
    }

    node *slow = head;
    node *fast = head->next;

    if (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

node *mergeSort(node *head)
{
    /* base case */
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    /* recursive case */
    //find mid
    node *mid = midPoint(head); // O(N) Time

    //break at mid
    node *left = head;
    node *right = mid->next;
    mid->next = NULL;

    //recursive sort
    left = mergeSort(left);
    right = mergeSort(right);

    //merge
    return merge(left, right);
}