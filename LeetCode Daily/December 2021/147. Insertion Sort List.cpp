// https://leetcode.com/problems/insertion-sort-list/

// Medium

// Tags - LinkedList, Insertion Sort

// What this problem wants to teach me?
// Create dummy node if it is required to delete or insert a node at head of LinkedList
// For an algorithm if you have to move ith(i>0) position to position 0 by moving backward direction(Right to Left)
// You can do the same work by starting from 0 to ith position by moving forward direction(Left to Right)
// Than means always keep in mind the reverse of everthing whatever you are process following in any particular question

#include<bits/stdc++.h>
using namespace std;

// Insertion-Sort | Time = O(n^2), Space = O(1)

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* start = new ListNode();   // create dummy node and point its next to head
        start->next = head;
        
        ListNode *prev = start, *curr = head;
        
        while(curr){
            if(curr->next && curr->next->val < curr->val){
                while(prev->next && prev->next->val < curr->next->val)
                    prev = prev->next;
                
                ListNode* temp = prev->next;
                prev->next = curr->next;
                curr->next = curr->next->next;
                prev->next->next = temp;
                prev = start;
            }
            else{
                curr = curr->next;
            }
        }
        
        return start->next; // dummy->next is pointing to head
    }
};