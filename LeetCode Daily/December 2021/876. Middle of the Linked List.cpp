// https://leetcode.com/problems/middle-of-the-linked-list/

// Easy

// Tags - Fast and Slow Pointer, LinkedList

// What this problem wants to teach me?
// We can insert all the nodes into array (or unordered_set or unordered_map) and then apply array operations on them

#include<bits/stdc++.h>
using namespace std;

// Approach 1: Output to Array | Time = O(N), Space = O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> A = {head};
        while (A.back()->next != NULL)
            A.push_back(A.back()->next);
        return A[A.size() / 2];
    }
};
// Approach 2: Fast and Slow Pointer | Time = O(N), Space = O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
};