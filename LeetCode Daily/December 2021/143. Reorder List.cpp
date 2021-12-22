// https://leetcode.com/problems/reorder-list/

// Medium

// Tags - LinkedList

#include<bits/stdc++.h>
using namespace std;

// Mid Find + List Reversal + Merge List | Time = O(2N), Space = O(1)

class Solution {
public:
    void reorderList(ListNode* head) {
        // 1. Find mid of list
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next)
             slow = slow->next, fast = fast->next->next;
        
        // 2. Reverse 2nd half of list
        ListNode* second = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;
        
        while(second){
            ListNode* tmp = second->next;
            second->next = prev;
            prev = second;
            second = tmp;
        }
        
        // 3. Merge two lists
        ListNode* first = head;
        second = prev;
        while(second){
            ListNode *tmp1 = first->next, *tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }  
    }
};