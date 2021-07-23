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

int kthLastElement(node *head, int k)
{
    node *slow = head;
    node *fast = head;

    // move fast by k jumps
    int cnt = 1;
    while (cnt < k)
    {
        fast = fast->next;
        cnt++;
    }

    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow->data;
}
