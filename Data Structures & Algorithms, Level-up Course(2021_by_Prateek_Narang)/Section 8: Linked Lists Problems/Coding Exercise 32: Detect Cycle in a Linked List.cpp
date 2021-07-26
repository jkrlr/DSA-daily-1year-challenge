// https://leetcode.com/problems/linked-list-cycle/submissions/
// Time = O(N), Space = O(1)

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

bool containsCycle(node *head)
{
    // Empty List
    if (head == NULL)
    {
        return false;
    }
    node *slow = head;
    node *fast = head->next;

    while (fast != NULL and fast->next != NULL)
    {
        if (slow == fast)
        {
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}