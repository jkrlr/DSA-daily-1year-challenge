// https://leetcode.com/problems/middle-of-the-linked-list/
// Time = O(N) in a single pass , Space = (1)

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

int getMid(node *head)
{
    node *slow = head;
    node *fast = head;

    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}