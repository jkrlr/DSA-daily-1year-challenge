// https://leetcode.com/problems/remove-linked-list-elements/

// Easy

// Tags - LinkedList, Recursion

// What this problem wants to teach me?
// How we can use dummy node concept for handling edge case of deleting head node while deleting a node in LinkedList
// Recursion can be used most of the LinkedList problems
// How we can write recursive soltion by just focusing on writing the solution for curr element by considering all the edge case
// Then, it will work for other cases as well

#include<bits/stdc++.h>
using namespace std;

// Iterative using Dummy Node | Time = O(N), Space = O(1)
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *prev = dummy;
        ListNode *curr = head;  // curr = dummy->next;
        
        while(curr!=NULL){
            if(curr->val==val){
                prev->next = curr->next;
                curr = curr->next;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
            
        return dummy->next;
    }
};

// Recursive | Time = O(N), Space = O(N)-depth of Recursion
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // base case
        if(head==NULL){
            return NULL;
        }
        
        // recursive case
        if(head->val==val){
            return removeElements(head->next,val);
        }
        else{
            head->next = removeElements(head->next,val);
            return head;
        }
    }
};