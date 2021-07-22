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

//-------recReverseLinkedList----// Time = O(N) and Space = O(1)
void reverse(node *&head)
{
    node *prev = NULL;
    node *current = head;

    while (current != NULL)
    {
        // store the next
        node *temp = current->next;

        //update the current
        current->next = prev;

        // prev and current
        prev = current;
        current = temp;
    }
    head = prev;
    return;
}