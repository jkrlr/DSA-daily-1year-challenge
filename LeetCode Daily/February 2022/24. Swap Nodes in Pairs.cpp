// https://leetcode.com/problems/subsets/

// Medium

// Tags - Pointer Manipulation - Edge case thinking, LinkedList, Recursion

// What this problem wants to teach me?
// How to think the correct pointer manipulation while reversing the LinkedList
// dummy node creation will be helpful


#include<bits/stdc++.h>
using namespace std;

// Pointer Manipulation - Edge case thinking  | Time - O(N), Space - O(1)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode *prev = dummy, *curr = head;

        while(curr && curr->next){
            ListNode* nextPair = curr->next->next;
            ListNode* second = curr->next;
            
            second->next = curr;
            curr->next = nextPair;
            prev->next = second;
            
            prev = curr;
            curr = nextPair;
        }
        
        return dummy->next;
    }
};

// Recursive  | Time - O(N), Space - O(N)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode* second = head->next;
        head->next = swapPairs(head->next->next);
        second->next = head;
        
        return second;
    }
};