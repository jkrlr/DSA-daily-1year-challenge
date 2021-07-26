// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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

int kthLastElement(node *head, int k)
{
    node *slow = head;
    node *fast = head;

    // move fast by k jumps
    int cnt = 1;
    while (cnt <= k)
    {
        fast = fast->next;
        cnt++;
    }

    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // fast is pointing to last element
    // slow is pointing to kthLastElement
    return slow->data;
}

// LeetCode removeNthNode Sol.
// Tricky step is to create dummy node to handle corner cases

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // create dummy nodes and points it to head
        // helpful for one node List or we've to delete head
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *slow = dummy;
        ListNode *fast = dummy;

        // move fast by n+1 jumps
        int cnt = 1;
        while (cnt<= n+1)
        {
            fast = fast->next;
            cnt++;
        }

        // move fast to end, while maintaing the gap
        while (fast!=NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        return dummy->next;
    }
};
*/